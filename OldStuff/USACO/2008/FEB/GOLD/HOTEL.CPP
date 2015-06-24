/*
Alfonso2 Peterssen
23 - 6 - 2008
USACO FEB08 "Hotel"
*/
#include <cstdio>

const int MAXN = 60000;

int N, Q;
int kind, d, lo, hi;
struct node {
    int l, c, r, best, used;
} tree[4 * MAXN];

int query( int x, int lo, int hi, int value ) {

    if ( lo > hi ) return 0;
    //printf( "query %d -> %d %d -> %d\n", x, lo, hi, value );
    int mid = ( lo + hi ) / 2;
    
    if ( tree[x].l >= value )
        return lo;
        
    if ( tree[2 * x + 1].best >= value )
        return query( 2 * x + 1, lo, mid, value );
        
    if ( tree[x].c >= value )
        return  mid - tree[2 * x + 1].r + 1;
        
    if ( tree[2 * x + 2].best >= value )
        return query( 2 * x + 2, mid + 1, hi, value );
        
    if ( tree[x].r >= value )
        return hi - tree[x].r;
    
    return 0;
}

void update( int x, int lo, int hi, int start, int end, int value ) {

    if ( lo > hi || lo > end || hi < start )
        return ;
        
    //printf( "upd %d -> %d %d -> %d %d -> %d\n", x, lo, hi, start, end, value );

    int mid = ( lo + hi ) / 2;
    
    if ( lo >= start && hi <= end ) {
        tree[x].used = value;
        if ( value == +1 ) tree[x].l = tree[x].c = tree[x].r = tree[x].best = 0;
        if ( value == -1 ) tree[x].l = tree[x].c = tree[x].r = tree[x].best = hi - lo + 1;
        //printf( "node %d = %d %d %d %d %d\n", x, tree[x].l, tree[x].c, tree[x].r, tree[x].best, tree[x].used );
        return ;
    }
    
    if ( tree[x].used != 0 ) {
        update( 2 * x + 1, lo, mid, lo, mid, tree[x].used );
        update( 2 * x + 2, mid + 1, hi, mid + 1, hi, tree[x].used );
        tree[x].used = 0;
    }
    
    update( 2 * x + 1, lo, mid, start, end, value );
    update( 2 * x + 2, mid + 1, hi, start, end, value );
    
    /* FIX */
    tree[x].l = tree[2 * x + 1].l;
    tree[x].r = tree[2 * x + 2].r;

    if ( tree[2 * x + 1].l == mid - lo + 1 )
        tree[x].l += tree[2 * x + 2].l;
        
    if ( tree[2 * x + 2].r == hi - ( mid + 1 ) + 1 )
        tree[x].r += tree[2 * x + 1].r;
    
    tree[x].c = tree[2 * x + 1].r + tree[2 * x + 2].l;
    tree[x].best = tree[2 * x + 1].best >?
                   tree[2 * x + 2].best >?
                   ( tree[x].l >? tree[x].c >? tree[x].r );
                   
    //printf( "node %d = %d %d %d %d %d\n", x, tree[x].l, tree[x].c, tree[x].r, tree[x].best, tree[x].used );
}

int main() {

    scanf( "%d %d", &N, &Q );
    
    update( 0, 1, N, 1, N, -1 );
    
    while ( Q-- ) {
        scanf( "%d", &kind );
        if ( kind == 1 ) {
            scanf( "%d", &d );
            int pos = query( 0, 1, N, d );
            printf( "%d\n", pos );
            if ( pos != 0 )
                update( 0, 1, N, pos, pos + d - 1, +1 ); // MARK
        } else {
            scanf( "%d %d", &lo, &hi );
            hi = lo + hi - 1;
            update( 0, 1, N, lo, hi, -1 ); // UNMARK
        }
    }

    return 0;
}
