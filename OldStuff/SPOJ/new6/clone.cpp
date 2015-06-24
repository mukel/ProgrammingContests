/*
Alfonso2 Peterssen
SPOJ #2881 "Find the Clones"
1 - 10 - 2008
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOREACH( it, c ) \
	for ( typeof( (c).begin() ) it = (c).begin(); it != (c).end(); it++ )

const int MAXN = 100000;

int N, M;
char line[40];
int sol[MAXN];

int main() {

	for (;;) {
		scanf( "%d %d", &N, &M );
		if ( !N && !M ) break;
		map< string, int > M;
		REP( i, N ) {
			sol[i] = 0;
			scanf( "%s", &line );
			M[ string( line ) ]++;
		}
		FOREACH( it, M )
		      sol[(*it).second - 1]++;
		REP( i, N )
		      printf( "%d\n", sol[i] );
	}

	return 0;
}
