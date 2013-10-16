/*
Alfonso2 Peterssen
23 - 7 - 2008
POI 2005 Stage I "Bankomat"
*/
#include <cstdio>
#include <algorithm>

using std::count;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
    for ( int i = (n) - 1; i >= 0; i-- )

const int
    MAXN = 1000,
    MAXT = 10001;

int N, T;
char S[MAXT];
int freq[10000];
int nxt[MAXT][10];

int main() {

    scanf( "%d", &N );
    REP( i, N ) {

        scanf( "%d %s", &T, &S );

        REP( k, 10 )
            nxt[T][k] = -1;
        REPD( j, T ) {
            REP( k, 10 )
                nxt[j][k] = nxt[j + 1][k];
            nxt[j][ S[j] - '0' ] = j;
        }

        REP( k, 10000 ) {
            if ( freq[k] != i )
                continue;

            int a = k / 1000 % 10;
            int b = k / 100 % 10;
            int c = k / 10 % 10;
            int d = k / 1 % 10;

            if ( nxt[0][a] != -1 &&
                 nxt[ nxt[0][a] ][b] != -1 &&
                 nxt[ nxt[ nxt[0][a] ][b] ][c] != -1 &&
                 nxt[ nxt[ nxt[ nxt[0][a] ][b] ][c] ][d] != -1 )
               freq[k]++;
        }
    }

    printf( "%d\n", count( freq, freq + 10000, N ) );

    return 0;
}
