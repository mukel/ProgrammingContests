/*
Alfonso2 Peterssen (mukel)
SPOJ #100 "Tower of Babylon"
5 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 30;

int N, M;
int dp[6 * MAXN];
struct block {
	int x, y, z;
	bool operator < ( const block& b ) const { return x > b.x; }
} V[6 * MAXN];

int main() {

	for (;;) {
		scanf( "%d", &N ); if ( !N ) break;
		
		M = 0;
		
		REP( i, N ) {
			int x, y, z;
			scanf( "%d %d %d", &x, &y, &z );
			V[M++] = (block){ x, y, z };
			V[M++] = (block){ x, z, y };
			V[M++] = (block){ y, x, z };
			V[M++] = (block){ y, z, x };
			V[M++] = (block){ z, x, y };
			V[M++] = (block){ z, y, x };
		}
		
		sort( V, V + M );
		
		REP( i, M ) {
			dp[i] = 0;
			REP( j, i )
			      if ( V[i].x < V[j].x && V[i].y < V[j].y )
			            dp[i] = max( dp[i], dp[j] );
			dp[i] += V[i].z;
		}
		
		printf( "%d\n", *max_element( dp, dp + M ) );
	}

	return 0;
}
