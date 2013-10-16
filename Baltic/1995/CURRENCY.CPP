/*
Alfonso2 Peterssen
8 - 5 - 2008
Baltic 1995 Task: CURRENCY
*/
#include <cstdio>

const int MAXN = 20;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

int N;
double C[MAXN][MAXN];

int main() {

    scanf( "%d", &N );
    REP( i, N )
    REP( j, N )
        scanf( "%lf", &C[i][j] );

    REP( i, N )
    REP( j, N )
        if ( i == j )
            C[i][j] = 1.;
        else
        if ( C[i][j] == 0. &&
             C[j][i] >  0. )
             C[i][j] = 1 / C[j][i];

    REP( k, N )
    REP( i, N )
    REP( j, N )
        if ( C[i][j] == 0. &&
             C[i][k] >  0. &&
             C[k][j] >  0. )
             C[i][j] = C[i][k] * C[k][j];

    REP( i, N )
    REP( j, N )
        printf( j < N - 1 ? "%.2lf " : "%.2lf\n", C[i][j] );

    return 0;
}
