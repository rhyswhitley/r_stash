#include "gridcell.hh"

// INITIALISERS - set size and fill with 0s
void GridCell::resIn_Year() {
    yaet    = 0.0; yeet    = 0.0;
    ypet    = 0.0; ydet    = 0.0;
    ypar    = 0.0; ymi     = 0.0;
    yalpha  = 0.0; ytc     = 0.0;
    ypr     = 0.0; yfs     = 0.0;
    ytn     = 0.0; ytx     = 0.0;
    yrd     = 0.0;
    yro     = 0.0; ychill  = 0.0;
    ygdd0   = 0.0; ygdd5   = 0.0;
    ygdd10  = 0.0; ybio01  = 0.0;
    ybio02  = 0.0; ybio03  = 0.0;
    ybio04  = 0.0;
    ybio05  = 0.0; ybio06  = 0.0;
    ybio07  = 0.0; ybio08  = 0.0;
    ybio09  = 0.0; ybio10  = 0.0;
    ybio11  = 0.0; ybio12  = 0.0;
    ybio13  = 0.0; ybio14  = 0.0;
    ybio15  = 0.0;
    ybio16  = 0.0; ybio17  = 0.0;
    ybio18  = 0.0; ybio19  = 0.0;
    ybio20  = 0.0; ybio21  = 0.0;
    ybio22  = 0.0; ybio23  = 0.0;
    ybio24  = 0.0;
    ybio25  = 0.0; ybio26  = 0.0;
    ybio27  = 0.0;
}
void GridCell::init_Month() {
    mmi     .resize(mlen,0);
    mro     .resize(mlen,0);
    mtc     .resize(mlen,0);
    mfs     .resize(mlen,0);
    mpr     .resize(mlen,0);
    mtn     .resize(mlen,0);
    mtx     .resize(mlen,0);
    mrd     .resize(mlen,0);
    maet    .resize(mlen,0);
    meet    .resize(mlen,0);
    mpet    .resize(mlen,0);
    mdet    .resize(mlen,0);
    mpar    .resize(mlen,0);
    gday0   .resize(mlen,0);
    gday5   .resize(mlen,0);
    gday10  .resize(mlen,0);
    gdd0    .resize(mlen,0);
    gdd5    .resize(mlen,0);
    gdd10   .resize(mlen,0);
    mgdd0   .resize(mlen,0);
    mgdd5   .resize(mlen,0);
    mgdd10  .resize(mlen,0);
    malpha  .resize(mlen,0);
    mchill  .resize(mlen,0);
    mbio02  .resize(mlen,0);
    mbio03  .resize(mlen,0);
    mbio04  .resize(mlen,0);
    mbio15  .resize(mlen,0);
    mbio23  .resize(mlen,0);
}
void GridCell::init_Day() {
    dsm     .resize(dlen,0);
    dro     .resize(dlen,0);
    dtc     .resize(dlen,0);
    dfs     .resize(dlen,0);
    dpr     .resize(dlen,0);
    dtn     .resize(dlen,0);
    dtx     .resize(dlen,0);
    drd     .resize(dlen,0);
    dmi     .resize(dlen,0);
    daet    .resize(dlen,0);
    deet    .resize(dlen,0);
    dpet    .resize(dlen,0);
    ddet    .resize(dlen,0);
    dpar    .resize(dlen,0);
    dalpha  .resize(dlen,0);
}
void GridCell::init_SMC(const float val) {
    dsm[0] = val;
}
void GridCell::reset_Month() {
    fill( mmi   .begin(), mmi   .end(), 0);
    fill( mro   .begin(), mro   .end(), 0);
    fill( mtc   .begin(), mtc   .end(), 0);
    fill( mfs   .begin(), mfs   .end(), 0);
    fill( mpr   .begin(), mpr   .end(), 0);
    fill( maet  .begin(), maet  .end(), 0);
    fill( meet  .begin(), meet  .end(), 0);
    fill( mpet  .begin(), mpet  .end(), 0);
    fill( mdet  .begin(), mdet  .end(), 0);
    fill( mpar  .begin(), mpar  .end(), 0);
    fill( gday0 .begin(), gday0 .end(), 0);
    fill( gday5 .begin(), gday5 .end(), 0);
    fill( gday10.begin(), gday10.end(), 0);
    fill( gdd0  .begin(), gdd0  .end(), 0);
    fill( gdd5  .begin(), gdd5  .end(), 0);
    fill( gdd10 .begin(), gdd10 .end(), 0);
    fill( mgdd0 .begin(), mgdd0 .end(), 0);
    fill( mgdd5 .begin(), mgdd5 .end(), 0);
    fill( mgdd10.begin(), mgdd10.end(), 0);
    fill( malpha.begin(), malpha.end(), 0);
    fill( mchill.begin(), mchill.end(), 0);
    fill( mbio02.begin(), mbio02.end(), 0);
    fill( mbio03.begin(), mbio03.end(), 0);
    fill( mbio04.begin(), mbio04.end(), 0);
    fill( mbio15.begin(), mbio15.end(), 0);
    fill( mbio23.begin(), mbio23.end(), 0);
}
void GridCell::reset_Day() {
    fill( dsm   .begin(), dsm   .end(), 0);
    fill( dmi   .begin(), dmi   .end(), 0);
    fill( dro   .begin(), dro   .end(), 0);
    fill( dtc   .begin(), dtc   .end(), 0);
    fill( dfs   .begin(), dfs   .end(), 0);
    fill( dpr   .begin(), dpr   .end(), 0);
    fill( daet  .begin(), daet  .end(), 0);
    fill( deet  .begin(), deet  .end(), 0);
    fill( dpet  .begin(), dpet  .end(), 0);
    fill( ddet  .begin(), ddet  .end(), 0);
    fill( dpar  .begin(), dpar  .end(), 0);
    fill( dalpha.begin(), dalpha.end(), 0);
}

