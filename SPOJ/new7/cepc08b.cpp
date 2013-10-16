/*
Alfonso2 Peterssen (mukel)
25 - 1 - 2009
SPOJ #3459 "SkyScrapers"
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef pair< int, int > elem;

const int
	MAXN = 1000000,
	MAXQ = 1000000;

int T, N, Q;
int cant;
int data[MAXN];
int used[MAXN];
int level[MAXQ];
int ans[MAXQ];
priority_queue< elem > PQ;

int FIND( int x ) {
	return ( data[x] < 0 ) ? x : data[x] = FIND( data[x] );
}

void JOIN( int x, int y ) {
	x = FIND( x );
	y = FIND( y );
	if ( x != y ) {
		if ( data[y] < data[x] )
		      swap( x, y );
		data[y] += data[x];
		data[x] = y;
		cant--;
	}
}

/* Fast IO */
int next_int() {
	register int res = 0;
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) < '0' );
	do {
		res *= 10;
		res += ( ch - '0' );
	} while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
	return res;
}


int main() {

	T = next_int();
	while ( T-- ) {

		// clear
		while ( !PQ.empty() ) PQ.pop();

		N = next_int();
		Q = next_int();
		//scanf( "%d %d", &N, &Q );
		REP( i, N ) {
			int height = next_int();
			//scanf( "%d", &height );
			PQ.push( make_pair( height, i ) );
			data[i] = -1;
			used[i] = false;
		}
		
		REP( i, Q ) level[i] = next_int();
		      //scanf( "%d", &level[i] );
		      
		cant = 0;
		REPD( i, Q ) {
			while ( !PQ.empty() ) {
				pair< int, int > top = PQ.top();
				if ( top.first > level[i] ) {
					PQ.pop();
					cant++;
					used[top.second] = true;
					if ( top.second > 0 && used[top.second - 1] )
					      JOIN( top.second, top.second - 1 );
					if ( top.second < N - 1 && used[top.second + 1] )
					      JOIN( top.second, top.second + 1 );
				} else
				      break;
			}
			ans[i] = cant;
		}
		
		REP( i, Q )
		      printf( "%d\n", ans[i] );
	}

	return 0;
}
