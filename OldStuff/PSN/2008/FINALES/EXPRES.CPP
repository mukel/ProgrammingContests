/*
Alfonso2 Peterssen
22 - 4 - 2008
TASK: EXPRESS
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using std::pair;

const int MAXN = 400;
const long long oo = 1000000000000000000LL;

typedef long long int64;
typedef pair< int64, int64 > par;

int N, i, j, k, h;
par dp[MAXN][MAXN];
int sum, mul, dec;
char expr[MAXN];

int digits( int64 x ) {
    if ( x == 0 ) return 1;
    int res = 0;
    for ( ; x != 0; x /= 10 )
        res++;
    return res;
}

par calc( int i, int j, int k ) { // start end pivot
    int64 a = dp[i][k - 1].second;
    int64 b = dp[k + 1][j].second;
    int64 lena = digits( a );
    int64 lenb = digits( b );
    int64 t = dp[i][k - 1].first + dp[k + 1][j].first;
    if ( expr[k] == '+' ) return par( sum * ( lena + lenb ) + t, a + b );
    if ( expr[k] == '-' ) return par( dec * ( lena + lenb ) + t, a - b );
    if ( expr[k] == '*' ) return par( mul * ( lena * lenb ) + t, a * b );
}

int main() {

	scanf( "%s", &expr );
    scanf( "%d %d %d", &sum, &dec, &mul );

	N = strlen( expr );
	for ( i = 0; i < N; i += 2 )
        dp[i][i].second = expr[i] - '0';

    /* DP */
	for ( h = 2; h < N; h += 2 )
        for ( i = 0; i < N - h; i += 2 ) {
            j = i + h;
            dp[i][j] = par( oo, oo );
            for ( k = i + 1; k < j; k += 2 ) {
                par t = calc( i, j, k );
                if ( t < dp[i][j] )
                    dp[i][j] = t;
            }
        }

	printf( "%I64d\n", dp[0][N - 1].first );
	fflush( stdout );

	return 0;
}

