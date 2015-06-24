/*
Alfonso Alfonso Peterssen
TASK: NSENSOR
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXC = 400;
const int mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef pair< int, int > point;

int N, F, C, i, j, k;
int x, y, nx, ny;
int startX, startY, endX, endY;
int best[MAXC];
bool mark[MAXC][MAXC];
int cost[MAXC][MAXC];
int dist[MAXC][MAXC];
int from[MAXC][MAXC];
queue< point > Q;

bool ok( int x, int y ) {
    return ( x > 0 && x <= F && y > 0 && y <= C );
}

void print( int x, int y ) {
    if ( x == startX && y == startY )
        return ;
    print( x - mov[ from[x][y] ][0], y - mov[ from[x][y] ][1] );
    printf( "%d %d\n", x, y );
}

int main() {
/*
    freopen( "nsensor.in", "r", stdin );
    freopen( "nsensor.out", "w", stdout );
*/
    scanf( "%d %d", &F, &C );
    scanf( "%d %d", &startX, &startY );
    scanf( "%d %d", &endX, &endY );
    scanf( "%d", &N );

    memset( best, 63, sizeof( best ) );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        mark[x][y] = true;
        best[x] <?= y;
    }

    memset( cost, 63, sizeof( cost ) );
    cost[startX][startY] = 0;

    Q.push( make_pair( startX, startY ) );
    while ( !Q.empty() ) {

        x = Q.front().first;
        y = Q.front().second;
        Q.pop();

        for ( i = 0; i < 4; i++ ) {
            nx = x + mov[i][0];
            ny = y + mov[i][1];
            if ( !ok( nx, ny ) || mark[nx][ny] )
                continue;

            int newcost = cost[x][y];
            if ( i < 2 && best[x] > y )
                newcost++;

            if ( newcost < cost[nx][ny] ) {
                Q.push( make_pair( nx, ny ) );
                cost[nx][ny] = newcost;
                dist[nx][ny] = dist[x][y] + 1;
                from[nx][ny] = i;
            }
        }
    }

    printf( "%d\n", dist[endX][endY] );
    printf( "%d\n", cost[endX][endY] );
    print( endX, endY );

    fflush( stdout );

    return 0;
}
