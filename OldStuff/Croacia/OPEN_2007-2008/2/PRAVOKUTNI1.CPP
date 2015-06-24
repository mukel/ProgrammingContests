/*
Alfonso Alfonso Peterssen
18 - 12 - 2007
COI 2007 Contest 2 "PRAVOKUTNI"
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1500;

int N, i, j, sol;
int x[MAXN], y[MAXN];

struct line {

    int x, y;

    void normalize() {
        int a = x, b = y;
        while ( a && b ) if ( a %= b ) b %= a;
        x /= a + b;
        y /= a + b;
    }

    line( int x = 0, int y = 0 ) : x( x ), y( y ) { }

    line rotate90() { return line( y, -x ); };

    bool operator < ( const line &t ) const {
        if ( x != t.x ) return x < t.x;
        return y < t.y;
    }
};

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ )
        cin >> x[i] >> y[i];

    for ( i = 0; i < N; i++ ) {

        vector< line > ls;

        for ( j = 0; j < N; j++ ) {
            if ( j == i ) continue;
            line ln( x[j] - x[i], y[j] - y[i] );
            ln.normalize();
            ls.push_back( ln );
        }

        sort( ls.begin(), ls.end() );

        for ( j = 0; j < ls.size(); j++ ) {
            line ln = ls[j].rotate90();
            sol += upper_bound( ls.begin(), ls.end(), ln ) -
                   lower_bound( ls.begin(), ls.end(), ln );
        }

    }

    cout << sol << endl;

    return 0;
}
