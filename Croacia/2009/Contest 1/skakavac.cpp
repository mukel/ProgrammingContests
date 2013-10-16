/*
Alfonso2 Peterssen (mukel)
20 - 1 - 2009
COCI 2009 Contest 1 SKAKAVAC
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 1500;

int N, X, Y;
int cant;
pair< int, int > bestX[MAXN][5];
pair< int, int > bestY[MAXN][5];
int ans[MAXN * MAXN];
struct box {
	int val, x, y;
	bool operator < ( const box& b ) const {
		return val < b.val;
	}
} B[MAXN * MAXN];

int query( pair< int, int > best[], int lo, int hi ) {
	REP( i, 4 )
	      if ( best[i].second < lo || best[i].second > hi )
			return best[i].first;
	return 0;
}

void update( pair< int, int > best[], int pos, int val ) {
	best[4] = make_pair( val, pos );
	sort( best, best + 5 );
	reverse( best, best + 5 );
}

int main() {

	scanf( "%d %d %d", &N, &X, &Y );
	X--; Y--;
	
	REP( i, N )
	REP( j, N ) {
		int val;
		scanf( "%d", &val );
		B[cant++] = (box){ val, i, j };
	}
	
	sort( B, B + cant );
	REP( i, cant ) {
		for ( int j = i; j < cant && B[j].val == B[i].val; j++ ) {
			int x = B[j].x;
			int y = B[j].y;
			if ( x > 0 ) ans[j] = max( ans[j], query( bestX[x - 1], y - 1, y + 1 ) );
			if ( y > 0 ) ans[j] = max( ans[j], query( bestY[y - 1], x - 1, x + 1 ) );
			if ( x + 1 < N ) ans[j] = max( ans[j], query( bestX[x + 1], y - 1, y + 1 ) );
			if ( y + 1 < N ) ans[j] = max( ans[j], query( bestY[y + 1], x - 1, x + 1 ) );
			if ( ans[j] > 0 || ( x == X && y == Y ) )
			      ans[j]++;
		}

		for ( int j = i; j < cant && B[j].val == B[i].val; i = j, j++ ) {
			int x = B[j].x;
			int y = B[j].y;
			update( bestX[x], y, ans[j] );
			update( bestY[y], x, ans[j] );
		}
	}
		
	printf( "%d\n", *max_element( ans, ans + cant ) );

	return 0;
}
