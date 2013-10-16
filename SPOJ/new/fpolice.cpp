/*
Alfonso2 Peterssen
4 - 9 - 2008
SPOJ #1027 "Fool the Police"
*/
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef pair< int, int > par;

const int
	MAXN = 100,
	MAXM = 300,
	oo = (int)1e9;

int T, N, M;
int F[MAXN][MAXN];
int R[MAXN][MAXN];
int best[MAXM][MAXN];
set< par > S;

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d %d", &N, &M );
		REP( i, N )
		REP( j, N )
		      scanf( "%d", &F[i][j] );
		      
		REP( i, N )
		REP( j, N )
		      scanf( "%d", &R[i][j] );
		      
		REP( i, M + 1 )
		      fill( best[i], best[i] + N, oo );
		best[0][0] = 0;
		
		REP( i, M + 1 ) {

			REP( j, N ) {
				if ( i ) best[i][j] = min( best[i][j], best[i - 1][j] );
				S.insert( make_pair( best[i][j], j ) );
			}
			
			while ( !S.empty() ){
				par top = *S.begin();
				S.erase( S.begin() );
				REP( j, N ) {
			 		int nf = i + F[top.second][j];
					int nr = top.first + R[top.second][j];
					if ( nf <= M && nr < best[nf][j] )
						if ( nf == i ) {
						      S.erase( make_pair( best[nf][j], j ) );
						      best[nf][j] = nr;
							S.insert( make_pair( best[nf][j], j ) );
						} else
						      best[nf][j] = nr;
				}
			}
		}
		
		int ans = 0;
		REP( i, M + 1 )
		      if ( best[i][N - 1] < best[ans][N - 1] )
				ans = i;
		
		if ( best[ans][N - 1] == oo )
		      printf( "-1\n" );
		else
			printf( "%d %d\n", best[ans][N - 1], ans );
	}
	

	return 0;
}