// SETTERS
void GridCell::set_WBflag ()                { wbss = false; }
void GridCell::set_SpinUp( const bool val) { spinup = val; }
void GridCell::set_Cell ( const int n )     { cell = n; }
void GridCell::set_Elev ( const float val ) { elev = val; }
void GridCell::set_Fcap ( const float val ) { fcap = val; }
void GridCell::set_Coord( const float rlat,
                          const float rlon ){ lat = rlat;
                                              lon = rlon; }
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
void GridCell::set_yTMIN   ( const float val ) { ytn   = val; }
void GridCell::set_yTMAX   ( const float val ) { ytx   = val; }
void GridCell::set_yRAD    ( const float val ) { yrd   = val; }
void GridCell::set_yALPHA  ( const float val ) { yalpha = val; }
void GridCell::set_yBIO01  ( const float val ) { ybio01 = val; }
void GridCell::set_yBIO02  ( const float val ) { ybio02 = val; }
void GridCell::set_yBIO03  ( const float val ) { ybio03 = val; }
void GridCell::set_yBIO04  ( const float val ) { ybio04 = val; }
void GridCell::set_yBIO05  ( const float val ) { ybio05 = val; }
void GridCell::set_yBIO06  ( const float val ) { ybio06 = val; }
void GridCell::set_yBIO07  ( const float val ) { ybio07 = val; }
void GridCell::set_yBIO08  ( const float val ) { ybio08 = val; }
void GridCell::set_yBIO09  ( const float val ) { ybio09 = val; }
void GridCell::set_yBIO10  ( const float val ) { ybio10 = val; }
void GridCell::set_yBIO11  ( const float val ) { ybio11 = val; }
void GridCell::set_yBIO12  ( const float val ) { ybio12 = val; }
void GridCell::set_yBIO13  ( const float val ) { ybio13 = val; }
void GridCell::set_yBIO14  ( const float val ) { ybio14 = val; }
void GridCell::set_yBIO15  ( const float val ) { ybio15 = val; }
void GridCell::set_yBIO16  ( const float val ) { ybio16 = val; }
void GridCell::set_yBIO17  ( const float val ) { ybio17 = val; }
void GridCell::set_yBIO18  ( const float val ) { ybio18 = val; }
void GridCell::set_yBIO19  ( const float val ) { ybio19 = val; }
void GridCell::set_yBIO20  ( const float val ) { ybio20 = val; }
void GridCell::set_yBIO21  ( const float val ) { ybio21 = val; }
void GridCell::set_yBIO22  ( const float val ) { ybio22 = val; }
void GridCell::set_yBIO23  ( const float val ) { ybio23 = val; }
void GridCell::set_yBIO24  ( const float val ) { ybio24 = val; }
void GridCell::set_yBIO25  ( const float val ) { ybio25 = val; }
void GridCell::set_yBIO26  ( const float val ) { ybio26 = val; }
void GridCell::set_yBIO27  ( const float val ) { ybio27 = val; }
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
void GridCell::set_mTMIN   ( const float val, const int i ) {  mtn  [i] = val; }
void GridCell::set_mTMAX   ( const float val, const int i ) {  mtx  [i] = val; }
void GridCell::set_mRAD    ( const float val, const int i ) {  mrd  [i] = val; }
void GridCell::set_mALPHA  ( const float val, const int i ) {  malpha[i] = val; }
void GridCell::set_mBIO02  ( const float val, const int i ) {  mbio02[i] = val; }
void GridCell::set_mBIO03  ( const float val, const int i ) {  mbio03[i] = val; }
void GridCell::set_mBIO04  ( const float val, const int i ) {  mbio04[i] = val; }
void GridCell::set_mBIO15  ( const float val, const int i ) {  mbio15[i] = val; }
void GridCell::set_mBIO23  ( const float val, const int i ) {  mbio23[i] = val; }
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
void GridCell::set_dTMIN   ( const float val, const int i ) {  dtn  [i] = val; }
void GridCell::set_dTMAX   ( const float val, const int i ) {  dtx  [i] = val; }
void GridCell::set_dRAD    ( const float val, const int i ) {  drd  [i] = val; }
void GridCell::set_dALPHA  ( const float val, const int i ) {  dalpha[i] = val; }

