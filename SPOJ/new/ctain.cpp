/*
Alfonso2 Peterssen
SPOJ #260 "Containers"
6 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 4;

int T, N;
struct state {
	char C[MAXN];
	int water_amount() {
		return accumulate( C, C + N, 0 );
	}
	bool operator < ( const state& s ) const {
		return lexicographical_compare( C, C + N, s.C, s.C + N );
	}
	bool operator == ( const state& s ) const {
		return equal( C, C + N, s.C );
	}
};
state first, target;
map< state, int > M;

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d", &N );
		REP( i, N ) {
			int x;
		      scanf( "%d", &x );
		      first.C[i] = x;
		}
		      
		REP( i, N ) {
			int x;
		      scanf( "%d", &x );
		      target.C[i] = x;
		}
		      
		int min_water = target.water_amount();
		
		if ( first < target || first.water_amount() < min_water ) {
			printf( "NO\n" );
			continue;
		}

		M.clear();

		queue< state > Q;
		for ( Q.push( first ); !Q.empty(); Q.pop() ) {
			state top = Q.front();
			int top_dist = M[top];

			/*REP( i, N )
				printf( "%d ", top.C[i] );
			printf( "\n" );
			*/
			
			if ( top == target )
				break;
				
			/*  */
			REP( i, N )
			REP( j, N ) {
				if ( i == j ) continue;
				state next = top;
				int kk = min( (int)next.C[i], first.C[j] - top.C[j] );
				next.C[i] -= kk;
				next.C[j] += kk;
				if ( M.find( next ) == M.end() ) {
					//printf( "insert\n" );
					M[next] = top_dist + 1;
					Q.push( next );
				}
			}
			
			/* drain */
			REP( i, N ) {
				state next = top;
				next.C[i] = 0;
				if ( next.water_amount() < min_water )
				      continue;
				if ( M.find( next ) == M.end() ) {
					//printf( "insert\n" );
					M[next] = top_dist + 1;
					Q.push( next );
				}
			}
		}
		
		if ( M.find( target ) == M.end() )
		      printf( "NO\n" );
		else
			printf( "%d\n", M[target] );
	}

	return 0;
}
