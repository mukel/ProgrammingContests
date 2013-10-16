/*
Alfonso2 Peterssen (mukel)
SPOJ #3898 "Palindrome"
21 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1 << 20;

int T, N;
char S[MAXN];
int rad[MAXN];

bool palin( int lo, int hi ) {
	while ( lo < hi ) {
	      if ( S[lo] != S[hi] ) return 0;
	      lo++; hi--;
	}
	return 1;

}

int main() {

	T = atoi( gets( S ) );
	while ( T-- ) {

		gets( S );
		N = strlen( S );
		if ( S[N - 1] == '\r' ) N--;
		
		if ( N & 1 ) {
			printf( "NO\n" );
			continue ;
		}

		for ( int i = 0; i < N; i++ ) {
			for ( int j = i + 1; j < N; j += 2 )
				if ( palin( i, j ) ) {
					i = j;
					goto next_i;
				}
				
			printf( "NO\n" );
			goto next_case;
				
			next_i:;
		}
		
		printf( "YES\n" );
		next_case:;
	}

	return 0;
}
