#include "gridcell.hh"

// INITIALISERS - set size and fill with 0s
void GridCell::resIn_Year(const float val) {
    yaet    = val; yeet    = val;
    ypet    = val; ydet    = val;
    ypar    = val; ymi     = val;
    yalpha  = val; ytc     = val;
    ypr     = val; yfs     = val;
    yro     = val; ychill  = val;
    ygdd0   = val; ygdd5   = val;
    ygdd10  = val;
}
void GridCell::init_Month(const float val) {
    mmi     .resize(mlen, val);
    mro     .resize(mlen, val);
    mtc     .resize(mlen, val);
    mfs     .resize(mlen, val);
    mpr     .resize(mlen, val);
    maet    .resize(mlen, val);
    meet    .resize(mlen, val);
    mpet    .resize(mlen, val);
    mdet    .resize(mlen, val);
    mpar    .resize(mlen, val);
    gday0   .resize(mlen, val);
    gday5   .resize(mlen, val);
    gday10  .resize(mlen, val);
    gdd0    .resize(mlen, val);
    gdd5    .resize(mlen, val);
    gdd10   .resize(mlen, val);
    mgdd0   .resize(mlen, val);
    mgdd5   .resize(mlen, val);
    mgdd10  .resize(mlen, val);
    malpha  .resize(mlen, val);
    mchill  .resize(mlen, val);
}
void GridCell::init_Day(const float val) {
    dsm     .resize(dlen, val);
    dro     .resize(dlen, val);
    dtc     .resize(dlen, val);
    dfs     .resize(dlen, val);
    dpr     .resize(dlen, val);
    dmi     .resize(dlen, val);
    daet    .resize(dlen, val);
    deet    .resize(dlen, val);
    dpet    .resize(dlen, val);
    ddet    .resize(dlen, val);
    dpar    .resize(dlen, val);
    dalpha  .resize(dlen, val);
}
void GridCell::init_SMC(const float val) {
    dsm[0] = val;
}
void GridCell::reset_Month(const float val) {
    fill( mmi   .begin(), mmi   .end(), val);
    fill( mro   .begin(), mro   .end(), val);
    fill( mtc   .begin(), mtc   .end(), val);
    fill( mfs   .begin(), mfs   .end(), val);
    fill( mpr   .begin(), mpr   .end(), val);
    fill( maet  .begin(), maet  .end(), val);
    fill( meet  .begin(), meet  .end(), val);
    fill( mpet  .begin(), mpet  .end(), val);
    fill( mdet  .begin(), mdet  .end(), val);
    fill( mpar  .begin(), mpar  .end(), val);
    fill( gday0 .begin(), gday0 .end(), val);
    fill( gday5 .begin(), gday5 .end(), val);
    fill( gday10.begin(), gday10.end(), val);
    fill( gdd0  .begin(), gdd0  .end(), val);
    fill( gdd5  .begin(), gdd5  .end(), val);
    fill( gdd10 .begin(), gdd10 .end(), val);
    fill( mgdd0 .begin(), mgdd0 .end(), val);
    fill( mgdd5 .begin(), mgdd5 .end(), val);
    fill( mgdd10.begin(), mgdd10.end(), val);
    fill( malpha.begin(), malpha.end(), val);
    fill( mchill.begin(), mchill.end(), val);
}
void GridCell::reset_Day(const float val) {
    fill( dsm   .begin(), dsm   .end(), val);
    fill( dmi   .begin(), dmi   .end(), val);
    fill( dro   .begin(), dro   .end(), val);
    fill( dtc   .begin(), dtc   .end(), val);
    fill( dfs   .begin(), dfs   .end(), val);
    fill( dpr   .begin(), dpr   .end(), val);
    fill( daet  .begin(), daet  .end(), val);
    fill( deet  .begin(), deet  .end(), val);
    fill( dpet  .begin(), dpet  .end(), val);
    fill( ddet  .begin(), ddet  .end(), val);
    fill( dpar  .begin(), dpar  .end(), val);
    fill( dalpha.begin(), dalpha.end(), val);
}

// SETTERS
void GridCell::set_WBflag()                { wbss = false; }
void GridCell::set_SpinUp( const bool val) { spinup = val; }
void GridCell::set_Cell ( const int n )     { cell = n; }
void GridCell::set_Elev ( const float val ) { elev = val; }
void GridCell::set_Fcap ( const float val ) { fcap = val; }
void GridCell::set_Coord( const float rlat,
                          const float rlon ){ lat = rlat;
                                              lon = rlon; }

