/*
Alfonso2 Peterssen
SPOJ #301 "Booklets"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 3000;

int T, S, X, N;
int value[MAXN];

struct val_cmp {
	bool operator () ( const int& i, const int& j ) const {
		return value[i] > value[j];
	}
};

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		priority_queue< int, vector< int >, val_cmp > Q;

		scanf( "%d %d %d", &S, &X, &N );
		REP( i, N ) {
			scanf( "%d", &value[i] );
			Q.push( i );
		}
		
		REP( i, S ) {
			int cant = N / S;
			if ( i + cant * S < N )
				cant++;
			
			int first = N;
			REP( j, cant ) {
				int x = Q.top(); Q.pop();
				first = min( first, x );
			}
			
			if ( i == X ) {
				printf( "%d\n", value[first] );
				break;
			}
		}
	}

	return 0;
}
