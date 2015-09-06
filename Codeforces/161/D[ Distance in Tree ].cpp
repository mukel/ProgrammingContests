// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXV = 50001,
	MAXK = 501;

int V, K;
bool seen[MAXV];
vector< int > childs;
int cnt[MAXK];
int depth[MAXV];
int size[MAXV];
vector< int > G[MAXV];
long long ans;
int root;

void computeSizes(int u)
{
	seen[u] = 1;
	size[u] = 1;

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!seen[v])
		{
			computeSizes(v);
			size[u] += size[v];
		}
	}
	seen[u] = 0;
}

void dfs(int u)
{
	seen[u] = 1;
	childs.push_back(u);

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!seen[v])
		{
			depth[v] = depth[u] + 1;
			dfs(v);
		}
	}

	seen[u] = 0;
}

int findCenter(int u)
{
	seen[u] = 1;
	bool isCenter = ((size[root] - size[u]) * 2 <= size[root]);

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!seen[v])
			isCenter &= (size[v] * 2 <= size[root]);
	}

	if (isCenter)
	{
		seen[u] = 0;
		return u;
	}

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!seen[v])
		{
			int c = findCenter(v);
			if (c != -1)
			{
				seen[u] = 0;
				return c;
			}
		}
	}

	seen[u] = 0;
	return -1;
}

void solve(int u)
{
	computeSizes(u);
	root = u;
	u = findCenter(u);

	REP(i, K + 1) cnt[i] = 0;
	cnt[0] = 1;

	seen[u] = 1;

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!seen[v])
		{
			childs.clear();
			depth[v] = 1;
			dfs(v);

			REP(j, SZ(childs))
			{
				int w = childs[j];
				if (depth[w] <= K)
					ans += cnt[K - depth[w]];
			}

			REP(j, SZ(childs))
			{
				int w = childs[j];
				if (depth[w] <= K)
					cnt[depth[w]]++;
			}
		}
	}

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!seen[v]) solve(v);
	}

	seen[u] = 0;
}

int main()
{
	scanf( "%d %d", &V, &K );
	REP(i, V - 1)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	solve(0);

	cout << ans << endl;

	return 0;
}
