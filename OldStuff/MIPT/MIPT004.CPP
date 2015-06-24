/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #004 "Athletes"
*/
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

typedef pair< int, int > par;

int N, i, j, k;
int sum, sol;
priority_queue< par, vector< par >, greater< par > > Q;

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &j, &k );
        Q.push( make_pair( k, j ) );
    }

    while ( !Q.empty() ) {
        if ( Q.top().first >= sum ) {
            sum += Q.top().second;
            sol++;
        }
        Q.pop();
    }

    printf( "%d\n", sol );

    return 0;
}
