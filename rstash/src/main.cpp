#include "main.hh"
#include <omp.h>

// Grided climate data is passed from R and accessed via Rcpp wrappers
// ==> cols 01:02 are lat:lon
// ==> cols 03:15 are monthly averages
// Values are then stored in a vector<GridCell>  of length equal to the total number of grid cells
// and contains private members storing the various time-dependent measure of the three drivers.
// GridCell objects are then passed to the evaporation routines where all the relevant bioclimatic
// information is determined.

RcppExport SEXP gridStash( const SEXP R_gtc, const SEXP R_gpr, const SEXP R_gfs, const SEXP R_gcChar ) {

    NumericMatrix   temp(R_gtc), prec(R_gpr), fsun(R_gfs), gcChar(R_gcChar);

    NumericVector   lon = fsun(_,0), lat = fsun(_,1), elev = gcChar(_,2), fcap = gcChar(_,3), swc0 = gcChar(_,4);

    unsigned int    mn;
    unsigned long   ll, ncell = fsun.nrow();

    NumericMatrix   gTOT    (ncell,nvar+2),
                    gAET    (ncell,14), gEET    (ncell,14), gPET    (ncell,14),
                    gDET    (ncell,14), gPAR    (ncell,14), gMI     (ncell,14),
                    gALPHA  (ncell,14), gGDD0   (ncell,14), gGDD5   (ncell,14),
                    gGDD10  (ncell,14), gCHILL  (ncell,14), gRO     (ncell,14),
                    gSWC0   (ncell,3);

    GridCell gridCell;
    // initialise vectors in object
    gridCell.init_Day();
    gridCell.init_Month();
    gridCell.resIn_Year();
    // run through each grid cell and perform daily time-series calculations
    #pragma omp parallel for private(mn) firstprivate(gridCell)
    for( ll=0; ll<ncell; ll++ ) {

        // initialise the cell and zero object private members
        gridCell.reset_Day();
        gridCell.reset_Month();
        gridCell.resIn_Year();

        // set cell characteristics
        gridCell.set_Cell( ll+1 );
        gridCell.set_Elev( elev(ll) );
        gridCell.set_Fcap( fcap(ll) );
        gridCell.set_Coord( lat(ll), lon(ll) );

        // if SWC has a value then set this as the initial condition and no spin-up is required
        if( swc0[ll]!=-9999.) {
            gridCell.init_SMC( swc0[ll] );
            gridCell.set_SpinUp( false );
        } else {
            gridCell.set_SpinUp( true );
        }

        // store monthly climate drivers in the gridCell object (+2 to get rid of lat-lon columns)
        for( mn=0; mn<gridCell.get_MLEN(); mn++ ) {
            gridCell.set_mTEMP( temp(ll,mn+2), mn );
            gridCell.set_mFSUN( fsun(ll,mn+2), mn );
            gridCell.set_mPPT ( prec(ll,mn+2), mn );
        }

        // linearly interpolate monthly values to daily values for the climate drivers
        gridCell.linearINT( gridCell, gridCell.get_mFSUN(),  &GridCell::set_dFSUN );
        gridCell.linearINT( gridCell, gridCell.get_mTEMP(),  &GridCell::set_dTEMP );
        gridCell.linearINT( gridCell, gridCell.get_mPPT (),  &GridCell::set_dPPT  );
        //cout << "STASHING >> Grid Cell :" << gridCell.get_Cell() << endl;
        // do water balance calculations
        waterBucket( gridCell );
        // perform monthly and annual sums
        gridCell.growDegDay();
        gridCell.monthlySums();
        gridCell.monthlyIndex();
        gridCell.annualSums();

#pragma omp critical
{
        // convert back to matrices for export to R
        assign_Rinit( gridCell, ll, gSWC0, 364, &GridCell::get_dSMC     );
        assign_Rtotal( gridCell, ll, gTOT );
        assign_Rmonth( gridCell, ll, gAET,     &GridCell::get_mAET     );
        assign_Rmonth( gridCell, ll, gEET,     &GridCell::get_mEET     );
        assign_Rmonth( gridCell, ll, gPET,     &GridCell::get_mPET     );
        assign_Rmonth( gridCell, ll, gDET,     &GridCell::get_mDET     );
        assign_Rmonth( gridCell, ll, gPAR,     &GridCell::get_mPAR     );
        assign_Rmonth( gridCell, ll, gRO,      &GridCell::get_mRUN     );
        assign_Rmonth( gridCell, ll, gMI,      &GridCell::get_mMI      );
        assign_Rmonth( gridCell, ll, gALPHA,   &GridCell::get_mALPHA   );
        assign_Rmonth( gridCell, ll, gGDD0,    &GridCell::get_mGDD0    );
        assign_Rmonth( gridCell, ll, gGDD5,    &GridCell::get_mGDD5    );
        assign_Rmonth( gridCell, ll, gGDD10,   &GridCell::get_mGDD10   );
        assign_Rmonth( gridCell, ll, gCHILL,   &GridCell::get_mCHILL   );

}

    }
    return List::create(
            _("Total")  = gTOT, _("AET")    = gAET, _("EET")    = gEET,     _("PET")    = gPET,      _("DET") = gDET,
            _("PAR")    = gPAR, _("MI")     = gMI,  _("RO")     = gRO,      _("Alpha")  = gALPHA,
            _("GDD0")   = gGDD0,_("GDD5")   = gGDD5,_("GDD10")  = gGDD10,   _("Chill")  = gCHILL,
            _("SWC0")   = gSWC0
            );
}

void assign_Rtotal( GridCell &gc, const unsigned long ll, NumericMatrix yGrid ) {
    NumericVector   year_vars(nvar+2);
    year_vars = NumericVector::create(
            gc.get_Lon(),   gc.get_Lat(),
            gc.get_yAET(),  gc.get_yEET(),  gc.get_yPET(),
            gc.get_yDET(),  gc.get_yPAR(),  gc.get_yMI(),
            gc.get_yALPHA(),gc.get_yTEMP(), gc.get_yPPT(),
            gc.get_yFSUN(), gc.get_yRUN(),
            gc.get_yGDD0(),
            gc.get_yGDD5(),
            gc.get_yGDD10(),
            gc.get_yCHILL()
            );
    for( unsigned int i=0; i<nvar+2; i++ ) {
        yGrid(ll,i) = year_vars(i);
    }
}

void assign_Rinit( GridCell &gc, const unsigned long ll, NumericMatrix mGrid, const unsigned int i, float (GridCell::*fget)(const int) const ) {
    mGrid(ll,0) = gc.get_Lon();
    mGrid(ll,1) = gc.get_Lat();
    mGrid(ll,2) = (gc.*fget)(i);
}

void assign_Rmonth( GridCell &gc, const unsigned long ll, NumericMatrix mGrid, float (GridCell::*fget)(const int) const ) {
    mGrid(ll,0) = gc.get_Lon();
    mGrid(ll,1) = gc.get_Lat();
    for( int i=0; i<gc.get_MLEN(); i++ ) {
        mGrid(ll,i+2) = (gc.*fget)(i);
    }
}

void assign_Rmonth( GridCell &gc, const unsigned long ll, NumericMatrix mGrid, int (GridCell::*fget)(const int) const ) {
    mGrid(ll,0) = gc.get_Lon();
    mGrid(ll,1) = gc.get_Lat();
    for( int i=0; i<gc.get_MLEN(); i++ ) {
        mGrid(ll,i+2) = (gc.*fget)(i);
    }
}

