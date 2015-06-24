/*
Alfonso Alfonso Peterssen
13 - 2 - 2008
Saratov #140 "Keyword"
*/
#include <cstdio>
#include <cstring>

const int MAXLEN = 500000;

int len, i, j, k;
int num, pot;
char seq[MAXLEN + 1];
bool used[MAXLEN];

int main() {

    scanf( "%d", &len );
    scanf( "%s", &seq );

    for ( i = 0; i < len; i++ )
        seq[i] -= 'a';

    for ( i = 1; i <= len; i++ ) {

        pot = 1 << i;
        memset( used, 0, pot );

        num = 0;
        for ( j = 0; j < i; j++ )
            num = ( num << 1 ) + seq[j];

        used[num] = true;

        for ( ; j < len; j++ ) {
            num = ( num << 1 ) - ( seq[j - i] << i ) + seq[j];
            used[num] = true;
        }

        for ( j = 0; j < pot && used[j]; j++ );

        if ( j < pot ) {
            printf( "%d\n", i );
            for ( k = i - 1; k >= 0; k-- )
                if ( j & ( 1 << k ) )
                     printf( "b" );
                else printf( "a" );
            printf( "\n" );
            break;
        }
    }

    return 0;
}
