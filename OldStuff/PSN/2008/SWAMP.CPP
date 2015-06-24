/*
Alfonso2 Peterssen
18 - 4 - 2008
TASK: SWAMP
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int N, i, j, k, zeros;
int dx, dy, sol;
int x[MAXN];
int y[MAXN];
pair< int, int > slopes[MAXN];

int GCD( int a, int b ) {
    while ( a && b ) if ( a %= b ) b %= a;
    return a + b;
}

int main() {

    #warning READ FROM FILES!!!
    freopen( "swamp.in", "r", stdin );
    freopen( "swamp.out", "w", stdout );

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d %d", &x[i], &y[i] );
        
    for ( i = 0; i < N; i++ ) {
        zeros = 0;
        for ( j = 0; j < N; j++ ) {
            dx = x[j] - x[i];
            dy = y[j] - y[i];
            int gcd = GCD( dx, dy );
            if ( gcd != 0 )
                dx /= gcd, dy /= gcd;
            if ( dx == 0 && dy == 0 )
                zeros++;
            slopes[j] = make_pair( dx, dy );
        }
        sort( slopes, slopes + N );
        for ( j = 0; j < N; j = k ) {
            for ( k = j + 1; k < N && slopes[j] == slopes[k]; k++ );
            if ( slopes[j].first  == 0 &&
                 slopes[j].second == 0 )
                      sol >?= zeros;
                 else sol >?= k - j + zeros;
        }
    }
    
    if ( sol < 4 ) sol = 0;
    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
