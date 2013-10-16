/*
Alfonso2 Peterssen
7 - 6 - 2008
SPOJ #2731 "Inventing Test Data"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

/* fors++  */
#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 15000;

int T, V;
int u, v, w;
int P[MAXV];
int S[MAXV];
long long sol;
struct edge {
    int u, v, w;
    bool operator < ( const edge &e ) const {
        return w < e.w;
    }
};
edge E[MAXV];

int FIND( int x ) { return x != P[x] ? P[x] = FIND( P[x]) : x; }

int main() {

    scanf( "%d", &T );
    while ( T-- ) {
        sol = 0;
        scanf( "%d", &V );
        REP( i, V - 1 ) {
            scanf( "%d %d %d", &u, &v, &w );
            u--; v--;
            E[i] = (edge){ u, v, w };
            sol += w;
        }
        sort( E, E + V - 1 );
        REP( i, V ) {
            P[i] = i;
            S[i] = 1;
        }
        REP( i, V - 1 ) {
            u = FIND( E[i].u );
            v = FIND( E[i].v );
            w = E[i].w;
            P[u] = v;
            sol += (long long)( w + 1 ) * ( S[u] * S[v] - 1 );
            S[v] += S[u];
        }
        cout << sol << endl;
    }

    return 0;
}
