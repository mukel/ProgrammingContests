/*
Alfonso2 Peterssen
11 - 6 - 1008
IOI 2002 "Utopia Divided"
check <input> <output>
*/
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 100000;
const int region[4][2] =
    {{+1,+1},{-1,+1},{-1,-1},{+1,-1}};

int N;
int x, y;
int u, v;
int reg[MAXN];
multiset< int > S;

void Error( char *msg ) {
    printf( "Wrong!!! -> %s\n", msg );
    exit( 0 );
}

int sign( int x ) {
    return ( x > 0 ) - ( x < 0 );
}

int main( int argc, char *argv[] ) {

    freopen( argv[1], "r", stdin );

    scanf( "%d", &N );
    REP( i, 2 * N ) {
        scanf( "%d", &x ); S.insert( x );
    }

    REP( i, N ) {
        scanf( "%d", &reg[i] );
        reg[i]--;
    }

    freopen( argv[2], "r", stdin );

    x = y = 0;
    REP( i, N ) {
    
        scanf( "%d %d", &u, &v );
        
        if ( S.find( abs( u ) ) == S.end() ||
             S.find( abs( v ) ) == S.end() )
            Error( "Value doesn't exist.\n" );
            
        S.erase( S.find( abs( u ) ) );
        S.erase( S.find( abs( v ) ) );
        
        x += u;
        y += v;
        
        if ( sign( x ) != region[ reg[i] ][0] ||
             sign( y ) != region[ reg[i] ][1] )
            Error( "The sequence doesn't match." );
    }

    printf( "OK!!!\n" );

    return 0;
}
