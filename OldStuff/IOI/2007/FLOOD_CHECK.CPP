/*
Alfonso2 Peterssen
9 - 5 - 2008
IOI 2007 Task Flood
check <ok_output> <your_output>
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

int A, B, i;
int a[MAXN], b[MAXN];

int main( int argc, char *argv[]  ) {

    freopen( argv[1], "r", stdin );
    scanf( "%d", &A ); for ( i = 0; i < A; i++ ) scanf( "%d", &a[i] );
    freopen( argv[2], "r", stdin );
    scanf( "%d", &B ); for ( i = 0; i < B; i++ ) scanf( "%d", &b[i] );

    sort( a, a + A );
    sort( b, b + B );
    if ( A == B && equal( a, a + A, b ) )
         printf( "OK!!!\n" );
    else printf( "Wrong!!!\n" );

    return 0;
}
