/*
Alfonso Alfonso Peterssen
20 - 2 - 2008
CNC 2008 Task 2C "Aislante"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 50000; // que inocente...

int n, i, j;
int a, b, start, cant;
int x, y, c, dx, dy;
int last[MAXN], ls[MAXN];
long long dp[MAXN];
struct box {
    int x, y, c;
} vec[MAXN];

bool comp( const int &i, const int &j ) {
    if ( vec[i].x != vec[j].x ) return vec[i].x < vec[j].x;
    return vec[i].y < vec[j].y;
}

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d %d %d", &x, &y, &c );
        if ( x > y )
            swap( x, y );
        vec[i] = ( box ){ x, y, c };
        ls[i] = i;
    }

    scanf( "%d", &x );
    x--;

    sort( ls, ls + n, comp );

    while ( ls[start] != x )
        start++;

    fill( last, last + n, -1 );
    for ( i = 0; i <= start; i++ ) {
        a = ls[i];
        dx = vec[a].x - 2 * vec[a].c;
        dy = vec[a].y - 2 * vec[a].c;
        for ( j = 0; j < i; j++ ) {
            b = ls[j];
            if ( vec[b].x >= dx ) break;
            if ( vec[b].y < dy && dp[b] > dp[a] ) {
                dp[a] = dp[b];
                last[a] = b;
            }
        }
        dp[a] += (long long)  vec[a].x * vec[a].y -
                 (long long)( vec[a].x - 2 * vec[a].c ) * ( vec[a].y - 2 * vec[a].c );
    }

    start = ls[start];
    for ( i = start; i != -1; i = last[i] )
        cant++;

    printf( "%d\n", cant );
    printf( "%d\n", vec[start].x * vec[start].y - dp[start] );
    for ( i = start; i != -1; i = last[i] )
        printf( "%d\n", i + 1 );

    return 0;
}
