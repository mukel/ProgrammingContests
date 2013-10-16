/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #57 "Hacker's attack"
*/
#include <cstdio>

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int a1, b1, c1;

bool solve(int m, int64 a, int64 b, int64 c)
{
	if (
		a1 % m != ((b * c) ^ a) % m ||
		b1 % m != ((a * c) ^ b) % m ||
		c1 % m != ((a * b) ^ c) % m)
			return 0;

	if (m == (1 << 24))
	{
		printf( "%d %d %d\n", (int)a, (int)b, (int)c );
		return 1;
	}

	REP(ma, 2)
	REP(mb, 2)
	REP(mc, 2)
		if (solve(m*2, a + m*ma, b + m*mb, c + m*mc))
			return 1;

	return 0;
}

int main()
{
	scanf( "%d %d %d", &a1, &b1, &c1 );

	if (!solve(1, 0, 0, 0))
		printf( "-1 -1 -1\n" );

	return 0;
}
