/*
Alfonso2 Peterssen
25 - 7 - 2008
CEOI 2007 "Ministry"
O( n ) expected using hash_map
*/
#include <cstdio>
#include <algorithm>
#include <ext/hash_map>
#include <cstring>

using namespace std;
using namespace __gnu_cxx;

extern int _stklen = 20000000;

const int MAXV = 1000000;

int V;
int sol[MAXV];
int depth[MAXV];

struct node {
    int son[3];
    node() {
        memset( son, -1, sizeof( son ) );
    }

    void normalize() {
        sort( son, son + 3 );
    }

    struct hash {
        int operator () ( const node &n ) const {
            return n.son[0] + n.son[1] + n.son[2];
        }
    };

    struct equal {
        bool operator () ( const node &a, const node &b ) const {
            return memcmp( a.son, b.son, sizeof( a.son ) ) == 0;
        }
    };

} tree[MAXV];


hash_map< node, int, node::hash, node::equal > M;
hash_map< node, int, node::hash, node::equal >::iterator it;

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
