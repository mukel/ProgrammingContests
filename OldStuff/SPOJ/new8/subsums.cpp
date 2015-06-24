/*
Alfonso2 Peterssen (mukel)
16 - 14 - 2009
SPOJ #3749 "Subset Sums"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 34;

int N, A, B;
int N1, N2;
int V1[MAXN];
int V2[MAXN];
int64 S1[1 << ( MAXN / 2 )];
int64 S2[1 << ( MAXN / 2 )];
int64 ans;

int main() {

	scanf( "%d %d %d", &N, &A, &B );
	
	N1 = N / 2;
	REP( i, N1 )
		scanf( "%d", &V1[i] );

	N2 = N - N1;
	REP( i, N2 )
		scanf( "%d", &V2[i] );
		
	N1 = 1 << N1;
	REP( i, N1 ) {
		if ( i )
			S1[i] = S1[i - (i & -i)] + V1[ __builtin_ctz( i ) ];
	}

	sort( S1, S1 + N1 );
	
	N2 = 1 << N2;
	REP( i, N2 ) {
		if ( i )
			S2[i] = S2[i - (i & -i)] + V2[ __builtin_ctz( i ) ];
		ans +=
			upper_bound( S1, S1 + N1, B - S2[i] ) -
			lower_bound( S1, S1 + N1, A - S2[i] );
	}

	printf( "%lld\n", ans );

	return 0;
}
