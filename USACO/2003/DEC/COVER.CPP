/*
Alfonso2 Peterssen
24 - 5 - 2008
USACO MAR03 Gold "Rain Cover"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair< int, int > event;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 25000;

int N, sol;
int u, v;
int i, j, k, id, cant;
int pos[MAXN];
vector< event > events;
int T[2 * MAXN + 1];

void update( int x ) {
    for ( ; x <= 2 * N; x += x & -x )
        T[x]++;
}

int query( int x ) {
    int sum = 0;
    for ( ; x > 0; x -= x & -x )
        sum += T[x];
    return sum;
}

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%d %d", &u, &v );
        events.push_back( event( u, i ) );
        events.push_back( event( v, i ) );
    }

    sort( ALL( events ) );

    /* Compress */
    for ( i = 0; i < events.size(); i = j ) {
        id++;
        for ( j = i + 1; j < events.size() &&
              events[j].first == events[i].first; j++ );
        for ( k = i; k < j; k++ )
            events[k].first = id;
    }

    /* Sweep */
    REP( i, events.size() ) {
        int idx = events[i].second;
        if ( pos[idx] == 0 )
            pos[idx] = events[i].first;
        else {
            sol >?= cant - query( pos[idx] );
            update( pos[idx] );
            cant++;
        }
    }

    printf( "%d\n", sol );

    return 0;
}
