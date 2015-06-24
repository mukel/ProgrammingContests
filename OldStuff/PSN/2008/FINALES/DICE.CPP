/*
Alfonso2 Peterssen
23 - 4 - 2008
TASK: DICE
*/
#include <cstdio>

const int MAXLEN = 100;

int Q, i, sol;
char cmd[MAXLEN];
int tmp[6], dice[6] = { 1, 2, 3, 4, 5, 6 };

int main() {

    #warning READ FROM FILES!!!
    freopen( "dice.in", "r", stdin );
    freopen( "dice.out", "w", stdout );
    
    sol = 1;
    for( scanf( "%d", &Q ); Q > 0; Q-- ) {

        scanf( "%s", &cmd );
        if ( cmd[0] == 'N' ) {
            tmp[0] = dice[1];
            tmp[1] = dice[5];
            tmp[2] = dice[2];
            tmp[3] = dice[3];
            tmp[4] = dice[0];
            tmp[5] = dice[4];
            for ( i = 0; i < 6; i++ )
                dice[i] = tmp[i];
        }

        if ( cmd[0] == 'S' ) {
            tmp[0] = dice[4];
            tmp[1] = dice[0];
            tmp[2] = dice[2];
            tmp[3] = dice[3];
            tmp[4] = dice[5];
            tmp[5] = dice[1];
            for ( i = 0; i < 6; i++ )
                dice[i] = tmp[i];
        }
        
        if ( cmd[0] == 'E' ) {
            tmp[0] = dice[3];
            tmp[1] = dice[1];
            tmp[2] = dice[0];
            tmp[3] = dice[5];
            tmp[4] = dice[4];
            tmp[5] = dice[2];
            for ( i = 0; i < 6; i++ )
                dice[i] = tmp[i];
        }

        if ( cmd[0] == 'W' ) {
            tmp[0] = dice[2];
            tmp[1] = dice[1];
            tmp[2] = dice[5];
            tmp[3] = dice[0];
            tmp[4] = dice[4];
            tmp[5] = dice[3];
            for ( i = 0; i < 6; i++ )
                dice[i] = tmp[i];
        }

        if ( cmd[0] == 'L' ) {
            tmp[0] = dice[0];
            tmp[1] = dice[3];
            tmp[2] = dice[1];
            tmp[3] = dice[4];
            tmp[4] = dice[2];
            tmp[5] = dice[5];
            for ( i = 0; i < 6; i++ )
                dice[i] = tmp[i];
        }
        
        if ( cmd[0] == 'R' ) {
            tmp[0] = dice[0];
            tmp[1] = dice[2];
            tmp[2] = dice[4];
            tmp[3] = dice[1];
            tmp[4] = dice[3];
            tmp[5] = dice[5];
            for ( i = 0; i < 6; i++ )
                dice[i] = tmp[i];
        }
        
        
        sol += dice[0];
    }

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
