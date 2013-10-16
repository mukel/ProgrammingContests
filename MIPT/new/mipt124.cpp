/*
Alfonso2 Peterssen(mukel)
MIPT #124 "Sudoku"
*/
#include <cstdio>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int main()
{
	int n; scanf( "%d", &n );
	REP(i, n)
	REP(j, n)
	{
		REP(k, n * n) printf( "%d ", (k + i + j * n) % (n*n) + 1 );
		printf( "\n" );
	}

	return 0;
}
