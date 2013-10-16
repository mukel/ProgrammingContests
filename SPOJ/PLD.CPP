/*
Alfonso2 Peterssen
1 - 9 - 2008
SPOJ #2426 "Palindromes"
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXLEN = 40000;
	
int N, K, sol;
char S[MAXLEN];
int rad[2 * MAXLEN];

int main() {

	scanf( "%d", &K );
	scanf( "%s", &S );
	N = strlen( S );

	/* Manacher */
	for ( int i = 0, j = 0, k; i < 2 * N - 1; i += k ) {

		while ( i - j >= 0 &&
			i + j + 1 < 2 * N &&
	           	S[(i - j) / 2] == S[(i + j + 1) / 2] )
			j++;

		rad[i] = j;
		for ( k = 1; k <= rad[i] && rad[i - k] != rad[i] - k; k++ )
			rad[i + k] = min( rad[i - k], rad[i] - k );

		j = max( j - k, 0 );
	}
	
	REP( i, N )
		if ( i >= K - 1 && rad[2 * (i - K/2) + !(K&1)] >= K )
			sol++;

	printf( "%d\n", sol );

	return 0;
}
