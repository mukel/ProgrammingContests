/*
Alfonso2 Peterssen
29 - 5 - 2008
Copa UCI 2008 "Beisbol en Königsberg"
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 10000;

int T, V, E;
int u, v;
int deg[MAXV];

int main() {

    scanf( "%d", &T );
    while ( T-- ) {

        scanf( "%d %d", &V, &E );
        memset( deg, 0, sizeof( deg ) );
        REP( i, E ) {
            scanf( "%d %d", &u, &v );
            u--; v--;
            deg[u]++;
            deg[v]++;
        }

        int euler = 1;
        REP( i, V )
            if ( deg[i] & 1 )
                euler = 0;

        printf( "%d\n", euler );
    }

    return 0;
}
