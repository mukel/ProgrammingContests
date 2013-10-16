/*
Alfonso2 Peterssen
8 - 6 - 2000
IOI 2000 "Walls"
*/
#include <cstdio>
#include <vector>

using std::vector;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXR = 200,
    MAXT = 250,
    MAXB = 30,
    oo = 1 << 29;

int R, T, B;
int x, cant, sol;
int boy[MAXB];
int cost[MAXR];
int next[MAXT][2];
vector< int > adjT[MAXR];
vector< int > adjR[MAXT];
int dist[MAXR][MAXR];

int main() {

    scanf( "%d %d %d", &R, &T, &B );
    REP( i, B ) {
        scanf( "%d", &boy[i] );
        boy[i]--;
    }

    REP( i, R ) {
        scanf( "%d", &cant );
        REP( j, cant ) {
            scanf( "%d", &x );
            x--;
            adjT[i].push_back( x );
            adjR[x].push_back( i );
        }
    }

    /* Build Graph */
    REP( i, R ) {
        memset( next, -1, sizeof( next ) );
        REP( k, adjT[i].size() ) {
            int now = adjT[i][k];
            int nxt = adjT[i][(k + 1) % adjT[i].size()];
            next[now][0] = nxt;
            next[nxt][1] = now;
        }
        REP( j, R ) {
            if ( i == j ) continue;
            dist[i][j] = oo;
            REP( k, adjT[j].size() ) {
                int now = adjT[j][k];
                int nxt = adjT[j][(k + 1) % adjT[j].size()];
                if ( nxt == next[now][0] ||
                     nxt == next[now][1] ) {
                    dist[i][j] = 1;
                    break;
                }
            }
        }
    }

    /* Floyd */
    REP( k, R )
    REP( i, R )
    REP( j, R )
        dist[i][j] <?= dist[i][k] + dist[k][j];

    REP( i, R ) {
        REP( j, B ) {
            int best = oo;
            REP( k, adjR[ boy[j] ].size() )
                best <?= dist[i][ adjR[ boy[j] ][k] ];
            cost[i] += best;
        }
        if ( cost[i] < cost[sol] )
            sol = i;
    }

    printf( "%d\n%d\n", cost[sol], sol + 1 );

    return 0;
}