// GETTERS
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
float GridCell::get_yTMIN   () const { return ytn; }
float GridCell::get_yTMAX   () const { return ytx; }
float GridCell::get_yRAD    () const { return yrd; }
float GridCell::get_yALPHA  () const { return yalpha; }
float GridCell::get_yBIO01  () const { return ybio01; }
float GridCell::get_yBIO02  () const { return ybio02; }
float GridCell::get_yBIO03  () const { return ybio03; }
float GridCell::get_yBIO04  () const { return ybio04; }
float GridCell::get_yBIO05  () const { return ybio05; }
float GridCell::get_yBIO06  () const { return ybio06; }
float GridCell::get_yBIO07  () const { return ybio07; }
float GridCell::get_yBIO08  () const { return ybio08; }
float GridCell::get_yBIO09  () const { return ybio09; }
float GridCell::get_yBIO10  () const { return ybio10; }
float GridCell::get_yBIO11  () const { return ybio11; }
float GridCell::get_yBIO12  () const { return ybio12; }
float GridCell::get_yBIO13  () const { return ybio13; }
float GridCell::get_yBIO14  () const { return ybio14; }
float GridCell::get_yBIO15  () const { return ybio15; }
float GridCell::get_yBIO16  () const { return ybio16; }
float GridCell::get_yBIO17  () const { return ybio17; }
float GridCell::get_yBIO18  () const { return ybio18; }
float GridCell::get_yBIO19  () const { return ybio19; }
float GridCell::get_yBIO20  () const { return ybio20; }
float GridCell::get_yBIO21  () const { return ybio21; }
float GridCell::get_yBIO22  () const { return ybio22; }
float GridCell::get_yBIO23  () const { return ybio23; }
float GridCell::get_yBIO24  () const { return ybio24; }
float GridCell::get_yBIO25  () const { return ybio25; }
float GridCell::get_yBIO26  () const { return ybio26; }
float GridCell::get_yBIO27  () const { return ybio27; }
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
vector<float>   GridCell::get_mTMIN   ()            const { return mtn; }
float           GridCell::get_mTMIN   (const int i) const { return mtn[i]; }
vector<float>   GridCell::get_mTMAX   ()            const { return mtx; }
float           GridCell::get_mTMAX   (const int i) const { return mtx[i]; }
vector<float>   GridCell::get_mRAD    ()            const { return mrd; }
float           GridCell::get_mRAD    (const int i) const { return mrd[i]; }
vector<float>   GridCell::get_mALPHA  ()            const { return malpha; }
float           GridCell::get_mALPHA  (const int i) const { return malpha[i]; }
vector<float>   GridCell::get_mBIO02  ()            const { return mbio02; }
float           GridCell::get_mBIO02  (const int i) const { return mbio02[i]; }
vector<float>   GridCell::get_mBIO03  ()            const { return mbio03; }
float           GridCell::get_mBIO03  (const int i) const { return mbio03[i]; }
vector<float>   GridCell::get_mBIO04  ()            const { return mbio04; }
float           GridCell::get_mBIO04  (const int i) const { return mbio04[i]; }
vector<float>   GridCell::get_mBIO15  ()            const { return mbio15; }
float           GridCell::get_mBIO15  (const int i) const { return mbio15[i]; }
vector<float>   GridCell::get_mBIO23  ()            const { return mbio23; }
float           GridCell::get_mBIO23  (const int i) const { return mbio23[i]; }
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
vector<float>   GridCell::get_dTMIN   ()            const { return dtn; }
float           GridCell::get_dTMIN   (const int i) const { return dtn[i]; }
vector<float>   GridCell::get_dTMAX   ()            const { return dtx; }
float           GridCell::get_dTMAX   (const int i) const { return dtx[i]; }
vector<float>   GridCell::get_dRAD    ()            const { return drd; }
float           GridCell::get_dRAD    (const int i) const { return drd[i]; }
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

