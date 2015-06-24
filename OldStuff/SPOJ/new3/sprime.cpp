/*
Alfonso2 Peterssen
SPOJ #2912 "Super Primes"
18 - 9 - 2008
*/
#include <cstdio>
#include <bitset>

using namespace std;

const int MAXN = 10000000;
	
int cant, idx;
bitset< MAXN > mark;

int main() {

	for ( int i = 3; i * i < MAXN; i += 2 )
		if ( !mark[i] )
	            for ( int j = i * i; j < MAXN; j += i )
				mark[j] = true;

	idx = 2; // 2 3
	cant = 1;
	printf( "3\n" );
	for ( int i = 5; i < MAXN; i += 2 ) {
	      if ( i > 10000000 ) break;
		if ( !mark[i] ) {
			idx++;
			if ( !mark[idx] && (idx&1) ) {
				cant++;
				printf( "%d\n", i );
			}
		}
	}
	
	return 0;
}
