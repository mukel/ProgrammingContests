/*
Alfonso2 Peterssen
SPOJ #734 "Ivan and his interesting game"
7 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

const int
	MAXC = 2001,
	oo = (int)1e9;

int A, B;
int a[MAXC];
int b[MAXC];
int dp[MAXC][MAXC];

int main() {

	scanf( "%d %d", &A, &B );
	FOR( i, 1, A ) scanf( "%d", &a[i] );
	FOR( i, 1, B ) scanf( "%d", &b[i] );
	
	FOR( i, 0, A )
	FOR( j, 0, B )
	      dp[i][j] = oo;
	dp[0][0] = 0;
	
	FOR( i, 1, A )
	FOR( j, 1, B )
		dp[i][j] = min( dp[i - 1][j - 1], min( dp[i - 1][j], dp[i][j - 1] ) ) + ( a[i] - 1 ) * ( b[j] - 1 );

	printf( "%d\n", dp[A][B] );

	return 0;
}