///////////////////////////////////////////////////////////////////////////////////
///// XU & HUTCHINSON INDICES FUNCTIONS ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Calculate tc with tmin and tmax
void GridCell::calc_tc() {
    for (int i=0; i<mlen; i++){
        mtc[i] = (mtn[i] + mtx[i])/2 ;
    }
}

void GridCell::calc_dpr( GridCell &gc ) {
    int dn=0, i, j;
    float ppt;
    const int   mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for( dn=0, i=0; i<gc.get_MLEN(); i++ ) {
        for( j=0; j<mdays[i]; j++, dn++ ) {
            // rainfall needs to be a fraction of the monthly total (should fix this initially)
            ppt = gc.get_dPPT(dn)/mdays[i];
            gc.set_dPPT(ppt, dn);
        }
    }
}

// Annual mean/sum (1 & 12 & 20)
void GridCell::annual_Variables () {
    ybio01  = accumulate( mtc   .begin(),   mtc     .end(), 0.0 ) / mlen;
    ybio12  = accumulate( mpr   .begin(),   mpr     .end(), 0.0 );
    ybio20  = accumulate( mrd   .begin(),   mrd     .end(), 0.0 ) / mlen;
}

float GridCell::max_element (vector <float> A){
    float n = A[0];
    for (unsigned int i=1; i<A.size(); i++){
        if (A[i]>n) {n=A[i];}
    }
    return n;
}

float GridCell::min_element (vector <float> A){
    float n = A[0];
    for (unsigned int i=1; i<A.size(); i++){
        if (A[i]<n) {n=A[i];}
    }
    return n;
}

