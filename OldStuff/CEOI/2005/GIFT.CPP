/*
Alfonso Alfonso Peterssen ( mukel )
CEOI 2005 Practice Task "Gift Giving"
*/
#include <cstdio>

const int MAXN = 1000000;

#define REP( i, n ) \
    for( i = 0; i < (n); i++ )

int n, i, j, sol;
int nx[MAXN];
int id[MAXN];
bool used[MAXN];
bool happy[MAXN];

int main() {

    scanf( "%d", &n );
    REP( i, n ) {
        scanf( "%d", &nx[i] );
        happy[ --nx[i] ] = true;
    }

    REP( i, n ) if ( !happy[i] ) {
        for ( j = i; id[j] < 1; id[j] = 1, j = nx[j] );
        if ( id[ nx[j] ] == 1 )
            for (      ; id[j] < 2; id[j] = 2, j = nx[j] )
                sol++, used[j] = true;
    }

    REP( i, n )
        if ( id[i] == 0 )
            sol++, used[j] = true;

    printf( "%d\n", sol );
    REP( i, n )
        if ( used[i] )
            printf( "%d ", i + 1 );

    printf( "\n" );

    fflush( stdout );

    return 0;
}
