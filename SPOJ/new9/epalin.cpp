/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 1 << 20;

int N;
char S[MAXN];
int rad[2 * MAXN];

int main() {

	while ( scanf( "%s", &S ) == 1 ) {
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

		int needed;
		for ( int i = (N-1) / 2; i < N; i++ ) {
			int len = (N - i - 1) * 2;
			if ( rad[2 * i] == len + 1 ) {
				needed = N - len - 1;
				break;
			}
			if ( rad[2 * i + 1] == len ) {
				needed = N - len;
				break;
			}
		}
		
		// add extra chars
		for (	int pos = needed - 1; pos >= 0; pos-- )
			S[N++] = S[pos];
			
		S[N] = '\0';
		printf( "%s\n", S );
	}

	return 0;
}
