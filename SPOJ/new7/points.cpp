/*
Alfonso2 Peterssen (mukel)
16 - 1 - 2009
SPOJ #2533 "Point Nesting"
Domination Sets Algorithm
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
typedef pair< int, int > point;
typedef pair< int, point > point3D;
typedef set< point > domset;
	
const int MAXN = 100000;

int T, N;
point3D pnts[MAXN];
vector< domset > V;

bool codominates( const point& A, const point& B ) {
	return (A.first >= B.first) && (A.second >= B.second);
}

bool codominates( domset& S, const point& P ) {
	typeof( S.begin() ) it = S.upper_bound( P );
	if ( it != S.begin() ) { it--; if ( codominates( P, (*it) ) ) return true; }
	if ( it != S.begin() ) { it--; if ( codominates( P, (*it) ) ) return true; }
	return false;
}

void insert( domset& S, const point& P ) {
	typeof( S.begin() ) it = S.lower_bound( P );
	
	if ( it != S.begin() ) {
		typeof( it ) lo = it; lo--;
		if ( (*lo).second <= P.second )
		      return ;
	}
	
	while ( it != S.end() && (*it).second >= P.second )
	      S.erase( it++ );
	
	S.insert( P );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d", &N );
		REP( i, N ) {
			int x, y, z;
			scanf( "%d %d %d", &x, &y, &z );
			pnts[i] = point3D( x, point( y, z ) );
		}

		V.clear();
		sort( pnts, pnts + N );
		
		REP( i, N ) {
			int lo = 0, hi = V.size() - 1;
			while ( lo <= hi ) {
				int mid = ( lo + hi ) / 2;
				if ( codominates( V[mid], pnts[i].second ) )
				      lo = mid + 1;
				else
				      hi = mid - 1;
			}
		
			if ( lo == V.size() )
			      V.push_back( domset() );
		      
			insert( V[lo], pnts[i].second );
		}
	
		printf( "%d\n", V.size() );
	}

	return 0;
}
