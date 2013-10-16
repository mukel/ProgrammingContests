/*
Alfonso2 Peterssen (mukel)
19 - 2 - 2009
SPOJ #3693 "Maximum Sum"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) for ( int i = (b); i <= (e); i++ )

typedef pair< int, int > par;

const int MAXN = 100005;

int N, Q;
int val[MAXN];
par T[4 * MAXN];
par qlo, qhi, ans;

par join( par A, par B ) {
	if ( val[ B.first ] > val[ A.first ] ) swap( A, B );
	return make_pair( A.first, val[ A.second ] > val[ B.first ] ? A.second : B.first );
}

void build( int x, int lo, int hi ) {

	if ( lo == hi ) {
		T[x].first = lo;
		return ;
	}
	
	int mid = ( lo + hi ) / 2;
	build( 2 * x + 1, lo, mid );
	build( 2 * x + 2, mid + 1, hi );

	T[x] = join( T[2 * x + 1], T[2 * x + 2] );
}

void update( int x, int lo, int hi, int pos ) {
	if ( lo > pos || hi < pos || lo > hi )
	      return ;
	      
	if ( lo == hi ) return ;
	
	int mid = ( lo + hi ) / 2;
	update( 2 * x + 1, lo, mid, pos );
	update( 2 * x + 2, mid + 1, hi, pos );
	
	T[x] = join( T[2 * x + 1], T[2 * x + 2] );
}

void query( int x, int lo, int hi, int start, int end ) {
	if ( lo > end || hi < start || lo > hi )
	      return ;
	      
	if ( lo >= start && hi <= end ) {
		ans = join( ans, T[x] );
		return ;
	}
	
	int mid = ( lo + hi ) / 2;
	query( 2 * x + 1, lo, mid, start, end );
	query( 2 * x + 2, mid + 1, hi, start, end );
}

int main() {

	scanf( "%d", &N );
	FOR( i, 1, N )
		scanf( "%d", &val[i] );

	val[0] = -(int)1e9; // sentinel
	build( 0, 1, N );

	scanf( "%d", &Q );
	while ( Q-- ) {
		char op[3];
		scanf( "%s", &op );
		if ( op[0] == 'U' ) {
			int pos, nval;
			scanf( "%d %d", &pos, &nval );
			
			val[pos] = nval;
			update( 0, 1, N, pos );
		} else {

			int lo, hi;
			scanf( "%d %d", &lo, &hi );

			ans = make_pair( 0, 0 );
			query( 0, 1, N, lo, hi );
			
			printf( "%d\n", val[ ans.first ] + val[ ans.second ] );
		}
	}

	return 0;
}
