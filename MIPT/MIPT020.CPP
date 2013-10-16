/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #020 "Island of straight roads"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 300;
const int64 oo = (int64)1e17;

int N, D;
int from[MAXN];
bool mark[MAXN];
int64 dist[MAXN];
int64 cost[MAXN][MAXN];
struct _city {
    string name; int x, y;
} city[MAXN];

struct _ditch {
    int x1, y1, x2, y2;
} ditch[MAXN];

template< typename T >
T sign( T &x ) { return ( x > 0 ) - ( x < 0 ); }

template< typename T >
T sqr( const T &x ) { return x*x; }

int64 length( int x0, int y0,
              int x1, int y1 ) {
    return sqr( x0 - x1 ) + sqr( y0 - y1 );
}

int64 area2( int x0, int y0,
             int x1, int y1,
             int x2, int y2 ) {
    return (int64)( x1 - x0 ) * ( y2 - y0 ) -
           (int64)( x2 - x0 ) * ( y1 - y0 );
}

bool intersect( int x0, int y0, int x1, int y1,
                int x2, int y2, int x3, int y3 ) {

    int a = area2( x0, y0, x1, y1, x2, y2 );
    int b = area2( x0, y0, x1, y1, x3, y3 );
    int c = area2( x2, y2, x3, y3, x0, y0 );
    int d = area2( x2, y2, x3, y3, x1, y1 );

    if ( a == 0 && b == 0 && c == 0 && d == 0 ) {
        if ( x0 > x1 ) swap( x0, x1 );
        if ( y0 > y1 ) swap( y0, y1 );
        return ( x2 >= x0 && x2 <= x1 && y2 >= y0 && y2 <= y1 ) ||
               ( x3 >= x0 && x3 <= x1 && y3 >= y0 && y3 <= y1 );
    }

    return sign( a ) != sign( b ) &&
           sign( c ) != sign( d );
}

int main() {

    cin >> N >> D;
    REP( i, N )
        cin >> city[i].name >> city[i].x >> city[i].y;
    REP( i, D )
        cin >> ditch[i].x1 >> ditch[i].y1
            >> ditch[i].x2 >> ditch[i].y2;

    REP( i, N )
        REP( j, i ) {
            cost[i][j] = cost[j][i] = length( city[i].x, city[i].y,
                                              city[j].x, city[j].y );
            REP( k, D )
                if ( intersect( city[i].x, city[i].y,
                                city[j].x, city[j].y,
                                ditch[k].x1, ditch[k].y1,
                                ditch[k].x2, ditch[k].y2 ) ) {
                    cost[i][j] = cost[j][i] = oo;
                    break;
                }
        }

    /* Prim */
    fill( dist, dist + N, oo );
    dist[0] = 0;
    REP( i, N ) {
        int k = -1;
        REP( j, N )
            if ( !mark[j] && ( k < 0 || dist[j] < dist[k] ) )
                k = j;
        mark[k] = true;
        if ( dist[k] == oo ) {
            cout << "NO" << endl;
            return 0;
        }
        REP( j, N )
            if ( !mark[j] && cost[k][j] < dist[j] ) {
                dist[j] = cost[k][j];
                from[j] = k;
            }
    }

    cout << "YES" << endl;
    cout << N - 1 << endl;
    REP( i, N )
        if ( i )
            cout << city[i].name << " "
                 << city[ from[i] ].name << endl;

    return 0;
}
