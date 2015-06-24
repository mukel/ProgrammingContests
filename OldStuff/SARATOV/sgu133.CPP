/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #133 "Border"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 20000;

int N, i, max_y, sol;
pair< int, int > ls[MAXN];

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d %d",
            &ls[i].first,
            &ls[i].second );

    sort( ls, ls + N );

    for ( i = 0; i < N;
          max_y >?= ls[i].second, i++ )
        if ( max_y > ls[i].second )
            sol++;

    printf( "%d\n", sol );

    return 0;
}
