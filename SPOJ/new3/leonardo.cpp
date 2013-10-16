/*
Alfonso2 Peterssen
SPOJ #1843 "Leonardo Notebook"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int ALPHA = 26;

int T;
char S[ALPHA + 1];
int cant[2 * ALPHA];
int next[2 * ALPHA];
int mark[2 * ALPHA];

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%s", &S );
		REP( i, ALPHA ) {
			S[i] -= 'A';
			next[i] = S[i] + ALPHA;
			next[ S[i] + ALPHA ] = S[i];
		}
		
		memset( cant, 0, sizeof( cant ) );
		memset( mark, 0, sizeof( mark ) );
		REP( i, ALPHA )
		if ( !mark[i] ) {
			int j = i, len = 0;
			while ( !mark[j] ) {
				mark[j] = true;
				j = next[j];
				len++;
			}
			cant[len/2]++;
		}
		
		bool wrong = false;
		REP( i, ALPHA )
		      if ( i % 2 == 0 && cant[i] % 2 == 1 ) {
				wrong = true;
				break;
			}
		      
		
		if ( !wrong )
			printf( "Yes\n" );
		else
		      printf( "No\n" );
	}

	return 0;
}
