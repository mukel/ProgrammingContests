/*
Alfonso2 Peterssen
22 - 5 - 2008
USACO OPEN08 Bronze "Coldwat"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <complex>

#define _NO_OLDNAMES 1
#include <cmath>

#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long int64;
typedef vector< int > array;
typedef vector< array > matrix;

/* fors++  */
#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = s; i <= (e); i++ )
#define FORD( i, s, e ) \
	for ( int i = (e); i >= (s); i-- )

/* containers */
#define ALL( c ) (c).begin(), (c).end()
#define VAR( x ) ( typeof(x) )
#define FOREACH( it, c ) \
	for ( VAR( (c).begin() ) it = (c).begin() ); it != (c).end(); it++ )

/* DEBUG */
#define DBG( x ) \
	cout << #x "=[" << (x) << "]" << endl;

const int MAXV = 100000;

int V, E;
int src, u, v;
int dp[MAXV];
int father[MAXV];

int dfs( int x ) {
    if ( dp[x] != 0 )
        return dp[x];
    dp[x] = dfs( father[x] ) + 1;
    return dp[x];
}

int main() {

	freopen( "coldwat.in", "r", stdin );
	freopen( "coldwat.out", "w", stdout );

	scanf( "%d %d", &V, &E );
	REP( i, E ) {
	    scanf( "%d %d %d", &src, &u, &v );
	    src--; u--; v--;
	    father[u] = src;
	    father[v] = src;
    }

    dp[0] = 1;
    REP( i, V ) {
        dfs( i );
        printf( "%d\n", dp[i] );
    }
    
	return 0;
}
