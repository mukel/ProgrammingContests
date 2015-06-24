/*
Alfonso2 Peterssen
21 - 9 - 2007
BalkanOI 2003 "Traversal"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXN = 100001,
    MODULO = 9901;

int N, D, sol;
int lo, hi, pos, cnt;
int S[MAXN];
int srt[MAXN];
int T[MAXN];

int lobit( int x ) { return x & -x; }

void add( int x, int amount ) {
    for ( ; x <= N; x += lobit( x ) )
        T[x] += amount;
}

int query( int x, int y ) {
    int sum = 0;
    for (     ; y; y -= lobit( y ) ) sum += T[y];
    for ( --x ; x; x -= lobit( x ) ) sum -= T[x];
    return sum;
}

int main() {

    scanf( "%d %d", &N, &D );
    REP( i, N ) {
        scanf( "%d", &S[i] );
        srt[i] = S[i];
    }

    sort( srt, srt + N );
    REP( i, N ) {
        lo =  lower_bound( srt, srt + N, S[i] - D ) - srt + 1;
        hi =  upper_bound( srt, srt + N, S[i] + D ) - srt;
        pos = upper_bound( srt, srt + N, S[i] ) - srt;
        cnt = query( lo, hi );
        sol = ( sol + cnt ) % MODULO;
        add( pos, ( cnt + 1 ) % MODULO );
    }

    printf( "%d\n", sol );

    return 0;
}
