/*
Alfonso2 Peterssen (mukel)
SPOJ #4179 "Temptation Island"
22 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 100;

int N, K, A, B;
int64 dp[2][MAXN];

int main() {

	while (1) {
		scanf( "%d %d", &N, &K );
		if ( N < 0 && K < 0 ) break ;
		
		scanf( "%d %d", &A, &B );
		A--; B--;
		
		memset( dp, 0, sizeof( dp ) );
		int next = 0, last = 1;
		dp[next][A] = 1;
		
		REP( i, K ) {
			swap( last, next );
			REP( j, N )
				dp[next][j] = dp[last][(j - 1 + N) % N] + dp[last][(j + 1) % N];
		}
		
		printf( "%lld\n", dp[next][B] );
	}

	return 0;
}
