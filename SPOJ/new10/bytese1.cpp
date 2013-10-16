/*
Alfonso2 Peterssen (mukel)
SPOJ #3920 "Lucius Dungeon"
19 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXC = 100,
	oo = (int)1e9;
	
const int mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int T, F, C;
int x, y, bomb;
int mat[MAXC][MAXC];
int dist[MAXC][MAXC];

void dijkstra( int srcx, int srcy ) {
	REP( i, F )
	REP( j, C )
	      dist[i][j] = oo;

	dist[srcx][srcy] = mat[srcx][srcy];
	set< pair< int, pair< int, int > > > S;
	S.insert( make_pair( dist[srcx][srcy], make_pair( srcx, srcy ) ) );

	while ( !S.empty() ) {
		int x = (*S.begin()).second.first;
 		int y = (*S.begin()).second.second;
 		S.erase( S.begin() );
 		REP( i, 4 ) {
			int nx = x + mov[i][0];
  			int ny = y + mov[i][1];
  			if ( nx < 0 || nx >= F ) continue ;
      		if ( ny < 0 || ny >= C ) continue ;
      		if ( dist[x][y] + mat[nx][ny] >= dist[nx][ny] )
      		      continue ;
			if ( dist[nx][ny] != oo )
			      S.erase( make_pair( dist[nx][ny], make_pair( nx, ny ) ) );
			dist[nx][ny] = dist[x][y] + mat[nx][ny];
			S.insert( make_pair( dist[nx][ny], make_pair( nx, ny ) ) );
		}
	}
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &F, &C );
		REP( i, F )
		REP( j, C )
		      scanf( "%d", &mat[i][j] );

		scanf( "%d %d %d", &x, &y, &bomb );
		x--; y--;
		
		dijkstra( 0, 0 );
		
		if ( dist[x][y] > bomb )
		      printf( "NO\n" );
		else
		      printf( "YES\n%d\n", bomb - dist[x][y] );
	}

	return 0;
}