// Quarterly variables (8,9,10,11 & 16,17,18,19 & 24,25,26,27)
void GridCell::quarter_Variables () {

    // vector of  monthly pr/tc/fs (include Nov Dec before and Jan Feb after)
    vector <float> mpr16(16), mtc16(16), mrd16(16);
    mpr16[0] = mpr[10]; mpr16[1] = mpr[11]; mpr16[14] = mpr[0]; mpr16[15] = mpr[1];
    mtc16[0] = mtc[10]; mtc16[1] = mtc[11]; mtc16[14] = mtc[0]; mtc16[15] = mtc[1];
    mrd16[0] = mrd[10]; mrd16[1] = mrd[11]; mrd16[14] = mrd[0]; mrd16[15] = mrd[1];
    for( unsigned int i=0; i<mpr.size(); i++ ) {
        mpr16[i+2] = mpr[i];
        mtc16[i+2] = mtc[i];
        mrd16[i+2] = mrd[i];
    }

    vector <float> qtrPr(14); // sum of precipitation for all possible quarters of the year
    vector <float> qtrTc(14); // mean temperature for all possible quarters of the year
    vector <float> qtrRd(14); // mean radiation for all possible quarters of the year
    for ( unsigned int i=0; i<qtrPr.size(); i++ ) {
        qtrPr[i]=mpr16[i]+mpr16[i+1]+mpr16[i+2];
        qtrTc[i]=(mtc16[i]+mtc16[i+1]+mtc16[i+2])/3;
        qtrRd[i]=(mrd16[i]+mrd16[i+1]+mrd16[i+2])/3;
    }

    // max and min value of qtrPr and qtrT
    float maxPr = max_element(qtrPr);
    float minPr = min_element(qtrPr);
    float maxTc = max_element(qtrTc);
    float minTc = min_element(qtrTc);

    // first month of the wettest/driest/warmest/coldest quarter
    int wet=0; while (maxPr!=qtrPr[wet]){wet++;}
    int dry=0; while (minPr!=qtrPr[dry]){dry++;}
    int warm=0; while (maxTc!=qtrTc[warm]){warm++;}
    int cold=0; while (minTc!=qtrTc[cold]){cold++;}

    // Temperature variables
    ybio08 = qtrTc[wet]; // BIO08 Mean Temperature of Wettest Quarter
    ybio09 = qtrTc[dry]; // BIO09 Mean Temperature of Driest Quarter
    ybio10 = qtrTc[warm]; // BIO10 Mean Temperature of Warmest Quarter
    ybio11 = qtrTc[cold]; // BIO11 Mean Temperature of Coldest Quarter

    // Precipitation variables
    ybio16 = qtrPr[wet]; // BIO16 Precipitation of Wettest Quarter
    ybio17 = qtrPr[dry]; // BIO17 Precipitation of Driest Quarter
    ybio18 = qtrPr[warm]; // BIO18 Precipitation of Warmest Quarter
    ybio19 = qtrPr[cold]; // BIO19 Precipitation of Coldest Quarter

    // Radiation variables
    ybio24 = qtrRd[wet] ;// BIO24 Radiation of Wettest Quarter
    ybio25 = qtrRd[dry] ;// BIO25 Radiation of Driest Quarter
    ybio26 = qtrRd[warm] ;// BIO26 Radiation of Warmest Quarter
    ybio27 = qtrRd[cold] ;// BIO27 Radiation of Coldest Quarter
}

