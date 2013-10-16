/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1470. UFOs
*/
#include <cstdio>
#include <iostream>

#include <algorithm>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 130;
	
int N;
int S[MAXN][MAXN][MAXN];

int lobit(int x) { return x & -x; }

void update(int x0, int y0, int z0, int amount)
{
	for (int x = x0 + 1; x < MAXN; x += lobit(x))
	for (int y = y0 + 1; y < MAXN; y += lobit(y))
	for (int z = z0 + 1; z < MAXN; z += lobit(z))
	      S[x][y][z] += amount;
}

int64 query(int x0, int y0, int z0)
{
	int64 sum = 0;
	for (int x = x0 + 1; x > 0; x -= lobit(x))
	for (int y = y0 + 1; y > 0; y -= lobit(y))
	for (int z = z0 + 1; z > 0; z -= lobit(z))
		sum += S[x][y][z];
	return sum;
}

int main()
{
	scanf( "%d", &N );
	while (1)
	{
		int op;
		scanf( "%d", &op );
		if (op == 3) break; // quit
		if (op == 1) // update
		{
			int x, y, z, k;
			scanf( "%d %d %d %d", &x, &y, &z, &k );
			update(x, y, z, k);
		}
		if (op == 2) // query
		{
			int x1, y1, z1, x2, y2, z2;
			scanf( "%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2 );
			int64 ans =
			      + query(x2, y2, z2)
				- query(x1 - 1, y2, z2) - query(x2, y1 - 1, z2) - query(x2, y2, z1 - 1)
				+ query(x1 - 1, y1 - 1, z2) + query(x1 - 1, y2, z1 - 1) + query(x2, y1 - 1, z1 - 1)
				- query(x1 - 1, y1 - 1, z1 - 1);
				
			printf( "%lld\n", ans );
		}
	}

	return 0;
}
