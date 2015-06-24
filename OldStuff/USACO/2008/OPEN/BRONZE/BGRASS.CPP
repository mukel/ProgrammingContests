/*
Alfonso2 Peterssen
22 - 5 - 2008
USACO OPEN08 Bronze "Bgrass"
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

int F, C, sol;
int cant;
char mat[MAXC][MAXC];
bool mark[MAXC][MAXC];

void dfs( int x, int y ) {
    cant++;
    mark[x][y] = true;
    REP( i, 4 ) {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        if ( nx < 0 || nx >= F ||
             ny < 0 || ny >= C )
             continue;
        if ( mark[nx][ny] )
            continue;
        if ( mat[nx][ny] == '#' )
            dfs( nx, ny );
    }
}

int main() {

	freopen( "bgrass.in", "r", stdin );
	freopen( "bgrass.out", "w", stdout );

	scanf( "%d %d", &F, &C );
	REP( i, F )
	    scanf( "%s", &mat[i] );

    REP( i, F )
    REP( j, C )
        if ( mat[i][j] == '#' &&
             !mark[i][j] ) {
            cant = 0;
            dfs( i, j );            
            if ( cant < 3 )
                sol++;
        }

    printf( "%d\n", sol );
	
	return 0;
}
