/*
Alfonso2 Peterssen (mukel)
SPOJ #4201 "Coder Ratings"
22 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef pair< int, int > par;

const int MAXN = 1 << 19;

int N;
int idx[MAXN];
int T[MAXN];
par score[MAXN];
map< par, int > ans, cnt;

bool rating_cmp( const int& i, const int& j ) {
	return score[i] < score[j];
}

inline int lobit( int x ) { return x & -x; }

int query( int x ) {
	int ans = 0;
	for ( ; x > 0; x -= lobit( x ) )
	      ans += T[x];
	return ans;
}

void update( int x, int val ) {
	for ( ; x < MAXN; x += lobit( x ) )
	      T[x] += val;
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		int x, y;
		scanf( "%d %d", &x, &y );
		score[i] = make_pair( x, y );
		cnt[ score[i] ]++;
		idx[i] = i;
	}
	
	sort( idx, idx + N, rating_cmp );
	
	REP( i, N ) {
		int id = idx[i];
		ans[ score[id] ] = query( score[id].second );
		if ( score[id] != score[ idx[i + 1] ] )
			update( score[id].second, cnt[ score[id] ] );
	}
	
	REP( i, N )
	      printf( "%d\n", ans[ score[i] ] );

	return 0;
}
