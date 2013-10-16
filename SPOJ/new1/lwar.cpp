/*
Alfonso2 Peterssen
SPOJ #693 "Lethal Warfare"
8 - 9 - 2008
*/
#include <cstdio>
#include <cstring>

const int MAXN = 40000;

int T, N;
char line[MAXN];

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%s", &line );
		
		N = strlen( line );
		for ( int i = 0; i < N; i += 2 )
			if ( line[i] == '0' ) {
				while ( i < N ) { printf( "%c", line[i] ); i++; }
				break;
			} else
				if ( line[i + 1] == '1' ) {
					printf( "1" ); i++;
					while ( i < N ) { printf( "%c", line[i] ^ 1 ); i++; }
					break;
				} else {
					printf( "1" );
					if ( i < N - 1 )
						printf( "1" );
				}
		
		printf( "\n" );
	}

	return 0;
}
