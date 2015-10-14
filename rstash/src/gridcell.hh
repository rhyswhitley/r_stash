#ifndef _gridcell_RCPP_GRIDCELL_H
#define _gridcell_RCPP_GRIDCELL_H
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

class GridCell {
/* Objects built from this class define a geographically referenced grid cell that holds estimations
 * of climate-surface energy exchange. Energy-exchange variables are used to determine bioclimatic
 * information for a given coordinate.
 * Based off the STASH sourced code (M. Sykes 1996) and PEATSTASH source code (Gallego-Sala 2010).
 * Modified to C++ by R. Whitley.
 */
private:
    // OBJECT VARIABLES
    static const int
                    mlen = 12, dlen = 365;
    bool            wbss,   spinup;
    unsigned int    cell,   ygdd0,  ygdd5,  ygdd10;
    float           lat,    lon,    elev,   fcap,
                    yaet,   yeet,   ypet,   ydet,   ypar,
                    ymi,    yalpha, ytc,    ypr,    yfs,
                    ytn,    ytx,    yrd,    yro,    ychill,
                    ybio01, ybio02, ybio03, ybio04, ybio05,
                    ybio06, ybio07, ybio08, ybio09, ybio10,
                    ybio11, ybio12, ybio13, ybio14, ybio15,
                    ybio16, ybio17, ybio18, ybio19, ybio20,
                    ybio21, ybio22, ybio23, ybio24, ybio25,
                    ybio26, ybio27;
    vector<int>     mchill, gday0,  gday5,  gday10;
    vector<float>   dtc,    dfs,    dpr,    dtn,
                    dtx,    drd,    dsm,    dro,
                    daet,   deet,   dpet,   ddet,
                    dmi,    dalpha, dpar,
                    gdd0,   gdd5,   gdd10,
                    mgdd0,  mgdd5,  mgdd10,
                    mtc,    mfs,    mpr,    mtn,
                    mtx,    mrd,    mro,
                    maet,   meet,   mpet,   mdet,
                    mmi,    malpha, mpar,
                    mbio02, mbio03, mbio04, mbio15, mbio23;
public:
    // CONSTRUCTOR
    GridCell() {
        init_Day();
        init_Month();
        resIn_Year();
        fcap    = 150.0;
        elev    = 1.0;
        wbss    = false;
        spinup  = false;
        dsm[0]  = fcap;
    };
    // INITIALISERS
    void init_Day();
    void init_Month();
    void resIn_Year();
    void reset_Day();
    void reset_Month();

