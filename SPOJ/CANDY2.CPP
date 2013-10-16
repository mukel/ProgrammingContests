/*
Alfonso Alfonso Petersse
26 - 12 - 2007
SPOJ #2136 "Candy II"
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5000;

int N, i, j, k, cost, cant;
int bag[MAXN][3];
int ls[MAXN];
int C, B, S;
vector< int > box[3];

struct comp {
    int flavor;
    comp( int fl ) : flavor( fl ) {}
    bool operator () ( const int &i, const int &j ) const {
        /* Decreasing */
        return bag[i][flavor] > bag[j][flavor];
    }
};

    void fill_box( int id ) {
        sort( ls, ls + N, comp( id ) );
        int i;
        for ( i = 0; i < 3; i++ )
            box[id].push_back( ls[i] );
        for ( ; i < N && bag[ ls[i] ][id] == bag[ ls[2] ][id]; i++ )
            box[id].push_back( ls[i] );
    }

int main() {
  
    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        ls[i] = i;
        for ( j = 0; j < 3; j++ ) {
            scanf( "%d", &bag[i][j] );
            cant += bag[i][j];
        }
    }
        
    for ( i = 0; i < 3; i++ )
        fill_box( i );

    /* Solve */
    cost = 1000000000;
    for ( i = 0; i < box[0].size(); i++ )
    for ( j = 0; j < box[1].size(); j++ )
    for ( k = 0; k < box[2].size(); k++ )
        if ( box[0][i] != box[1][j] &&
             box[0][i] != box[2][k] &&
             box[1][j] != box[2][k] ) {

             int new_cost = cant - bag[ box[0][i] ][0] -
                                   bag[ box[1][j] ][1] -
                                   bag[ box[2][k] ][2];
                                   
             if ( new_cost < cost ) {
                 cost = new_cost;
                 C = box[0][i];
                 S = box[1][j];
                 B = box[2][k];
             }
        }

//    printf( "%d\n", cost );
    printf( "%d\n%d\n%d\n", C, S, B );
    
    return 0;
}
