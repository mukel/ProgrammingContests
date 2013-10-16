/*
Alfonso2 Peterssen
17 - 6 - 2008
IOI 2005 "Mountains"
Very Nice Tree
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXQ = 100005,
    UNUSED = -(1 << 30);

int Q, N;
int coords[MAXQ * 2];
struct op {
    int kind, lo, hi, value;
} ops[MAXQ];
struct node {
    int sum, maxheight, value;
} tree[MAXQ * 6];

void update( int x, int lo, int hi, int start, int end, int value ) {

    if ( lo > hi || lo > end || hi < start )
        return ;

    if ( lo >= start && hi <= end ) {
        tree[x].sum = ( coords[hi] - coords[lo - 1] ) * value;
        tree[x].maxheight = tree[x].sum >? 0; // keep it non-negative
        tree[x].value = value;
        return ;
    }

    int mid = ( lo + hi ) / 2;
    if ( tree[x].value != UNUSED ) {
        update( 2 * x + 1, lo, mid, lo, mid, tree[x].value );
        update( 2 * x + 2, mid + 1, hi, mid + 1, hi, tree[x].value );
        tree[x].value = UNUSED;
    }

    update( 2 * x + 1, lo, mid, start, end, value );
    update( 2 * x + 2, mid + 1, hi, start, end, value );

    tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
    tree[x].maxheight = tree[2 * x + 1].maxheight >?
                        tree[2 * x + 1].sum + tree[2 * x + 2].maxheight;
}

int query( int x, int lo, int hi, int height ) {

    if ( tree[x].maxheight <= height )
            return coords[hi];

    if ( tree[x].value != UNUSED )
        return coords[lo - 1] + height / tree[x].value;

    int mid = ( lo + hi ) / 2;
    return ( tree[2 * x + 1].maxheight > height )
        ? query( 2 * x + 1, lo, mid, height )
        : query( 2 * x + 2, mid + 1, hi, height - tree[2 * x + 1].sum );
}

int main() {

    // sentinels
    coords[N++] = 0;
    scanf( "%d\n", &coords[N] ); N++;

    for ( ; ; Q++ ) {
        scanf( "%c ", &ops[Q].kind );
        if ( ops[Q].kind == 'I' ) {
            scanf( "%d %d %d\n", &ops[Q].lo, &ops[Q].hi, &ops[Q].value );
            ops[Q].lo--;
            coords[N++] = ops[Q].lo;
            coords[N++] = ops[Q].hi;
        } else
        if ( ops[Q].kind == 'Q' )
            scanf( "%d\n", &ops[Q].lo );
        else
            break;
    }

    sort( coords, coords + N );
    N = unique( coords, coords + N ) - coords;

    for ( int i = 0; i < Q; i++ ) {
        if ( ops[i].kind == 'Q' )
            printf( "%d\n", query( 0, 0, N - 1, ops[i].lo ) );
        else
            update( 0, 0, N - 1,
                lower_bound( coords, coords + N, ops[i].lo ) - coords + 1,
                lower_bound( coords, coords + N, ops[i].hi ) - coords,
                ops[i].value );
    }

    return 0;
}

