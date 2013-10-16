/*
Alfonso2 Peterssen
19 - 4 - 2008
TASK: SQUARES
*/
#include <cstdio>
#include <cmath>

const int MAXN = 100;
const double SQRT2 = sqrt( 2 );

int N, i, j, k, sol;
int side[MAXN];
double pos[MAXN];
bool mark[MAXN];
bool visible[MAXN];
double lo[MAXN], hi[MAXN];

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d", &side[i] );

    lo[0] = 0;
    hi[0] = SQRT2 * side[0];
    pos[0] = SQRT2 * side[0] / 2.;
    for ( i = 1; i < N; i++ ) {
        for ( j = 0; j < i; j++ )
            pos[i] >?= pos[j] + ( side[i] <? side[j] ) * SQRT2;
        lo[i] = pos[i] - SQRT2 / 2. * side[i];
        hi[i] = pos[i] + SQRT2 / 2. * side[i];
    }

    for ( i = 0; i < N; i++ ) {
        k = -1;
        for ( j = 0; j < N; j++ )
            if ( !mark[j] && ( k == -1 || side[j] > side[k] ) )
                k = j;
        if ( k == -1 ) break;
        
        sol++;
        visible[k] = true;
        mark[k] = true;
        
        for ( j = 0; j < N; j++ )
            if ( !mark[j] && j != k ) {
                if ( lo[j] >= lo[k] &&
                     hi[j] <= hi[k] )
                     mark[j] = true;
                     
                if ( lo[j] <= hi[k] && hi[j] >= hi[k] )
                    lo[j] >?= hi[k];
                if ( lo[j] <= lo[k] && hi[j] >= lo[k] )
                    hi[j] <?= lo[k];
                    
                if ( lo[j] >= hi[j] ||
                     ( fabs( hi[j] - lo[j] ) < 1e-4 ) )
                    mark[j] = true;
            }
    }

    for ( i = 0; i < N; i++ )
        if ( visible[i] )
            printf( --sol ? "%d " : "%d\n", i + 1 );
    fflush( stdout );

    return 0;
}
