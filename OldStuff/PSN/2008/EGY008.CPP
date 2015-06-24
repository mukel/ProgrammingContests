/*
Alfonso Alfonso Peterssen
21 - 2 - 2008
CNC 2008 Task 1B "Dobles"
*/
#include <cstdio>
#include <cstring>

const int
    MAXB = 200,
    MAXLEN = 10000;

int B, i, j, t, carry, len;
int num[MAXLEN];
int sol[MAXLEN];
bool mark[MAXB];

int main() {

    scanf( "%d", &B );
    
    len = MAXLEN;
    for ( i = 1; i < B; i++ ) {
        num[0] = i;
        memset( mark, 0, sizeof( mark ) );
        for ( j = 0; !mark[i]; j++ ) {
            t = 2 * num[j] + carry;
            num[j + 1] = t % B;
            carry = t / B;
            if ( carry == 0 )
                mark[ num[j + 1] ] = true;
        }
        if ( j < len )
            memcpy( sol, num, ( len = j ) * 4 );
    }
    
    for ( j = len - 1; j >= 0; j-- )
        printf( j == 0 ? "%d\n" : "%d ", sol[j] );

    return 0;
}
