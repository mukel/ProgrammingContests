/*
Alfonso2 Peterssen
SPOJ #699 "Huge Knap Sack"
23 - 9 - 2008
tricky...
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

typedef long long int64;

const int
	MAXN = 18,
	MAXV = 18,
	MAXS = 1000,
	LIMIT = 1000; // FIX

int T, M, S, Y, C, N;
int bestW, bestV;
int best[MAXV];
int W[MAXN];
int V[MAXN];
int64 knap[MAXS];
int64 dp[LIMIT + 1];

int main() {

	assert( LIMIT >= MAXS );

	for ( scanf( "%d", &T ); T--; ) {

		N = 0;
		bestW = -1;
		bestV = +1;
		fill( best, best + MAXV, -1 );
		
		scanf( "%d %d %d %d", &M, &S, &Y, &C );
		while ( M-- ) {
			int w, v;
			scanf( "%d %d", &w, &v );
			best[v] = max( best[v], w );
		}
		
		REP( i, MAXV )
		      if ( best[i] != -1 ) {
				W[N] = best[i];
				V[N] = i;
				if ( W[N] * bestV > bestW * V[N] ) {
					bestW = W[N];
					bestV = V[N];
				}
				N++;
			}

		memset( dp, 0, sizeof( dp ) );
		REP( i, N )
		FOR( j, V[i], LIMIT )
			dp[j] = max( dp[j], dp[ j - V[i] ] + W[i] );
			
		REP( i, S ) {
			int64 value = -1;
			int64 cap = (int64)(i + 1) * Y;
			int64 fac = cap / bestV;
			int64 res = cap - fac * bestV;
			while ( res < LIMIT ) {
				value = max( value, fac * bestW + dp[res] );
				fac--;
				res += bestV;
			}
			knap[i] = value - (int64)i * C;
		}

		memset( dp, 0, sizeof( dp ) );
		REP( i, S )
		FOR( j, i + 1, S )
		      dp[j] = max( dp[j], dp[j - i - 1] + knap[i] );
		
		printf( "%lld\n", dp[S] );
	}

	return 0;
}
