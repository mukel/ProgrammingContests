/*
Alfonso Alfonso Peterssen
11 - 12 - 2007
Task: PERLEXI
Lang: C++
*/
#include <cstdio>
#include <cstring>

const int MAXLEN = 11;

long Q, len, pos, rank;
long i, j, k, dig;
char st[MAXLEN], perm[MAXLEN];
long fact[MAXLEN], less[MAXLEN];
bool mark[MAXLEN];

int main() {

    fact[0] = 1;
    for ( i = 1; i < MAXLEN; i++ )
        fact[i] = fact[i - 1] * i;

    for ( scanf( "%d", &Q ); Q; Q-- ) {

        scanf( "%d", &len );
        if ( len == -1 ) {

            scanf( "%s", &st );

            rank = 0;
            len = strlen( st );
            for ( i = 0; i < len; i++ )
                less[i] = i;

            for ( i = 0; i < len; i++ ) {
                dig = st[i] - '0';
                rank += less[dig] * fact[ len - i - 1 ];
                for ( j = dig; j < len; j++ )
                    less[j]--;
            }

            printf( "%d\n", rank + 1 );

        } else {

            scanf( "%d", &pos );
            pos--;

            for ( i = 0; i < len; i++ )
                mark[i] = false;

            for ( i = 0; i < len; i++ ) {
                j = pos / fact[ len - i - 1 ];
                pos %= fact[ len - i - 1 ];
                for ( k = 0; k < len; k++ )
                    if ( !mark[k] && j-- == 0 ) {
                        mark[k] = true;
                        perm[i] = k + '0';
                        break;
                    }
            }

            perm[len] = '\0';
            printf( "%s\n", perm );
        }
    }

    return 0;
}
