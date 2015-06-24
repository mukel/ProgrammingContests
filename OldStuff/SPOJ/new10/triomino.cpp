/*
Alfonso2 Peterssen (mukel)
SPOJ #2961 "Triomino Game"
20 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXW = 28,
	win[MAXW] = {0,1,4,7,12,14,16,17,23,28,33,39,44,50,56,60,66,67,82,86,93,98,102,142,146,152,179,524};

int T, N;

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &N );
		printf( "%c\n", count( win, win + MAXW, N ) ? 'Y' : 'X' );
	}

	return 0;
}
