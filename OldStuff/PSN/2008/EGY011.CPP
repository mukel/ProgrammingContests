/*
Alfonso Alfonso Peterssen
21 - 2 - 2008
CNC 2008 Task 2B "Sensor"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXF = 400; // ...
const int oo = 1 << 20;
const int mov[2][2][2] = {{{0,-1},{0,1}},{{-1,0},{1,0}}};

typedef pair< int, int > point;

FILE *fin = fopen( "sensor.in", "r" );
FILE *fout = fopen( "sensor.out", "w" );

int F, C, O, i, j, k;
int x, y;
int startX, startY, endX, endY;
bool blocked[MAXF][MAXF];
int dist[MAXF][MAXF];
int sensor[MAXF][MAXF];
point last[MAXF][MAXF];
queue< point > Q;

    void print_path( int x, int y ) {
        if ( x == startX && y == startY )
            return;
        print_path( last[x][y].first, last[x][y].second );
        fprintf( fout, "%d %d\n", x, y );
    }

int main() {

    fscanf( fin, "%d %d", &F, &C );
    fscanf( fin, "%d %d %d %d", &startX, &startY, &endX, &endY );
    fscanf( fin, "%d", &O );
    for ( i = 0; i < O; i++ ) {
        fscanf( fin, "%d %d", &x, &y );
        blocked[x][y] = true;
    }

    /* Init */
    for ( i = 1; i <= F; i++ ) {
        fill( dist[i], dist[i] + C + 1, oo );
        fill( sensor[i], sensor[i] + C + 1, oo );
    }

    /* BFS */
    dist[startX][startY] = 0;
    sensor[startX][startY] = 0;
    Q.push( make_pair( startX, startY ) );

    while ( !Q.empty() ) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();

        for ( i = 0; i < 2; i++ )
            for ( j = 0; j < 2; j++ ) {
                int nx = x + mov[i][j][0];
                int ny = y + mov[i][j][1];
                if ( nx <= 0 || nx > F ||
                    ny <= 0 || ny > C ||
                    blocked[nx][ny] )
                    continue;
                if ( sensor[x][y] + i < sensor[nx][ny] ) {
                    sensor[nx][ny] = sensor[x][y] + i;
                    dist[nx][ny] = dist[x][y] + 1;
                    last[nx][ny] = make_pair( x, y );
                    Q.push( make_pair( nx, ny ) );
                }
            }
    }

    fprintf( fout, "%d\n%d\n", dist[endX][endY], sensor[endX][endY] );
    print_path( endX, endY );

    fclose( fout );

    return 0;
}

