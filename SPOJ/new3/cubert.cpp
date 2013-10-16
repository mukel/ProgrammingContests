/*
Alfonso2 Peterssen
SPOJ #291 "Cube Root"
16 - 9 - 2008
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
	MAXLEN = 100;

int T;
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

bigint operator + ( bigint a, bigint& b ) {
	a.size = max( a.size, b.size );
	REP( i, a.size )
	      a.T[i] += b.T[i];
	return normal( a );
}

bigint operator + ( bigint a, int64 x ) {
	a.T[0] += x;
	return normal( a );
}

bigint operator - ( bigint a, bigint& b ) {
	a.size = max( a.size, b.size );
	REP( i, a.size )
	      a.T[i] += b.T[i];
	return normal( a );
}

bigint operator - ( bigint a, int64 x ) {
	a.T[0] -= x;
	return normal( a );
}

bigint operator * ( bigint a, bigint b ) {
	bigint c( 0, a.size + b.size );
	REP( i, a.size )
	REP( j, b.size )
	      c.T[i + j] += a.T[i] * b.T[j];
	return normal( c );
}

bigint operator * ( bigint a, int64 x ) {
	REP( i, a.size )
		a.T[i] *= x;
	return normal( a );
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

int64 operator % ( bigint bn, int64 x ) {
	return divmod( bn, x ).second;
}

void print( bigint bn ) {
	printf( "%lld", bn.T[bn.size - 1] );
	REPD( i, bn.size - 1 )
	      printf( "%0*lld", BASE_LOG, bn.T[i] );
}

void read( bigint& bn ) {
	static char line[200];
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

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		bigint X;
		read( X );
		
		REP( i, 15 ) X = X * 100;
		
		bigint lo( 0 );
		bigint hi = X;
		
		while ( lo <= hi ) {
			bigint mid = ( lo + hi ) / 2;
			if ( mid * mid * mid <= X )
			      lo = mid + 1;
			else
				hi = mid - 1;
		}
		
		lo = lo - 1;
		
		pair< bigint, int64 > R;
		R = divmod( lo, 100000 );
		int p1 = R.second; lo = R.first;
		R = divmod( lo, 100000 );
		int p2 = R.second; lo = R.first;
		
		int sum = 0;
		REP( i, lo.size )
			for ( int x = lo.T[i]; x != 0; x /= 10 )
			      sum = ( sum + x ) % 10;

		for ( int x = p1; x != 0; x /= 10 )
		      sum = ( sum + x ) % 10;
		      
		for ( int x = p2; x != 0; x /= 10 )
		      sum = ( sum + x ) % 10;
		
		printf( "%d ", sum ); print( lo ); printf( ".%05d%05d\n", p2, p1 );
	}

	return 0;
}
