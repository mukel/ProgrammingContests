/*
Alfonso2 Peterssen
19 - 6 - 208
BalticOI 2001 "Excursion"
check <input> <output>
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 50000;

int V, E, N;
int wish[MAXV][2];
bool used[MAXV];
char line[100];

int main( int argc, char *argv[] ) {

    freopen( argv[1], "r", stdin );
    
    scanf( "%d %d", &E, &V );
    REP( i, E )
    REP( j, 2 )
        scanf( "%d", &wish[i][j] );
        
    freopen( argv[2], "r", stdin );
    
    gets( line );

    if ( strcmp( line, "NO" ) == 0 ) {
        printf( "Your answer is NO\n" );
        return 0;
    }
    
    sscanf( line, "%d", &N );
    REP( i, N ) {
        int x;
        scanf( "%d", &x );
        used[x] = true;
    }
    
    REP( i, E ) {
        int x = wish[i][0];
        if ( ( x < 0 && !used[-x] ) || ( x > 0 && used[x] ) )
            continue;
        x = wish[i][1];
        if ( ( x < 0 && !used[-x] ) || ( x > 0 && used[x] ) )
            continue;
        printf( "Wrong!!!\n" );
        return 0;
    }
    
    printf( "OK!!!\n" );

    return 0;
}
