/*
Alfonso2 Peterssen (mukel)
27 - 1 - 2009
SPOJ #187 "Flat broken lines"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef pair< int, int > point;

const int MAXN = 30000;

int T, N;
point pnts[MAXN];
vector< int > V;

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		V.clear();
		scanf( "%d", &N );
		REP( i, N ) {
			int x, y;
		      scanf( "%d %d", &x, &y );
		      pnts[i] = make_pair( x + y, x - y );
		}
		sort( pnts, pnts + N );
		REPD( i, N ) {
			int val = pnts[i].second;
			int lo = 0, hi = V.size() - 1;
			while ( lo <= hi ) {
				int mid = ( lo + hi ) / 2;
				if ( val > V[mid] )
				      lo = mid + 1;
				else
				      hi = mid - 1;
			}
			if ( lo == V.size() )
			      V.push_back( val );
			else
			      V[lo] = val;
		}
		printf( "%d\n", V.size() );
	}

	return 0;
}