    void init_SMC   (const float val);
    // SETTERS
    void set_Cell   ( const int i);
    void set_Coord  ( const float rlat, const float rlon );
    void set_Elev   ( const float val );
    void set_Fcap   ( const float val );
    void set_WBflag ();
    void set_SpinUp ( const bool val );
    // yearly
    void set_yGDD0  ( const int val );
    void set_yGDD5  ( const int val );
    void set_yGDD10 ( const int val );
    void set_yCHILL ( const int val );
    void set_yMI    ( const float val );
    void set_yRUN   ( const float val );
    void set_yAET   ( const float val );
    void set_yEET   ( const float val );
    void set_yPET   ( const float val );
    void set_yDET   ( const float val );
    void set_yPAR   ( const float val );
    void set_yTEMP  ( const float val );
    void set_yFSUN  ( const float val );
    void set_yPPT   ( const float val );
    void set_yTMIN  ( const float val );
    void set_yTMAX  ( const float val );
    void set_yRAD   ( const float val );
    void set_yALPHA ( const float val );
    void set_yBIO01 ( const float val );
    void set_yBIO02 ( const float val );
    void set_yBIO03 ( const float val );
    void set_yBIO04 ( const float val );
    void set_yBIO05 ( const float val );
    void set_yBIO06 ( const float val );
    void set_yBIO07 ( const float val );
    void set_yBIO08 ( const float val );
    void set_yBIO09 ( const float val );
    void set_yBIO10 ( const float val );
    void set_yBIO11 ( const float val );
    void set_yBIO12 ( const float val );
    void set_yBIO13 ( const float val );
    void set_yBIO14 ( const float val );
    void set_yBIO15 ( const float val );
    void set_yBIO16 ( const float val );
    void set_yBIO17 ( const float val );
    void set_yBIO18 ( const float val );
    void set_yBIO19 ( const float val );
    void set_yBIO20 ( const float val );
    void set_yBIO21 ( const float val );
    void set_yBIO22 ( const float val );
    void set_yBIO23 ( const float val );
    void set_yBIO24 ( const float val );
    void set_yBIO25 ( const float val );
    void set_yBIO26 ( const float val );
    void set_yBIO27 ( const float val );
    // monthly
    void set_mGDD0  ();
    void set_mGDD5  ();
    void set_mGDD10 ();
    void set_CHILL  ( const int i );
    void set_GDEG0  ( const float val, const int i );
    void set_GDEG5  ( const float val, const int i );
    void set_GDEG10 ( const float val, const int i );
    void set_mRUN   ( const float val, const int i );
    void set_mMI    ( const float val, const int i );
    void set_mAET   ( const float val, const int i );
    void set_mEET   ( const float val, const int i );
    void set_mPET   ( const float val, const int i );
    void set_mDET   ( const float val, const int i );
    void set_mPAR   ( const float val, const int i );
    void set_mPPT   ( const float val, const int i );
    void set_mFSUN  ( const float val, const int i );
    void set_mTEMP  ( const float val, const int i );
    void set_mTMIN  ( const float val, const int i );
    void set_mTMAX  ( const float val, const int i );
    void set_mRAD   ( const float val, const int i );
    void set_mALPHA ( const float val, const int i );
    void set_mBIO02 ( const float val, const int i );
    void set_mBIO03 ( const float val, const int i );
    void set_mBIO04 ( const float val, const int i );
    void set_mBIO15 ( const float val, const int i );
    void set_mBIO23 ( const float val, const int i );
    // daily
    void set_dSMC   ( const float val, const int i );
    void set_dRUN   ( const float val, const int i );
    void set_dMI    ( const float val, const int i );
    void set_dAET   ( const float val, const int i );
    void set_dEET   ( const float val, const int i );
    void set_dPET   ( const float val, const int i );
    void set_dPAR   ( const float val, const int i );
    void set_dDET   ( const float val, const int i );
    void set_dPPT   ( const float val, const int i );
    void set_dFSUN  ( const float val, const int i );
    void set_dTEMP  ( const float val, const int i );
    void set_dTMIN  ( const float val, const int i );
    void set_dTMAX  ( const float val, const int i );
    void set_dRAD   ( const float val, const int i );
    void set_dALPHA ( const float val, const int i );
    void set_dCHILL ( const float val, const int i );
    // GETTERS
    float get_Cell   () const;
    float get_MLEN   () const;
    float get_DLEN   () const;
    float get_Lat    () const;
    float get_Lon    () const;
    float get_Fcap   () const;
    float get_Elev   () const;
    bool  get_SpinUp () const;
    // yearly
    int get_yCHILL   () const;
    float get_yGDD0  () const;
    float get_yGDD5  () const;
    float get_yGDD10 () const;
    float get_yMI    () const;
    float get_yRUN   () const;
    float get_yAET   () const;
    float get_yEET   () const;
    float get_yPET   () const;
    float get_yDET   () const;
    float get_yPAR   () const;
    float get_yTEMP  () const;
    float get_yFSUN  () const;
    float get_yPPT   () const;
    float get_yTMIN  () const;
    float get_yTMAX  () const;
    float get_yRAD   () const;
    float get_yALPHA () const;
    float get_yBIO01 () const;
    float get_yBIO02 () const;
    float get_yBIO03 () const;
    float get_yBIO04 () const;
    float get_yBIO05 () const;
    float get_yBIO06 () const;
    float get_yBIO07 () const;
    float get_yBIO08 () const;
    float get_yBIO09 () const;
    float get_yBIO10 () const;
    float get_yBIO11 () const;
    float get_yBIO12 () const;
    float get_yBIO13 () const;
    float get_yBIO14 () const;
    float get_yBIO15 () const;
    float get_yBIO16 () const;
    float get_yBIO17 () const;
    float get_yBIO18 () const;
    float get_yBIO19 () const;
    float get_yBIO20 () const;
    float get_yBIO21 () const;
    float get_yBIO22 () const;
    float get_yBIO23 () const;
    float get_yBIO24 () const;
    float get_yBIO25 () const;
    float get_yBIO26 () const;
    float get_yBIO27 () const;

