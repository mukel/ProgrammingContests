/*
Alfonso2 Peterssen
SPOJ #401 "Translations"
22 - 9 - 2008
graph isomorphism( from prefield ) with some hashing
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 25,
	MAXE = 250,
	MODULO = 1234567;

int N;
char st[1000];
string strA[MAXV];
string strB[MAXV];
string sol[MAXV];

struct graph {
	int V, E;
	int head[MAXV];
	int in_deg[MAXV];
	int ou_deg[MAXV];
	int adj[MAXV][MAXV];
	struct edge {
		int v, next;
	} edges[MAXE];
	
	void reset() {
		V = E = 0;
		memset( adj, 0, sizeof( adj ) );
		memset( head, -1, sizeof( head ) );
		memset( in_deg, 0, sizeof( in_deg ) );
		memset( ou_deg, 0, sizeof( ou_deg ) );
	}
	
	void insert( int u, int v ) {
		adj[u][v]++;
		ou_deg[u]++;
		in_deg[v]++;
		edges[E++] = (edge){ v, head[u] };
		head[u] = E - 1;
	}
	
} A, B;

struct thing {
	int idx, in_deg, ou_deg, hashV;
	bool operator < ( const thing& t ) const {
		if ( in_deg != t.in_deg ) return in_deg < t.in_deg;
		if ( ou_deg != t.ou_deg ) return ou_deg < t.ou_deg;
		if ( hashV != t.hashV ) return hashV < t.hashV;
		return idx < t.idx;
	}
	bool operator == ( const thing& t ) const {
		return
			in_deg == t.in_deg &&
			ou_deg == t.ou_deg &&
			hashV == t.hashV;
	}
} HA[MAXV], HB[MAXV];

int getHash( const graph& G, int u ) {
	int val1 = 1, val2 = 0;
	for ( int e1 = G.head[u]; e1 != -1; e1 = G.edges[e1].next ) {
		int v = G.edges[e1].v;
		val1 = ( val1 * ( G.in_deg[v] + G.ou_deg[v] ) ) % MODULO;
		for ( int e2 = G.head[v]; e2 != -1; e2 = G.edges[e2].next ) {
			int w = G.edges[e2].v;
			val2 = ( val2 + ( G.in_deg[w] * G.ou_deg[w] ) ) % MODULO;
		}
	}
	return ( val1 + val2 ) % MODULO;
}

bool comb( int x ) {
	if ( x == A.V ) return true;
	for ( int i = x; i < A.V && HB[i] == HA[x]; i++ ) {
		swap( HB[i], HB[x] );
		int u = HA[x].idx, v = HB[x].idx;
		for ( int j = 0; j <= x; j++ )
			if ( A.adj[u][ HA[j].idx ] != B.adj[v][ HB[j].idx ] ||
				A.adj[ HA[j].idx ][u] != B.adj[ HB[j].idx ][v] )
				goto esc;
		if ( comb( x + 1 ) )
			return true;
		esc:;
		swap( HB[i], HB[x] );
	}
	return false;
}

int main() {

	for (;;) {
		scanf( "%d", &N ); if ( !N ) break;
		
		A.reset();
		B.reset();
		map< string, int > idxA, idxB;
		
		REP( i, N ) {
			string word1, word2;
			scanf( "%s", &st ); word1 = st;
			scanf( "%s", &st ); word2 = st;
			if ( idxA.find( word1 ) == idxA.end() ) {
				strA[A.V] = word1;
			      idxA[word1] = A.V++;
			}
			if ( idxA.find( word2 ) == idxA.end() ) {
				strA[A.V] = word2;
			      idxA[word2] = A.V++;
			}
			A.insert( idxA[word1], idxA[word2] );
		}
		
		REP( i, N ) {
			string word1, word2;
			scanf( "%s", &st ); word1 = st;
			scanf( "%s", &st ); word2 = st;
			if ( idxB.find( word1 ) == idxB.end() ) {
				strB[B.V] = word1;
			      idxB[word1] = B.V++;
			}
			if ( idxB.find( word2 ) == idxB.end() ) {
				strB[B.V] = word2;
			      idxB[word2] = B.V++;
			}
			B.insert( idxB[word1], idxB[word2] );
		}

		REP( i, A.V ) {
			HA[i].idx = i;
			HA[i].in_deg = A.in_deg[i];
			HA[i].ou_deg = A.ou_deg[i];
			HA[i].hashV = getHash( A, i );
		}
		
		REP( i, B.V ) {
			HB[i].idx = i;
			HB[i].in_deg = B.in_deg[i];
			HB[i].ou_deg = B.ou_deg[i];
			HB[i].hashV = getHash( B, i );
		}
		
		sort( HA, HA + A.V );
		sort( HB, HB + B.V );

		assert( comb( 0 ) );

		REP( i, A.V )
		      sol[i] = strA[ HA[i].idx ] + "/" + strB[ HB[i].idx ];
		      
		sort( sol, sol + A.V );
		REP( i, A.V )
		      printf( "%s\n", sol[i].c_str() );
		      
		printf( "\n" );
	}

	return 0;
}