// initialise all values to the missing value
void GridCell::set_MissingCell() {
    GridCell::reset_Day(miss_val);
    GridCell::reset_Month(miss_val);
    GridCell::resIn_Year(miss_val);
}
// yearly
void GridCell::set_yGDD0   ( const int val )   { ygdd0  = val; }
void GridCell::set_yGDD5   ( const int val )   { ygdd5  = val; }
void GridCell::set_yGDD10  ( const int val )   { ygdd10 = val; }
void GridCell::set_yMI     ( const float val ) { ymi   = val; }
void GridCell::set_yRUN    ( const float val ) { yro   = val; }
void GridCell::set_yAET    ( const float val ) { yaet  = val; }
void GridCell::set_yEET    ( const float val ) { yeet  = val; }
void GridCell::set_yPET    ( const float val ) { ypet  = val; }
void GridCell::set_yPAR    ( const float val ) { ypar  = val; }
void GridCell::set_yDET    ( const float val ) { ydet  = val; }
void GridCell::set_yPPT    ( const float val ) { ypr   = val; }
void GridCell::set_yFSUN   ( const float val ) { yfs   = val; }
void GridCell::set_yTEMP   ( const float val ) { ytc   = val; }
void GridCell::set_yALPHA  ( const float val ) { yalpha = val; }
// monthly
void GridCell::set_CHILL   ( const int i ) { mchill[i]++; }
void GridCell::set_GDEG0   ( const float val, const int i ) {  gday0 [i]++; gdd0 [i] += val-0.0;  }
void GridCell::set_GDEG5   ( const float val, const int i ) {  gday5 [i]++; gdd5 [i] += val-5.0;  }
void GridCell::set_GDEG10  ( const float val, const int i ) {  gday10[i]++; gdd10[i] += val-10.0; }
void GridCell::set_mMI     ( const float val, const int i ) {  mmi  [i] = val; }
void GridCell::set_mRUN    ( const float val, const int i ) {  mro  [i] = val; }
void GridCell::set_mAET    ( const float val, const int i ) {  maet [i] = val; }
void GridCell::set_mEET    ( const float val, const int i ) {  meet [i] = val; }
void GridCell::set_mPET    ( const float val, const int i ) {  mpet [i] = val; }
void GridCell::set_mPAR    ( const float val, const int i ) {  mpar [i] = val; }
void GridCell::set_mDET    ( const float val, const int i ) {  mdet [i] = val; }
void GridCell::set_mPPT    ( const float val, const int i ) {  mpr  [i] = val; }
void GridCell::set_mFSUN   ( const float val, const int i ) {  mfs  [i] = val; }
void GridCell::set_mTEMP   ( const float val, const int i ) {  mtc  [i] = val; }
void GridCell::set_mALPHA  ( const float val, const int i ) {  malpha[i] = val; }
// daily
void GridCell::set_dRUN    ( const float val, const int i ) {  dro  [i] = val; }
void GridCell::set_dSMC    ( const float val, const int i ) {  dsm  [i] = val; }
void GridCell::set_dMI     ( const float val, const int i ) {  dmi  [i] = val; }
void GridCell::set_dAET    ( const float val, const int i ) {  daet [i] = val; }
void GridCell::set_dEET    ( const float val, const int i ) {  deet [i] = val; }
void GridCell::set_dPET    ( const float val, const int i ) {  dpet [i] = val; }
void GridCell::set_dPAR    ( const float val, const int i ) {  dpar [i] = val; }
void GridCell::set_dDET    ( const float val, const int i ) {  ddet [i] = val; }
void GridCell::set_dPPT    ( const float val, const int i ) {  dpr  [i] = val; }
void GridCell::set_dFSUN   ( const float val, const int i ) {  dfs  [i] = val; }
void GridCell::set_dTEMP   ( const float val, const int i ) {  dtc  [i] = val; }
void GridCell::set_dALPHA  ( const float val, const int i ) {  dalpha[i] = val; }

