/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1004. Sightseeing trip
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXV = 500,
	MAXLGV = 11,
	MAXE = 1 << 17,
	oo = (int)1e9;

int V, E;
int data[MAXV];
int level[MAXV];
int lca[MAXV][MAXLGV];
int maxEdge[MAXV][MAXLGV];
vector< pair<int, int> > G[MAXV];
struct edge
{
	int u, v, w;
	bool inMST;
	edge(int _u = 0, int _v = 0, int _w = 0)
	{
		u = _u;
		v = _v;
		w = _w;
		inMST = 0;
	}
} edges[MAXE];

bool operator < (const edge& a, const edge& b)
{
	return a.w < b.w;
}

int FIND(int x)
{
	return data[x] < 0 ? x : data[x] = FIND(data[x]);
}

int SIZE(int x)
{
	return -data[FIND(x)];
}

void JOIN(int u, int v)
{
	u = FIND(u);
	v = FIND(v);
	if (u != v)
	{
		if (SIZE(u) < SIZE(v))
		      swap(u, v);
		data[u] += data[v];
		data[v] = u;
	}
}

int log2(int x)
{
	int lg = 1;
	while (1 << lg < x) lg++;
	return lg - 1;
}

void dfs(int u)
{
	REP(i, G[u].size())
	{
		int v = G[u][i].first;
		int w = G[u][i].second;
		if (!level[v])
		{
			level[v] = level[u] + 1;
			
			lca[v][0] = u;
			maxEdge[v][0] = w;
			
			int lg = log2(level[v]);
			for (int i = 1; i <= lg; i++)
			{
				lca[v][i] = lca[ lca[v][i - 1] ][i - 1];
				maxEdge[v][i] = max(maxEdge[v][i - 1], maxEdge[ lca[v][i - 1] ][i - 1]);
			}
		}
	}
}

int getMaxEdge(int u, int v)
{
	if (level[v] > level[u])
	      swap(u, v);
	      
	int ans = -oo;
	for (int i = log2(level[u]); i >= 0; i--)
		if (level[u] - (1 << i) >= level[v])
		{
			ans = max(ans, maxEdge[u][i]);
			u = lca[u][i];
		}
		
	if (u == v)
	      return ans;
	      
	for (int i = log2(level[u]); i >= 0; i--)
		if (lca[u][i] != lca[v][i])
		{
			ans = max(ans, maxEdge[u][i]);
			ans = max(ans, maxEdge[v][i]);
			u = lca[u][i];
			v = lca[v][i];
		}
		
	ans = max(ans, maxEdge[u][0]);
	ans = max(ans, maxEdge[v][0]);
		
	return ans;
}

int main()
{

	scanf( "%d %d", &V, &E );
	REP(i, E)
	{
		int u, v, w;
		scanf( "%d %d %d", &u, &v, &w );
		u--; v--;
		edges[i] = edge(u, v, w);
	}
	
	REP(i, V) data[i] = -1;
	
	sort(edges, edges + E);
	
	int firstMST = 0;
	REP(i, E)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		
		if (u == v) continue ;
		
		int w = edges[i].w;
		if (FIND(u) != FIND(v))
		{
			firstMST += w;
			//printf( "-> %d %d %d\n", u + 1, v + 1, w );
			edges[i].inMST = true;
			
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
			
			JOIN(u, v);
		}
	}
	
	level[0] = 1;
	dfs(0);
	
	int secondMST = oo;
	REP(i, E)
		if (!edges[i].inMST)
		{
			int u = edges[i].u;
			int v = edges[i].v;
			if (u == v) continue ;
			
			int w = edges[i].w;
			secondMST = min(secondMST, w - getMaxEdge(u, v));
		}

	if (secondMST == oo)
	      secondMST = -1;
	else
	      secondMST += firstMST;

	printf( "Case: %d\nCase: %d\n", firstMST, secondMST );

	return 0;
}
