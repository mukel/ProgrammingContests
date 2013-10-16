/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #116 "Hard Life"
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

const int MAXV = 200;
const double EPSILON = 1e-6;

int V, E, i, j, k;
double lo, hi, mid;
int from[MAXV];
int degree[MAXV];
double cap[MAXV][MAXV];
double fl[MAXV][MAXV];
double flow[MAXV];
vector< int > G[MAXV];
vector< int > sol;

    bool exist( double value ) {

        int i, j, cant = 0;
        memset( fl, 0, sizeof( fl ) );

        for ( i = 1; i <= V; i++ )
            cap[i][V + 1] = E - degree[i] + value;

        /* Max-Flow */
        while ( 1 ) {

            fill( flow, flow + V + 2, 0.0 );
            fill( from, from + V + 2, -1 );
            flow[0] = 1e10; // oo
            from[0] = 0;

            /* BFS */
            queue< int > Q;
            for ( Q.push( 0 ); !Q.empty(); Q.pop() ) {

                int x = Q.front();
                for ( i = 0; i < G[x].size(); i++ ) {

                    int y = G[x][i];
                    if ( from[y] < 0 && fl[x][y] < cap[x][y] ) {
                        Q.push( y );
                        from[y] = x;
                        flow[y] = min( flow[x],
                                       cap[x][y] - fl[x][y] );
                    }
                }
            }

            if ( from[V + 1] < 0 )
                break;

            /* Reflow */
            for ( i = V + 1; i; i = from[i] ) {
                j = from[i];
                fl[j][i] += flow[V + 1];
                fl[i][j] -= flow[V + 1];
            }
        }

        for ( i = 1; i <= V; i++ )
            if ( from[i] >= 0 ) cant++;

        if ( cant > 1 ) {
            sol.clear();
            for ( i = 1; i <= V; i++ )
                if ( from[i] >= 0  )
                    sol.push_back( i );
        }

        return cant > 1;
    }

int main() {

    cin >> V >> E;

    if ( E == 0 ) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }

    for ( i = 0; i < E; i++ ) {
        int weight = 1;
        cin >> j >> k; //>> weight;
        degree[j] += weight;
        degree[k] += weight;
        G[j].push_back( k );
        G[k].push_back( j );
        cap[j][k] = cap[k][j] = weight;
    }

    for ( i = 1; i <= V; i++ ) {
        cap[0][i] = E;
        G[0].push_back( i );
        G[i].push_back( V + 1 );
    }

    lo = 0.0; hi = 1e6;
    while ( hi - lo > EPSILON ) {
        mid = ( lo + hi ) / 2.0;
        if ( exist( mid ) )
             lo = mid;
        else hi = mid;
    }

    cout << sol.size() << endl;
    copy( sol.begin(), sol.end(),
          ostream_iterator< int >( cout, "\n" ) );

    return 0;
}
