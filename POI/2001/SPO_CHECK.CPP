/*
Alfonso2 Peterssen
22 - 6 - 2008
PolishOI 2001 "Peaceful Commission"
Simple Output Checker
check <input> <output>
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

int V, E;
int x;
bool used[20000];
int wich[20000][2];
char line[10];

int main( int arvc, char *argv[] ) {

    freopen( argv[1], "r", stdin );
    
    scanf( "%d %d", &V, &E );
    REP( i, E )
    REP( j, 2 )
        scanf( "%d", &wich[i][j] );
        

    freopen( argv[2], "r", stdin );
    
    gets( line );
    if ( strcmp( line, "NIE" ) == 0 ) {
        printf( "Your answer is NIE\n" );
        return 0;
    }
    
    if ( sscanf( line, "%d", &x ) )
        used[x] = true;
    
    while ( scanf( "%d", &x ) != EOF )
        used[x] = true;
        
    REP( i, E )
        if ( used[ wich[i][0] ] && used[ wich[i][1] ] ) {
            printf( "Wrong!!! %d and %d are enemies\n", wich[i][0], wich[i][1] );
            return 0;
        }
        
    REP( i, V )
        if ( !( used[2 * i + 1] ^ used[2 * i + 2] ) ) {
            printf( "Wrong!!! check party %d\n", i + 1 );
            return 0;
        }

    printf( "OK!!!\n" );

    return 0;
}
