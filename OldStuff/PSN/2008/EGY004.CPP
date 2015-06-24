/*
Alfonso Alfonso Peterssen
Task: MINERS
*/
#include <cstdio>
#include <cstring>

const int MAXN = 200000;

#define REP( i, n ) \
    for ( i = 0; i < (n); i++ )

int n, i, sol;
int a, b, c, d;
char s[MAXN + 1];
int last[4][4][4][4];
int next[4][4][4][4];

int cost( int a, int b, int c ) {
    int res = ( a != b ) + ( a != c ) + ( b != c );
    return res + !res - !a;
}

int main() {

    scanf( "%d", &n );
    scanf( "%s", &s ) ;
    REP( i, n )
        s[i] = ( s[i] == 'M' ? 1 : ( s[i] == 'B' ? 2 : 3 ) );

    memset( next, -1, sizeof( next ) );
    next[0][0][0][0] = 0;
    REP( i, n ) {
        memcpy( last, next, sizeof( next ) );
        memset( next,   -1, sizeof( next ) );
        REP( a, 4 ) REP( b, 4 )
        REP( c, 4 ) REP( d, 4 )
            if ( last[a][b][c][d] != -1 ) {
                int x = last[a][b][c][d] + cost( b, a, s[i] );
                int y = last[a][b][c][d] + cost( d, c, s[i] );
                next[ s[i] ][a][c][d] >?= x;
                next[a][b][ s[i] ][c] >?= y;
                sol >?= ( x >? y );
        }
    }

    printf( "%d\n", sol );

    return 0;
}
