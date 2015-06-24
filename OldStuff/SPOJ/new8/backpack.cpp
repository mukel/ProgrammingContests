/*
Alfonso2 Peterssen (mukel)
SPOJ #2008 "Dab of Backpack"
6 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXN = 60,
	MAXC = 1 << 15;

int T, W, N;
int V[MAXN];
int C[MAXN];
int dp[MAXC];
bool mark[MAXN];
vector< int > atch[MAXN];

int main() {

	scanf( "%d", &T );
	while ( T-- ) {

		fill( atch, atch + MAXN, vector< int >() );
		memset( mark, 0, sizeof( mark ) );
		memset( dp, 0, sizeof( dp ) );

		scanf( "%d %d", &W, &N );
		REP( i, N ) {
			int parent;
			scanf( "%d %d %d", &V[i], &C[i], &parent );
			parent--;
			if ( parent != -1 ) {
				atch[parent].push_back( i );
				mark[i] = true;
			}
		}
		
		REP( i, N ) {
			if ( mark[i] )
				continue;
			for ( int j = W; j >= V[i]; j-- ) {

				// none
				dp[j] = max( dp[j], dp[j - V[i]] + V[i] * C[i] );
			      
				// one
				REP( k, atch[i].size() ) {
					int id = atch[i][k];
					int jj = j - V[i] - V[id];
					int cc = V[i] * C[i] + V[id] * C[id];
					if ( jj < 0 )
						continue;
					dp[j] = max( dp[j], dp[jj] + cc );
				}
				
				// two
				if ( atch[i].size() < 2 )
					continue;
				int id1 = atch[i][0];
				int id2 = atch[i][1];
				int jj = j - V[i] - V[id1] - V[id2];
				int cc = V[i] * C[i] + V[id1] * C[id1] + V[id2] * C[id2];
				if ( jj < 0 ) continue;
				
				dp[j] = max( dp[j], dp[jj] + cc );
			}
		}

		printf( "%d\n", dp[W] );
	}

	return 0;
}
