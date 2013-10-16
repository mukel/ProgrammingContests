/*
ID: mukel
TASK: TRI
LANG: C++
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int a, b, c;

    void solution( string s1, string s2 ) {
        cout << a << s1 << b << s2 << c << endl;
        exit( 0 );
    }

int main() {

    cin >> a >> b >> c;
    
    if ( a + b == c ) solution( "+", "=" );
    if ( a - b == c ) solution( "-", "=" );
    if ( a * b == c ) solution( "*", "=" );
    if ( b && a % b == 0 && a / b == c ) solution( "/", "=" );
    
    if ( b + c == a ) solution( "=", "+" );
    if ( b - c == a ) solution( "=", "-" );
    if ( b * c == a ) solution( "=", "*" );
    if ( c && b % c == 0 && b / c == a ) solution( "=", "/" );

    return 0;
}
