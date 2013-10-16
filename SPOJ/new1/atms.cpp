/*
Alfonso2 Peterssen
SPOJ #184 "Automatic Teller Machines"
6 - 9 - 2008
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
	MAXN = 500,
	BASE = 100000000,
	BASE_LOG = 8,
	MAXLEN = 5;

int T;
int dig[MAXN];
int sol[MAXN];

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

bool IS_ZERO( bigint& bn ) {
	return bn.size == 1 && bn.T[0] == 0;
}

void increment( int pos, int x ) {
//	printf( "inc %d %d\n", pos, x );
	if ( x == 0 ) return ;
	if ( pos % 2 )
		dig[pos] -= x;
	else
		dig[pos] += x;

	if ( dig[pos] > 1 ) {
		dig[pos + 1]++;
		dig[pos + 2]++;
		dig[pos] = 0;
	}

	if ( dig[pos] < 0 ) {
		dig[pos + 1]++;
		dig[pos] = 1;
	}
	
//	printf( "-> %d %d\n", dig[pos], dig[pos + 1] );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		bigint num, x;
		read( num );

		memset( dig, 0, sizeof( dig ) );
		
		x = num;
		for ( int i = 0; ; i++ ) {
			if ( IS_ZERO( x ) ) {
				int cant = 0;
				REPD( j, MAXN )
					if ( dig[j] )
						if ( j > 99 ) {
							printf( "No\n" );
							break;
						} else
							sol[cant++] = j;
				REP( j, cant )
				      printf( j < cant - 1 ? "%d " : "%d\n", sol[j] );
				break;
			}
			int val = x.T[0] % 2;
			increment( i, val );
			x = x / 2;
		}
		
		
		memset( dig, 0, sizeof( dig ) );
		
		x = num;
		for ( int i = 0; ; i++ ) {
			if ( IS_ZERO( x ) ) {
				int cant = 0;
				REPD( j, MAXN )
					if ( dig[j] )
						if ( j > 99 ) {
							printf( "No\n" );
							break;
						} else
                                          sol[cant++] = j;
				REP( j, cant )
				      printf( j < cant - 1 ? "%d " : "%d\n", sol[j] );
				break;
			}
			pair< bigint, int64 > R = divmod( x, 2 );
			x = R.first;
			increment( i, -R.second );
		}
	}

	return 0;
}
