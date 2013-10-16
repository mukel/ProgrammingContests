/*
Alfonso Alfonso Peterssen
1 - 12 - 2007
SPOJ #1028 "Hubulullu"
*/
#include <cstdio>

const char* name[2] =
    { "Airborne", "Pagfloyd" };

int T, N, P;

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {
        scanf( "%d %d", &N, &P );
        printf( "%s wins.\n", name[P] );
    }

    return 0;
}
