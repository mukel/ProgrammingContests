/*
Alfonso2 Peterssen
12 - 4 - 2008
TASK: PARKING
*/
#include <cstdio>

int i, j, lo, hi;
int money;
int cost[4];
int trucks[200];

int main() {

    for ( i = 1; i <= 3; i++ )
        scanf( "%d", &cost[i] );
        
    for ( i = 1; i <= 3; i++ ) {
        scanf( "%d %d", &lo, &hi );
        for ( j = lo; j < hi; j++ )
            trucks[j]++;
    }
    
    for ( i = 0; i <= 100; i++ )
        money += trucks[i] * cost[ trucks[i] ];
        
    printf( "%d\n", money );

    return 0;
}


