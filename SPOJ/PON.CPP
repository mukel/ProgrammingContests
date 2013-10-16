/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
SPOJ #288 "Prime or Not"
*/
#include <iostream>
using namespace std;

typedef unsigned long long qword;

const int
    MAXP = 9,
    prime[MAXP] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

    qword mul( qword a, qword b, qword m ) {

        if ( b == 0 ) return 0;

        qword res = 2 * mul( a, b / 2, m ) % m;
        if ( b % 2 )
            res = ( res + a ) % m;

        return res;
    }

    qword power( qword x, qword n, qword m ) {

        qword res = 1;
        for ( ; n; x = mul( x, x, m ), n /= 2 )
        if ( n % 2 )
            res = mul( res, x, m );

        return res;
    }

    bool rabin_miller( qword p ) {

        if ( p < 2 || ( p > 2 && !( p % 2 ) ) )
            return false;

        for ( int i = 0; i < MAXP && prime[i] < p; i++ )
            if ( power( prime[i], p - 1, p ) != 1 )
                return false;

        return true;
    }

int main() {

    int T;
    qword N;

    for ( cin >> T; T; T-- ) {
        cin >> N;
        if ( rabin_miller( N ) )
             cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
