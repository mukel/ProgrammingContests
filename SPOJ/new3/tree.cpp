/*
Alfonso2 Peterssen
SPOJ #738 "Another Counting Problem"
15 - 9 - 2008
from Guo Huayang
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef long long int64;

const int
	MAXN = 40,
	MAXD = 20,
	BASE = 1000000,
	BASE_LOG = 6,
	MAXLEN = 100;

struct bigint {
	int size;
	int64 T[MAXLEN];
	bigint( int64 x = 0, int size = 1 ) : size( size ) {
		memset( T, 0, sizeof( T ) );
		T[0] = x;
	}
};

bigint& normal( bigint& bn ) {
	int64 r = 0, t;
	REP( i, bn.size ) {
		while ( bn.T[i] < 0 ) {
			bn.T[i + 1] -= 1;
			bn.T[i] += BASE;
		}
		t = bn.T[i] + r;
		bn.T[i] = t % BASE;
		r = t / BASE;
	}
	for ( ; r > 0; r /= BASE )
		bn.T[bn.size++] = r % BASE;
	while ( bn.size > 1 && bn.T[bn.size - 1] == 0 )
		bn.size--;
	return bn;
}

bigint operator + ( bigint a, bigint b ) {
	a.size = max( a.size, b.size );
	REP( i, a.size )
	      a.T[i] += b.T[i];
	return normal( a );
}

bigint operator * ( bigint& a, bigint& b ) {
	bigint c( 0, a.size + b.size );
	REP( i, a.size )
	REP( j, b.size )
	      c.T[i + j] += a.T[i] * b.T[j];
	return normal( c );
}

int N, D;
bigint f[MAXN][MAXD];
bigint g[MAXN][MAXD];
bool mark[MAXN][MAXD];

void memo( int N, int D ) {

	REP( i, D + 1 )
	if ( !mark[N][i] ) {
		mark[N][i] = true;
		if ( i == 0 )
			f[N][i] = 1;
		else {
			bigint p( 0 );
			bigint q( 1 );
			REP( j, N ) {
				p = ( p * g[N][i - 1] ) + ( q * f[N][i - 1] );
				if ( i > 1 )
					q = q * g[N][i - 2];
				else
					q = 0;
			}
			f[N][i] = p;
		}
		g[N][i] = f[N][i];
		if ( i > 0 )
			g[N][i] = g[N][i] + g[N][i - 1];
	}
}

void print( bigint bn ) {
	printf( "%lld", bn.T[bn.size - 1] );
	REPD( i, bn.size - 1 )
	      printf( /* use BASE_LOG */"%06lld", bn.T[i] );
}

int main() {

	for (;;) {
		scanf( "%d %d", &N, &D );
		if ( !N && !D ) break;
		memo( N, D );
		printf( "%d %d ", N, D );
		print( f[N][D] );
		printf( "\n" );
	}

	return 0;
}
