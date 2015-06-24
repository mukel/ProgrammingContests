/*
Alfonso2 Peterssen
SPOJ #347 "Lazy Cows"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 1001,
	oo = (int)1e9;

int T, N, B, K;
int last, next;
int dp[2][MAXN][5];
int mask, dist;
int last_pos, cur_pos;
struct point {
	int x, y;
	bool operator < ( const point& p ) const { return x < p.x; }
} cows[MAXN];

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d %d", &N, &K, &B );
		REP( i, N ) {
			int x, y;
			scanf( "%d %d", &y, &x );
			cows[i] = (point){ x, y };
		}

		sort( cows, cows + N );
		
		next = last ^ 1;
		memset( dp[next], 63, sizeof( dp[next] ) );
		dp[next][0][0] = 0;

		last_pos = 0;
		REP( i, N ) {

			swap( last, next );
			memset( dp[next], 63, sizeof( dp[next] ) );

			mask = cows[i].y;
			if ( i < N - 1 && cows[i].x == cows[i + 1].x ) {
				mask |= cows[i + 1].y;
				i++;
			}
			
			cur_pos = cows[i].x;
			dist = cur_pos - last_pos;
			
			for ( int j = 1; j <= K; j++ ) {

				// 0 anything
				// 1 up only
				// 2 down only
				// 3 up and down
				// 4 both
				
				dp[next][j][1] = oo;
				dp[next][j][2] = oo;
				
				if ( mask == 1 )
				dp[next][j][1] = min(
					min( dp[last][j][1], dp[last][j][3] ) + dist, // join
					dp[last][j - 1][0] + 1 ); // new box

				if ( mask == 2 )
				dp[next][j][2] = min(
					min( dp[last][j][2], dp[last][j][3] ) + dist, // join
					dp[last][j - 1][0] + 1 ); // new box
				
				int val3 = oo;
				val3 <?= min(
					min( dp[last][j - 1][1], dp[last][j - 1][2] ),
					dp[last][j - 1][3] ) + dist + 1;
				      
				val3 = min( val3, dp[last][j][3] + 2 * dist ); // new boxes
				if ( j >= 2 ) val3 = min( val3, dp[last][j - 2][0] + 2 ); // no join
				dp[next][j][3] = val3;
				
				dp[next][j][4] = min(
					dp[last][j - 1][0] + 2, // new box
					dp[last][j][4] + 2 * dist ); // join
				
				dp[next][j][0] = min(
					min( dp[next][j][1], dp[next][j][2] ),
					min( dp[next][j][3], dp[next][j][4] ) );
			}
			
			last_pos = cur_pos;
		}
		
		printf( "%d\n", dp[next][K][0] );
	}

	return 0;
}