// GETTERS
float GridCell::get_Missing () const { return miss_val; }
float GridCell::get_Cell    () const { return cell; }
float GridCell::get_Lat     () const { return lat; }
float GridCell::get_Lon     () const { return lon; }
float GridCell::get_Fcap    () const { return fcap; }
float GridCell::get_Elev    () const { return elev; }
float GridCell::get_MLEN    () const { return mlen; }
float GridCell::get_DLEN    () const { return dlen; }
bool  GridCell::get_SpinUp  () const { return spinup; }
// yearly
int GridCell::get_yCHILL    () const { return ychill; }
float GridCell::get_yGDD0   () const { return ygdd0; }
float GridCell::get_yGDD5   () const { return ygdd5; }
float GridCell::get_yGDD10  () const { return ygdd10; }
float GridCell::get_yMI     () const { return ymi; }
float GridCell::get_yRUN    () const { return yro; }
float GridCell::get_yAET    () const { return yaet; }
float GridCell::get_yEET    () const { return yeet; }
float GridCell::get_yPET    () const { return ypet; }
float GridCell::get_yPAR    () const { return ypar; }
float GridCell::get_yDET    () const { return ydet; }
float GridCell::get_yPPT    () const { return ypr; }
float GridCell::get_yFSUN   () const { return yfs; }
float GridCell::get_yTEMP   () const { return ytc; }
float GridCell::get_yALPHA  () const { return yalpha; }
// monthly + overloads
vector<int>     GridCell::get_mCHILL  ()            const { return mchill; }
int             GridCell::get_mCHILL  (const int i) const { return mchill[i]; }
vector<float>   GridCell::get_mGDD0   ()            const { return mgdd0; }
float           GridCell::get_mGDD0   (const int i) const { return mgdd0[i]; }
vector<float>   GridCell::get_mGDD5   ()            const { return mgdd5; }
float           GridCell::get_mGDD5   (const int i) const { return mgdd5[i]; }
vector<float>   GridCell::get_mGDD10  ()            const { return mgdd10; }
float           GridCell::get_mGDD10  (const int i) const { return mgdd10[i]; }
vector<float>   GridCell::get_mRUN    ()            const { return mro; }
float           GridCell::get_mRUN    (const int i) const { return mro[i]; }
vector<float>   GridCell::get_mMI     ()            const { return mmi; }
float           GridCell::get_mMI     (const int i) const { return mmi[i]; }
vector<float>   GridCell::get_mAET    ()            const { return maet; }
float           GridCell::get_mAET    (const int i) const { return maet[i]; }
vector<float>   GridCell::get_mEET    ()            const { return meet; }
float           GridCell::get_mEET    (const int i) const { return meet[i]; }
vector<float>   GridCell::get_mPET    ()            const { return mpet; }
float           GridCell::get_mPET    (const int i) const { return mpet[i]; }
vector<float>   GridCell::get_mDET    ()            const { return mdet; }
float           GridCell::get_mDET    (const int i) const { return mdet[i]; }
vector<float>   GridCell::get_mPAR    ()            const { return mpar; }
float           GridCell::get_mPAR    (const int i) const { return mpar[i]; }
vector<float>   GridCell::get_mPPT    ()            const { return mpr; }
float           GridCell::get_mPPT    (const int i) const { return mpr[i]; }
vector<float>   GridCell::get_mFSUN   ()            const { return mfs; }
float           GridCell::get_mFSUN   (const int i) const { return mfs[i]; }
vector<float>   GridCell::get_mTEMP   ()            const { return mtc; }
float           GridCell::get_mTEMP   (const int i) const { return mtc[i]; }
vector<float>   GridCell::get_mALPHA  ()            const { return malpha; }
float           GridCell::get_mALPHA  (const int i) const { return malpha[i]; }
// daily + overloads
vector<float>   GridCell::get_dRUN    ()            const { return dro; }
float           GridCell::get_dRUN    (const int i) const { return dro[i]; }
vector<float>   GridCell::get_dSMC    ()            const { return dsm; }
float           GridCell::get_dSMC    (const int i) const { return dsm[i]; }
vector<float>   GridCell::get_dMI     ()            const { return dmi; }
float           GridCell::get_dMI     (const int i) const { return dmi[i]; }
vector<float>   GridCell::get_dAET    ()            const { return daet; }
float           GridCell::get_dAET    (const int i) const { return daet[i]; }
vector<float>   GridCell::get_dEET    ()            const { return deet; }
float           GridCell::get_dEET    (const int i) const { return deet[i]; }
vector<float>   GridCell::get_dPET    ()            const { return dpet; }
float           GridCell::get_dPET    (const int i) const { return dpet[i]; }
vector<float>   GridCell::get_dDET    ()            const { return ddet; }
float           GridCell::get_dDET    (const int i) const { return ddet[i]; }
vector<float>   GridCell::get_dPAR    ()            const { return dpar; }
float           GridCell::get_dPAR    (const int i) const { return dpar[i]; }
vector<float>   GridCell::get_dPPT    ()            const { return dpr; }
float           GridCell::get_dPPT    (const int i) const { return dpr[i]; }
vector<float>   GridCell::get_dFSUN   ()            const { return dfs; }
float           GridCell::get_dFSUN   (const int i) const { return dfs[i]; }
vector<float>   GridCell::get_dTEMP   ()            const { return dtc; }
float           GridCell::get_dTEMP   (const int i) const { return dtc[i]; }
vector<float>   GridCell::get_dALPHA  ()            const { return dalpha; }
float           GridCell::get_dALPHA  (const int i) const { return dalpha[i]; }

