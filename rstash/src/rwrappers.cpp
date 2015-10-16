#include "energy.hh"
#include "extras.hh"

RcppExport SEXP sunshine( const SEXP r_sun ) {
// Calculates the total radiation at the top of the atmosphere based on
// latitude and day of the year and the consequent monthly sunshine hours.
// -- used for gridded datasets
    NumericMatrix   swr(r_sun);

    const int   mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31},
                nmon    = 12;

    int             dn, i, j;
    unsigned long   ll, ncell = swr.nrow();

    float   rtoa;

    NumericMatrix   mrtoa( ncell, nmon+2 ),
                    mrsun( ncell, nmon+2 );

    // fill matrices with zeroes
    fill( mrtoa.begin(), mrtoa.end(), 0 );
    fill( mrsun.begin(), mrsun.end(), 0 );
    // allocate lat and lon columns
    // do radiation calculations
    for( ll=0, dn=0; ll<ncell; ll++ ) {
        mrtoa(ll,0) = swr(ll,0);
        mrtoa(ll,1) = swr(ll,1);
        mrsun(ll,0) = swr(ll,0);
        mrsun(ll,1) = swr(ll,1);

        // echo progress to user
        if( ll == 0 ) {
            cout << "Sunshine Progress:" << endl;
        }
        progress_bar(ll, ncell);

        // for each month determine the fraction of sunlight hours
        for( i=0; i<nmon; i++ ) {
            if( swr(ll,i+2)!=-999. ) {
                for( j=0; j<mdays[i]; j++, ++dn ) {
                    // instantaneous radiation at the top of the atmosphere
                    rtoa = cf_TRA( dn, swr(ll,1) );     // column index 1 of the swr matrix is the lat column
                    // monthly total radiation at the top of the atmosphere
                    mrtoa(ll,i+2) += rtoa/mdays[i];
                }
                // monthly fraction of sunlight hours
                mrsun(ll,i+2) = ( (swr(ll,i+2)/mrtoa(ll,i+2))-0.25 )/0.5;
            } else {
                // if is a sea grid cell or missing data set flag
                mrtoa(ll,i+2) = -999.;
                mrsun(ll,i+2) = -999.;
            } // end day
        } // end month
    } // end cell

    // flush to new line -- ready for R
    cout << endl;

    // return SEXP-list of outputs to user
    return List::create( _("Sun.Hrs")=mrsun, _("Rad.Top")=mrtoa );
} // end program


