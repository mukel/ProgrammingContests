/*
Alfonso2 Peterssen (mukel)
SPOJ #4465 "The Ant"
3 - 6 - 2009
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <bitset>

#include <complex>
#include <cmath>

#include <cstdlib>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )
#define FORD( i, hi, lo ) for ( int i = (hi); i >= (lo); i-- )

#define ITER(c) typeof( (c).begin() )
#define FORALL( it, c ) for ( ITER(c) it = (c).begin(); it != (c).end(); it++ )
#define FORRANGE( it, lo, hi ) for ( typeof(lo) it = (lo); it != (hi); it++ )
	
#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int MAXN = 1000;

int T, N, Q;
int cnt;
int X[MAXN][2], Y[MAXN][2];
int comp[MAXN];
vector< int > G[MAXN];

void dfs( int u, int id ) {
	comp[u] = id;
	REP( i, G[u].size() ) {
		int v = G[u][i];
		if ( comp[v] == -1 )
		      dfs( v, id );
	}
}

template< typename T >
T sign( T &x ) { return ( x > 0 ) - ( x < 0 ); }


int64 area2( int x0, int y0,
             int x1, int y1,
             int x2, int y2 ) {
    return (int64)( x1 - x0 ) * ( y2 - y0 ) -
           (int64)( x2 - x0 ) * ( y1 - y0 );
}

bool intersect( int x0, int y0, int x1, int y1,
                int x2, int y2, int x3, int y3 ) {

    int a = area2( x0, y0, x1, y1, x2, y2 );
    int b = area2( x0, y0, x1, y1, x3, y3 );
    int c = area2( x2, y2, x3, y3, x0, y0 );
    int d = area2( x2, y2, x3, y3, x1, y1 );

    if ( a == 0 && b == 0 && c == 0 && d == 0 ) {
        if ( x0 > x1 ) swap( x0, x1 );
        if ( y0 > y1 ) swap( y0, y1 );
        return ( x2 >= x0 && x2 <= x1 && y2 >= y0 && y2 <= y1 ) ||
               ( x3 >= x0 && x3 <= x1 && y3 >= y0 && y3 <= y1 );
    }

    return sign( a ) != sign( b ) &&
           sign( c ) != sign( d );
}

bool cut( int i, int j ) {
	return intersect( X[i][0], Y[i][0], X[i][1], Y[i][1],
				X[j][0], Y[j][0], X[j][1], Y[j][1] );
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &N, &Q );
		REP( i, N )
		      scanf( "%d %d %d %d", &X[i][0], &Y[i][0], &X[i][1], &Y[i][1] );
		      
		REP( i, N )
		      G[i].clear();

		REP( i, N )
 		REP( j, i )
			if ( cut( i, j ) ) {
				G[i].push_back( j );
   				G[j].push_back( i );
			}
			
		fill( comp, comp + N, -1 );
			
		REP( i, N )
		      if ( comp[i] == -1 )
				dfs( i, ++cnt );
				
		while ( Q-- ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			printf( (comp[u] == comp[v]) ? "YES\n" : "NO\n" );
		}

	}


	return 0;
}
