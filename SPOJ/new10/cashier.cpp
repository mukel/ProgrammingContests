/*
Alfonso2 Peterssen (mukel)
SPOJ #1466 "Blue Mary Needs Help Again"
18 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	DELTA = 1 << 19,
	MAXW = 1 << 18;

int TC, Q, low, dels;
int T[2 * DELTA];

// tree from Ivan
void add( int x ) {
	for ( x += DELTA; x > 0; x /= 2 )
	      T[x]++;
}

void erase( int x, int lo, int hi, int val ) {
	if ( !T[x] ) return ;
	if ( lo >= val ) return ;
	if ( x >= DELTA ) {
		dels += T[x];
		T[x] = 0;
		return ;
	}
	
	int mid = (lo + hi) / 2;
	erase( 2 * x, lo, mid, val );
	erase( 2 * x + 1, mid + 1, hi, val );
	
	T[x] = T[2 * x] + T[2 * x + 1];
}

int findKth( int x, int kth ) {
	if ( x >= DELTA )
	      return x - DELTA;
	      
	if ( kth <= T[2 * x] )
	      return findKth( 2 * x, kth );
	else
	      return findKth( 2 * x + 1, kth - T[2 * x] );
}

int main() {

	scanf( "%d", &TC );
	while ( TC-- ) {

		scanf( "%d %d", &Q, &low );
		
		memset( T, 0, sizeof( T ) );
		int offset = 0;
		dels = 0;

		while ( Q-- ) {
			
			int x; char cmd[5];
			scanf( "%s %d", &cmd, &x );
			
			char ch = cmd[0];
			if ( ch == 'I' ) {
				if ( x < low ) continue ;
				add( x - offset + MAXW );
			} else
			if ( ch == 'A' ) {
				offset += x;
			} else
			if ( ch == 'S' ) {
				offset -= x;
				erase( 1, 0, DELTA - 1, low - offset + MAXW );
			} else
			if ( ch == 'F' ) {
				if ( x > T[1] )
				      printf( "-1\n" );
				else
				      printf( "%d\n", findKth( 1, T[1] - x + 1 ) + offset - MAXW );
			}
		}
		
		printf( "%d\n", dels );
	}

	return 0;
}
