/*
Alfonso2 Peterssen (mukel)
29 - 12 - 2008
USACO DEC08 "Winning Checkers"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int MAXN = 600;
const int mov[4][2] = {{-2,-2},{-2,2},{2,2},{2,-2},};

int N;
int checkers;
int pass;
char mat[MAXN][MAXN];
int edge[MAXN][MAXN][4];
vector< pair< int, int > > path;

bool eulerize( int x, int y ) {
	REP( i, 4 )
		if ( edge[x][y][i] != 0 && edge[x][y][i] != pass ) {
			int nx = x + mov[i][0];
			int ny = y + mov[i][1];
			edge[x][y][i] = pass;
			edge[nx][ny][(i+2)%4] = pass;
			if ( !eulerize( nx, ny ) )
			      return false;
		}

	if ( !path.empty() &&
		( abs( path.back().first - x ) != 2 ||
		abs( path.back().second - y ) != 2 ) )
		return false;

	path.push_back( make_pair( x, y ) );

	return true;
}

void set_edges( int x, int y, int value = -1 ) {
	REP( i, 4 ) {
		int nx = x + mov[i][0];
		int ny = y + mov[i][1];
		if ( nx < 0 || nx >= N || ny < 0 || ny >= N || mat[nx][ny] != '+' )
		      continue;
		if ( mat[x + mov[i][0] / 2][y + mov[i][1] / 2] != 'o' )
		      continue;
		edge[x][y][i] = value;
		edge[nx][ny][(i+2)%4] = value;
	}
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		scanf( "%s", &mat[i] );
		checkers += count( mat[i], mat[i] + N, 'o' );
	}

	// build graph
	REP( x, N )
	REP( y, N )
		if ( mat[x][y] == '+' )
			set_edges( x, y );

	REP( x, N )
	REP( y, N )
		if ( mat[x][y] == 'K' ) {
			pass++;
			// add edges
			set_edges( x, y );
			path.clear();
			if ( eulerize( x, y ) && path.size() == checkers + 1 ) {
				REPD( i, path.size() )
				      printf( "%d %d\n", path[i].first + 1, path[i].second + 1 );
				exit( 0 );
			}
			// delete edges
			set_edges( x, y, 0 );
		}

	printf( "impossible\n" );

	return 0;
}
