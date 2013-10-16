/*
Alfonso2 Peterssen(mukel)
MIPT #33 "Triangles"
*/
#include <cstdio>

#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair< int, int > point;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXC = 1 << 8;
	
int N;
char buf[MAXC];
map< point, vector< point > > G;
map< point, int > ans;
map< point, bool > mark;
vector< point > order;
bool foundCycle;

void dfs(point u)
{
	mark[u] = true;
	REP(i, G[u].size())
	{
		point v = G[u][i];
		if (!mark[v]) dfs(v);
	}
	
	order.push_back(u);
}

int main()
{
	scanf( "%d", &N );

	REP(i, (N - 1) * 2)
	{
		scanf( "%s", &buf );
		for (int j = 0; buf[j]; j++)
	      {
			point u, v;
			if (i & 1) u = point(i/2 + 1, j), v = point(i/2 + 1, j + 1);
			else u = point(i/2, j*2), v = point(i/2 + 1, j*2 + 1);
			if (buf[j] == '<') swap(u, v);
			G[u].push_back(v);
		}
	}

	REP(i, N)
	REP(j, 2 * i + 1)
	{
		point p = point(i, j);
	      if (!mark[p]) dfs(p);
	}

	REP(i, N*N)
	      ans[order[i]] = i;

	REP(i, N)
	REP(j, 2 * i + 1)
	{
		point p = point(i, j);
		REP(k, G[p].size())
		{
			if (ans[p] < ans[ G[p][k] ])
			      foundCycle = true;
		}
	}
	      
	if (foundCycle) printf( "0\n" );
	else
	{
		printf( "1\n" );
		REP(i, N)
		REP(j, 2 * i + 1)
		{
			printf( "%d", ans[ point(i, j) ] + 1 );
		      if (j < 2 * i) printf( " " );
			else printf( "\n" );
		}
	}
	
	return 0;
}
