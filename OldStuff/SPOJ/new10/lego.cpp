/*
Alfonso2 Peterssen (mukel)
SPOJ #4198 "Lego"
22 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

#define ITER(c) typeof( (c).begin() )
#define FORALL( it, c ) for ( ITER(c) it = (c).begin(); it != (c).end(); it++ )
	
#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 1 << 17;

int N, ans;
int dad[MAXN];
struct evnt {
	int lo, hi, id, top;
};
map< int, vector< evnt > > M;

int FIND( int x ) {
	return ( x == dad[x] ) ? x : dad[x] = FIND( dad[x] );
}

void JOIN( int x, int y ) {
	x = FIND( x );
	y = FIND( y );
	if ( x != y ) {
		ans--;
		dad[x] = y;
	}
}

bool cmp_1( const evnt& a, const evnt& b ) {
	if ( a.hi != b.hi ) return a.hi < b.hi;
	return (a.top < b.top);
}

bool cmp_2( const evnt& a, const evnt& b ) {
	if ( a.lo != b.lo ) return a.lo > b.lo;
	return (a.top < b.top);
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		int x1, y1, x2, y2;
		scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
		M[y1].push_back( (evnt){ x1, x2, i, 1 } );
 		M[y2].push_back( (evnt){ x1, x2, i, 0 } );
	}

	ans = N;
	REP( i, N ) dad[i] = i;

	FORALL( it, M ) {
		vector< evnt >& V = (*it).second;
		vector< evnt > bot;
		
		// case 1
		bot.clear();
		sort( ALL( V ), cmp_1 );
		REP( i, V.size() ) {
			if ( V[i].top ) {
				REPD( j, bot.size() ) {
					if ( V[i].lo < bot[j].hi  )
					      JOIN( V[i].id, bot[j].id );
					else
					      break;
				}
			} else
			      bot.push_back( V[i] );
		}
		
 		// case 2
		bot.clear();
		sort( ALL( V ), cmp_2 );
		REP( i, V.size() ) {
			if ( V[i].top ) {
				REPD( j, bot.size() ) {
					if ( V[i].hi > bot[j].lo  )
					      JOIN( V[i].id, bot[j].id );
					else
					      break;
				}
			} else
			      bot.push_back( V[i] );
		}
	}

	printf( "%d\n", ans );

	return 0;
}
