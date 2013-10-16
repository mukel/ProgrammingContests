/*
Alfonso2 Peterssen (mukel)
SPOJ #359 "Alpha Centauri Tennis"
5 - 3 - 2009
*/
#include <cstdio>
#include <cstring>

const int MAXN = 60000;

int T;
char S[MAXN];

int main() {

	scanf( "%d", &T );
	while ( T-- ) scanf( "%*d %s", &S ), printf( "%c\n", S[strlen(S) - 1] );

	return 0;
}
