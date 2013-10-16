/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
SPOJ #1880 "Hanoi Calls"
*/
#include <cstdio>

const int MAXN = 33;

int N, i, j, k, sol;
int ls[2][MAXN];

  int moveall( int id, int dest ) {

  	int res = 0;

	  for ( int sz = N - 1; sz; sz-- )
  		if ( ls[id][sz] != dest ) {
		  	res += 1 << ( sz - 1 );
	  		dest = 3 - ls[id][sz] - dest;
  		}

	  return res;
  }

int main() {

	for (;;) {

    scanf( "%d", &N );
    if ( !N ) break;

		for ( i = 0; i < 2; i++ )
			for ( j = 1; j <= N; j++ ) {
			  scanf( "%d", &ls[i][j] );
				ls[i][j]--;
		  }

    while ( N && ls[0][N] == ls[1][N] ) N--;

		if ( N == 0 ) {
      printf( "0\n" );
      continue;
    }

		sol = moveall( 0, 3 - ls[0][N] - ls[1][N] ) +
          moveall( 1, 3 - ls[0][N] - ls[1][N] ) + 1;

		printf( "%d\n", sol );

	}

	return 0;
}