// FUNCTIONS

// linear interpolation -- convert monthly to daily
void GridCell::linearINT( GridCell &gc, const vector<float> mly12, void (GridCell::*fset)(const float, const int) ) {
    // Vector of days in month (includes bookend months - Dec year before and Jan year after)
    const float m14days[] = {31,31,28,31,30,31,30,31,31,30,31,30,31,31};
    // Matrix of 12 month columns and N grid cell rows
    vector<float>   mly14;
    float           mbef, maft, inc, d15;
    int             i, j, dn, dbef, daft,
                    nm12 = mly12.size(),
                    nm14 = nm12+2;
    // must include months either side of a year
    mly14.resize(nm14);
    mly14[0]  = mly12[11];
    mly14[13] = mly12[1];
    for( i=0; i<nm12; i++ ) {
        mly14[i+1] = mly12[i];
    }
    // Perform a linear interpolation between monthly 'mid-point' values
    for( dn=0, i=1; i<(nm14-1); i++ ) {
        for( j=0; j<m14days[i]; j++, ++dn ) {
            // first half of month
            if( j<(m14days[i]/2) ) {
                mbef = mly14[i-1];
                maft = mly14[i];
                dbef = m14days[i-1];
                daft = m14days[i];
            // second half of month
            } else {
                mbef = mly14[i];
                maft = mly14[i+1];
                dbef = m14days[i];
                daft = m14days[i+1];
            }
            inc = (maft-mbef)/((dbef+daft)/2);
            if( inc!=0 ) {
                if( j<(m14days[i]/2) ) {
                    d15 = j+(dbef/2);
                } else {
                    d15 = j-(daft/2);
                }
                (gc.*fset)( mbef+(d15*inc), dn );
            } else {
                (gc.*fset)( mbef, dn );
            }
        }
    }
}
// end routine

// ifelse hack
float GridCell::calcGDD( const float gtemp, const int gdays ) {
    if( gdays>0 ) {
        return gtemp/(float)(gdays);
    } else {
        return 0.0;
    }
}

// growing degree days
void GridCell::growDegDay() {
    for( int i=0; i<mlen; i++ ) {
        mgdd0[i]    = calcGDD( gdd0[i], gday0[i] );
        mgdd5[i]    = calcGDD( gdd5[i], gday5[i] );
        mgdd10[i]   = calcGDD( gdd10[i], gday10[i] );
    }
}

// monthly sums of energy/water-use
void GridCell::monthlySums() {
    const int   mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int         dn = 0;
    for( int i=0; i<mlen; i++ ) {
        for( int j=0; j<mdays[i]; j++ ) {
            mpet[i] += dpet[dn];
            maet[i] += daet[dn];
            meet[i] += deet[dn];
            mdet[i] += ddet[dn];
            mpar[i] += dpar[dn];
            mro[i]  += dro[dn];
            dn++;
        }
    }
}

void GridCell::annualSums() {
    // sums
    yaet    = accumulate( maet  .begin(),   maet    .end(), 0.0 );
    yeet    = accumulate( meet  .begin(),   meet    .end(), 0.0 );
    ypet    = accumulate( mpet  .begin(),   mpet    .end(), 0.0 );
    ydet    = accumulate( mdet  .begin(),   mdet    .end(), 0.0 );
    ypar    = accumulate( mpar  .begin(),   mpar    .end(), 0.0 );
    yro     = accumulate( mro   .begin(),   mro     .end(), 0.0 );
    ypr     = accumulate( mpr   .begin(),   mpr     .end(), 0.0 );
    ychill  = accumulate( mchill.begin(),   mchill  .end(), 0.0 );
    ygdd0   = accumulate( mgdd0 .begin(),   mgdd0   .end(), 0.0 );
    ygdd5   = accumulate( mgdd5 .begin(),   mgdd5   .end(), 0.0 );
    ygdd10  = accumulate( mgdd10.begin(),   mgdd10  .end(), 0.0 );
    // means
    ytc     = accumulate( mtc   .begin(),   mtc     .end(), 0.0 ) / mlen;
    yfs     = accumulate( mfs   .begin(),   mfs     .end(), 0.0 ) / mlen;
    // indices
    ymi     = ypr/yeet;
    yalpha  = yaet/yeet;
}

// monthly indices of wet and dry
void GridCell::monthlyIndex() {
    for( int i=0; i<mlen; i++ ) {
        mmi[i]    = mpr[i]/meet[i];
        malpha[i] = maet[i]/meet[i];
    }
}

