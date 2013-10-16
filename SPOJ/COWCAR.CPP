/*
Alfonso2 Peterssen
6 - 7 - 2008
SPOJ #2714 "Cow Cars"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 100000;

int N, M, D, L, sol;
int S[MAXN];

int main() {
    scanf( "%d %d %d %d", &N, &M, &D, &L );
    REP( i, N )
        scanf( "%d", S + i );
    sort( S, S + N );
    REP( i, N )
        if ( S[i] - D * ( sol / M ) >= L )
            sol++;
    printf( "%d\n", sol );
    return 0;
}
