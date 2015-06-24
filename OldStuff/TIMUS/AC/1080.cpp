/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1080. Map Colouring
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
const int
	MAXN = 100;

int N;
int color[MAXN];
vector< int > G[MAXN];

bool oddCycle;

void dfs(int u, int c)
{
	color[u] = c;
	REP(i, G[u].size())
	{
		int v = G[u][i];
		if (color[v] < 0)
		      dfs(v, c ^ 1);
		else
		if (color[u] == color[v])
		      oddCycle = 1;
	}
}

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		while (1)
		{
			int x;
			scanf( "%d", &x ); if (!x) break;
			x--;
			G[i].push_back(x);
			G[x].push_back(i);
		}
	}

	memset(color, -1, sizeof(color));

	dfs(0, 0);

	if (oddCycle)
	      printf( "-1\n" );
	else
	{
	      REP(i, N)
	            printf( "%d", color[i] );
		printf( "\n" );
	}

	return 0;
}
