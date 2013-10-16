/*
Alfonso2 Peterssen (mukel)
made during contest...
USACO HOL09 "Holiday Painting"
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) \
	for ( int i = (b); i <= (e); i++ )

const int
	MAXF = 50001,
	MAXC = 16;

int F, C, Q;
char line[MAXC];
int S[MAXC][MAXF];
struct node {
	int diff, color;
	node() : color( -1 ) {}
} T[MAXC][4 * MAXF];

void update( int idx, int x, int lo, int hi, int start, int end, int color ) {
	if ( lo > end || hi < start || lo > hi )
		return ;

	if ( lo >= start && hi <= end ) {
		T[idx][x].color = color;
		if ( color == 1 )
			T[idx][x].diff = ( hi - lo + 1 ) - ( S[idx][hi] - S[idx][lo - 1] );
		else
		if ( color == 0 )
			T[idx][x].diff = S[idx][hi] - S[idx][lo - 1];
		return ;
	}

	int mid = ( lo + hi ) / 2;
	if ( T[idx][x].color != -1 ) {
		// Propagate
		update( idx, 2 * x + 1, lo, mid, lo, mid, T[idx][x].color );
		update( idx, 2 * x + 2, mid + 1, hi, mid + 1, hi, T[idx][x].color );
		T[idx][x].color = -1;
	}

	update( idx, 2 * x + 1, lo, mid, start, end, color );
	update( idx, 2 * x + 2, mid + 1, hi, start, end, color );

	if ( lo < hi )
		T[idx][x].diff =
			T[idx][2 * x + 1].diff +
			T[idx][2 * x + 2].diff;
}

int main() {

	scanf( "%d %d %d", &F, &C, &Q );
	FOR( i, 1, F ) {
		scanf( "%s", &line );
		REP( j, C )
			S[j][i] = S[j][i - 1] + ( line[j] == '1' );
	}

	REP( i, C )
		update( i, 0, 1, F, 1, F, 0 ); // Set all to 0

	while ( Q-- ) {
		int x1, y1, x2, y2, color;
		scanf( "%d %d %d %d %d", &x1, &x2, &y1, &y2, &color );
		y1--; y2--;

		FOR( i, y1, y2 )
			update( i, 0, 1, F, x1, x2, color );

		int ans = F * C;
		REP( i, C )
			ans -= T[i][0].diff;

		printf( "%d\n", ans );
	}

	return 0;
}
