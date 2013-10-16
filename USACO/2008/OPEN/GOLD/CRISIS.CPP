/*
Alfonso2 Peterssen
5 - 6 - 2008
USACO OPEN08 Gold "Crisis on the Farm"
*/
#include <cstdio>
#include <cstring>

/* fors */
#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
    for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )
    
const int
    MAXN = 1000,
    MAXC = 1001,
    MAXK = 31;
    
const char* dir = "WSNE";
const int mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int N, M, K, sol;
int x, y;
int X[MAXN];
int Y[MAXN];
bool haystack[MAXC][MAXC];

/* Neg-Arrays */
int __hs[2 * MAXK][2 * MAXK];
int __dp[MAXK][2 * MAXK][2 * MAXK];
int __fr[MAXK][2 * MAXK][2 * MAXK];
#define hs( x, y ) __hs[(x) + MAXK][(y) + MAXK]
#define dp( i, x, y ) __dp[i][(x) + MAXK][(y) + MAXK]
#define fr( i, x, y ) __fr[i][(x) + MAXK][(y) + MAXK]

int main() {

    freopen( "crisis.in", "r", stdin );
    freopen( "crisis.out", "w", stdout );

    scanf( "%d %d %d", &N, &M, &K );
    
    REP( i, N )
        scanf( "%d %d", &X[i], &Y[i] );
    
    REP( i, M ) {
        scanf( "%d %d", &x, &y );
        haystack[x][y] = true;
    }
    
    FOR( dx, -K, +K )
    FOR( dy, -K, +K )
        REP( i, N ) {
            x = X[i] + dx;
            y = Y[i] + dy;
            if ( x < 0 || x >= MAXC ||
                 y < 0 || y >= MAXC )
                 continue;
            hs( dx, dy ) += haystack[x][y];
        }
    
    memset( __dp, -1, sizeof( __dp ) );
    dp( 0, 0, 0 ) = 0;
    
    FOR( i, 1, K )
        FOR( dx, -K, +K )
        FOR( dy, -K, +K ) {
            int best = -1;
            REP( j, 4 ) {
                x = dx + mov[j][0];
                y = dy + mov[j][1];
                best >?= dp( i - 1, x, y );
            }
            if ( best != -1 )
                sol >?= dp( i, dx, dy ) = best + hs( dx, dy );
        }
        
    /* find path */
    memset( __fr, -1, sizeof( __fr ) );
    FOR( dx, -K, +K )
    FOR( dy, -K, +K )
        if ( dp( K, dx, dy ) == sol )
             fr( K, dx, dy ) = 0;
             
    REPD( i, K )
        FOR( dx, -K, +K )
        FOR( dy, -K, +K )
            REP( j, 4 ) {
                x = dx + mov[j][0];
                y = dy + mov[j][1];
                if ( fr( i + 1, x, y ) == -1 )
                    continue;
                if ( dp( i, dx, dy ) + hs( x, y ) == dp( i + 1, x, y ) )
                    fr( i, dx, dy ) = j;
            }
    
    printf( "%d\n", sol );
    x = y = 0;
    REP( i, K ) {
        int d = fr( i, x, y );
        printf( "%c", dir[d] );
        x += mov[d][0];
        y += mov[d][1];
    }
    printf( "\n" );
        
    return 0;
}
