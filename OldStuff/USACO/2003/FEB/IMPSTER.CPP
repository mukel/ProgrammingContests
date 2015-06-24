/*
Alfonso2 Peterssen
4 - 6 - 2008
USACO FEB03 "Cow Imposters"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXN = 100,
    MAXL = 16,
    oo = 1 << 29;
    
int L, N;
int target;
int delta;
int now, next;
int diff, sol;
int brand[MAXN];
int dist[1 << MAXL];
char st[MAXL + 1];
queue< int > Q;

int main() {

    scanf( "%d %d", &L, &N );
    
    scanf( "%s", &st );
    REP( i, L )
        target = target * 2 + ( st[i] == '1' );
        
    fill( dist, dist + ( 1 << L ), oo );
    REP( i, N ) {
        scanf( "%s", &st );
        REP( j, L )
            brand[i] = brand[i] * 2 + ( st[j] == '1' );
        dist[ brand[i] ] = 0;
        Q.push( brand[i] );
    }
    
    for ( ; !Q.empty(); Q.pop() ) {
        now = Q.front();
        REP( i, N ) {
            next = now ^ brand[i];
            if ( dist[next] == 0 || dist[now] + 1 < dist[next] ) {
                dist[next] = dist[now] + 1;
                Q.push( next );
            }
        }
    }
    
    diff = oo;
    REP( i, ( 1 << L ) ) {
        if ( dist[i] == oo )
            continue;
        delta = __builtin_popcount( i ^ target );
        if ( delta < diff ||
           ( delta == diff && dist[i] < dist[sol] ) ) {
            diff = delta;
            sol = i;
        }
    }

    printf( "%d\n", dist[sol] );
    REP( i, L )
        st[L - i - 1] = '0' + ( sol >> i ) % 2;
    printf( "%s\n", st );

    return 0;
}
