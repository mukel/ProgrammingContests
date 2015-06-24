/*
Alfonso2 Peterssen
SPOJ #2852 "Broken Keyboard"
20 - 9 - 2008
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 1000001;

int D;
char line[MAXN];
int freq[0x100];

int main() {

	for (;;) {
		scanf( "%d\n", &D ); if ( !D ) break;
		gets( line );
		int len = strlen( line );
		
		int lo = 0, hi = 0;
		int sol = 0, diff = 0;
		memset( freq, 0, sizeof( freq ) );

		while ( hi < len ) {
			freq[ line[hi] ]++;
			if ( freq[ line[hi] ] == 1 ) diff++;
			hi++;
			while ( diff > D ) {
				freq[ line[lo] ]--;
				if ( freq[ line[lo] ] == 0 ) diff--;
				lo++;
			}
			sol = std::max( sol, hi - lo );
		}
		
		printf( "%d\n", sol );
	}

	return 0;
}
