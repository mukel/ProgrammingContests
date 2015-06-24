/*
Alfonso Alfonso Peterssen
21 - 11 - 2007
COI 2004 Olympiad "NEVENKA"
*/
#include <iostream>
#include <queue>
using namespace std;

const int MAXV = 1001;

int V, E, H, C, P, i, j, k, p1, p2;
int max_dist;
int church[MAXV], pub[MAXV];
bool path[MAXV][MAXV];
int dist[MAXV][MAXV];

    void bfs( int src ) {

        queue< int > Q;
        fill( dist[src], dist[src] + V + 1, -1 );
        dist[src][src] = 0;

        for ( Q.push( src ); !Q.empty(); Q.pop() ) {
            int x = Q.front();
            for ( int y = 1; y <= V; y++ )
                if ( path[x][y] && dist[src][y] == -1 ) {
                    dist[src][y] = dist[src][x] + 1;
                    Q.push( y );
                }
        }
    }

int main() {

    cin >> V >> H;

    cin >> C;
    for ( i = 0; i < C; i++ )
        cin >> church[i];

    cin >> P;
    for ( i = 0; i < P; i++ )
        cin >> pub[i];

    cin >> E;
    for ( i = 0; i < E; i++) {
      cin >> j >> k;
      path[j][k] = path[k][j] = true;
    }

    for ( i = 0; i < C; i++ )
        bfs( church[i] );

    max_dist = 1000000000;
    for ( i = 0; i < P; i++ )
        for ( j = i + 1; j < P; j++ ) {

            int candy = -1000000000;
            for ( k = 0; k < C; k++ )
                candy >?= ( dist[ church[k] ][ pub[i] ] <?
                            dist[ church[k] ][ pub[j] ] ) - dist[ church[k] ][ H ];

            if ( candy < max_dist ) {
                max_dist = candy;
                p1 = pub[i];
                p2 = pub[j];
            }
        }

    cout << p1 << ' ' << p2 << endl;

    return 0;
}
