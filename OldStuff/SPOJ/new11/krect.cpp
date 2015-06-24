/*
Alfonso2 Peterssen (mukel)
SPOJ #4329 "Counting K-Rectangle"
3 - 6 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXC = 1 << 7,
	ALPHA = 26;

int F, C, K;
int ans;
char mat[MAXC][MAXC];
int cnt[MAXC][ALPHA];

int main() {

	scanf( "%d %d %d", &F, &C, &K );
	REP( i, F )
	      scanf( "%s", &mat[i] );

	REP( i, F ) {

		// init
		memset( cnt, 0, sizeof( cnt ) );

		for ( int j = i; j < F; j++ ) {

			// add row j
			REP( k, C )
				cnt[k][ mat[j][k] - 'A' ]++;

			int lo = 0, hi = 0;
			int lodiff = 0, hidiff = 0;

			int locnt[ALPHA], hicnt[ALPHA];

			memset( locnt, 0, sizeof( locnt ) );
  			memset( hicnt, 0, sizeof( hicnt ) );

			REP( k, C ) {

				if ( k > 0 ) {
					// erase k - 1 row
					REP( a, ALPHA ) {
						if ( locnt[a] && locnt[a] == cnt[k - 1][a] ) lodiff--;
						if ( hicnt[a] && hicnt[a] == cnt[k - 1][a] ) hidiff--;
						locnt[a] -= cnt[k - 1][a];
						hicnt[a] -= cnt[k - 1][a];
					}
				}

				while ( lodiff < K && lo < C ) {
					REP( a, ALPHA ) {
						if ( !locnt[a] && cnt[lo][a] )
						      lodiff++;
						locnt[a] += cnt[lo][a];
					}
					
					lo++;
				}

				while ( hidiff <= K && hi < C ) {
					REP( a, ALPHA ) {
						if ( !hicnt[a] && cnt[hi][a] )
						      hidiff++;
						hicnt[a] += cnt[hi][a];
					}

					hi++;
				}

				if ( lodiff == K ) {
					ans += hi - lo;
					if ( hidiff == K )
						ans++;
				}
			}
		}
	}
	
	printf( "%d\n", ans );

	return 0;
}
