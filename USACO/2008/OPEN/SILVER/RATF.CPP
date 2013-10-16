/*
Alfonso2 Peterssen
29 - 5 - 2008
USACO OPEN08 Silver "Caminos alrededor de La Granja"
*/
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int N, K;
map< int, int > M;

int memo( int x ) {
    if ( x <= K )
        return 1;
    if ( ( x - K ) & 1 ) return 1;
    if ( ( x + K ) & 1 ) return 1;
    int res = M[x];
    if ( res != 0 )
        return res;
    res = memo( ( x - K ) / 2 ) + memo( ( x + K ) / 2 );
    return ( M[x] = res );
}

int main() {

    freopen( "ratf.in", "r", stdin );
    freopen( "ratf.out", "w", stdout );

    cin >> N >> K;

    cout << memo( N ) << endl;

    return 0;
}
