/*
Alfonso Alfonso Petersse
26 - 12 - 2007
SPOJ #2127 "IPSC Rain"
*/
#include <cstdio>

const int MAXN = 1500001;

int T, N, M, i, j, k, sum, sol;
int s[MAXN], t[MAXN], a[MAXN];

int main() {

    for( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d %d %d %d", &s[0], &t[0], &N, &M );
        
        sum = 0;
        sol = MAXN;
        for ( i = j = 1; j <= N; ) {

            for ( ; j <= N && sum <= M; j++ ) {
                s[j] = ( 78901 + 31 * s[j - 1] ) % 699037;
                t[j] = ( 23456 + 64 * t[j - 1] ) % 2097151;
                a[j] = ( s[j] % 100 + 1 ) * ( t[j] % 100 + 1 );
                sum += a[j];
            }
            
            for ( ; i <= j && sum > M; i++ )
                sum -= a[i];
                
            sol <?= j - i;
        }
            
        printf( "%d\n", sol );
    }

    return 0;
}
