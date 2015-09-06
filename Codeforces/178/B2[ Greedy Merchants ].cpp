// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXV = 1 << 17;

int V, E;
vector< int > G[MAXV];
int dfsnum[MAXV];
int low[MAXV];
bool pop[MAXV];
stack< int > S;
int dtime;

int bcCount;
int bc[MAXV];
vector< int > comps[MAXV];

int depth[MAXV];
bool mark[MAXV];
int lca[MAXV][18];

void dfs(int u, int from = -1)
{
	low[u] = dfsnum[u] = ++dtime;
	S.push(u);

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (v == from) continue ;

		if (!dfsnum[v])
		{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else
			if (!pop[u])
				low[u] = min(low[u], dfsnum[v]);
	}

	if (low[u] == dfsnum[u])
	{
		while (!pop[u])
		{
			int x = S.top();
			bc[x] = bcCount;
			comps[bcCount].push_back(x);

			pop[x] = true;
			S.pop();
		}
		bcCount++;
	}
}

void dfs2(int curComp)
{
	mark[curComp] = true;

	REP(i, SZ(comps[curComp]))
	{
		int u = comps[curComp][i];
		REP(j, SZ(G[u]))
		{
			int nxtComp = bc[ G[u][j] ];
			if (!mark[nxtComp])
			{
				lca[nxtComp][0] = curComp;
				depth[nxtComp] = depth[curComp] + 1;

				for (int i = 1; depth[nxtComp] - (1 << i) >= 0; ++i)
					lca[nxtComp][i] = lca[ lca[nxtComp][i - 1] ][i - 1];

				dfs2(nxtComp);
			}
		}
	}
}

int getLca(int u, int v)
{
	if (depth[v] > depth[u]) swap(u, v);

	for (int i = 17; i >= 0; --i)
		if (depth[u] - (1 << i) >= depth[v])
			u = lca[u][i];

	if (u == v) return u;

	for (int i = 17; i >= 0; --i)
		if (depth[u] - (1 << i) >= 0 && lca[u][i] != lca[v][i])
		{
			u = lca[u][i];
			v = lca[v][i];
		}

	return lca[u][0];
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> V >> E;
	REP(i, E)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(0);
	dfs2(0);

	int Q; for (cin >> Q; Q--;)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;

		u = bc[u];
		v = bc[v];

		//cout << " --->>> " << u << " " << v << endl;

		int z = getLca(u, v);

		cout << depth[u] + depth[v] - 2 * depth[z] << "\n";
	}

	return 0;
}
