/*
Alfonso2 Peterssen
15 - 5 - 2008
Saratov #242 "Student's Morning"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000;

int S, U, flow;
int i, j, k;
int from[MAXN];
bool mark[MAXN];
vector< int > G[MAXN];

bool augment( int x ) {
    if ( mark[x] )
        return false;
    mark[x] = true;
    for ( int i = 0; i < G[x].size(); i++ )
        if ( from[ G[x][i] ] == -1 ||
             augment( from[ G[x][i] ] ) ) {
            from[ G[x][i] ] = x;
            return true;
        }
    return false;
}

int main() {

    scanf( "%d %d", &S, &U );
    for ( i = 0; i < S; i++ ) {
        scanf( "%d", &j );
        while ( j-- ) {
            scanf( "%d", &k );
            k--;
            G[i].push_back( k );
            G[i].push_back( k + U );
        }
    }

    fill( from, from + 2 * U, -1 );
    for ( i = 0; i < S; i++ ) {
        if ( flow == 2 * U )
            break;
        fill( mark, mark + S, false );
        if ( augment( i ) )
            flow++;
    }

    if ( flow != 2 * U )
        printf( "NO\n" );
    else {
        printf( "YES\n" );
        for ( i = 0; i < U; i++ )
            printf( "2 %d %d\n", from[i] + 1, from[i + U] + 1 );
    }

    return 0;
}
