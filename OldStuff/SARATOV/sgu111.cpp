/*
Alfonso2 Peterssen (mukel)
3 - 2 - 2009
SGU #111 "Very simple problem"
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
	BASE = 1000000000,
	BASE_LOG = 9,
	MAXLEN = 130;
	
struct bigint {
	int size;
	int64 T[MAXLEN];
	bigint( int64 x = 0, int size = 1 ) : size( size ) {
		memset( T, 0, sizeof( T ) );
		T[0] = x;
	}
};

bool operator < ( const bigint& a, const bigint& b ) {
	if ( a.size != b.size )
	      return a.size < b.size;
	REPD( i, a.size )
		if ( a.T[i] != b.T[i] )
		      return a.T[i] < b.T[i];
	return false;
}

bool operator <= ( const bigint& a, const bigint& b ) {
	return !( b < a );
}
	
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

bigint& operator * ( bigint& a, bigint& b ) {
	bigint c( 0, a.size + b.size );
	REP( i, a.size )
	REP( j, b.size )
	      c.T[i + j] += a.T[i] * b.T[j];
	return normal( c );
}

bigint& operator + ( bigint& a, bigint& b ) {
	bigint c( 0, max( a.size, b.size ) );
	REP( i, c.size )
	      c.T[i] += a.T[i] + b.T[i];
	return normal( c );
}

bigint& operator + ( bigint& bn, int64 x ) {
	bn.T[0] += x;
	return normal( bn );
}

bigint& operator - ( bigint& bn, int64 x ) {
	bn.T[0] -= x;
	return normal( bn );
}

pair< bigint, int64 > divmod( bigint bn, int64 x ) {
	int64 r = 0, t;
	REPD( i, bn.size ) {
		t = BASE * r + bn.T[i];
		bn.T[i] = t / x;
		r = t % x;
	}
	return make_pair( normal( bn ), r );
}


bigint operator / ( bigint bn, int64 x ) {
	return divmod( bn, x ).first;
}

bigint sqrt( bigint bn ) {
	bigint lo, hi;
	hi.size = bn.size / 2 + 2;
	hi.T[ hi.size - 1 ] = 1LL;
	normal( hi );
	while ( lo <= hi ) {
		bigint mid = ( lo + hi ) / 2;
		if ( mid * mid <= bn )
		      lo = mid + 1;
		else
		      hi = mid - 1;
	}
	return lo - 1;
}

void read( bigint& bn ) {
	static char line[MAXLEN * BASE_LOG];
	scanf( "%s", &line );
	int len = strlen( line );
	int i = len % BASE_LOG;
	if ( i > 0 ) i -= BASE_LOG;
	for ( ; i < len; i += BASE_LOG ) {
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
	      printf( /* use BASE_LOG */"%09lld", bn.T[i] );
}

bigint N;

int main() {

	read( N );
	print( sqrt( N ) ); printf( "\n" );
	
	return 0;
}
