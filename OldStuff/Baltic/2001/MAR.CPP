/*
Alfonso2 Peterssen
19 - 6 - 2008
Baltic 2001 "Mars Maps"
O( n lg MAXC )
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXN = 10000,
    MAXC = 30000;

int N, E;
int sol, last;
int x1, y1, x2, y2;
struct event {
    int idx, lo, hi, kind;
    bool operator < ( const event &e ) const {
        if ( idx != e.idx ) return idx < e.idx;
        return kind > e.kind;
    }
} events[MAXN * 2];

struct node {
    int covered, marks;
} tree[4 * MAXC];

void update( int x, int lo, int hi, int start, int end, int value ) {

    if ( lo > hi || lo > end || hi < start )
        return ;

    if ( lo >= start && hi <= end )
        tree[x].marks += value;
    else {
        int mid = ( lo + hi ) / 2;
        update( 2 * x + 1, lo, mid, start, end, value );
        update( 2 * x + 2, mid + 1, hi, start, end, value );
    }

    if ( tree[x].marks > 0 )
        tree[x].covered = hi - lo + 1;
    else
        if ( lo == hi )
             tree[x].covered = 0;
        else tree[x].covered = tree[2 * x + 1].covered +
                               tree[2 * x + 2].covered;
}

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
        y1++;
        events[E++] = (event){ x1, y1, y2, +1 };
        events[E++] = (event){ x2, y1, y2, -1 };
    }

    sort( events, events + E );

    last = events[0].idx;
    REP( i, E ) {
        sol += ( events[i].idx - last ) * tree[0].covered;
        last = events[i].idx;
        update( 0, 0, MAXC, events[i].lo, events[i].hi, events[i].kind );
    }

    printf( "%d\n", sol );

    return 0;
}
