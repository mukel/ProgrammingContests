/*
Alfonso2 Peterssen
BalkanOI 2007 "Points"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 1000;

int N, sol;
int cant[MAXN + 1];
struct point {

	int x, y, z;
	point() {}
	point( int x, int y, int z ) : x( x ), y( y ), z( z ) {}

	int gcd( int a, int b ) {
		while ( a && b ) if ( a %= b ) b %= a;
		return a + b;
	}

	void normalize() {
		int g = gcd( gcd( x, y ), z );
		x /= g;	y /= g;	z /= g;
	}

	bool operator < ( const point &p ) const {
		if ( x != p.x ) return x < p.x;
		if ( y != p.y ) return y < p.y;
		return z < p.z;
	}

	bool operator == ( const point &p ) const {
		return x == p.x && y == p.y && z == p.z;
	}

} P[MAXN];


int main() {

	scanf( "%d", &N );
	REP( i, N )
		scanf( "%d %d %d", &P[i].x, &P[i].y, &P[i].z );

	REP( i, N ) {
		vector< point > V;
		REP( j, N ) {
			if ( j == i ) continue;
			point p( P[j].x - P[i].x, P[j].y - P[i].y, P[j].z - P[i].z );
			p.normalize();
			V.push_back( p );
		}
		sort( ALL( V ) );
		for ( int j = 0, k; j < V.size(); j = k ) {
			for ( k = j + 1; k < V.size() && V[k] == V[j]; k++ );
			cant[k - j + 1]++;
		}
	}

	for ( int i = 3; i <= N; i++ )
	    sol += cant[i] / i;

	printf( "%d\n", sol );

	return 0;
}
