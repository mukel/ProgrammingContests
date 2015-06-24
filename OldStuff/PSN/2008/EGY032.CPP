/*
Alfonso Alfonso Peterssen
24 - 3 - 2008
USACO MAR08 Gold "Acquire"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50000;

typedef long long int64;
typedef pair< int64, int64 > line;

int N, M, i, j;
int x, y, lo, hi;
int64 dp;
line lines[MAXN];
line hull[MAXN];

int64 gety( line &l, int x ) {
    return l.first * x + l.second;
}

double cut_point( line &l1, line &l2 ) {
    return ( l2.second - l1.second ) /
           ( double )( l1.first - l2.first );
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        lines[i] = line( x, y );
    }

    sort( lines, lines + N );
    for ( i = 0; i < N; i++ ) {
        while ( M > 0 &&
                lines[i].second >= lines[M - 1].second )
                M--;
        lines[M++] = lines[i];
    }

    for ( i = 0; i < M; i++ ) {

        x = lines[i].first;
        line ln = line( lines[i].second, dp );

        while ( lo + 1 < hi &&
                cut_point( hull[hi - 2], hull[hi - 1] ) >
                cut_point( hull[hi - 1], ln ) )
                hi--;

        hull[hi++] = ln;
        while ( lo + 1 < hi &&
                gety( hull[lo],     x ) >=
                gety( hull[lo + 1], x ) )
                lo++;

        dp = gety( hull[lo], x );
    }

    printf( "%I64d\n", dp );

    return 0;
}
