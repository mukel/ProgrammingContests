/*
Alfonso Alfonso Peterssen
1 - 3 - 2008
POI #2003 Stage I "Chocolate"
*/
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 2000;

typedef pair< int, int > par;

int n, m, i, j, sol;
int cant[2] = { 1, 1 };
par ls[MAXN];

int main() {

    scanf( "%d %d", &n, &m );
    n--; m--;
    for ( i = 0; i < n + m; i++ ) {
        scanf( "%d", &j );
        ls[i] = make_pair( j, i < n );
    }

    sort( ls, ls + n + m, greater< par >() );

    for ( i = 0; i < n + m; i++ ) {
        sol += ls[i].first * cant[ !(ls[i].second) ];
        cant[ ls[i].second ]++;
    }

    printf( "%d\n", sol );

    return 0;
}
