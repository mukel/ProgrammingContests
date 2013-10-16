/*
Alfonso2 Peterssen
22 - 5 - 2008
USACO OPEN08 Bronze "Cowflix"
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

const int MAXN = 20;

int T, N, sol;
int w[MAXN];

int main() {

	freopen( "cowflix.in", "r", stdin );
	freopen( "cowflix.out", "w", stdout );

	scanf( "%d %d", &T, &N );
	REP( i, N )
	    scanf( "%d", &w[i] );

    REP( i, ( 1 << N ) ) {
        int kg = 0;
        REP( j, N )
            if ( i & ( 1 << j ) )
                kg += w[j];
        if ( kg <= T )
            sol >?= kg;
    }

    printf( "%d\n", sol );	

	return 0;
}
