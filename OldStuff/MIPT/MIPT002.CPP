/*
Alfonso2 Peterssen
17 - 7 - 2008
MIPT #002 "Set Intersection"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXC = 1000001;

int x;
bool output;
bool used[MAXC][2];

int main() {

    while ( scanf( "%d", &x ) && x != -1 ) used[x][0] = true;
    while ( scanf( "%d", &x ) && x != -1 ) used[x][1] = true;
    
    REP( i, MAXC )
        if ( used[i][0] && used[i][1] ) {
            printf( "%d ", i );
            output = true;
        }
        
    if ( !output )
        printf( "empty\n" );

    return 0;
}
