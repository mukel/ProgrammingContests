/*
Alfonso2 Peterssen
SPOJ #362 "Ignore the Garbage"
4 - 9 - 2008
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
	MAXLEN = 50,
	BASE = 100000000,
	BASE_LOG = 8;
	
const int number[7] = {0,1,2,5,9,8,6};

int T;
struct bigint {
	int size;
	int T[MAXLEN];
	bigint( int x = 0, int size = 1 ) : size( size ) {
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

pair< bigint, int64 > divmod( bigint bn, int64 x ) {
	int64 r = 0, t;
	REPD( i, bn.size ) {
		t = BASE * r + bn.T[i];
		bn.T[i] = t / x;
		r = t % x;
	}
	return make_pair( normal( bn ), r );
}

void read( bigint& bn ) {
	static char line[400];
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

bool IS_ZERO( bigint& bn ) {
	return bn.size == 1 && bn.T[0] == 0;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		bigint num;
		read( num );
		while ( !IS_ZERO( num ) ) {
			pair< bigint, int64 > kk = divmod( num, 7 );
		      printf( "%d", number[kk.second] );
			num = kk.first;
		}
		printf( "\n" );
	}

	return 0;
}
