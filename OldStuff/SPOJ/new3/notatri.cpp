/*
Alfonso2 Peterssen
SPOJ #2905 "Not a Triangle"
18 - 9 - 2008
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 2000,
	MAXS = 2000001;

int N, sol;
int stick[MAXN];
short int S[MAXS];

int main() {

	for (;;) {
		scanf( "%d", &N ); if ( !N ) break;
		
		sol = 0;
		memset( S, 0, sizeof( S ) );
		
		REP( i, N ) {
			scanf( "%d", &stick[i] );
			S[ stick[i] ]++;
		}
		
		for ( int i = 1; i < MAXS; i++ )
		      S[i] += S[i - 1];
		
		REP( i, N )
		REP( j, i )
			sol += N - S[ stick[i] + stick[j] ];
			
		printf( "%d\n", sol );
	}

	return 0;
}
