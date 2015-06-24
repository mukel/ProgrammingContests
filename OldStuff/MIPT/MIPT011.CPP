/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #011 "Multiple Brackets"
*/
#include <cstdio>
#include <cstring>
#include <stack>

using std::stack;

const char
    brackets[] = "(){}[]<>";

const int MAXLEN = 100000;

int len, pos, i;
char line[MAXLEN + 1];
stack< char > S;

int main() {

    gets( line );
    len = strlen( line );

    for ( i = 0; i < len; i++ ) {
        char ch = line[i];
        pos = strchr( brackets, ch ) - brackets;
        if ( !( pos & 1 ) )
            S.push( ch );
        else {
            if ( S.empty() ) break;
            if ( S.top() != brackets[pos^1] ) break;
            S.pop();
        }
    }

    if ( i == len && S.empty() )
         printf( "YES\n" );
    else printf( "NO\n" );

    return 0;
}
