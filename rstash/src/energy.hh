#ifndef _energy_RCPP_ENERGY_H
#define _energy_RCPP_ENERGY_H
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <Rcpp.h>
#include "gridcell.hh"

using namespace std;
using namespace Rcpp;

// numerical constants used in evaporation calculations
    static const float
                eccn    = 0.01675,
                d2r     = M_PI/180.0,
                cw      = 1.0,
                solc    = 1367.0,
                dtime   = 0.0036,
                nsecs   = 86400.0,
                albedo  = 0.17;
// single returns
    float cf_ARG    ( const int day     );
    float cf_SOLC   ( const int day     );
    float cf_DELT   ( const int day     );
    float cf_SLOPE  ( const float Tair  );
    float cf_TRA    ( const int day,    const float lat );
    float cf_RTA    ( const float msolc,const float hs, const float x,      const float y );
    float cf_HS     ( const float x,    const float y,  const float lat,    const float delta   );
    float cf_AET    ( const float par,   const float h1, const float spl,    const float u, const float v );
    float cf_EET    ( const float h0,   const float u,  const float v );
    float cf_PAR    ( const float rabs, const float hs, const float rsin,   const float rcos );
// multiple returns
    void cf_H01     ( const float u,    const float v,  const float spl,    float &h0,      float &h1 );
    void cf_XYproj  ( const float lat,  const float delta,float& x,           float& y);
    void cf_TABLE   ( const float temp, float &gamma,   float &lambda );
// main routines
    // point
    void evaporate  ( const float tair, const float fsun, const float lat, const float spl, const int day,
                            float& par, float& aet, float& eet, float& pet, float& det );
    // gridded
    void Gevap_wrap ( GridCell &gc,     const float spl,const int day );
    void waterBucket( GridCell &gc );
// inline functions
    inline float cf_ARG ( const int day )                                   { return 360.*day/365; }
    inline float cf_RABS( const float fsun )                                { return (0.25+0.5*fsun)*(1-albedo); }
    inline float cf_REFL( const float fsun,const float tair )               { return (0.2+0.8*fsun)*(107.-tair); }
    inline float cf_ECON( const float lam, const float gam, const float dS ){ return dtime/lam*dS/(dS+gam); }
// R connection functions
    RcppExport SEXP sunshine    ( const SEXP R_sun );
    RcppExport SEXP sunray      ( const SEXP R_swr, const SEXP R_mon, const SEXP R_lat );
    RcppExport SEXP pointStash  ( const SEXP R_tc, const SEXP R_pr, const SEXP R_fs, const SEXP R_mon, const SEXP R_lat, const SEXP R_fcap, const SEXP R_elev );

#endif
