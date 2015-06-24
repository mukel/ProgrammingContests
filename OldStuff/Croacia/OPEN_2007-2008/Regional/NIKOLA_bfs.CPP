/*
Alfonso Alfonso Peterssen
TASK: NIKOLA
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1000;

typedef pair< int, int > par;

int n, i, next, sol;
int fee[MAXN];
int cost[MAXN][MAXN];
queue< par > Q;

int main() {

	scanf( "%d", &n );
	for ( i = 0; i < n; i++ )
		scanf( "%d", &fee[i] );

	for ( i = 0; i < n; i++ )
		fill( cost[i], cost[i] + n, ( 1 << 29 ) );

	cost[0][0] = 0;
	Q.push( make_pair( 0, 0 ) );
	while ( !Q.empty() ) {

		int square = Q.front().first;
		int jumps  = Q.front().second;
		Q.pop();

		next = square + jumps + 1;
		if ( next < n ) {
			if ( cost[square][jumps] + fee[next] <
			     cost[next][jumps + 1] ) {
				 cost[next][jumps + 1] = cost[square][jumps] + fee[next];
				 if ( jumps + 1 < n )
        			 Q.push( make_pair( next, jumps + 1 ) );
			}
		}

		next = square - jumps;
		if ( next >= 0 ) {
			if ( cost[square][jumps] + fee[next] <
			     cost[next][jumps] ) {
				 cost[next][jumps] = cost[square][jumps] + fee[next];
                 Q.push( make_pair( next, jumps ) );
			}
		}
	}

	sol = *min_element( cost[n - 1], cost[n - 1] + n );
	printf( "%d\n", sol );
	fflush( stdout );

	return 0;
}
