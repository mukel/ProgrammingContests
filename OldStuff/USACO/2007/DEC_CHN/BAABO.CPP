/*
Alfonso2 Peterssen
22 - 5 - 2008
USACO DEC07++ "Baabo"
*/
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long int64;

#define FOR( i, s, e ) \
    for ( int i = s; i <= (e); i++ )

const int MAXN = 1001;

int N;
int64 sol;
int A[MAXN], B[MAXN];
int64 SA[MAXN], SB[MAXN];
int64 dp[MAXN][MAXN];
struct point {
    int64 x, y;
};
deque< point > hull[MAXN];

int64 cross( point &a, point &b, point &c ) {
    return ( b.x - a.x ) * ( c.y - a.y ) -
           ( c.x - a.x ) * ( b.y - a.y );
}

int64 eval( point &p, int64 value ) {
    return p.x * value + p.y;
}

int64 sqr( int64 x ) { return x * x; }

void hull_add( int id, point p ) {
    while ( hull[id].size() > 1 &&
            cross( hull[id][ hull[id].size() - 2],
                   hull[id][ hull[id].size() - 1],
                   p ) >= 0 )
        hull[id].pop_back();
    hull[id].push_back( p );
}

int64 hull_query( int id, int64 value ) {
    while ( hull[id].size() > 1 &&
            eval( hull[id][0], value ) <=
            eval( hull[id][1], value ) )
        hull[id].pop_front();
    return eval( hull[id][0], value );
}

int main() {

    scanf( "%d", &N );
    FOR( i, 1, N ) { scanf( "%d", A + i ); SA[i] += SA[i - 1] + A[i]; }
    FOR( i, 1, N ) { scanf( "%d", B + i ); SB[i] += SB[i - 1] + B[i]; }

    FOR( i, 1, N ) {
        hull[0].clear();
        FOR( j, 1, N ) {
            if ( i == 1 && j == 1 ) dp[i][j] = 0;
            if ( i != 1 && j == 1 ) dp[i][j] = -sqr( SA[i - 1] );
            if ( i == 1 && j != 1 ) dp[i][j] = -sqr( SB[j - 1] );
            if ( i != 1 && j != 1 )
                dp[i][j] = max( hull_query( 0, SB[j - 1] ) - sqr( SB[j - 1] ),
                                hull_query( j, SA[i - 1] ) - sqr( SA[i - 1] ) );

            dp[i][j] += A[i] * B[j];
            sol >?= dp[i][j] - sqr( SA[N] - SA[i] ) - sqr( SB[N] - SB[j] );

            hull_add( 0, (point){ 2 * SB[j], dp[i - 1][j] - sqr( SB[j] ) } );
            hull_add( j, (point){ 2 * SA[i], dp[i][j - 1] - sqr( SA[i] ) } );
        }
    }

    printf( "%I64d\n", sol );

    return 0;
}
