/*
Alfonso2 Peterssen
SPOJ #185 "Chase"
22 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 3000,
	MAXE = 30000;

int T, V, L, A, B, E;
int discover_time;
int low[MAXV];
int dfsnum[MAXV];
bool in_cycle[MAXV];
int distA[MAXV];
int distB[MAXV];
int head[MAXV];
struct edge {
	int v, next;
} edges[MAXE];
stack< int > S;

void dfs( int u, int father ) {
	dfsnum[u] = low[u] = ++discover_time;
	S.push( u );
	for ( int e = head[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( v == father ) continue;
		if ( !dfsnum[v] ) {
			dfs( v, u );
			low[u] = min( low[u], low[v] );
		} else
		      low[u] = min( low[u], dfsnum[v] );
	}
	if ( dfsnum[u] == low[u] )
		if ( S.top() != u )
			for (;;) {
				int x = S.top();
				in_cycle[x] = true;
				S.pop();
				if ( x == u ) break;
			}
		else
		      S.pop();
}

void bfs( int src, int dist[] ) {
	fill( dist, dist + V, -1 );
	dist[src] = 0;
	queue< int > Q;
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( dist[v] == -1 ) {
				dist[v] = dist[u] + 1;
				Q.push( v );
			}
		}
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;
		discover_time = 0;
		memset( head, -1, sizeof( head ) );
		memset( dfsnum, 0, sizeof( dfsnum ) );
		memset( in_cycle, 0, sizeof( in_cycle ) );

		scanf( "%d %d", &V, &L );
		scanf( "%d %d", &A, &B );
		A--; B--;
		REP( i, L ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			edges[E++] = (edge){ v, head[u] }; head[u] = E - 1;
			edges[E++] = (edge){ u, head[v] }; head[v] = E - 1;
		}
		
		dfs( 0, -1 );
		bfs( A, distA );
		bfs( B, distB );
		
		int sol = 0;
		REP( i, V )
			if ( distA[i] < distB[i] ) {
				sol = max( sol, distB[i] );
				if ( in_cycle[i] ) {
					sol = -1;
					break;
				}
			}

		if ( sol == -1 )
		      printf( "No\n" );
		else
			printf( "%d\n", sol );
	}

	return 0;
}
