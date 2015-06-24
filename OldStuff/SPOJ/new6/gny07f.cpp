/*
Alfonso2 Peterssen
SPOJ #2528 "Monkey Vines"
29 - 9 - 2008
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

const int MAXLEN = 200;

int T, pos;
int cant, sol;
char line[MAXLEN];

int main() {

	T = atoi( gets( line ) );
	for ( int tc = 1; tc <= T; tc++ ) {
		gets( line );
		sol = cant = 0;
		for ( int i = 0; line[i]; i++ )
		      if ( line[i] == '[' ) {
				cant++;
				sol = max( sol, cant );
			}
			else
			      cant--;
		printf( "%d %d\n", tc, 1 << sol );
	}

	return 0;
}
