/*
Alfonso Alfonso Peterssen
18 - 12 - 2007
COI 2007 Contest 2 "PRAVOKUTNI"
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1500;

int N, i, j, k, sol;
int x[MAXN], y[MAXN];
int cant[4];

struct point {

    int x, y, quadrant;

    point( int x, int y ) : x( x ), y( y ), quadrant( 0 ) {}

    point rotate90() {
        swap( x, y ); y = -y;
        ++quadrant &= 3;
    }

    bool operator < ( const point &p ) const {
        return ( long long )x * p.y < ( long long )p.x * y;
    }

    bool operator == ( const point &p ) const {
        return ( long long )x * p.y == ( long long )p.x * y;
    }

} ls[MAXN];
int sz;

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ )
        cin >> x[i] >> y[i];

    for ( i = 0; i < N; i++ ) {

        vector< point > ls;

        for ( j = 0; j < N; j++ ) {

            if ( j == i ) continue;

            point p( x[j] - x[i], y[j] - y[i] );

            while ( !( p.x > 0 && p.y >= 0 ) )
                p.rotate90();

            ls.push_back( p );
        }

        sort( ls.begin(), ls.end() );

        for ( j = 0; j < ls.size(); j = k ) {

            fill( cant, cant + 4, 0 );

            for ( k = j; k < ls.size() && ls[j] == ls[k]; k++ )
                cant[ ls[k].quadrant ]++;

            sol += cant[0] * cant[1];
            sol += cant[1] * cant[2];
            sol += cant[2] * cant[3];
            sol += cant[3] * cant[0];
        }
    }

    cout << sol << endl;

    return 0;
}
