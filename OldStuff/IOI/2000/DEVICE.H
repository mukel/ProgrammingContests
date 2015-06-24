/*
Alfonso2 Peterssen
8 - 6 - 2008
IOI 2000 "Median"
Simple Test Library -> #include "device.h"
*/
#include <cstdio>
#include <algorithm>

/* define library namespace */
namespace device {

using std::swap;

const int MAXN = 1500;
int N, queries;
int S[MAXN];

int GetN() {
    scanf( "%d", &N );
    for ( int i = 1; i <= N; i++ )
        scanf( "%d", S + i );
    printf( "GetN() = %d\n", N );
    return N;
}

int Med3( int a, int b, int c ) {
    queries++;
    if ( S[a] > S[b] ) swap( a, b );
    if ( S[b] > S[c] ) swap( b, c );
    if ( S[a] > S[b] ) swap( a, b );
    //printf( "Med3( %d, %d, %d ) = %d\n", a, b, c, b );
    return b;
}

void Answer( int sol ) {
    printf( "Answer: %d -> using %d queries\n", sol, queries );
    if ( S[sol] == N / 2 + 1 )
         printf( "OK!!!\n" );
    else printf( "Wrong!!!\n" );
}

} // end library namespace

/* public interface */
using device::GetN;
using device::Med3;
using device::Answer;
