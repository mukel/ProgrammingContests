/*
Alfonso2 Peterssen
10 - 6 - 2008
BalticOI 2001 "Teleports"
*/
#include <cstdio>
#include <queue>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 100000;

int A, B;
int to[MAXN];
int st[MAXN];
int deg[MAXN];
std::queue< int > Q;

int main() {

    scanf( "%d %d", &A, &B );
    REP( i, A + B ) {
        scanf( "%d", &to[i] );
        to[i]--;
        if ( i < A ) {
            st[i] = 1;
            to[i] += A;
            deg[ to[i] ]++;
        }
    }

    REP( i, B )
        if ( !deg[i + A] )
            Q.push( i + A );

    for ( ; !Q.empty(); Q.pop() ) {
        int top = Q.front();
        st[top] = 1;
        if ( st[ to[top] ] ) {
            st[ to[top] ] = 0;
            int nxt = to[ to[top] ];
            if ( !st[nxt] && !--deg[nxt] )
                Q.push( nxt );
        }
    }

    REP( i, A ) printf( "%d", st[i] );     printf( "\n" );
    REP( i, B ) printf( "%d", st[i + A] ); printf( "\n" );

    return 0;
}
