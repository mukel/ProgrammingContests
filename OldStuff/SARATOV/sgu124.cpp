/*
Alfonso2 Peterssen (mukel)
4 - 2 - 2009
SGU #124 "Broken line"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef pair< int, int > point;
typedef pair< point, point > seg;

const int
	MAXN = 10000;

int N, X, Y;
int cant;
seg segs[MAXN];

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		int x1, y1, x2, y2;
		scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
		if ( x2 < x1 ) swap( x1, x2 );
		if ( y2 < y1 ) swap( y1, y2 );
		segs[i] = seg( point( x1, y1 ), point( x2, y2 ) );
	}
	
	scanf( "%d %d", &X, &Y );
	
	REP( i, N ) {
		int x1 = segs[i].first.first;
		int y1 = segs[i].first.second;
		int x2 = segs[i].second.first;
		int y2 = segs[i].second.second;
		
		if ( x1 == x2 ) {
			if ( X == x1 && Y >= y1 && Y <= y2 ) {
				printf( "BORDER\n" );
				exit( 0 );
			}
		}
		
		if ( y1 == y2 ) {
			if ( Y == y1 && X >= x1 && X <= x2 ) {
				printf( "BORDER\n" );
				exit( 0 );
			}
			if ( Y < y1 && X >= x1 && X < x2 )
			      cant++;
		}
	}
	
	if ( cant % 2 )
		printf( "INSIDE\n" );
	else
		printf( "OUTSIDE\n" );

	return 0;
}
