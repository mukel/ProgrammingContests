/*
Alfonso2 Peterssen
SPOJ #413 "Word Puzzles"
16 - 9 - 2008
low memory, huge code
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int mov[8][2] = // in clockwise order starting in 'A'
	{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

const int
	MAXC = 1001,
	MAXW = 1000,
	MAXNODES = 1000001;

int T, F, C, W;
char st[MAXC];
char board[MAXC][MAXC];
struct pos {
	int x, y, dir;
} sol[MAXW];
struct Trie {

	int V, E;
	int where[MAXW];
	int head[MAXNODES];
	struct edge {
		int v, letter, next;
	} edges[MAXNODES];
	
	struct node {
		int fail, idx;
	} nodes[MAXNODES];
	
	void reset() {
		V = E = 0;
		memset( head, -1, sizeof( head ) );
		// add root
		nodes[V++] = (node){ 0, -1 };
	}
	
	void add_edge( int u, int v, int letter ) {
		edges[E++] = (edge){ v, letter, head[u] };
		head[u] = E - 1;
	}
	
	// insert reversed word
	void Insert( char* st, int idx ) {
		int len = strlen( st );
		int root = 0;
		REPD( i, len ) {

			int e = head[root];
			while ( e != -1 && edges[e].letter != st[i] )
			      e = edges[e].next;
			      
			if ( e != -1 )
				root = edges[e].v;
			else {
				nodes[V] = (node){ 0, -1 };
				add_edge( root, V, st[i] );
				root = V;
				V++;
			}
		}
		nodes[root].idx = idx;
		where[idx] = root;
	}
	
	int GetFail( int x, int ch ) {
		for (;;) {
			int e = head[x];
			while ( e != -1 && edges[e].letter != ch )
			      e = edges[e].next;
			if ( e != -1 )
			      return edges[e].v;
			if ( x == 0 )
			      return 0;
			x = nodes[x].fail;
		}
	}
	
	void BFS() {
		queue< int > Q;
		for ( Q.push( 0 ); !Q.empty(); Q.pop() ) {
			int u = Q.front();
			for ( int e = head[u]; e != -1; e = edges[e].next ) {
				int v = edges[e].v;
				if ( u == 0 )
					nodes[v].fail = 0;
				else
					nodes[v].fail = GetFail( nodes[u].fail, edges[e].letter );
					
				if ( nodes[v].idx == -1 )
				      nodes[v].idx = nodes[ nodes[v].fail ].idx;
					
				Q.push( v );
			}
		}
	}
} S;

void Search( int x, int y, int dir ) {
	int root = 0;
	while ( x >= 0 && x < F && y >= 0 && y < C ) {
		root = S.GetFail( root, board[x][y] );
		int idx = S.nodes[root].idx;
		while ( idx != -1 ) {
			sol[idx].x = x;
			sol[idx].y = y;
			sol[idx].dir = dir;
			idx = S.nodes[ S.nodes[ S.where[idx] ].fail ].idx;
		}
		x -= mov[dir][0];
		y -= mov[dir][1];
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		S.reset();

		scanf( "%d %d %d", &F, &C, &W );
		REP( i, F )
		      scanf( "%s", &board[i] );
		      
		REP( i, W ) {
			scanf( "%s", &st );
			S.Insert( st, i );
		}
		
		S.BFS();
		
		// Searching Phase
		REP( i, F ) {
			Search( i, 0, 5 ); // F
			Search( i, 0, 6 ); // G
			Search( i, 0, 7 ); // H
			
			Search( i, C - 1, 1 ); // B
			Search( i, C - 1, 2 ); // C
			Search( i, C - 1, 3 ); // D
		}

		REP( i, C ) {
			Search( 0, i, 7 ); // H
			Search( 0, i, 0 ); // A
			Search( 0, i, 1 ); // B
			
			Search( F - 1, i, 3 ); // D
			Search( F - 1, i, 4 ); // E
			Search( F - 1, i, 5 ); // F
		}

		REP( i, W )
		      printf( "%d %d %c\n", sol[i].x, sol[i].y, sol[i].dir + 'A' );
		      
		if ( T != 0 )
			printf( "\n" );
	}

	return 0;
}
