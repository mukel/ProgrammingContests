/*
Alfonso2 Peterssen
SPOJ #2 "Prime Generator"
3 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

const int
	MAXP = 1000000000,
	SQRP = 100001;

int T, lo, hi;
int cant;
bool mark[SQRP];
int primes[SQRP];

bool prime( int x ) {
	if ( x < 2 ) return false;
	for ( int i = 0; i < cant && primes[i] * primes[i] <= x; i++ )
		if ( x % primes[i] == 0 )
		      return false;
	return true;
}

int main() {

	for ( int i = 2; i <= SQRP; i++ )
		if ( !mark[i] ) {
			primes[cant++] = i;
			for ( int j = 2 * i; j <= SQRP; j += i )
			      mark[j] = true;
		}

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &lo, &hi );
		FOR( i, lo, hi )
		      if ( prime( i ) )
		            printf( "%d\n", i );
		printf( "\n" );
	}
	
	return 0;
}
