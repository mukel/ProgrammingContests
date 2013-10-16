/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1471. Tree
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 50000,
	MAXLGN = 17;

int N, M;
int dist[MAXN];
int level[MAXN];
int lca[MAXN][MAXLGN];
vector< pair<int, int> > G[MAXN];

int log2(int x)
{
	int lg = 1;
	while (1 << lg < x) lg++;
	return lg - 1;
}

int queryLCA(int u, int v)
{
	if (level[v] > level[u])
	      swap(u, v);
	      
	for (int i = log2(level[u]); i >= 0; i--)
		if (level[u] - (1 << i) >= level[v])
		      u = lca[u][i];
	
	assert(level[u] == level[v]);
	
	if (u == v) return u;
	
	for (int i = log2(level[u]); i >= 0; i--)
		if (lca[u][i] != lca[v][i])
		{
			u = lca[u][i];
			v = lca[v][i];
		}
	
	assert(lca[u][0] == lca[v][0]);
	
	return lca[u][0];
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
	
	queue< int > Q;
	for (Q.push(0), level[0] = 1; !Q.empty(); Q.pop())
	{
		int u = Q.front();
		REP(i, G[u].size())
		{
			int v = G[u][i].first;
			int w = G[u][i].second;
			if (level[v]) continue;
			
			Q.push(v);
			lca[v][0] = u;
			dist[v] = dist[u] + w;
			level[v] = level[u] + 1;

			int lg = log2(level[v]);
			for (int i = 1; i <= lg; i++)
				lca[v][i] = lca[ lca[v][i - 1] ][i - 1];
		}
	}
	
	scanf( "%d", &M );
	while (M--)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		int z = queryLCA(u, v);
		printf( "%d\n", dist[u] + dist[v] - 2 * dist[z] );
	}

	return 0;
}
