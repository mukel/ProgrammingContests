/*
Alfonso2 Peterssen
SPOJ #325 "The Tall Windmills"
17 - 9 - 2008
Don't try to understand this code...
*/
#include <cstdio>
#include <algorithm>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 100;

int T, N;
int offset;
int sol[MAXN];

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d", &N );
		
		if ( N % 2 == 0 ) {
			offset = N / 2 + 1;
			REP( i, N / 2 )
				sol[i] = offset + i * ( N - 1 );
			offset = 1;
			REP( i, N / 2 )
			      sol[N / 2 + i] = offset + i * ( N - 1 );
		}
		
		if ( N % 2 == 1 ) {
			offset = N / 2 + 3;
			for ( int i = 1; i < N / 2; i++ )
				sol[i] = offset + (i - 1) * N;
			if ( N == 3 ) sol[0] = 3;
			else
			      if ( N > 3 )
			            sol[0] = sol[N / 2 - 1] + offset - 1;
			sol[N / 2] = 1;
			REP( i, N / 2 )
			      sol[N / 2 + i + 1] = sol[i] + N / 2;
		}
		
		REP( i, N )
		      printf( i < N - 1 ? "%d " : "%d", sol[i] );
		printf( "\n" );
	}
	

	return 0;
}
