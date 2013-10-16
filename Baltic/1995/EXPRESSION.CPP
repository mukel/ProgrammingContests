/*
Alfonso2 Peterssen
8 - 5 - 2008
Baltic 1995 TASK: EXPRESSION
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <cstring>

using namespace std;

const int
    MAXLEN = 50,
    EMPTY = 1 << 30;

int len, pos;
int val;
string vars;
char x, sign;
char expr[MAXLEN];
int value[0x100];
bool defined[0x100];
map< string, int > M;

int main() {

    gets( expr );
    len = strlen( expr );

    for ( x = 'a'; x <= 'z'; x++ )
        value[x] = EMPTY;

    while ( scanf( "%c=%d\n", &x, &val ) != EOF )
        value[x] = val;

    sign = '+';
    while ( pos < len ) {

        vars = ""; val = 1;
        while ( pos < len &&
                expr[pos] != '+' &&
                expr[pos] != '-' ) {

            if ( isdigit( expr[pos] ) ) {
                int v = 0;
                while ( pos < len && isdigit( expr[pos] ) ) {
                    v = v * 10 + ( expr[pos] - '0' );
                    pos++;
                }
                val *= v;
            }

            if ( isalpha( expr[pos] ) ) {
                if ( value[ expr[pos] ] == EMPTY )
                     vars = vars + expr[pos];
                else val *= value[ expr[pos] ];
                pos++;
            }
        }

        sort( vars.begin(), vars.end() );
        if ( pos != 0 )
            if ( sign == '+' )
                 M[vars] += val;
            else M[vars] -= val;

        sign = expr[pos];
        pos++;
    }

    map< string, int >::iterator it;
    for ( it = M.begin(); it != M.end(); it++ )
        if ( (*it).first != "" &&
             (*it).second != 0 ) {
            printf( "UNDEFINED\n" );
            return 0;
        }

    printf( "%d\n", M[""] );

    return 0;
}
