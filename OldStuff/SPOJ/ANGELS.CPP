/*
Alfonso Alfonso Peterssen
28 - 11 - 2007
SPOJ #1022 "Angels and Devils"
*/
#include <iostream>
using namespace std;

const int
    MAXF = 300,
    MAXV = 45000;

int T, F, C, E, i, j, k, flow;
char mat[MAXF][MAXF];
int vcant, hcant;
int vid[MAXF][MAXF], hid[MAXF][MAXF];
bool mark[MAXV];
int P[MAXV], from[MAXV];
struct edge {
    int v, next;
} ls[MAXV];

    bool augment( int x ) {

        if ( mark[x] ) return false;

        int i, j;

        mark[x] = true;
        for ( i = P[x]; i; i = ls[i].next ) {
            j = ls[i].v;
            if ( !from[j] || augment( from[j] ) ) {
                from[j] = x;
                return true;
            }
        }

        return false;
    }

int main() {

    for ( cin >> T; T; T-- ) {

        cin >> F >> C;
        for ( i = 0; i < F; i++ )
            for ( j = 0; j < C; j++ )
                cin >> mat[i][j];

        /* Init */
        E = 0;
        vcant = hcant = 0;
        memset( P, 0, sizeof( P ) );
        memset( from, 0, sizeof( from ) );

        /* Build Flow-Network */
        for ( i = 0; i < F; i++ )
            for ( j = 0; j < C; j++ )
                if ( mat[i][j] != 'A' ) {

                    if ( !i || mat[i - 1][j] == 'A' )
                         vid[i][j] = ++vcant;
                    else vid[i][j] = vid[i - 1][j];

                    if ( !j || mat[i][j - 1] == 'A' )
                         hid[i][j] = ++hcant;
                    else hid[i][j] = hid[i][j - 1];

                    /* Connect */
                    if ( mat[i][j] == 'H' ) {
                        ls[++E] = ( edge ) { hid[i][j], P[ vid[i][j] ] };
                        P[ vid[i][j] ] = E;
                    }
                }

        /* Bipartite Matching */
        flow = 0;
        for ( i = 1; i <= vcant; i++ ) {
            memset( mark, 0, sizeof( mark ) );
            if ( augment( i ) ) flow++;
        }

        cout << flow << endl;
    }

    return 0;
}
