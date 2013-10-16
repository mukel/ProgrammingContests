/*
Alfonso2 Peterssen
SPOJ #2006 "Load Balancing"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 10000;

int N;
int jobs[MAXN];

int main() {

	for (;;) {

		int64 sum = 0;
		scanf( "%d", &N ); if ( N == -1 ) break;
		REP( i, N ) {
		      scanf( "%d", &jobs[i] );
		      sum += jobs[i];
		}

		if ( sum % N != 0 ) {
			printf( "-1\n" );
			continue;
		}
		
		int64 cant = sum / N;
		int64 cumul = 0;
		int64 sol = 0;
		
		REP( i, N ) {
		      cumul += jobs[i] - cant;
			sol = max( sol, abs( cumul ) );
		}
		
		printf( "%lld\n", sol );
	}

	return 0;
}
