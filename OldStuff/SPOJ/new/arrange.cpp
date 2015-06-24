/*
Alfonso2 Peterssen
SPOJ #2412 "Arranging Amplifiers"
6 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 1000000;

int T, N;
int val[MAXN];
int sol[MAXN];

int main() {

	for ( scanf( "%d", &T ); T-- ; ) {
		scanf( "%d", &N );
		REP( i, N )
		      scanf( "%d", &val[i] );
		      
		int cant = 0;
		      
		sort( val, val + N );
		int pos;
		for ( pos = 0; pos < N && val[pos] == 1; pos++ )
			sol[cant++] = 1;
			
		if ( pos == N - 2 && val[pos] == 2 && val[pos + 1] == 3 ) {
		      sol[cant++] = 2;
		      sol[cant++] = 3;
		      pos += 2;
		}
			
		for ( int i = N - 1; i >= pos; i-- )
			sol[cant++] = val[i];
		
		REP( i, N )
		      printf( i < N - 1 ? "%d " : "%d\n", sol[i] );
	}

	return 0;
}
