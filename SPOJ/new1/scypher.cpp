/*
Alfonso2 Peterssen
SPOJ #44 "Substitution Cipher"
10 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXL = 30,
	MAXK = 1000,
	MAXN = 1000000,
	MAXLEN = 2000;

int T, L, K;
int cant;
char msg[MAXN];
int order[MAXL];
int rank[MAXL];
bool mark[MAXL];
char words[MAXK][MAXLEN];
char code[256];
vector< int > G[MAXL];

void solve( int lo, int hi, int pos ) {
	if ( lo == hi ) return ;
	for ( int i = lo, j; i <= hi; i = j ) {
		for ( j = i + 1; j <= hi && words[j][pos] == words[i][pos]; j++ );
		if ( words[i][pos] == '\0' ) continue;
		solve( i, j - 1, pos + 1 );
		if ( j <= hi ) {
			int u = words[i][pos] - 'a';
			int v = words[j][pos] - 'a';
			// u < v
			G[u].push_back( v );
		}
	}
}

void topsort( int x ) {
	mark[x] = true;
	REP( i, G[x].size() ) {
		int y = G[x][i];
		if ( !mark[y] )
		      topsort( y );
	}
	order[cant++] = x;
}

int main() {

	for ( scanf( "%d\n", &T ); T--; ) {

		REP( i, 256 )
			code[i] = i;
			
		scanf( "%d %d\n", &L, &K );
		REP( i, K )
		      scanf( "%s\n", &words[i] );
		gets( msg );

		REP( i, L ) G[i].clear();

		solve( 0, K - 1, 0 );
		
		cant = 0;
		memset( mark, 0, sizeof( mark ) );
		REP( i, L )
		      if ( !mark[i] )
		            topsort( i );

		reverse( order, order + cant );

		memset( rank, 0, sizeof( rank ) );
		REPD( i, cant ) {
			int u = order[i];
			REP( j, G[u].size() ) {
				int v = G[u][j];
				rank[u] = max( rank[u], rank[v] + 1 );
			}
		}
		
		if ( rank[ order[0] ] != L - 1 ) {
			printf( "Message cannot be decrypted.\n" );
			continue;
		}

		REP( i, cant )
		      code[ order[i] + 'a' ] = i + 'a';

		int N = strlen( msg );
		REP( i, N )
		      printf( "%c", code[ msg[i] ] );
		printf( "\n" );
	}

	return 0;
}
