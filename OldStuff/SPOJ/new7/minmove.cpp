/*
Alfonso2 Peterssen (mukel)
SPOJ #xxx
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const
	int MAXN = 500000;

int max( int a, int b ) { return a > b ? a : b; }
	
int N;
char S[MAXN];
int ans, nxt, delta;

int main() {

	scanf( "%s", &S );
	N = strlen( S );
	
	ans = 0;
	nxt = 1;
	while ( nxt < N && ans + delta < N ) {
		if ( S[(ans + delta) % N] < S[(nxt + delta) % N] ) {
			nxt = nxt + delta + 1;
			delta = 0;
		} else
		if ( S[(ans + delta) % N] > S[(nxt + delta) % N] ) {
			int __nxt = nxt;
			nxt = max( ans + delta, nxt + 1 );
			ans = __nxt;
			delta = 0;
		} else
			delta++;
	}
	
	printf( "%d\n", ans );

	return 0;
}
