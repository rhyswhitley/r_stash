#include "extras.hh"
// Process has done i out of n rounds,
// and we want a bar of width w and resolution r.
//const void loadbar(const unsigned int x, const unsigned int n, const unsigned int w) {
//
//    if ( (x != n) && (x % (n/100+1) != 0) ) return;
//
//    float ratio = x/(float)n;
//    unsigned int  c = ratio * w;
//
//    cout << setw(3) << (int)(ratio*100) << "% [";
//    for (unsigned int x=0; x<c; x++) cout << "=";
//    for (unsigned int x=c; x<w; x++) cout << " ";
//    cout << "]\r" << flush;
//}


void progress_bar(const double x, const double N) {
    // how wide you want the progress meter to be
    int totaldotz = 40;
    double fraction = x/N;
    // part of the progressmeter that's already "full"
    int dotz = round(fraction * totaldotz);

    // create the "meter"
    int ii=0;
    printf("%3.0f%% [",fraction*100);
    // part  that's full already
    for ( ; ii < dotz; ii++) {
        printf("=");
    }
    // remaining part (spaces)
    for ( ; ii < totaldotz; ii++) {
        printf(" ");
    }
    // and back to line begin - do not forget the fflush to avoid output buffering problems!
    printf("]\r");
    fflush(stdout);
}
