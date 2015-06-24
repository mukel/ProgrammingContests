/*
Alfonso2 Peterssen
SPOJ #1001 "Babylonian Roulette"
15 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int P, B, E;

int main() {

	for (;;) {
		scanf( "%d %d %d", &P, &B, &E );
		if ( !P && !B && !E ) break;
		int money = abs( E - P );
		int g3 = money / ( 3 * B );
		money -= g3 * 3 * B;
		int g2 = money / ( 2 * B );
		money -= g2 * 2 * B;
		int g1 = money / ( 1 * B );
		money -= g1 * 1 * B;
		if ( money != 0 )
			printf( "No accounting tablet\n" );
		else
			printf( "%d\n", g1 + g2 + g3 );
	}

	return 0;
}
