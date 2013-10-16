/*
Alfonso2 Peterssen (mukel)
15 - 2 - 2009
SPOJ #2321 "Segments"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
	
#define ALL( c ) (c).begin(), (c).end()

const int
	MAXN = 400,
	MAXV = 2 * MAXN,
	MAXE = 3 * MAXV;

int N, V, E;
vector< int > pnts;
pair< int, int > S[MAXN];
int dist[MAXV];
struct edge {
	int u, v, w;
} edges[MAXE];

bool negativeCycle( int cost ) {
	REP( i, N )
	      edges[i].w = cost;
	      
	fill( dist, dist + V, 0 );

	REP( i, V + 1 ) {
		bool update = false;
		REP( i, E ) {
			int u = edges[i].u;
			int v = edges[i].v;
			int w = edges[i].w;
			if ( dist[u] + w < dist[v] ) {
				dist[v] = dist[u] + w;
				update = true;
			}
		}
		if ( !update )
		      return false;
	}

	return true;
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		int lo, hi;
		scanf( "%d %d %*d", &lo, &hi );
		S[i] = make_pair( lo, hi );
		pnts.push_back( lo );
		pnts.push_back( hi );
	}
	
	sort( ALL( pnts ) );
	pnts.erase( unique( ALL( pnts ) ), pnts.end() );
	
	V = 2 * pnts.size();
	
	REP( i, N ) {
		int lo, hi;
		lo = lower_bound( ALL( pnts ), S[i].first ) - pnts.begin();
		hi = lower_bound( ALL( pnts ), S[i].second ) - pnts.begin();
		S[i].first = lo * 2;
		S[i].second = hi * 2 - 1;
	}
	
	REP( i, N ) {
		int u, v;
		u = S[i].first;
		v = S[i].second;
		edges[E++] = (edge){ u, v, 0 };
	}
	
	REP( i, N ) {
		int u, v;
		u = S[i].second;
		v = S[i].first;
		edges[E++] = (edge){ u, v, -1 };
	}

	REP( i, V ) {
		int u, v;
		u = i + 1;
		v = i;
		edges[E++] = (edge){ u, v, 0 };
	}
	
	int lo = 0, hi = N;
	while ( lo <= hi ) {
		int mid = ( lo + hi ) / 2;
		if ( !negativeCycle( mid ) )
		      hi = mid - 1;
		else
		      lo = mid + 1;
	}
	
	printf( "%d\n", hi + 1 );

	return 0;
}
