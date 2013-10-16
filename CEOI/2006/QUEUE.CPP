/*
Alfonso2 Peterssen
Task: "Queue"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

typedef pair< int, int > par;

const int
    MAXS = 50000,
    oo = (int)2e9;

int N, S;
char op;
int a, b, l, value;
int val, last_val, next_val;
int pos, last_pos, next_pos;
map< int, int > next, last;
int sol[MAXS];
vector< par > P, L;

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%d %d", &a, &b );
        if ( next.find( a ) == next.end() ) next[a] = a + 1;
        if ( last.find( a ) == last.end() ) last[a] = a - 1;
        if ( last.find( b ) == last.end() ) last[b] = b - 1;
        // erase a
        next[ last[a] ] = next[a];
        last[ next[a] ] = last[a];
        // insert a
        next[ last[b] ] = a;
        next[a] = b;
        last[a] = last[b];
        last[b] = a;
    }

    scanf( "%d\n", &S );
    REP( i, S ) {
        scanf( "%c %d\n", &op, &value );
        if ( op == 'L' )
             L.push_back( make_pair( value, i ) );
        else P.push_back( make_pair( value, i ) );
    }

    sort( ALL( L ) );
    sort( ALL( P ) );

    next[oo] = oo; // sentinel
    while ( val != oo ) {

        if ( next.find( val ) == next.end() ) {
            next_val = (*next.upper_bound( val )).first;
            last_pos = pos;
            pos += next_val - val;
            last_val = val;
            val = next_val;
        } else {
            last_pos = ++pos;
            last_val = val = next[val];
        }

        while ( l < L.size() &&
                L[l].first >= last_pos && L[l].first <= pos ) {
            sol[ L[l].second ] = last_val + L[l].first - last_pos;
            l++;
        }

        int lo = lower_bound( ALL( P ), make_pair( last_val, -oo ) ) - P.begin();
        int hi = upper_bound( ALL( P ), make_pair( val, +oo ) ) - P.begin();
        for ( ; lo < hi; lo++ )
            sol[ P[lo].second ] = last_pos + P[lo].first - last_val;
    }

    REP( i, S )
        printf( "%d\n", sol[i] );

    return 0;
}
