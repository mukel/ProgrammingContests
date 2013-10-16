/*
Alfonso2 Peterssen
SPOJ #1673 "Ambitious Manager"
23 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

typedef long long int64;

const int MAXK = 60;

int T, K;
int64 N;
int64 A[MAXK];
int64 B[MAXK];
int64 S[MAXK];
int cant;
int sol[MAXK];

bool comb( int idx, int64 val ) {
	if ( val == 0 ) return true;
	if ( val > S[idx] ) return false;
	if ( val >= B[idx] ) {
		sol[cant++] = idx;
		return comb( idx - 1, val - B[idx] );
	}
	return comb( idx - 1, val );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%lld %d", &N, &K );
		FOR( i, 1, K ) {
		      scanf( "%d", &A[i] );
		      B[i] = B[i - 1] * 2LL + A[i];
		      S[i] = S[i - 1] + B[i];
		}
		cant = 0;
		if ( comb( K, N ) )
			REPD( i, cant )
			      printf( i ? "%d " : "%d\n", sol[i] );
		else
		      printf( "-1\n" );
	}

	return 0;
}
