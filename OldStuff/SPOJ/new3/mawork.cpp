/*
Alfonso2 Peterssen
SPOJ #135 "Men at work"
15 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXN = 27,
	MAXD = 10000; // FIX this
	
const int mov[5][2] =
	{{0,0},{-1,0},{0,-1},{0,1},{1,0}};

int T, N;
char board[MAXN][MAXN];
char schdl[MAXN][MAXN];
int dist[MAXN][MAXN];
bool mark[MAXN][MAXN][MAXD];
struct state {
	int x, y, time;
};

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		REP( i, N )
		      scanf( "%s", &board[i] );
		      
		REP( i, N )
		      scanf( "%s", &schdl[i] );

		memset( mark, 0, sizeof( mark ) );
		memset( dist, -1, sizeof( dist ) );
		mark[0][0][0] = true;
		dist[0][0] = 0;
		      
		queue< state > Q;
		for ( Q.push( (state){ 0, 0, 0 } ); !Q.empty(); Q.pop() ) {
			state top = Q.front();
			if ( top.x == N - 1 && top.y == N - 1 )
				break;
			REP( i, 5 ) {
				int nx = top.x + mov[i][0];
				int ny = top.y + mov[i][1];
				int nt = top.time + 1;
				
				if ( nx < 0 || nx >= N || ny < 0 || ny >= N )
				      continue;
				      
				if ( dist[nx][ny] != -1 && nt - dist[nx][ny] >= MAXD )
				      continue;
				      
				if ( mark[nx][ny][nt - dist[nx][ny]] )
				      continue;
				      
				if ( schdl[nx][ny] == '0' ) {
                              if ( board[nx][ny] == '*' )
					      continue;
				} else {
					int per = nt / ( schdl[nx][ny] - '0' );
					// 0 same state
					// 1 opposite state
					if (
					( per % 2 == 0 && board[nx][ny] == '*' ) ||
					( per % 2 == 1 && board[nx][ny] == '.' ) )
						continue;
				}
				      
				if ( dist[nx][ny] == -1 )
					dist[nx][ny] = nt;

				mark[nx][ny][nt - dist[nx][ny]] = true;
				Q.push( (state){ nx, ny, nt } );
			}
		}
		
		if ( dist[N - 1][N - 1] != -1 )
		      printf( "%d\n", dist[N - 1][N - 1] );
		else
		      printf( "NO\n" );
	}

	return 0;
}
