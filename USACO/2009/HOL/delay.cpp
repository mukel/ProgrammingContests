/*
Alfonso2 Peterssen (mukel)
6 - 1 - 2009
USACO HOL09 "Transmission Delay"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, b, e ) \
	for ( int i = (b), __end = (e); i <= __end; i++ )
#define FORD( i, e, b ) \
	for ( int i = (e), __begin = (b); i >= __begin; i-- )

const int
	MAXN = 2001,
	MODULO = 100000000;

int N, D, K;
vector< int > P[2];
char seq[MAXN];
int dp[MAXN][MAXN];

int main() {

	scanf( "%d %d %d", &N, &D, &K );
	K--;

	scanf( "%s", &seq );
	reverse( seq, seq + N );

	P[0].push_back( -1 );
	P[1].push_back( +1 );
	REP( i, N )
		P[( seq[i] == '1' )].push_back( i + 1 );

	int ones = P[1].size() - 1, zeroes = P[0].size() - 1;

	/* init */
	dp[0][0] = 1;
	FOR( i, 1, N )
	      if ( i <= zeroes && abs( i - P[0][i] ) <= D )
			dp[0][i] = 1;
		else
		      break;

	/* DP */
	FOR( i, 1, ones )
	FOR( j, i, N ) {
		if ( j > i > 0 && j - i <= zeroes && abs( j - P[0][j - i] ) <= D )
			dp[i][j] += dp[i][j - 1];
		if ( abs( j - P[1][i] ) <= D )
			dp[i][j] += dp[i - 1][j - 1];
		if ( dp[i][j] >= MODULO )
			dp[i][j] = ( dp[i][j] % MODULO ) + MODULO;
		//printf( "dp[%d][%d] = %d\n", i, j, dp[i][j] );
	}

	printf( "%d\n", dp[ones][N] % MODULO );
	FORD( i, N, 1 )
		if ( abs( i - P[0][zeroes] ) <= D ) {
			if ( K >= dp[ones][i - 1] ) {
				K -= dp[ones][i - 1];
				printf( "1" );
				ones--;
			} else {
				printf( "0" );
				zeroes--;
			}
		} else {
			printf( "1" );
			ones--;
		}

	printf( "\n" );

	return 0;
}
