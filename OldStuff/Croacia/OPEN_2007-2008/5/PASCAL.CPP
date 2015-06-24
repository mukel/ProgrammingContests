/*
ID: mukel
TASK: PASCAL
LANG: C++
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int n, i;

int main() {

    cin >> n;
    for ( i = 2; i * i <= n; i++ )
        if ( n % i == 0 ) {
            cout << n - ( n / i ) << endl;
            exit( 0 );
        }
    
    cout << n - 1 << endl;

    return 0;
}
