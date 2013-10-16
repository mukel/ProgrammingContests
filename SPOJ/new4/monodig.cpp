/*
Alfonso2 Peterssen
SPOJ #200 "Monodigital Representations"
19 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOREACH( it, c ) \
	for ( typeof( (c).begin() ) it = (c).begin(); it != (c).end(); it++  )

int T, K, N;
int num[10][10];
set< int > S[10][10];

int main() {

	// preprocess
	for ( int digit = 1; digit <= 9; digit++ ) {

		num[digit][1] = digit;
		
		S[digit][1].insert( digit );
		for ( int i = 2; i <= 8; i++ ) {
		      num[digit][i] = num[digit][i - 1] * 10 + digit;
			S[digit][i].insert( num[digit][i] );
			
			for ( int j = 1; j < i; j++ )
			FOREACH( it1, S[digit][j] )
			FOREACH( it2, S[digit][i - j] ) {
				int a = (*it1), b = (*it2);
				S[digit][i].insert( a + b );
				S[digit][i].insert( a - b );
				S[digit][i].insert( b - a );
				S[digit][i].insert( a * b );
				if ( b != 0 && a % b == 0 )
					S[digit][i].insert( a / b );
				if ( a != 0 && b % a == 0 )
					S[digit][i].insert( b / a );
			}
		}
	}

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d", &K );
		scanf( "%d", &N );
		REP( i, N ) {
			int value;
			scanf( "%d", &value );
			
			bool found = false;
			for ( int i = 1; i < 9; i++ )
			      if ( S[K][i].find( value ) != S[K][i].end() ) {
					printf( "%d\n", i );
					found = true;
					break;
				}
				
			if ( !found ) printf( "NO\n" );
		}
	}

	return 0;
}
