/*
Alfonso2 Peterssen
SPOJ #1803 "Fold"
7 - 9 - 2008
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

const int MAXN = 300;

int N;
string line;
int rad[MAXN];
int dp[MAXN][MAXN];

int main() {

	while ( cin >> line ) {
		N = line.size();
		REP( i, N ) {
			int j;
			for ( j = 0; i - j - 1 >= 0 && i + j + 1 < N &&
				line[i - j - 1] != line[i + j + 1]; j++ );
			rad[i] = j;
		}

		N++;
		FOR( delta, 1, N - 1 )
			REP( i, N - delta ) {
				int j = i + delta;
				dp[i][j] = (int)1e9;
				FOR( k, i, j - 1 )
				      if ( rad[k] >= min( k - i, j - k - 1 ) )
				      dp[i][j] = min( dp[i][j], max( dp[i][k], dp[k + 1][j] ) + 1 );
			}
		
		printf( "%d\n", dp[0][N - 1] );
	}

	return 0;
}
