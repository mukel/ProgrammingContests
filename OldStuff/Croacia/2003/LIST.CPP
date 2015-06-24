/*
Alfonso2 Peterssen
Croatia 2003 Final 1 "List"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 100000;

int N;
int S[MAXN];
int deg[MAXN];
priority_queue< int, vector< int >, greater< int > > Q;

int main() {

    scanf( "%d", &N );
    REP( i, N - 1 ) {
        scanf( "%d", &S[i] );
        deg[ --S[i] ]++;
    }

    REP( i, N )
        if ( !deg[i] ) Q.push( i );

    REP( i, N - 1 ) {
        printf( "%d %d\n", S[i] + 1, Q.top() + 1 ); Q.pop();
        if ( !--deg[ S[i] ] )
            Q.push( S[i] );
    }

    return 0;
}
