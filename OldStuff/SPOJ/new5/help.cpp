/*
Alfonso2 Peterssen
SPOJ #386 "Help the problem setter"
22 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
typedef long long int64;

const int MAXN = 60;

int N;
int L[MAXN];
int R[MAXN];
int64 sol[MAXN];
bool mark[MAXN];

void dfs( int x ) {
	sol[x] = 1LL;
	if ( L[x] != -2 ) { dfs( L[x] ); sol[x] += 2 * sol[ L[x] ] - 1; }
	if ( R[x] != -2 ) { dfs( R[x] ); sol[x] += 2 * sol[ R[x] ] - 1; }
}

int main() {

	for(;;) {
		scanf( "%d", &N ); if ( !N ) break;
		memset( mark, 0, sizeof( mark ) );
		REP( i, N ) {
			scanf( "%d %d", &L[i], &R[i] );
			L[i]--;
			R[i]--;
			if ( L[i] != -2 ) mark[ L[i] ] = true;
			if ( R[i] != -2 ) mark[ R[i] ] = true;
		}
		
		REP( i, N )
		      if ( !mark[i] ) {
				dfs( i );
				break;
			}
			
		REP( i, N )
		      printf( i < N - 1 ? "%lld " : "%lld\n", sol[i] );
	}

	return 0;
}
