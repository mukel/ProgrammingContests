/*
ID: a2peter1
TASK: buylow
LANG: C++
*/
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 5000;

int N, i, j, len;
int ls[MAXN], dp[MAXN];

const int
    BASE = 1000000000,
    LOGBASE = 9,
    MAXSIZE = 80;

struct bigint {

    int size, digit[MAXSIZE];

    void operator += ( const bigint &x ) {
        size >?= x.size;
        int i, tmp, r = 0;
        for ( i = 0; i < size; i++ ) {
            tmp = digit[i] + x.digit[i] + r;
            digit[i] = tmp % BASE;
            r = tmp / BASE;
        }
        for ( ; r > 0; r /= BASE )
            digit[size++] = r % BASE;
    }

    void operator = ( int x ) {
        size = 0;
        for ( ; x > 0; x /= BASE )
            digit[size++] = x % BASE;
    }

} cant, ways[MAXN];

    ostream& operator << ( ostream &f, const bigint &x ) {
        f << x.digit[ x.size - 1 ];
        for ( int i = x.size - 2; i >= 0; i-- ) {
            f.width( LOGBASE ); f.fill( '0' );
            f << x.digit[i];
        }
        return f;
    }

int main() {

    freopen( "buylow.in", "r", stdin );
    freopen( "buylow.out", "w", stdout );

    cin >> N;
    for ( i = 0; i < N; i++ ) {

        cin >> ls[i];

        for ( j = 0; j < i; j++ )
            if ( ls[j] > ls[i] )
                dp[i] >?= dp[j] + 1;

        len >?= dp[i];

        for ( j = i - 1; j >= 0; j-- ) {
            if ( ls[j] == ls[i] && dp[j] == dp[i] )
                break;
            if ( ls[j] > ls[i] && dp[j] + 1 == dp[i] )
                 ways[i] += ways[j];
        }

        if ( j < 0 && dp[i] == 0 )
            ways[i] = 1;
    }

    for ( i = 0; i < N; i++ )
        if ( dp[i] == len )
            cant += ways[i];

    cout << len + 1 << " " << cant << endl;

    return 0;
}
