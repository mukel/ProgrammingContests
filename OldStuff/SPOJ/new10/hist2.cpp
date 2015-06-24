/*
Alfonso2 Peterssen (mukel)
SPOJ #3436 "Histogram"
19 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 15;

int T, N;
int H[MAXN];
int best[1 << MAXN][MAXN];
int ways[1 << MAXN][MAXN];
int idx[1 << MAXN];

bool my_comp( const int& i, const int& j ) {
	int si = __builtin_popcount( i );
	int sj = __builtin_popcount( j );
	if ( si != sj )
		return si < sj;
	return i < j;
}

int main() {

	while (1) {
		scanf( "%d", &N ); if ( !N ) break ;
		
		REP( i, N )
			scanf( "%d", &H[i] );

		memset( best, -1, sizeof( best ) );
 		memset( ways, 0, sizeof( ways ) );

		// init
		REP( i, N ) {
			best[1 << i][i] = H[i];
			ways[1 << i][i] = 1;
		}
		
		REP( i, (1 << N) )
		      idx[i] = i;
		      
		sort( idx, idx + (1 << N), my_comp );
		
		// DP
		REP( x, (1 << N) ) {
			int i = idx[x];
			REP( j, N )
		      if ( (i >> j) & 1 )
				REP( k, N )
			      if ( !((i >> k) & 1) ) {
					int ii = i | (1 << k);
					int val = best[i][j] + abs( H[j] - H[k] );
					if ( ii == (1 << N) - 1 )
					      val += H[k];
					if ( val > best[ii][k] ) {
						best[ii][k] = val;
						ways[ii][k] = ways[i][j];
					} else if ( val == best[ii][k] )
					      ways[ii][k] += ways[i][j];
				}
		}

		// get answer
		int allbest = -1, allways = 0;
		REP( i, N )
		      if ( best[(1 << N) - 1][i] > allbest ) {
				allbest = best[(1 << N) - 1][i];
				allways = ways[(1 << N) - 1][i];
			} else
		      if ( best[(1 << N) - 1][i] == allbest )
				allways += ways[(1 << N) - 1][i];

		allbest += 2 * N;
		printf( "%d %d\n", allbest, allways );
	}

	return 0;
}
