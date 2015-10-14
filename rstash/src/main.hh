#ifndef _main_RCPP_MAIN_H
#define _main_RCPP_MAIN_H
#define _USE_MATH_DEFINES

#include <omp.h>
// [[Rcpp::plugins(openmp)]]
#include <iostream>
#include <vector>
#include <math.h>
#include <Rcpp.h>
#include "gridcell.hh"
#include "energy.hh"

using namespace std;
using namespace Rcpp;

static const unsigned int nvar = 15;    // the number of bioclimatic variables being returned

RcppExport SEXP gridStash       ( const SEXP R_gtc, const SEXP R_gpr, const SEXP R_gfs, const SEXP R_gcChar );
//NumericVector   RConvert        ( vector<GridCell> &gc );
void            assign_Rtotal   ( GridCell &gc, const unsigned long ll, NumericMatrix yGrid );
void            assign_Rinit    ( GridCell &gc, const unsigned long ll, NumericMatrix mGrid, const unsigned int i, float (GridCell::*fget)(const int) const );
void            assign_Rmonth   ( GridCell &gc, const unsigned long ll, NumericMatrix mGrid, int (GridCell::*fget)(const int) const );
void            assign_Rmonth   ( GridCell &gc, const unsigned long ll, NumericMatrix mGrid, float (GridCell::*fget)(const int) const );

#endif
