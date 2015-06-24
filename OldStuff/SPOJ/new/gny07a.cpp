/*
Alfonso2 Peterssen
SPOJ #2523 "Mispelling"
6 - 9 - 2008
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXLEN = 100;

int T, pos;
char st[MAXLEN];

int main() {

	scanf( "%d", &T );
	REP( i, T ) {
		scanf( "%d %s", &pos, &st );
		st[pos - 1] = '\0';
		printf( "%d %s%s\n", i + 1, st, st + pos );
	}

	return 0;
}
