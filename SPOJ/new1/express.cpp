/*
Alfonso2 Peterssen
SPOJ #1683 "Expressions"
10 - 9 - 2008
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int MAXN = 20000;

int T, pos, size;
char expr[MAXN];
string S[MAXN];

void solve( int idx ) {
	pos--;
	size = max( size, idx + 1 );
	S[idx] += expr[pos];
	if ( expr[pos] >= 'A' && expr[pos] <= 'Z' ) {
		solve( idx + 1 );
		solve( idx + 1 );
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%s", &expr );
		pos = strlen( expr );
		size = 0;
		fill( S, S + pos, "" );
		solve( 0 );
		REPD( i, size )
			printf( "%s", S[i].c_str() );
		printf( "\n" );
	}

	return 0;
}
