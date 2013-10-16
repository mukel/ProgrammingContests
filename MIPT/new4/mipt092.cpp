/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #92 "Stations"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXV = 2011;

int V, E;
vector< int > G[MAXV];
stack< int > S;
int disTime;
int dfsnum[MAXV];
int low[MAXV];
bool pop[MAXV];
int comp[MAXV];
int inDeg[MAXV];
int ans;
int sccCnt;

int dfs(int u)
{
	S.push(u);
	dfsnum[u] = low[u] = ++disTime;
	
	REP(i, G[u].size())
	{
		int v = G[u][i];
		if (!dfsnum[v])
		{
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else
		      if (!pop[v])
		            low[u] = min(low[u], dfsnum[v]);
	}

	if (dfsnum[u] == low[u])
	{
		while (!pop[u])
		{
			pop[S.top()] = true;
			comp[S.top()] = sccCnt;
			S.pop();
		}
		sccCnt++;
	}
}

int main()
{
	scanf( "%d %d", &V, &E );
	REP(i, E)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		G[u].push_back(v);
	}
	
	REP(i, V)
	      if (!dfsnum[i])
	            dfs(i);
	            
	REP(u, V)
		REP(i, G[u].size())
		{
			int v = G[u][i];
			if (comp[u] != comp[v])
				inDeg[comp[v]]++;
		}
		
	REP(i, sccCnt)
	      if (!inDeg[i]) ans++;

	printf( "%d\n", ans );

	return 0;
}
