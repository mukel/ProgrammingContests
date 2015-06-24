/*
Alfonso2 Peterssen
SPOJ #31 "Fast Multiplication"
5 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef long long int64;

const int
	BASE = 10000000,
	BASE_LOG = 7,
	MAXLEN = 3000;

int T;
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

bigint operator * ( bigint& a, bigint& b ) {
	bigint c( 0, a.size + b.size );
	REP( i, a.size )
	REP( j, b.size )
	      c.T[i + j] += a.T[i] * b.T[j];
	return normal( c );
}

void read( bigint& bn ) {
	static char line[20000];
	scanf( "%s", &line );
	int len = strlen( line );
	int i = len % BASE_LOG;
	if ( i > 0 ) i -= BASE_LOG;
	for ( ;i < len; i += BASE_LOG ) {
		int64 x = 0;
	      REP( j, BASE_LOG )
			x = 10 * x + ( i + j >= 0 ? line[i + j] - '0' : 0 );
		bn.T[bn.size++] = x;
	}
	reverse( bn.T, bn.T + bn.size );
	normal( bn );
}

void print( bigint bn ) {
	printf( "%lld", bn.T[bn.size - 1] );
	REPD( i, bn.size - 1 )
	      printf( /* use BASE_LOG */"%07lld", bn.T[i] );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		bigint a, b;
		read( a );
		read( b );
		print( a * b ); printf( "\n" );
	}

	return 0;
}
