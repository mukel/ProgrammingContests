/*
Alfonso2 Peterssen
SPOJ #682 "Pairs of Integers"
8 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXC = 1000000;

int T, N;
int cant;
pair< int, int > sol[MAXC];
int64 pow10[11];

void comb( int pos, int64 A, int64 B, bool used ) {

	if ( used ) {
		int64 diff = N - A - B;
		if ( A != B &&
		diff >= 0 && diff % 2 == 0 &&
		diff / 2 < pow10[pos + 1] ) {
			sol[cant].first = A + diff / 2;
			sol[cant].second = B + diff / 2;
			cant++;
		}
		return ;
	}

	if ( pos == -1 ) return ;
	if ( A + B / 10 > N ) return ; // overflow
	if ( A + B / 10 + pow10[pos + 1] - 1 + pow10[pos] - 1 < N ) return ; // underflow
	
	// digit
	REP( i, 10 ) {
		int64 dig = pow10[pos] * i;
		comb( pos - 1, A + dig, B + dig, false );
		if ( !used )
			comb( pos - 1, A + dig, B / 10, true );
	}
}

int main() {

	pow10[0] = 1LL;
	for( int i = 1; i <= 11; i++ )
	      pow10[i] = pow10[i - 1] * 10;

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		
		int len = 0;
		for ( int x = N; x > 0; x /= 10, len++ );
		
		cant = 0;
		comb( len - 1, 0, 0, false );
		
		sort( sol, sol + cant );
		cant = unique( sol, sol + cant ) - sol;
		
		printf( "%d\n", cant );
		REP( i, cant ) {
			int size = len - 1 - ( sol[i].first < pow10[len - 1] );
			printf( "%d + %0*d = %d\n", sol[i].first, size, sol[i].second, N );
		}
	}

	return 0;
}
