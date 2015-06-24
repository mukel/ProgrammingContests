/*
Alfonso2 Peterssen
23 - 7 - 2008
APIO 2007 "Backup"
*/
#include <cstdio>
#include <set>

using std::set;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 100001;

int N, K, sol;
int value, kk;
int l, r, pos;
int C[MAXN];
int next[MAXN];
int last[MAXN];
struct _comp {
    bool operator () ( const int &i, const int &j ) {
        return C[i] != C[j] ? C[i] < C[j] : i < j;
    }
};
set< int, _comp > S;

int main() {

    scanf( "%d %d", &N, &K );
    REP( i, N ) {
        scanf( "%d", &value );
        if ( i ) {
            C[i] = value - kk;
            S.insert( i );
            next[i] = i + 1;
            last[i] = i - 1;
        }
        kk = value;
    }
    next[N - 1] = last[1] = 0; // none

    REP( i, K ) {

        pos = *S.begin();
        l = last[pos];
        r = next[pos];

        S.erase( pos );
        if ( l ) S.erase( l );
        if ( r ) S.erase( r );

        sol += C[pos];
        C[pos] = C[l] + C[r] - C[pos];
        if ( l && r ) {
            S.insert( pos );
            last[pos] = last[l];
            next[pos] = next[r];
        } else
            pos = 0;

        if ( last[l] ) next[ last[l] ] = pos;
        if ( next[r] ) last[ next[r] ] = pos;
    }

    printf( "%d\n", sol );

    return 0;
}
