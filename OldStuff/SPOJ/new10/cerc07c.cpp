/*
Alfonso2 Peterssen (mukel)
SPOJ #2051 "Cell Phone"
20 - 5 - 2009
based on CEOI 2006 ANTENNA
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 1 << 11;
const double PI = acos( -1 );

int N, R;
int X[MAXN], Y[MAXN];
struct event {
	double angle; int kind;
	bool operator < ( const event &e ) const {
	if ( angle != e.angle ) return angle < e.angle;
		return kind > e.kind;
	}
} evts[4 * MAXN];

int sqr( int x ) { return x * x; }

double dist( int i, int j ) {
	return sqrt( sqr( X[i] - X[j] ) + sqr( Y[i] - Y[j] ) );
}

int main() {

	while (1) {
		scanf( "%d %d", &N, &R ); if ( !N && !R ) break ;
		REP( i, N )
		      scanf( "%d %d", &X[i], &Y[i] );
		      
		int ans = 1;
		REP( i, N ) {
			int E = 0;

			REP( j, N )
			if ( j != i && dist( i, j ) - (1e-7) <= 2 * R ) {
                		double a = atan2( Y[j] - Y[i], X[j] - X[i] );
                		double b = acos( dist( i, j ) / (2 * R) );
                		evts[E++] = (event){a - b, +1};
				evts[E++] = (event){a + b, -1};
				evts[E++] = (event){a - b + 2 * PI, +1};
				evts[E++] = (event){a + b + 2 * PI, -1};
			}
            	
        		sort( evts, evts + E );
        		
			int inside = 1;
			REP( j, E ) {
				inside += evts[j].kind;
				ans = max( ans, inside );
			}
		}
		
		printf( "It is possible to cover %d points.\n", ans );
	}

	return 0;
}
