/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1471. Tree
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 50000,
	MAXQ = 75000;
	
int N, M;
int dist[MAXN];
int ancestor[MAXN];
int ans[MAXQ];
bool color[MAXN];
bool mark[MAXN];
vector< pair<int, int> > G[MAXN];
vector< pair<int, int> > Q[MAXN]; // queries

int data[MAXN];

int FIND(int x)
{
	return data[x] < 0 ? x : data[x] = FIND(data[x]);
}

int SIZE(int u)
{
	return -data[FIND(u)];
}

void JOIN(int u, int v)
{
	u = FIND(u);
	v = FIND(v);
	if (u == v) return ;
	      
	if (SIZE(v) < SIZE(u))
	      swap(u, v);

	data[v] += data[u];
	data[u] = v;
}

void dfs(int u)
{
	data[u] = -1;
	mark[u] = true;
	
	ancestor[ FIND(u) ] = u;
	
	REP(i, G[u].size())
	{
		int v = G[u][i].first;
		int w = G[u][i].second;
		if (!mark[v])
		{
			dist[v] = dist[u] + w;
			dfs(v);
			JOIN(u, v);
			ancestor[FIND(u)] = u;
		}
	}
	
	color[u] = 1;
	REP(i, Q[u].size())
	{
		int v = Q[u][i].first;
		if (color[v])
			ans[ Q[u][i].second ] = dist[u] + dist[v] - 2 * dist[ ancestor[FIND(v)] ];
	}
}

int main()
{
	scanf( "%d", &N );
	REP(i, N - 1)
	{
		int u, v, w;
		scanf( "%d %d %d", &u, &v, &w );
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}

	scanf( "%d", &M );
	REP(i, M)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		Q[u].push_back(make_pair(v, i));
		Q[v].push_back(make_pair(u, i));
	}
	
	dfs(0);
	
	REP(i, M)
	      printf( "%d\n", ans[i] );

	return 0;
}

