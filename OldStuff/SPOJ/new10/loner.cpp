/*
Alfonso2 Peterssen (mukel)
SPOJ #140 "The Loner"
18 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

const int MAXN = 1 << 15;

int T, N;
char S[MAXN];

bool doit( char& a, char &b, char &c ) {
	if ( a != '1' || b != '1' || c != '0' ) return 0;
	a = '0'; b = '0'; c = '1';
	return 1;
}

bool doit( char& a, char &b, char &c, char &d ) {
	if ( a != '1' || b != '0' || c != '1' || d != '1' ) return 0;
	a = '0'; b = '0'; c = '1'; d = '0';
	return 1;
}

bool doit( char& a, char &b, char &c, char &d, char& e ) {
	if ( a != '1' || b != '1' || c != '1' || d != '1' || e != '0' ) return 0;
	a = '0'; b = '0'; c = '1'; d = '0'; e = '1';
	return 1;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &N );
		scanf( "%s", &S );
		
		REP( i, N )
		if ( S[i] == '1' ) {
			if ( i + 2 < N && doit( S[i], S[i + 1], S[i + 2] ) ) continue ;
  			if ( i + 3 < N && doit( S[i], S[i + 1], S[i + 2], S[i + 3] ) ) continue ;
     			if ( i + 4 < N && doit( S[i], S[i + 1], S[i + 2], S[i + 3], S[i + 4] ) ) continue ;
			break ;
		}
		
		REPD( i, N )
		if ( S[i] == '1' ) {
			if ( i - 2 >= 0 && doit( S[i], S[i - 1], S[i - 2] ) ) continue ;
  			if ( i - 3 >= 0 && doit( S[i], S[i - 1], S[i - 2], S[i - 3] ) ) continue ;
     			if ( i - 4 >= 0 && doit( S[i], S[i - 1], S[i - 2], S[i - 3], S[i - 4] ) ) continue ;
			break ;
		}

		if ( count( S, S + N, '1' ) == 1 )
		      printf( "yes\n" );
		else
		      printf( "no\n" );
	}

	return 0;
}
