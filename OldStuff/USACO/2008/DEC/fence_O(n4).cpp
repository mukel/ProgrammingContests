/*
Alfonso2 Peterssen (mukel)
27 - 12 - 2008
USACO DEC08 "Largest Fence"
Simple O( n^4 )
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 250;

int N;
int sol;
int dp[MAXN][MAXN];
struct point {
	int x, y;
	bool operator < ( const point& p ) const {
		return ( x != p.x ) ? x < p.x : y < p.y;
	}
} P[MAXN];

int64 area2( const point& a, const point& b, const point& c ) {
	return
		(int64)( b.x - a.x ) * ( c.y - a.y ) -
		(int64)( c.x - a.x ) * ( b.y - a.y );
}

int memo( int a, int b, int c ) {
	int& ans = dp[b][c];
	if ( ans != -1 )
		return ans;

	ans = 3; // triangle
	for ( int i = a + 1; i < N; i++ )
		if (	area2( P[i], P[b], P[c] ) > 0 &&
			area2( P[a], P[i], P[b] ) > 0 )
			ans = max( ans, memo( a, i, b ) + 1 );

	return ans;
}

int main() {

	scanf( "%d", &N );
	REP( i, N )
	      scanf( "%d %d", &P[i].x, &P[i].y );

	sort( P, P + N );

	REP( i, N ) {
		memset( dp, -1, sizeof( dp ) );
		for ( int j = i + 1; j < N; j++ )
		for ( int k = i + 1; k < N; k++ )
		      if ( area2( P[i], P[j], P[k] ) > 0 ) {
				sol = max( sol, memo( i, j, k ) );
				break;
			}
	}

	printf( "%d\n", sol );

	return 0;
}
