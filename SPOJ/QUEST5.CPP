/*
Alfonso2 Peterssen
7 - 6 - 2008
SPOJ #661 "Nail Them"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/* fors++  */
#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 100000;

int T, N;
int nails;
int u, v;
bool mark[MAXN];
struct event {
    int pos, kind, id;
    bool operator < ( const event &e ) const {
        if ( pos != e.pos ) return pos < e.pos;
        return kind > e.kind;
    }
};
stack< int > S;

int main() {

    scanf( "%d", &T );
    while ( T-- ) {
        scanf( "%d", &N);

        vector< event > events;
        fill( mark, mark + N, 0 );

        REP( i, N ) {
            scanf( "%d %d", &u, &v );
            events.push_back( (event){ u, +1, i } );
            events.push_back( (event){ v, -1, i } );
        }

        nails = 0;
        stable_sort( ALL( events ) );

        REP( i, events.size() ) {
            int id = events[i].id;
            if ( events[i].kind == +1 )
                S.push( id );
            else if ( !mark[id] ) {
                nails++;
                for ( ; !S.empty(); S.pop() )
                    mark[ S.top() ] = true;
            }
        }

        printf( "%d\n", nails );
    }

    return 0;
}
