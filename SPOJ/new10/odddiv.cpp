/*
Alfonso2 Peterssen (mukel)
SPOJ #3107 "Odd Numbers of Divisors"
18 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )
	
#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int
	MAXSQ = (int)1e5,
	MAXP = (int)1e3,
	MAXK = (int)1e4;
	
int T, P;
bool mark[MAXP];
int prime[MAXP];
vector< int64 > V[MAXK];

int main() {

	for ( int i = 2; i < MAXP; i++ )
	      if ( !mark[i] ) {
			prime[P++] = i;
			for ( int j = 2 * i; j < MAXP; j += i )
			      mark[j] = true;
		}

	FOR( i, 2, MAXSQ ) {
		int x = i, divs = 1;
		REP( j, P ) {
			if ( prime[j] > x ) break ;
			if ( x % prime[j] ) continue ;
			int cnt = 0;
			do x /= prime[j], cnt++; while ( !(x % prime[j]) );
			divs *= 2 * cnt + 1;
		}
		
		if ( x > 1 ) divs *= 3;
		
		V[divs].push_back( (int64)i * i );
	}
	
	scanf( "%d", &T );
	while ( T-- ) {
		int K; int64 lo, hi;
		scanf( "%d %lld %lld", &K, &lo, &hi );
		printf( "%d\n", upper_bound( ALL( V[K] ), hi ) - lower_bound( ALL( V[K] ), lo ) );
	}

	return 0;
}
