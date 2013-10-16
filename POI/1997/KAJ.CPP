/*
Alfonso2 Peterssen
10 - 5 - 2008
POI 1997 Stage III "Canoes"
sorting + O( n ) -> can use radix sort
*/
#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN = 30000;

int W, N, lo, hi, sol;
int seq[MAXN];
bool used[MAXN];

int main() {

    scanf( "%d %d", &W, &N );
    for ( int i = 0; i < N; i++ )
        scanf( "%d", &seq[i] );

    sort( seq, seq + N );

    hi = N - 1;
    for ( lo = 0; lo < N; lo++ ) {
        if ( used[lo] ) continue;
        while ( hi > 0 && ( used[hi] || seq[lo] + seq[hi] > W ) )
            hi--;
        used[lo] = true;
        if ( lo < hi ) used[hi] = true;
        sol++;
    }

    printf( "%d\n", sol );

    return 0;
}
