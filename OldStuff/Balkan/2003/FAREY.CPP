/*
Alfonso2 Peterssen
18 - 6 - 2008
BalkanOI 2003 "Farey sequence"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50000;

int N, K, F;
int pos;
int lo, hi, mid;
int dp[MAXN];
struct fr {
    int a, b;
    bool operator < ( const fr &f ) const {
        return a * f.b < f.a * b;
    }
} frac[MAXN];

int cant( int value ) {
    int res = 0;
    for ( int i = 2; i <= N; i++ )
        dp[i] = ( i * value / N );
    for ( int i = 2; i <= N; i++ ) {
        res += dp[i];
        for ( int j = 2 * i; j <= N; j += i )
            dp[j] -= dp[i];
    }
    return res;
}

int main() {

    scanf( "%d %d", &N, &K ); K--;

    lo = 0;
    hi = N;
    while ( lo <= hi ) {
        mid = ( lo + hi ) / 2;
        if ( cant( mid ) <= K )
             lo = mid + 1;
        else hi = mid - 1;
    }

    lo--;
    for ( int i = 2; i <= N; i++ ) {
        int x = lo * i / N + 1;
        if ( __gcd( x, i ) == 1 )
            frac[F++] = (fr){ x, i };
    }

    pos = K - cant( lo );
    nth_element( frac, frac + pos, frac + F );

    printf( "%d %d\n", frac[pos].a, frac[pos].b );

    return 0;
}
