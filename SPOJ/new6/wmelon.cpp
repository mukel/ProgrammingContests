/*
Alfonso2 Peterssen
SPOJ #274 "Johnny and the Watermelon Plantation"
30 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 1000;

int T, N, K;
int cx[MAXN], CX;
int cy[MAXN], CY;
struct wmelon {
	int x, y, k;
	bool operator < ( const wmelon& w ) const { return y < w.y; }
};
list< wmelon > W, L;
typedef list< wmelon >::iterator lit;

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &N, &K );

		W.clear();
		
		REP( i, N ) {
			int x, y, k;
			scanf( "%d %d %d", &x, &y, &k );
			W.push_back( (wmelon){ x, y, k } );
			cx[i] = x;
			cy[i] = y;
		}
		
		sort( cx, cx + N ); CX = unique( cx, cx + N ) - cx;
		sort( cy, cy + N ); CY = unique( cy, cy + N ) - cy;
		
		if ( CY < CX ) {
			swap( CX, CY );
			REP( i, N ) swap( cx[i], cy[i] );
			lit it = W.begin();
			while ( it != W.end() ) {
				swap( (*it).x, (*it).y );
			      it++;
			}
		}
		
		W.sort();
		
		int sol = (int)1e9;
		REP( i, CX ) { // all x's must be >= cx[i]

			lit it = W.begin();
			while ( it != W.end() )
				if ( (*it).x < cx[i] ) {
					lit tmp = it;
					it++;
					W.erase( tmp );
				} else
				      it++;
				      
			L = W;
			for ( int j = CX - 1; j >= i; j-- ) {//all x's must be <= cx[j]

				int sum = 0;
				
				lit it = L.begin();
				lit lo = L.end();
				while ( it != L.end() )
					if ( (*it).x > cx[j] ) {
						lit tmp = it;
						it++;
						L.erase( tmp );
					} else {
						sum += (*it).k;
						if ( lo == L.end() ) lo = L.begin();
						while ( sum - (*lo).k >= K ) {
							sum -= (*lo).k;
							lo++;
						}
//						printf( "%d %d - %d %d\n", cx[j], cx[i], (*it).y, (*lo).y );
						if ( sum >= K )
						      sol = min( sol, ( cx[j] - cx[i] ) * ( (*it).y - (*lo).y ) );
					      it++;
					}
			}
		}
	
		printf( "%d\n", sol );
	}

	return 0;
}
