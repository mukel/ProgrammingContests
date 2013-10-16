/* Alfonso2 Peterssen
21 - 4 - 2008
TASK: MOBILE
*/
#include <cstdio>
#include <algorithm>

using std::swap;

const int MAXN = 5000;
typedef long long int64;

#define DEBUG false

int N, M, i, j;
int p[MAXN];
int q[MAXN];
int l, r, sign;
int64 g, a, b, sol;
int64 num[MAXN];
int64 den[MAXN];
int father[MAXN];

int64 GCD( int64 a, int64 b ) {
    while ( ( a != 0 ) && ( b != 0 ) ) if ( ( a %= b ) != 0 ) b %= a;
    return a + b;
}

void my_sum( int64 &a, int64 &b, int64 c, int64 d ) {
    c *= a;
    d *= b;
    int64 g = GCD( b, d );
    a = a * ( d / g );
    c = c * ( b / g );
    a += c;
    b = b * ( d / g );
    g = GCD( a, b );
    a /= g;
    b /= g;
}

int main() {

    #warning READ FROM FILES!!!
    freopen( "mobile.in", "r", stdin );
    freopen( "mobile.out", "w", stdout );

    scanf( "%d", &N );
    
    M = N + 1;
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d %d %d %d", &p[i], &q[i], &l, &r );
        g = GCD( p[i], q[i] );
        p[i] /= g;
        q[i] /= g;
        if ( l == 0 )
             father[M++] = -i;
        else father[l] = -i;
        if ( r == 0 )
             father[M++] = +i;
        else father[r] = +i;
    }
    
    for ( i = N + 1; i < M; i++ ) {
        /* Goes up */
        if ( DEBUG )
            printf( "var %d\n", i );
        num[i] = den[i] = 1;
        
        j = i;
        for (;;) {

            int f = father[j];
            
            if ( f == 0 ) break;
            
            if ( f > 0 )
                 sign = +1;
            else sign = -1;

            j = abs( f );
            
            a = p[j];
            b = q[j];
            
            if ( sign == +1 )
                swap( a, b );

            my_sum( num[i], den[i], a, b );
            if ( DEBUG )
                printf( "  %d %d + -> %d %d\n", num[i], den[i], a, b );
        }
    }

    sol = 1;
    for ( i = N + 1; i < M; i++ )
        sol = sol / GCD( sol, num[i] ) * num[i];

    printf( "%lld\n", sol );
    fflush( stdout );

    return 0;
}
