/*
Alfonso2 Peterssen (mukel)
USACO MAR09 "cleanup"
*/
#include <cstdio>
#include <algorithm>

using std :: min;

const int
	MAXN = 400001,
	MAXSQRTN = 201;

int N;
int val[MAXN];
int last[MAXN];
int dp[MAXN];
int low[MAXSQRTN];
int cnt[MAXSQRTN];

int main() {

	scanf( "%d %*d", &N );
	for ( int i = 1; i <= N; i++ ) {
		scanf( "%d", &val[i] );
		dp[i] = i;
		
		for ( int j = 1; j * j < N; j++ ) {
			if ( last[ val[i] ] <= low[j] )
				cnt[j]++;

			while ( cnt[j] > j ) {
				low[j]++;
				if ( last[ val[ low[j] ] ] == low[j] )
					cnt[j]--;
			}

			dp[i] = min( dp[i], cnt[j] * cnt[j] + dp[ low[j] ] );
		}
		
		last[ val[i] ] = i;
	}
	
	printf( "%d\n", dp[N] );

	return 0;
}
