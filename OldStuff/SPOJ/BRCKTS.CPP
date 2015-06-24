/*
Alfonso Alfonso Peterssen
28 - 11 - 2007
SPOJ #61 "Brackets"
*/
#include <cstdio>

const int MAXN = 30000;

int T, Q, N, offset, i, j, k;
char st[MAXN + 1];
struct node {
    int sum, value;
} tree[ 3 * MAXN ];

    void update( int x ) {
        tree[x].sum =   tree[ 2 * x ].sum + tree[ 2 * x + 1 ].sum;
        tree[x].value = ( tree[ 2 * x ].value <?
                          tree[ 2 * x ].sum + tree[ 2 * x + 1 ].value );
    }

int main() {

    for ( T = 1; T <= 10; T++ ) {

        scanf( "%d", &N );
        scanf( "%s", &st );

        /* Build Segment Tree */
        for ( offset = 1; offset < N; offset *= 2 );

        for ( i = 0; i < N; i++ ) {
            ( st[i] == '(' ) ? j = 1 : j = -1;
            tree[ offset + i ] = ( node ) { j, j };
        }

        for ( i += offset; i < offset * 2; i++ )
            tree[i] = ( node ) { 0, 0 };

        for ( i = offset - 1; i; i-- )
            update( i );

        /* Answer the queries */
        printf( "Test %d:\n", T );
        for ( scanf( "%d", &Q ); Q; Q-- ) {

            scanf( "%d", &j );
            if ( j ) {

                j += offset - 1;
                k = tree[j].value;
                tree[j] = ( node ) { -k, -k };

                while ( j /= 2 )
                    update( j );

            } else
                if ( tree[1].value == 0 && tree[1].sum == 0 )
                     printf( "YES\n" );
                else printf( "NO\n" );
        }
    }

    return 0;
}
