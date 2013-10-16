/*
Alfonso2 Peterssen
22 - 5 - 2008
USACO OPEN08 Bronze "Munch"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <complex>

#define _NO_OLDNAMES 1
#include <cmath>

#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long int64;
typedef vector< int > array;
typedef vector< array > matrix;

/* fors++  */
#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = s; i <= (e); i++ )
#define FORD( i, s, e ) \
	for ( int i = (e); i >= (s); i-- )

/* containers */
#define ALL( c ) (c).begin(), (c).end()
#define VAR( x ) ( typeof(x) )
#define FOREACH( it, c ) \
	for ( VAR( (c).begin() ) it = (c).begin() ); it != (c).end(); it++ )

/* DEBUG */
#define DBG( x ) \
	cout << #x "=[" << (x) << "]" << endl;

const int MAXC = 200;
const int mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int F, C;
int x, y, nx, ny;
char mat[MAXC][MAXC];
int dist[MAXC][MAXC];
struct point {
    int x, y;
};
queue< point > Q;

int main() {

	freopen( "munch.in", "r", stdin );
	freopen( "munch.out", "w", stdout );

	scanf( "%d %d", &F, &C );
	REP( i, F ) {
	    scanf( "%s", &mat[i] );
	    REP( j, C )
	        if ( mat[i][j] == 'C' ) {
	            dist[i][j] = 1;
                Q.push( (point){ i, j } );
            }
    }

    /* BFS */
    while ( !Q.empty() ) {
        x = Q.front().x;
        y = Q.front().y;
        Q.pop();
        REP( i, 4 ) {
            nx = x + mov[i][0];
            ny = y + mov[i][1];
            if ( nx < 0 || nx >= F ||
                 ny < 0 || ny >= C )
                 continue;
            if ( mat[nx][ny] == '*' )
                continue;
            if ( dist[x][y] + 1 < dist[nx][ny] ||
                 dist[nx][ny] == 0 ) {
                dist[nx][ny] = dist[x][y] + 1;
                Q.push( (point){ nx, ny } );
            }                 
        }
    }

    REP( i, F )
    REP( j, C )
        if ( mat[i][j] == 'B' ) {
            printf( "%d\n", dist[i][j] - 1 );
            exit( 0 );
        }

	fflush( stdout );

	return 0;
}
