/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #92 "Stations"
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	MAXV = 1 << 15;
	
int V, E;

vector< int > G[MAXV];
int inDeg[MAXV];

int dtime, scc;
int dfsnum[MAXV];
int low[MAXV];
int scomp[MAXV];
stack< int > S;
bool mark[MAXV];

void dfs(int u)
{
	dfsnum[u] = low[u] = ++dtime;
	S.push(u);
	
	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!dfsnum[v])
		{
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else
		      if (!scomp[v])
		            low[u] = min(low[u], dfsnum[v]);
	}
	if (dfsnum[u] == low[u])
	{
		scc++;
		while (!scomp[u])
		{
			scomp[S.top()] = scc;
			S.pop();
		}
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
	      if (!dfsnum[i]) dfs(i);
	      
	REP(u, V)
	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (scomp[u] != scomp[v])
			inDeg[scomp[v]]++;
	}

	cout << count(inDeg + 1, inDeg + scc + 1, 0) << endl;

	return 0;
}
