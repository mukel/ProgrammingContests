/*
Alfonso2 Peterssen
19 - 6 - 2008
BalticOI 2003 "Barrel"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const double EPSILON = 1e-6;
const int MAXN = 1000;

int N;
double A, H, W;
double S[MAXN];
double D[MAXN];
double lo, hi, mid;

double volume( double value ) {
    double vol = 0;
    REP( i, N ) {
        if ( D[i] > 1.0 ) D[i] = 1.0; // FIX IT
        double kk = ( S[i] * D[i] ) <? value;
        if ( value + S[i] - kk > H )
            kk = S[i] - ( H - value );
        vol += kk * S[i] * S[i];
    }
    return vol + W;
}

int main() {

    scanf( "%lf %lf %lf", &A, &H, &W );
    scanf( "%d", &N );
    REP( i, N )
        scanf( "%lf %lf", &S[i], &D[i] );

    lo = 0;
    hi = H;
    while ( hi - lo > EPSILON ) {
        mid = ( lo + hi ) / 2.;
        if ( volume( mid ) >= mid * A )
             lo = mid;
        else hi = mid;
    }

    printf( "%lf\n", lo );

    return 0;
}
