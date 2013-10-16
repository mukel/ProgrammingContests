/*
Alfonso2 Peterssen
SPOJ #132 "Help R2-D2!"
7 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXC = 100000;

int T, K, N;
int ships, sum;
int tree[4 * MAXC];
char line[100];

void update( int x, int lo, int hi, int value ) {
	if ( lo == hi ) {
		tree[x] += value;
		ships = max( ships, lo + 1 );
		return ;
	}
	int mid = ( lo + hi ) / 2;
	if ( tree[2 * x + 1] + value <= K )
		update( 2 * x + 1, lo, mid, value );
	else
		update( 2 * x + 2, mid + 1, hi, value );
	
	tree[x] = min( tree[2 * x + 1], tree[2 * x + 2] );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		memset( tree, 0, sizeof( tree ) );

		scanf( "%d %d\n", &K, &N );
		
		ships = sum = 0;
		while ( N > 0 ) {

			gets( line );
			int cant, w;
			if ( sscanf( line, "b %d %d", &cant, &w ) != 2  ) {
			      sscanf( line, "%d", &w );
			      cant = 1;
			}
			
			N -= cant;
			while ( cant-- ) {
				sum += w;
				update( 0, 0, MAXC, w );
			}
		}
		
		printf( "%d %d\n", ships, ships * K - sum );
	}

	return 0;
}
