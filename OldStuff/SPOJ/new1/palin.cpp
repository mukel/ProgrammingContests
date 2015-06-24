/*
Alfonso2 Peterssen
SPOJ #5 "The Next Palindrome"
3 - 9 - 2008
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

#define ALL( c ) (c).begin(), (c).end()

const int MAXLEN = 1000001;

int T;
string S, L, R, rL, rR, sol;
char line[MAXLEN];

void PLUS( string& st ) {
	int r = 0, t;
	reverse( ALL( st ) );
	REP( i, st.size() ) {
		t = st[i] - '0' + r + !i;
		r = t / 10;
		st[i] = (char)t % 10 + '0';
	}
	if ( r > 0 )
		st.push_back( (char)r + '0' );
	reverse( ALL( st ) );
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%s", line );
		
		S = line;

		PLUS( S );
		L = S.substr( 0, S.size() / 2 );
		R = S.substr( ( S.size() + 1 ) / 2, S.size() / 2 );

		rL = L;
		reverse( ALL( rL ) );
		
		if ( rL >= R ) {
			if ( S.size() % 2 )
				sol = L + S[S.size() / 2] + rL;
			else
				sol = L + rL;
		}
		else {
			if ( S.size() % 2 == 0 ||
				( S.size() % 2 == 1 && S[S.size() / 2] == '9' ) )
				PLUS( L );
			rL = L;
			reverse( ALL( rL ) );
			if ( S.size() % 2 )
				sol = L + (char)( ( S[S.size() / 2] - '0' + 1 ) % 10 + '0' ) + rL;
			else
				sol = L + rL;
		}
				
		printf( "%s\n", sol.c_str() );
	}

	return 0;
}
