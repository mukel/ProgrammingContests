/*
Alfonso2 Peterssen (mukel)
27 - 12 - 2008
USACO DEC08 "Secret Message"
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 500000;

int N, M;
int len, digit;
int nodes;
struct node {
	int next[2], cnt, match;
} T[MAXN];

int main() {

	scanf( "%d %d", &N, &M );
	REP( i, N ) {
		int root = 0;
		scanf( "%d", &len );
		while ( len-- ) {
			scanf( "%d", &digit );
			int& nxt = T[root].next[digit];
			if ( !nxt )
				nxt = ++nodes;
			root = nxt;
			T[root].cnt++;
		}
		T[root].match++;
	}

	REP( i, M ) {
		int root = 0, words = 0;
		scanf( "%d", &len );
		while ( len-- ) {
			scanf( "%d", &digit );
			if ( root == -1 )
				continue;
			words += T[root].match;
			root = T[root].next[digit];
			if ( !root )
				root = -1; // stop searching
		}
		printf( "%d\n", ( root == -1 ? 0 : T[root].cnt ) + words );
	}

	return 0;
}
