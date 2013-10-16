/*
Alfonso2 Peterssen (mukel)
3 - 2 - 2009
SGU #116 "Index of super-prime"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) \
	for ( int i = (b); i <= (e); i++ )

const int
	MAXN = 10001,
	oo = (int)1e9;

int N;
int cant;
int from[MAXN];
int best[MAXN];
vector< int > SP;

int prime( int x ) {
	if ( x < 2 ) return false;
	if ( x == 2 || x == 3 )
	      return true;
	if ( x % 2 == 0 || x % 3 == 0 )
	      return false;
	for ( int i = 6; (i-1) * (i-1) <= x; i += 6 )
	      if ( x % (i - 1) == 0 || x % (i + 1) == 0)
	            return false;
	return true;
}

int main() {

	scanf( "%d", &N );
	FOR( i, 2, N )
	      if ( prime( i ) ) {
			cant++;
			if ( prime( cant ) )
				SP.push_back( i );
		}
		
	//printf( "%d\n", SP.size() );
		
	fill( best, best + N + 1, oo );
	best[0] = 0;
	REP( i, SP.size() ) {
		int val = SP[i];
	      FOR( j, val, N )
			if ( best[j - val] + 1 < best[j] ) {
				best[j] = best[j - val] + 1;
				from[j] = i;
			}
	}
	
	if ( best[N] == oo )
		printf( "0\n" );
	else {
		printf( "%d\n", best[N] );
		int val = N;
		while ( val > 0 ) {
			printf( "%d ", SP[ from[val] ] );
			val -= SP[ from[val] ];
		}
		printf( "\n" );
	}

	return 0;
}
