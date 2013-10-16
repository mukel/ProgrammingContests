/*
Alfonso2 Peterssen
13 - 7 - 2008
CEOI 2008 "Fence"
*/
#include <cstdio>
#include <algorithm>
#include <complex>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

typedef complex< int > point;

const int
    MAXN = 300,
    oo = (int)1e8;

int N, M, H;
int top;
int cover, outside;
point P[MAXN];
point hull[MAXN];
int C[MAXN][MAXN];

int area2( point a, point b, point c ) {
    return imag( conj(b-a) * (c-a) );
}

bool point_cmp( const point &a, const point &b ) {
    if ( real(a) != real(b) ) return real(a) < real(b);
    return imag(a) < imag(b);
}

bool contains( point hull[], int H, point p ) {
    REP( i, H )
        if ( area2( hull[i], hull[(i + 1) % H], p ) < 0 )
            return 0;
    return 1;
}

int main() {

    scanf( "%d %d", &N, &M );
    REP( i, N + M )
        scanf( "%d %d", &real( P[i] ), &imag( P[i] ) );

    sort( P, P + N, point_cmp );

    top = 1;
    for ( int i = 0; i < N; hull[H++] = P[i++] )
        while ( H > top &&
                area2( hull[H - 2], hull[H - 1], P[i] ) < 0 )
                H--;

    top = H;
    for ( int i = N - 2; i >= 0; hull[H++] = P[i--] )
        while ( H > top &&
                area2( hull[H - 2], hull[H - 1], P[i] ) < 0 )
                H--;
    H--;

    REP( i, M )
        while ( i < M &&
                !contains( hull, H, P[N + i] ) ) {
            M--;
            swap( P[N + i], P[N + M] );
            outside++;
        }

    if ( M == 0 ) {
        printf( "%d\n", 111 * outside );
        return 0;
    }

    REP( i, N )
    REP( j, N ) {
        C[i][j] = 1;
        REP( k, M )
            if ( area2( P[i], P[j], P[N + k] ) > 0 ) {
                C[i][j] = oo;
                break;
            }
    }

    REP( i, N )
        C[i][i] = oo;

    REP( k, N )
    REP( i, N )
    REP( j, N )
        C[i][j] <?= C[i][k] + C[k][j];

    cover = H;
    REP( i, N )
        cover <?= C[i][i];

    printf( "%d\n", cover * 20 + outside * 111 );

    return 0;
}
