/*
Alfonso2 Peterssen
SPOJ #2322 "Tree Game"
17 - 9 - 2008
*/
#include <cstdio>

const int MAXN = 200000;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

int N, leaf, x, y;
int val[MAXN];

int main() {

	scanf( "%d", &N );
	REP( i, (1 << N) - 1 ) {
		if ( i ) printf( " " );
		
		scanf( "%d", &leaf );
		leaf += ( 1 << N ) - 1;
		
		x = leaf;
		do {
			y = x;
			x /= 2;
		} while ( val[y] || val[y^1] );
		
		val[y] = 2;
		while ( y < ( 1 << N ) ) {
			y *= 2;
			if ( val[y] ) y++;
			if ( val[y/2] == 1 )
			      val[y] = 2;
			else
			      val[y] = 1;
		}
		printf( "%d", val[leaf] - 1 );
	}

	printf( "\n" );

	return 0;
}
