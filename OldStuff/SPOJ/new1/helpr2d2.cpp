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
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

typedef long long int64;

const int
	MAXC = 100000;

int T, K, N;
int tree[4 * MAXC];
char line[100];

int query( int x, int lo, int hi, int start, int end, int value ) {
	if ( lo == hi ) return lo;
	int mid = ( lo + hi ) / 2;
	if ( tree[2 * x + 1] + value <= K )
	      return query( 2 * x + 1, lo, mid, start, end, value );
	else
		return query( 2 * x + 2, mid + 1, hi, start, end, value );
}

void update( int x, int lo, int hi, int pos, int value ) {
	if ( lo > pos || hi < pos || lo > hi )
	      return ;
	if ( lo == hi ) {
		tree[x] += value;
		return ;
	}
	int mid = ( lo + hi ) / 2;
	update( 2 * x + 1, lo, mid, pos, value );
	update( 2 * x + 2, mid + 1, hi, pos, value );
	
	tree[x] = min( tree[2 * x + 1], tree[2 * x + 2] );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		memset( tree, 0, sizeof( tree ) );

		scanf( "%d %d\n", &K, &N );
		
		int ships = 0, sum = 0;
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
				int pos = query( 0, 0, MAXC, 0, MAXC, w );
				update( 0, 0, MAXC, pos, w );
				ships = max( ships, pos + 1 );
			}
		}
		
		printf( "%d %d\n", ships, ships * K - sum );
	}

	return 0;
}
