/*
Alfonso2 Peterssen (mukel)
SPOJ #4305 "Drilling"
6 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>

using std::max;

const int
	MAXN = 1 << 11,
	oo = (int)1e9;

int N;
int S[MAXN];
int best[MAXN][MAXN];
int from[MAXN][MAXN];

int solve( int lo, int hi ) {

	int& ans = best[lo][hi];
	int& frm = from[lo][hi];
	if ( frm )
	      return ans;

	if ( lo > hi ) {
		ans = 0;
		frm = lo;
		return ans;
	}

	if ( lo == hi ) {
		ans = S[lo];
		frm = lo;
		return ans;
	}

	ans = oo;
	
	// take S[hi]
	int ra = solve( lo, hi - 1 );
	int rf = from[lo][hi - 1];

	int tmp = max( solve( lo, rf - 1 ), solve( rf + 1, hi ) ) + S[rf];
	if ( tmp < ans ) {
		ans = tmp;
		frm = rf;
	}

	if ( tmp == ra )
		return ans;

	// take S[lo]
	int la = solve( lo + 1, hi );
	int lf = from[lo + 1][hi];

	tmp = max( solve( lo, lf - 1 ), solve( lf + 1, hi ) ) + S[lf];
	if ( tmp < ans ) {
		ans = tmp;
		frm = lf;
	}

	if ( tmp == la )
		return ans;

	for ( int k = lo; k <= hi; k++ ) {
		int tmp = max( solve( lo, k - 1 ), solve( k + 1, hi ) ) + S[k];
		if ( tmp < ans ) {
			ans = tmp;
			frm = k;
		}
	}

	return ans;
}

int main() {

	scanf( "%d", &N );
	for ( int i = 1; i <= N; i++ )
	      scanf( "%d", &S[i] );

	printf( "%d\n", solve( 1, N ) );

	return 0;
}
