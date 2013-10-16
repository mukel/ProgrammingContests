/*
Alfonso2 Peterssen
SPOJ #2737 "Perfect Rhyme"
21 - 9 - 2008
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXNODES = 7500000,
	MAXW = 250000,
	oo = (int)1e9;

int W, sol;
string words[MAXW];
char line[40];
struct Trie {

	int V, E;
	int head[MAXNODES];
	int idx[MAXNODES];
	int best[MAXNODES];
	struct edge {
		int v, letter, next;
	} edges[MAXNODES];

	void reset() {
		V = E = 0;
		memset( head, -1, sizeof( head ) );
		// add root
		idx[V++] = oo;
	}

	void add_edge( int u, int v, int letter ) {
		edges[E++] = (edge){ v, letter, head[u] };
		head[u] = E - 1;
	}

	// insert reversed word
	void Insert( string& st, int id ) {
		int root = 0;
		REPD( i, st.size() ) {
			int e = head[root];
			while ( e != -1 && edges[e].letter != st[i] )
			      e = edges[e].next;
			if ( e != -1 )
				root = edges[e].v;
			else {
				idx[V] = oo;
				add_edge( root, V, (int)st[i] );
				root = V;
				V++;
			}
		}
		idx[root] = id;
	}
	
	void DFS( int u ) {
		best[u] = idx[u];
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			DFS( v );
			best[u] = min( best[u], best[v] );
		}
	}
} S;

int main() {

	S.reset();
	for (;;) {
		gets( line );
		if ( !strlen( line ) ) break;
		words[W++] = line;
	}
	sort( words, words + W );
	
	REP( i, W )
		S.Insert( words[i], i );

	S.DFS( 0 );

	while ( scanf( "%s", &line ) != EOF ) {
		string st( line );
		
		int root = 0;
		REPD( i, st.size() ) {
			int e = S.head[root];
			while ( e != -1 && S.edges[e].letter != st[i] )
			      e = S.edges[e].next;
			if ( e != -1 )
			      root = S.edges[e].v;
			else {
				sol = S.best[root];
			      break;
			}
			if ( i == 0 )
			      sol = S.best[root];
		}

		if ( words[sol] == st ) {
			int kk = oo;
			
			root = 0;
			REPD( i, st.size() ) {
				int e = S.head[root];
				while ( e != -1 && S.edges[e].letter != st[i] )
				      e = S.edges[e].next;
			      root = S.edges[e].v;
				int val = oo;
			      if ( S.idx[root] != sol )
			            val = S.idx[root];
				for ( int e = S.head[root]; e != -1; e = S.edges[e].next ) {
					int v = S.edges[e].v;
					if ( S.best[v] != sol && S.best[v] < val )
						val = S.best[v];
				}
				if ( val != oo )
					kk = val;
			}
			sol = kk;
		}

		printf( "%s\n", words[sol].c_str() );
	}

	return 0;
}
