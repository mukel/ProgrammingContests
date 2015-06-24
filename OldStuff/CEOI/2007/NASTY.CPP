/*
Alfonso2 Peterssen
25 - 7 - 2008
CEOI 2007 "Nasty Calculations"
*/
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

enum __sign { PLUS = -4, MINUS, MUL, VAR };

const int MAXB = 36;

int B, N;
int t;
char tok[100], ch;
int result[MAXB];
vector< int > T;

int digit( char ch ) {
    if ( ch <= '9' ) return ch - '0';
    return ch - 'A' + 10;
}

int get_value( char *s, int base ) {
    int len = strlen( s ), value = 0;
    REP( i, len )
        value = value * base + digit( s[i] );
    return value;
}

int main() {

    scanf( "%d %d\n", &B, &N );
    while ( ch != '\n' ) {
        scanf( "%s%c", &tok, &ch );
        switch ( tok[0] ) {
            case '+' : T.push_back( PLUS ); break;
            case '-' : T.push_back( MINUS ); break;
            case '*' : T.push_back( MUL ); break;
            case 'x' : T.push_back( VAR ); break;
            default : T.push_back( get_value( tok, B ) % B ); break;
        }
    }

    REP( x, B ) {
        stack< int > S;
        REP( i, T.size() )
            switch ( T[i] ) {
                case PLUS  : t = S.top(); S.pop(); S.top() = ( S.top() + t ) % B; break;
                case MINUS : t = S.top(); S.pop(); S.top() = ( S.top() - t + B ) % B; break;
                case MUL   : t = S.top(); S.pop(); S.top() = ( S.top() * t ) % B; break;
                case VAR   : S.push( x ); break;
                default    : S.push( T[i] ); break;
            }
        result[x] = S.top();
    }

    REP( i, N ) {
        gets( tok );
        ch = result[ get_value( tok, B ) % B ] % B;
        printf( "%c\n", ( ch <= 9 ) ? ch + '0' : ch - 10 + 'A'  );
    }

    return 0;
}
