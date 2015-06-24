/*
Alfonso2 Peterssen
SPOJ #5151 "Alice’s Cube"
9 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 16,
	E = 32,
	edges[E][2] = {
	{1, 2},
	{1, 3},
	{1, 5},
	{1, 9},
	{2, 4},
	{2, 6},
	{2, 10},
	{3, 4},
	{3, 7},
	{3, 11},
	{4, 8},
	{4, 12},
	{5, 6},
	{5, 7},
	{5, 13},
	{6, 8},
	{6, 14},
	{7, 8},
	{7, 15},
	{8, 16},
	{9, 10},
	{9, 11},
	{9, 13},
	{10, 12},
	{10, 14},
	{11, 12},
	{11, 15},
	{12, 16},
	{13, 14},
	{13, 15},
	{14, 16},
	{15, 16}
};

int dist[1 << MAXN];

int main()
{
	int src = (1 << 8) - 1;
	memset(dist, -1, sizeof(dist));
	dist[src] = 0;
	
	queue< int > Q;
	for (Q.push(src); !Q.empty(); Q.pop())
	{
		int top = Q.front();

		if (dist[top] == 3)
			continue;
			
		REP(i, E)
		{
			int u = edges[i][0] - 1;
			int v = edges[i][1] - 1;
			if (((top >> u) & 1) ^ ((top >> v) & 1))
			{
				int nxt = (top ^ (1 << u)) ^ (1 << v);
				if (dist[nxt] < 0)
				{
					dist[nxt] = dist[top] + 1;
					Q.push(nxt);
				}
			}
		}
	}

	int T;
	scanf( "%d", &T );
	for (int test = 1; test <= T; test++)
	{
		int target = 0;
		REP(i, 16)
		{
			int x;
			scanf( "%d", &x );
			target = (target << 1) | x;
		}
		
		printf( "Case #%d: ", test );
		if (dist[target] < 0)
		      printf( "more\n" );
		else
		      printf( "%d\n", dist[target] );
	}

	return 0;
}
