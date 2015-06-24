/*
Alfonso2 Peterssen
SPOJ #119 "Servers"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef pair< int, int > par;

const int
	MAXV = 30000,
	MAXE = 5 * MAXV,
	MAXR = 10,
	oo = (int)1e9;

int T, V, L, E;
int rank[MAXV];
int head[MAXV];
int best[MAXR][MAXV];
int mark[MAXV];
struct edge {
	int v, w, next;
} edges[2 * MAXE];
priority_queue< par, vector< par >, greater< par > > Q;

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;

		scanf( "%d %d", &V, &L );
		REP( i, V ) {
		     scanf( "%d", &rank[i] );
		     rank[i]--;
		     mark[i] = head[i] = -1;
		}
		
		REP( i, L ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			edges[E++] = (edge){ v, w, head[u] }; head[u] = E - 1;
			edges[E++] = (edge){ u, w, head[v] }; head[v] = E - 1;
		}

		REP( r, MAXR ) {
			REP( i, V )
				if ( rank[i] > r ) {
				     best[r][i] = 0;
				     Q.push( make_pair( best[r][i], i ) );
				} else
				     best[r][i] = oo;

			while ( !Q.empty() ) {
				int u = Q.top().second;
				int w = Q.top().first;
				Q.pop();
				if ( w > best[r][u] )
				      continue;
				for ( int e = head[u]; e != -1; e = edges[e].next ) {
					int v = edges[e].v;
					if ( w + edges[e].w < best[r][v] ) {
						best[r][v] = w + edges[e].w;
						Q.push( make_pair( best[r][v], v ) );
					}
				}
			}
		}

		int sol = 0;
		REP( i, V ) {
			Q.push( make_pair( 0, i ) );
			while ( !Q.empty() ) {
				int u = Q.top().second;
				int w = Q.top().first;
				Q.pop();
				if ( mark[u] == i )
					continue;
				else
					mark[u] = i;
				sol++;
				for ( int e = head[u]; e != -1; e = edges[e].next ) {
					int v = edges[e].v;
					if ( w + edges[e].w < best[ rank[i] ][v] )
						Q.push( make_pair( w + edges[e].w, v ) );
				}
			}
		}
		
		printf( "%d\n", sol );
	}

	return 0;
}
