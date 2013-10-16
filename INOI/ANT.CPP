/*
Alfonso2 Peterssen
14 - 4 - 2008
TASK: ANT
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

typedef pair< int, int > par;

int N, T;
int i, j, pos;
par a[MAXN];
int b[MAXN];
int dir[MAXN];
int hello[MAXN];
bool mark[MAXN];

/* Queue */
int Q[MAXN];
int last, next;

int bs( int s[], int x ) {
    int lo, hi, mid;
    lo = 0; hi = N - 1;
    while ( lo <= hi ) {
        mid = ( lo + hi ) >> 1;
        if ( s[mid] >= x )
             hi = mid - 1;
        else lo = mid + 1;
    }
    if ( s[hi + 1] == x )
        if ( !mark[hi + 1] )
            return hi + 1;
    return -1;
}

void process1() {
    last = next = 0;
    for ( int i = 0; i < N; i++ ) {
        while ( last < next && a[ Q[last] ].first + 2 * T < a[i].first ) last++;
        if ( dir[i] == +1 ) Q[next++] = i;
        if ( dir[i] == -1 ) hello[ a[i].second ] += next - last;
    }
}

void process2() {
    last = next = 0;
    for ( int i = 0; i < N; i++ ) {
        while ( last < next && a[ Q[last] ].first - 2 * T > a[i].first ) last++;
        if ( dir[i] == -1 ) Q[next++] = i;
        if ( dir[i] == +1 ) hello[ a[i].second ] += next - last;
    }
}

int main() {

    scanf( "%d %d", &N, &T );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &a[i].first );
        a[i].second = i;
    }
    for ( i = 0; i < N; i++ )
        scanf( "%d", b + i );
        
    sort( a, a + N );
    sort( b, b + N );
    
    for ( i = 0; i < N; i++ ) {

        pos = bs( b, a[i].first - T );
        if ( pos != -1 ) {
            mark[pos] = true;
            dir[i] = -1;
            continue;
        }
        
        pos = bs( b, a[i].first + T );
        if ( pos != -1 ) {
            mark[pos] = true;
            dir[i] = +1;
            continue;
        }
        
        printf( "impossible\n" );
        fflush( stdout );
        exit( 0 );
    }
    
    /* Count */
    process1();
    reverse( a, a + N );
    reverse( dir, dir + N );
    process2();

    for ( i = 0; i + 1 < N; i++ )
        printf( "%d ", hello[i] );
    printf( "%d\n", hello[N - 1] );
    
    return 0;
}
