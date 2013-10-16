/*
Alfonso2 Peterssen
SPOJ #2742 "Summing Sums"
23 - 9 - 2008
WOW!!!
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int
	MAXN = 50000,
	MAXLOG = 32,
	MODULO = 98765431;
	
int N, T;
int64 S;
int C[MAXN];
int64 sum[MAXLOG];
int64 pow[MAXLOG];

int main() {

	scanf( "%d %d", &N, &T );
	REP( i, N ) {
	      scanf( "%d", &C[i] );
	      S = ( S + C[i] ) % MODULO;
	}

	int64 val = 0, p = 1;
	
	sum[0] = ( N - 2 ) % MODULO;
	pow[0] = ( N - 1 ) % MODULO;
	for ( int i = 1; T >> i; i++ ) {
		pow[i] = ( pow[i - 1] * pow[i - 1] ) % MODULO;
		sum[i] = ( sum[i - 1] + sum[i - 1] * pow[i] ) % MODULO;
		if ( ( T >> i ) & 1 ) {
			val = ( val + sum[i - 1] * p ) % MODULO;
			p = ( p * pow[i] ) % MODULO;
		}
	}

	if ( T & 1 )
		val = ( val * (N - 1) + 1 ) % MODULO;
	
	val = ( val * S ) % MODULO;

	REP( i, N )
	      if ( T % 2 )
	            printf( "%d\n", ( val - C[i] + MODULO ) % MODULO );
		else
		      printf( "%d\n", ( val + C[i] ) % MODULO );

	return 0;
}
