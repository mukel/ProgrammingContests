/*
Alfonso2 Peterssen
SPOJ #261. Triangle Partitioning
6 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


const double
	FACTOR = 10000000,
	EPSILON = 1e-7;

int T;
struct triangle {
	double a, b, c;
	triangle( double _a, double _b, double _c ) {
		a = _a;
		b = _b;
		c = _c;
		if ( b < a ) swap( a, b );
		if ( c < a ) swap( a, c );
		if ( c < b ) swap( b, c );
	}
	
	bool operator < ( const triangle& t ) const {
		double ab = a / b - t.a / t.b;
		if ( fabs( ab ) > EPSILON )
		      return ab < 0.;
		      
		double ac = a / c - t.a / t.c;
		if ( fabs( ac ) > EPSILON )
		      return ac < 0.;
		      
		return false;
	}
};
map< triangle, bool > M;

template< typename T >
T sqr( const T x ) { return x * x; }

void memo( triangle T ) {
	if ( M.find( T ) != M.end() )
	      return ;
	      
	M[T] = true;
	double M = sqrt( 2 * sqr( T.a ) + 2 * sqr( T.b ) - sqr( T.c ) ) / 2.;
	
	memo( triangle( T.a, M, T.c / 2. ) );
	memo( triangle( T.b, M, T.c / 2. ) );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		int a, b, c;
		scanf( "%d %d %d", &a, &b, &c );
		
		triangle first( a * FACTOR, b * FACTOR, c * FACTOR );
		
		M.clear();
		
		memo( first );
		printf( "%d\n", M.size() );
	}

	return 0;
}
