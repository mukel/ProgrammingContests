/*
Alfonso2 Peterssen (mukel)
7 - 1 - 2009
USACO NOV08 "Light Switching"
*/
#include <cstdio>
#include <algorithm>

using std::min;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) \
	for ( int i = (b); i <= (e); i++ )
	
#define FLIP( x , p ) \
	cant[ piece[x] ] += ((seq[x] ^= 1) ^ flip[ piece[x] ]) * 2 - 1;

const int
	MAXSQ = 400,
	MAXN = 110000;

int N, Q;
int sq;
int seq[MAXN];
int piece[MAXN];
int start[MAXSQ], end[MAXSQ];
int cant[MAXSQ];
int flip[MAXSQ];

int query( int lo, int hi ) {
	int last = piece[lo];
	int next = piece[hi];
	
	int ans = 0;
	if ( last == next ) {
		FOR( i, lo, hi )
			ans += seq[i] ^ flip[last];
		return ans;
	}
	
	FOR( i, last + 1, next - 1 )
		ans += cant[i];
	FOR( i, lo, end[last] )
		ans += seq[i] ^ flip[last];
	FOR( i, start[next], hi )
		ans += seq[i] ^ flip[next];
		
	return ans;
}

void update( int lo, int hi ) {
	int last = piece[lo];
	int next = piece[hi];
	
	if ( last == next ) {
		FOR( i, lo, hi )
			FLIP( i );
		return ;
	}
	
	FOR( i, last + 1, next - 1 ) {
		flip[i] ^= 1;
		cant[i] = (end[i] - start[i] + 1) - cant[i];
	}
	FOR( i, lo, end[last] )
		FLIP( i );
	FOR( i, start[next], hi )
		FLIP( i );
}

int main() {

	scanf( "%d %d", &N, &Q );
	
	while ( sq * sq < N ) sq++;
	REP( i, sq ) {
		start[i] = i * sq;
		end[i] = min( N - 1, start[i] + sq - 1 );
		FOR( j, start[i], end[i] )
			piece[j] = i;
	}
	
	while ( Q-- ) {
		int op, lo, hi;
		scanf( "%d %d %d", &op, &lo, &hi );
		lo--; hi--;
		if ( op )
			printf( "%d\n", query( lo, hi ) );
		else
			update( lo, hi );
	}

	return 0;
}