    // monthly vectors + overloads
    vector<int>     get_mCHILL  ()              const;
    int             get_mCHILL  (const int i)   const;
    vector<float>   get_mGDD0   ()              const;
    float           get_mGDD0   (const int i)   const;
    vector<float>   get_mGDD5   ()              const;
    float           get_mGDD5   (const int i)   const;
    vector<float>   get_mGDD10  ()              const;
    float           get_mGDD10  (const int i)   const;
    vector<float>   get_mRUN    ()              const;
    float           get_mRUN    (const int i)   const;
    vector<float>   get_mMI     ()              const;
    float           get_mMI     (const int i)   const;
    vector<float>   get_mAET    ()              const;
    float           get_mAET    (const int i)   const;
    vector<float>   get_mEET    ()              const;
    float           get_mEET    (const int i)   const;
    vector<float>   get_mPET    ()              const;
    float           get_mPET    (const int i)   const;
    vector<float>   get_mDET    ()              const;
    float           get_mDET    (const int i)   const;
    vector<float>   get_mPAR    ()              const;
    float           get_mPAR    (const int i)   const;
    vector<float>   get_mPPT    ()              const;
    float           get_mPPT    (const int i)   const;
    vector<float>   get_mFSUN   ()              const;
    float           get_mFSUN   (const int i)   const;
    vector<float>   get_mTEMP   ()              const;
    float           get_mTEMP   (const int i)   const;
    vector<float>   get_mTMIN   ()              const;
    float           get_mTMIN   (const int i)   const;
    vector<float>   get_mTMAX   ()              const;
    float           get_mTMAX   (const int i)   const;
    vector<float>   get_mRAD    ()              const;
    float           get_mRAD    (const int i)   const;
    vector<float>   get_mALPHA  ()              const;
    float           get_mALPHA  (const int i)   const;
    vector<float>   get_mBIO02  ()              const;
    float           get_mBIO02  (const int i)   const;
    vector<float>   get_mBIO03  ()              const;
    float           get_mBIO03  (const int i)   const;
    vector<float>   get_mBIO04  ()              const;
    float           get_mBIO04  (const int i)   const;
    vector<float>   get_mBIO15  ()              const;
    float           get_mBIO15  (const int i)   const;
    vector<float>   get_mBIO23  ()              const;
    float           get_mBIO23  (const int i)   const;
    // daily vectors + overloads
    vector<float>   get_dSMC    ()              const;
    float           get_dSMC    (const int i)   const;
    vector<float>   get_dRUN    ()              const;
    float           get_dRUN    (const int i)   const;
    vector<float>   get_dMI     ()              const;
    float           get_dMI     (const int i)   const;
    vector<float>   get_dAET    ()              const;
    float           get_dAET    (const int i)   const;
    vector<float>   get_dEET    ()              const;
    float           get_dEET    (const int i)   const;
    vector<float>   get_dPET    ()              const;
    float           get_dPET    (const int i)   const;
    vector<float>   get_dDET    ()              const;
    float           get_dDET    (const int i)   const;
    vector<float>   get_dPAR    ()              const;
    float           get_dPAR    (const int i)   const;
    vector<float>   get_dPPT    ()              const;
    float           get_dPPT    (const int i)   const;
    vector<float>   get_dFSUN   ()              const;
    float           get_dFSUN   (const int i)   const;
    vector<float>   get_dTEMP   ()              const;
    float           get_dTEMP   (const int i)   const;
    vector<float>   get_dTMIN   ()              const;
    float           get_dTMIN   (const int i)   const;
    vector<float>   get_dTMAX   ()              const;
    float           get_dTMAX   (const int i)   const;
    vector<float>   get_dRAD    ()              const;
    float           get_dRAD    (const int i)   const;
    vector<float>   get_dALPHA  ()              const;
    float           get_dALPHA  (const int i)   const;

    // FUNCTIONS
    void linearINT( GridCell &gc, const vector<float> mly12, void (GridCell::*fset)(const float, const int) );
    void growDegDay();
    void monthlySums();
    void annualSums();
    void monthlyIndex();
    float calcGDD( const float gtemp, const int gdays );

    // FUNCTIONS ANUCLIMATE
    void calc_tc ();
    void calc_dpr ( GridCell &gc );
    void annual_Variables ();
    float max_element (vector <float> A);
    float min_element (vector <float> A);
    void quarter_Variables ();
    void period_Variables ( GridCell &gc );
    void seasonal_Variables ();
    void mean_Diurnal_Range ( GridCell &gc );
    void isothermality ();

    // DESTRUCTOR
    ~GridCell(){};
};
#endif
