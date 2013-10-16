/*
Alfonso2 Peterssen
SPOJ #264 "Corporative Network"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using std::abs;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

extern unsigned int _stklen = 1000000;

const int MAXN = 20000;

int T, N;
int dist[MAXN];
int father[MAXN];

int query( int x ) {
	if ( father[x] != x ) {
		int y = father[x];
		father[x] = query( y );
		dist[x] += dist[y];
	}
	return father[x];
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		
		REP( i, N ) dist[i] = 0, father[i] = i;
		
		for (;;) {
			char cmd[5];
			scanf( "%s", &cmd );
			if ( cmd[0] == 'O' ) break;
			if ( cmd[0] == 'I' ) {
				int u, v;
				scanf( "%d %d", &u, &v );
				u--; v--;
				dist[u] = abs( u - v ) % 1000;
			      father[u] = v;
			}
			if ( cmd[0] == 'E' ) {
				int u;
				scanf( "%d", &u );
				u--;
				query( u );
				printf( "%d\n", dist[u] );
			}
		}
	}

	return 0;
}
