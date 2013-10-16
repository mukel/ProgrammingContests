/*
Alfonso2 Peterssen
SPOJ SEQ5
30 - 9 - 2008
*/
#include <cstdio> // for getc_unlocked

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef unsigned int uint;

const int MAXN = 1 << 21;

int N, L, R;
long long sol;
int seq[MAXN];
int lo, hi;
int diffL, cantL[MAXN];
int diffR, cantR[MAXN];

#define getc_unlocked( x ) getchar()

uint next_int() {
	register uint res = 0;
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) < '0' ) {}
	do {
		res *= 10;
		res += ( ch - '0' );
	} while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
	return res;
}

struct hash_set {
	const static int
		MAXLEN = 2000003;
	int L;
	int head[MAXLEN];
	struct link {
		uint val, id, next;
	} links[MAXN];

	int insert( uint val ) {
		int idx = val % MAXLEN;
		for ( int e = head[idx]; e > 0; e = links[e].next )
			if ( val == links[e].val ) return links[e].id;
		L++;
		links[L] = (link){ val, L, head[idx] };
		head[idx] = L;
		return links[L].id;
	}
} H;

int main() {

	N = next_int();
	L = next_int();
	R = next_int();
	
	REP( i, N ) {
		uint x = next_int();
	      seq[i] = H.insert( x );
	}
		
	REP( i, N ) {
		// fix lo
		while ( diffL < L && lo < N + 1 ) {
			if ( lo < N ) {
				if ( cantL[ seq[lo] ] == 0 ) diffL++;
				cantL[ seq[lo] ]++;
			} else
			      diffL++;
			lo++;
		}
		
		// fix hi
		while ( diffR <= R && hi < N + 1 ) {
			if ( hi < N ) {
				if ( cantR[ seq[hi] ] == 0 ) diffR++;
				cantR[ seq[hi] ]++;
			} else
			      diffR++;
			hi++;
		}

		sol += hi - lo;
			
		if ( cantR[ seq[i] ] == 1 )
		      diffR--;
	      cantR[ seq[i] ]--;
	      
		if ( cantL[ seq[i] ] == 1 )
		      diffL--;
	      cantL[ seq[i] ]--;
	}
	
	printf( "%lld\n", sol );

	return 0;
}
