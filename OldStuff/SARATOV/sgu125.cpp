/*
Alfonso2 Peterssen (mukel)
4 - 2 - 2009
SGU #125 "Shtirlits"
*/
#include <cstdio>
#include <cstdlib>
#include <cassert>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 3;

int N;
int sol[MAXN][MAXN];
int best[MAXN][MAXN];

int check( int row ) {
	int ans = 0;
	REP( i, N ) {
		int cant = 0;
		int val = sol[row][i];
		if ( i > 0 ) cant += (val < sol[row][i - 1]);
		if ( i < N - 1 ) cant += (val < sol[row][i + 1]);
		if ( row > 0 ) cant += (val < sol[row - 1][i]);
		if ( row < N - 1 ) cant += (val < sol[row + 1][i]);
		if ( cant > best[row][i] )
		      return +1;
		if ( cant < best[row][i] )
			ans = -1;
	}
	return ans;
}

void comb( int row ) {

	if ( row == N ) {
		if ( check( row - 1 ) == 0 ) {
			REP( i, N ) {
				REP( j, N )
				      printf( "%d ", sol[i][j] );
				printf( "\n" );
			}
			exit( 0 );
		}
		return ;
	}

	REP( a, 10 )
	REP( b, 10 )
	REP( c, 10 ) {
		sol[row][0] = a;
		sol[row][1] = b;
		sol[row][2] = c;
		if ( check( row ) != +1 && (row == 0 || check( row - 1 ) == 0 ) )
			comb( row + 1 );
	}
	
	REP( i, N )
	      sol[row][i] = 0;
}

int main() {

	scanf( "%d", &N );
	REP( i, N )
	REP( j, N )
	      scanf( "%d", &best[i][j] );
	      
	if ( N == 1 ) {
		if ( best[0][0] == 0 )
		      printf( "0\n" );
		exit( 0 );
	} else
	if ( N == 2 ) {
		REP( a, 10 )
		REP( b, 10 )
		REP( c, 10 )
		REP( d, 10 )
			if (
				(a < b) + (a < c) == best[0][0] &&
				(b < a) + (b < d) == best[0][1] &&
				(c < a) + (c < d) == best[1][0] &&
				(d < b) + (d < c) == best[1][1] ) {
		   		printf( "%d %d\n%d %d\n", a, b, c, d );
		   		exit( 0 );
			}
	} else
		comb( 0 );
	
	printf( "NO SOLUTION\n" );

	return 0;
}