// Period variables (5,6,7 & 13,14 & 21,22)
void GridCell::period_Variables ( GridCell &gc) {
    // max and min value of mpr and mtc
    float max_mpr = max_element(mpr);
    float min_mpr = min_element(mpr);
    float max_mtc = max_element(mtc);
    float min_mtc = min_element(mtc);
    float max_mrd = max_element(mrd);
    float min_mrd = min_element(mrd);

    // month of the wettest/driest/warmest/coldest/high and low rad period
    int wet=0;  while (max_mpr!=mpr[wet]) {wet++;}
    int dry=0;  while (min_mpr!=mpr[dry]) {dry++;}
    int warm=0; while (max_mtc!=mtc[warm]){warm++;}
    int cold=0; while (min_mtc!=mtc[cold]){cold++;}
    int high=0; while (max_mrd!=mrd[high]){high++;}
    int low=0;  while (min_mrd!=mrd[low]) {low++;}

    // Temperature variables
    ybio05 = gc.get_mTMAX(warm) ;// BIO05 Maximum Temperature of Warmest Period
    ybio06 = gc.get_mTMIN(cold) ;// BIO06 Minimum Temperature of Coldest Period

    ybio07 = ybio05 - ybio06 ; // BIO07 Temperature Annual Range (BIO05 - BIO06)

    // Precipitation variables
    ybio13 = mpr[wet] ;// BIO13 Precipitation of Wettest Period
    ybio14 = mpr[dry] ;// BIO14 Precipitation of Driest Period

    // Radiation variables
    ybio21 = mrd[high] ;// BIO21 Highest Period Radiation
    ybio22 = mrd[low] ;// BIO22 Lowest Period Radiation
}

// Seasonality variables (standard deviation * 100) (4,15,23)
void GridCell::seasonal_Variables () {
    const int   mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dn=0;
    for (int i=0; i<mlen; i++){
        float temp=0, prec=0, rad=0, pmean1=(mpr[i]+mdays[i])/mdays[i];
        for (int j=0; j<mdays[i]; j++){
            temp += (mtc[i] - dtc[dn])*(mtc[i] - dtc[dn]);
            prec += (pmean1 - dpr[dn])*(pmean1 - dpr[dn]);
            rad  += (mrd[i] - drd[dn])*(mrd[i] - drd[dn]);
            dn++;
        }
        mbio04[i] = sqrt(temp/(mdays[i]-1))*100 ;// BIO04 Temperature Seasonality
        mbio15[i] = (sqrt(prec/(mdays[i]-1))/pmean1)*100 ;// BIO15 Precipitation Seasonality
        mbio23[i] = sqrt(rad/(mdays[i]-1))*100 ;// BIO23 Radiation Seasonality
    }

    float temp2=0, prec2=0, rad2=0, pmean=(ybio12+mlen)/mlen;
    for (int k=0; k<mlen; k++) {
        temp2 += (ybio01 - mtc[k])*(ybio01 - mtc[k]);
        prec2 += (pmean - (mpr[k]+1))*(pmean - (mpr[k]+1));
        rad2  += (ybio20 - mrd[k])*(ybio20 - mrd[k]);
    }
    ybio04 = sqrt(temp2/(mlen-1))*100 ;// BIO04 Temperature Seasonality
    ybio15 = (sqrt(prec2/(mlen-1))/pmean)*100 ;// BIO15 Precipitation Seasonality
    ybio23 = sqrt(rad2/(mlen-1))*100 ;// BIO23 Radiation Seasonality
}

// Mean diurnal Range (2)
void GridCell::mean_Diurnal_Range( GridCell &gc ) {
    float tmin, tmax, b2=0;
    for (int i=0; i<mlen; i++) {
        // getting
        tmin    = gc.get_mTMIN(i);
        tmax    = gc.get_mTMAX(i);
        // calculations
        mbio02[i] = tmax-tmin;
        b2 = b2 +mbio02[i];
    }
    ybio02 = b2 / mlen;
}

// Isothermality ((bio02/bio07)*100) (3)
void GridCell::isothermality (){
    for ( unsigned int i=0; i<mbio03.size();i++ ) {
        mbio03[i] = (mbio02[i]/ybio07)*100;
    }
    ybio03 = (ybio02/ybio07)*100;
}

