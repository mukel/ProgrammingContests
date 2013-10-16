/*
Alfonso2 Peterssen
12 - 6 - 2008
IOI 2002 "Batch Scheduling"
*/
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long int64;

const int MAXN = 10001;

int N, S, dp;
int T[MAXN];
int F[MAXN];
struct point {
    int x, y;
    point() {}
    point( int x, int y ) : x( x ), y( y ) {}
};
deque< point > H;

int64 cross( point a, point b, point c ) {
    return (int64)( b.x - a.x ) * ( c.y - a.y ) -
           (int64)( c.x - a.x ) * ( b.y - a.y );
}

int eval( point p, int x ) {
    return p.x * x + p.y;
}

void hull_add( point p ) {
    while ( H.size() > 1 &&
            cross( H[H.size() - 2], H[H.size() - 1], p ) >= 0 )
            H.pop_back();
    H.push_back( p );
}

int hull_query( int x ) {
    while ( H.size() > 1 &&
            eval( H[0], x ) <= eval( H[1], x ) )
            H.pop_front();
    return eval( H[0], x );
}

int main() {

    scanf( "%d %d", &N, &S );
    for ( int i = 1; i <= N; i++ ) {
        scanf( "%d %d", &T[i], &F[i] );
        T[i] += T[i - 1];
        F[i] += F[i - 1];
    }

    for ( int i = N; i > 0; i-- ) {
        hull_add( point( -T[i], -dp ) );
        int f = F[N] - F[i - 1];
        dp = -hull_query( f ) + f * ( S - T[i - 1] );
    }

    printf( "%d\n", dp );

    return 0;
}
