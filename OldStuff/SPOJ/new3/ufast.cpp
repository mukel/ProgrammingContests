/*
Alfonso2 Peterssen
SPOJ #695 "Unite Fast"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

const int
	MAXN = 100,
	MAXC = 1000,
	oo = (int)1e9;

int T, N, D;
int pos[MAXN + 1];
int next[MAXC + 1];
int dp0[MAXN + 1][MAXC + 1];
int dp1[MAXN + 1][MAXC + 1];

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d %d", &N, &D );
		FOR( i, 1, N )
		      scanf( "%d", &pos[i] );

		sort( pos + 1, pos + N + 1 );
		
		FOR( i, 1, N ) {

			for ( int j = 0; j < i; j++ )
			      dp0[i][j] = dp1[i][j] = oo;

			// dp0
			FORD( j, MAXC, 1 ) {
				int k = j + 1;
				while( k <= MAXC && !( dp0[i - 1][k] < dp0[i - 1][j] ) )
					k = next[k];
				next[j] = k;
			}

			for ( int lo = 1, hi = i; hi <= MAXC; hi++ ) {
				if ( hi - lo > D )
					lo++;
				while ( next[lo] <= hi )
					lo = next[lo];
				dp0[i][hi] = max( dp0[i - 1][lo], abs( pos[i] - hi ) );
			}

			// dp1
			FORD( j, MAXC, 1 ) {
				int k = j + 1;
				while( k <= MAXC && !( dp1[i - 1][k] < dp1[i - 1][j] ) )
					k = next[k];
				next[j] = k;
			}
			
			for ( int lo = 1, hi = i; hi <= MAXC; hi++ ) {
				if ( hi - lo > D )
					lo++;
				while ( next[lo] <= hi )
					lo = next[lo];
				dp1[i][hi] = dp1[i - 1][lo] + abs( pos[i] - hi );
			}
		}
		
		int sol0 = N, sol1 = N;
		FOR( i, 1, MAXC ) {
		      if ( dp0[N][i] < dp0[N][sol0] )
		            sol0 = i;
		      if ( dp1[N][i] < dp1[N][sol1] )
		            sol1 = i;
		}
		
		printf( "%d %d\n", dp0[N][sol0], dp1[N][sol1] );
	}

	return 0;
}
