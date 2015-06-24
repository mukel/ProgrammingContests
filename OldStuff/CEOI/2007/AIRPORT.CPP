/*
Alfonso2 Peterssen
26 - 7 - 2008
CEOI 2007 "Airport Show"
*/
#include <cstdio>
#include <cstdlib>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 5000;

int N;
int S[2];
int owner[MAXN];
int rway[2][MAXN];
int sol[2 * MAXN];
bool mark[MAXN][MAXN];

void dfs( int a, int b ) {

    if ( a >= S[0] || b >= S[1] || mark[a][b] )
        return ;

    mark[a][b] = true;
    int &bossa = owner[ rway[0][a] ];
    int &bossb = owner[ rway[1][b] ];

    if ( bossa == 2 && bossb == 1 ) {
        REP( i, a + b )
            printf( "%d", sol[i] );
        printf( "\n" );
        exit( 0 );
    }

    if ( bossa == 0 || bossa == 1 ) {
        bossa ^= 1;
        sol[a + b] = 1;
        dfs( a + 1, b );
        bossa ^= 1;
    }

    if ( bossb == 0 || bossb == 2 ) {
        bossb ^= 2;
        sol[a + b] = 2;
        dfs( a, b + 1 );
        bossb ^= 2;
    }
}

int main() {

    scanf( "%d", &N );
    REP( i, 2 ) {
        scanf( "%d", &S[i] );
        REP( j, S[i] )
            scanf( "%*s %d", &rway[i][j] );
    }

    dfs( 0, 0 );

    printf( "The performances will always finish.\n" );

    return 0;
}
