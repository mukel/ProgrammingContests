/*
Alfonso2 Peterssen
10 - 6 - 2008
IOI 2002 "The Troublesome Frog"
*/
#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

typedef pair< int, int > point;

const int MAXN = 5000;

int F, C, N;
int cnt, sol;
int x ,y, dx, dy;
point P[MAXN];
bitset< MAXN > used[MAXN];

inline bool inbox( int x, int y ){
    return ( x >= 0 && x < F && y >= 0 && y < C );
}

int main() {

    scanf( "%d %d", &F, &C );
    scanf( "%d", &N );
    for ( int i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        x--; y--;
        used[x][y] = true;
        P[i] = point( x, y );
    }

    sort( P, P + N );

    for ( int i = 0; i < N - 1; i++ )
    for ( int j = i + 1; j < N; j++ ) {
        x = P[j].first;
        y = P[j].second;
        dx = x - P[i].first;
        dy = y - P[i].second;
        if ( inbox( x - 2 * dx, y - 2 * dy ) )
            continue;
        for ( cnt = 1; inbox( x, y ) && used[x][y]; cnt++ ) {
            x += dx;
            y += dy;
        }
        if ( !inbox( x, y ) )
            sol >?= cnt;
    }

    printf( "%d\n", sol < 3 ? 0 : sol );

    return 0;
}
