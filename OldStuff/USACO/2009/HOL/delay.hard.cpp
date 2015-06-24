/*
Alfonso2 Peterssen (mukel)
made during contest...
USACO HOL09 "Transmission Delay"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

// faster FORS
#define FOR( i, b, e ) \
	for ( int i = (b), __end = (e); i <= __end; i++ )
#define FORD( i, e, b ) \
	for ( int i = (e), __begin = (b); i >= __begin; i-- )

typedef long long int64;

const int
	MAXN = 2001,
	MODULO = 100000000;

int N, D, K;
vector< int > P[2];
char seq[MAXN];
int dp[MAXN][MAXN];
int oflw[MAXN][MAXN];
int sol[MAXN];

int64 buff[2][MAXN]; // only two rows needed
int64 *nxt_sum = buff[0];
int64 *lst_sum = buff[1];

int main() {

	scanf( "%d %d %d", &N, &D, &K );
	scanf( "%s", &seq );

	reverse( seq, seq + N );

	P[0].push_back( -1 );
	P[1].push_back( -1 );
	REP( i, N )
		P[( seq[i] == '1' )].push_back( i + 1 );

	/* init */
	FOR( i, 1, N ) {
		if ( abs( i - P[1][1] ) <= D )
			dp[1][i] = 1;
		if ( abs( i - P[0][i] ) > D )
		      break;
	}
	
	int ones = P[1].size() - 1, zeroes = P[0].size() - 1;

	FOR( i, 1, N )
		nxt_sum[i] = nxt_sum[i - 1] + dp[1][i];

	/* DP */
	FOR( i, 2, ones ) {
		int last = 0;
		swap( nxt_sum, lst_sum );

		FOR( j, i, N ) {
			int lo = max( last, P[1][i - 1] - D - 1 );
			int hi = min( j - 1, P[1][i - 1] + D );

			if ( lo < hi && abs( j - P[1][i] ) <= D ) {
				if ( oflw[i - 1][hi] - oflw[i - 1][lo] > 0 ) {
					oflw[i][j] = 1;
					dp[i][j] = ( lst_sum[hi] - lst_sum[lo] + MODULO ) % MODULO;
				} else {
					int64 sum = lst_sum[hi] - lst_sum[lo];
					if ( sum >= MODULO ) {
						oflw[i][j] = 1;
						dp[i][j] = sum % MODULO;
					} else
					      dp[i][j] = sum;
				}

			}

			int z = j - i + 1;
			if ( z > zeroes ) break;
			if ( abs( j - P[0][z] ) > D )
				last = j - 1;
		}

		memset( nxt_sum, 0, sizeof( buff[0] ) );
		FOR( j, i, N ) {
			oflw[i][j] += oflw[i][j - 1];
			nxt_sum[j] = nxt_sum[j - 1] + dp[i][j];
		}
	}

	/* now, build the path */

	// deaccumulate oflw
/*	FOR( i, 1, ones )
	FORD( j, N, i )
	      oflw[i][j] = oflw[i][j] - oflw[i][j - 1];
	      */

	int last_pos = N + 1;

	K--;
	FORD( i, ones, 1 ) {
		int pos = -1;

		// fix last
		int z = zeroes;
		FORD( j, last_pos - 1, i ) {
			if ( abs( j - P[0][z] ) > D ) {
				FORD( k, j - 1, i ) {
			            dp[i][k] = 0;
			            oflw[i][k] = 0;
				}
		            break;
			}
			z--;
		}

		FOR( j, max( i, P[1][i] - D ), min( N, P[1][i] + D ) ) {
			if ( oflw[i][j] || dp[i][j] > K ) {
				pos = j;
				break;
			}
     		      K -= dp[i][j];
		}

		zeroes -= last_pos - pos - 1;
		last_pos = pos;
		sol[pos - 1] = 1;
	}

	int ans = 0;
	FOR( i, ones, N )
		ans = ( ans + dp[ones][i] ) % MODULO;

	printf( "%d\n", ans );
	REPD( i, N )
	      printf( "%d", sol[i] );
	printf( "\n" );

	return 0;
}


