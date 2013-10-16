/*
Alfonso Alfonso Peterssen
7 - 2 - 2008
MIPT #013 "Boxes"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 500;

int N, i, j, k, flow;
int from[MAXN];
bool mark[MAXN];
int ls[MAXN][3];
vector< int > G[MAXN];

    bool augment( int node ) {

        if ( mark[node] )
            return false;
            
        mark[node] = true;
        
        for ( int i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i];
            if ( from[next] < 0 || augment( from[next] ) ) {
                from[next] = node;
                return true;
            }
        }

        return false;
    }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < 3; j++ )
            scanf( "%d", &ls[i][j] );
        sort( ls[i], ls[i] + 3 );
    }
    
    for ( i = 0; i < N; i++ )
        for ( j = 0; j < N; j++ ) {
            for ( k = 0; k < 3; k++ )
                if ( ls[i][k] >= ls[j][k] )
                    break;
            if ( k == 3 )
                G[i].push_back( j );
        }

    fill( from, from + N, -1 );
    for ( i = 0; i < N; i++ ) {
        fill( mark, mark + N, false );
        if ( augment( i ) )
            flow++;
    }

    printf( "%d\n", N - flow );

    return 0;
}
