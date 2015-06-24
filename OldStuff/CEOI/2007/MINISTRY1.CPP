/*
Alfonso2 Peterssen
25 - 7 - 2008
CEOI 2007 "Ministry"
Simple O( n lg n )
*/
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

extern int _stklen = 20000000;

const int MAXV = 1000000;

int V;
int sol[MAXV];
int depth[MAXV];

struct node {
    int son[3];
    node() { memset( son, -1, sizeof( son ) ); }
    void normalize() { sort( son, son + 3 ); }
    bool operator < ( const node &n ) const {
        return memcmp( son, n.son, sizeof( son ) ) < 0;
    }
} tree[MAXV];

map< node, int > M;
map< node, int >::iterator it;

int dfs() {

    int u = V++;
    for ( int i = 0; getchar() == '('; i++ )
        depth[u] >?= depth[ tree[u].son[i] = dfs() ] + 1;

    tree[u].normalize();
    it = M.find( tree[u] );
    if ( it == M.end() ) {
        sol[ depth[u] ]++;
        M[ tree[u] ] = u;
    } else
        u = (*it).second;

    return u;
}

int main() {

    getchar(); dfs();
    for ( int i = 0; i <= depth[0]; i++ )
        printf( "%d\n", sol[i] );

    return 0;
}
