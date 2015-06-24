/*
Alfonso2 Peterssen
23 - 4 - 2008
TASK: HIGHWAY
*/
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

const int MAXE = 30000;

typedef long long int64;

int L, D, N, E, sol;
int i, j, k;
int x, y;
long double lo, hi;
bool mark[MAXE];
struct event {
    long double pos;
    int id, flag;
    bool operator < ( const event &e ) const {
        if ( pos != e.pos ) return pos < e.pos;
        return flag < e.flag;
    }
} ls[MAXE];

stack< int > S;

int main() {

    #warning READ FROM FILES!!!
    freopen( "highway.in", "r", stdin );
    freopen( "highway.out", "w", stdout );

    scanf( "%d", &L );
    scanf( "%d", &D );
    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        long double b = sqrt( ( long double )( ( int64 )D * D - ( int64 )y * y ) );
        lo = x - b; lo >?= 0;
        hi = x + b; hi <?= L;
        ls[E++] = ( event ){ lo, i, 0 };
        ls[E++] = ( event ){ hi, i, 1 };
    }
    
    /* ... */
    sort( ls, ls + E );
    for ( i = 0; i < E; i++ ) {
        if ( ls[i].flag == 0 )
            S.push( ls[i].id );
        if ( ls[i].flag == 1 &&
             !mark[ ls[i].id ] ) {
            while ( !S.empty() ) {
                mark[S.top()] = true;
                S.pop();
            }
            sol++;
        }
    }

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
