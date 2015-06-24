/*
Alfonso2 Peterssen
SPOJ #228 "Shamans"
29 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef long long int64;
typedef complex< int > point;

const int MAXN = 2000;

int T, N, H;
int dp[MAXN][MAXN];
int from[MAXN][MAXN];
point hull[MAXN];
point P[MAXN];

int cross( const point& a, const point& b ) {
	return imag( conj(a) * b );
}

int area2( const point& a, const point& b, const point& c ) {
	return cross( b - a, c - a );
}

namespace std {
	bool operator < ( const point& a, const point& b ) {
		if ( real(a) != real(b) )
		      return real(a) < real(b);
		return imag(a) < imag(b);
	}
};

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		REP( i, N ) {
			int x, y;
			scanf( "%d %d", &x, &y );
			P[i] = point( x, y );
		}
		
		sort( P, P + N );
		
		H = 0; int top = 1;
		for ( int i = 0; i < N; hull[H++] = P[i++] )
			while ( H > top &&
				area2( hull[H - 2], hull[H - 1], P[i] ) < 0 )
			H--;

		top = H;
		for ( int i = N - 2; i >= 0; hull[H++] = P[i--] )
			while ( H > top &&
				area2( hull[H - 2], hull[H - 1], P[i] ) < 0 )
			H--;
		H--;
		
		REP( i, H ) from[i][i] = i;

		for ( int delta = 1; delta < H; delta++ )
		REP( i, H ) {
			int j = ( i + delta ) % H;
			dp[i][j] = -1;
			int k = from[i][(j - 1 + H)%H];
			for (;;) {
				int val = area2( hull[i], hull[k], hull[j] );
				assert( val >= 0 );
				if ( val > dp[i][j] ) {
					dp[i][j] = val;
					from[i][j] = k;
				}
				if ( k == from[(i + 1)%H][j] )
				      break;
				k = (k + 1) % H;
			}
		}

		int sol = 0;
		REP( i, H )
		REP( j, i )
		      sol = max( sol, dp[i][j] + dp[j][i] );
		
		printf( "%d.%d\n", sol / 2, 5 * (sol%2) );
	}

	return 0;
}
