/*
Alfonso2 Peterssen
SPOJ #899 "Ws Cipher"
7 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 100;

int K[3], N;
int pos[MAXN], __pos[MAXN];
char line[MAXN];
char msg[MAXN];

int main() {

	for (;;) {
		scanf( "%d %d %d", &K[0], &K[1], &K[2] );
		
		if ( K[0] + K[1] + K[2] == 0 )
		      break;
		      
		scanf( "%s", &line );
		N = strlen( line );
		
		REP( i, 3 ) {

			int cant = 0;
			REP( j, N ) {
				char ch = line[j];
				if ( ch >= 'a' && ch <= 'i' ) {
					if ( i == 0 ) pos[cant++] = j;
				} else if ( ch >= 'j' && ch <= 'r' ) {
					if ( i == 1 ) pos[cant++] = j;
				} else if ( i == 2 )
				      pos[cant++] = j;
			}
			
			REP( j, cant ) __pos[j] = pos[j];
			if ( cant > 1 )
				rotate( pos, pos + cant - ( K[i] % cant ), pos + cant );
			REP( j, cant )
			      msg[ __pos[j] ] = line[ pos[j] ];
		}
		
		msg[N] = '\0';
		printf( "%s\n", msg );
	}

	return 0;
}
