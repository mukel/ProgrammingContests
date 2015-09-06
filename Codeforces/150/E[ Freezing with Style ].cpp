#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair< int, int > par;

#define ALL(c) (c).begin(), (c).end()

const int
	MAXV = 1 << 17;

int V;
int L, R;

struct edge
{
	int v, w;
	edge(int _v, int _w) : v(_v), w(_w) {}
};
vector< edge > G[MAXV];

vector< int > W;
int medianValue;
int size[MAXV];
int seen[MAXV];
int deep[MAXV];
int cost[MAXV];
vector< int > childs;
par lastPath;

int delta;
int tSize;
par T[4 * MAXV];

const par
	NONE = par(-1000000005, -1);

void build(int n)
{
	tSize = ++n;
	for (delta = 1; delta < n; delta <<= 1);
	for (int i = 0; i <= n + delta; ++i)
		T[i] = NONE;
}

void update(int n, par val)
{
	for (n += delta; n > 0 && val > T[n]; n >>= 1)
		T[n] = val;
}

par query(int a, int b)
{
	if (b < 0 || a > b) return NONE;
	a = max(a, 0);
	b = min(b, tSize - 1);

	par ret = NONE;

	for (a += delta, b += delta; a <= b; a >>= 1, b >>= 1)
	{
		if ( a & 1) { ret = max(ret, T[a]); ++a; }
		if (~b & 1) { ret = max(ret, T[b]); --b; }
	}

	return ret;
}

int diameter;

int computeSize(int u)
{
	seen[u] = 1;
	size[u] = 1;

	int d = 0;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i].v; if (seen[v]) continue ;
		int t = computeSize(v) + 1;
		diameter = max(diameter, d + t);
		d = max(d, t);
		size[u] += size[v];
	}
	seen[u] = 0;

	return d;
}

int findCenter(int u, int treeSize)
{
	bool ok = ((treeSize - size[u]) * 2 <= treeSize);
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i].v; if (seen[v]) continue ;
		ok &= (size[v] * 2 <= treeSize);
		if (!ok) break ;
	}

	if (ok) return u;

	seen[u] = 1;

	int ret = -1;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i].v; if (seen[v]) continue ;

		ret = findCenter(v, treeSize);
		if (ret != -1) break;
	}

	seen[u] = 0;

	return ret;
}

void dfs(int u)
{
	seen[u] = 1;
	childs.push_back(u);
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i].v; if (seen[v]) continue ;
		int w = G[u][i].w;
		deep[v] = deep[u] + 1;
		cost[v] = cost[u] + ((w < medianValue) ? -1 : +1);
		dfs(v);
	}
	seen[u] = 0;
}

bool solve(int u)
{
	diameter = 0;
	computeSize(u);

	if (diameter < L) return false;
	build(size[u]+5);

	u = findCenter(u, size[u]);

	update(0, par(0, u));

	seen[u] = 1;

	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i].v; if (seen[v]) continue ;
		int w = G[u][i].w;

		cost[v] = ((w < medianValue) ? -1 : +1);
		deep[v] = 1;
		childs.clear();
		dfs(v);

		// queries
		for (int j = 0; j < childs.size(); ++j)
		{
			int v = childs[j];
			par best = query(L - deep[v], R - deep[v]);
			if (best.first + cost[v] >= 0)
			{
				lastPath = par(v, best.second);
				seen[u] = 0;
				return 1;
			}
		}

		// updates
		for (int j = 0; j < childs.size(); ++j)
		{
			int v = childs[j];
			update(deep[v], par(cost[v], v));
		}
	}

	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i].v; if (seen[v]) continue ;
		if (solve(v))
		{
			seen[u] = 0;
			return 1;
		}
	}

	seen[u] = 0;

	return 0;
}

int main()
{
	scanf( "%d %d %d", &V, &L, &R );

	for (int i = 0; i < V - 1; ++i)
	{
		int u, v, w;
		scanf( "%d %d %d", &u, &v, &w );
		--u;
		--v;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));

		W.push_back(w);
	}

	sort(ALL(W));

	int lo = 0;
	int hi = unique(ALL(W)) - W.begin() - 1;

	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		medianValue = W[mid];
		if (solve(0)) lo = mid + 1;
		else
			hi = mid - 1;
	}

	medianValue = W[lo - 1];
	solve(0);

	printf( "%d %d\n", lastPath.first + 1, lastPath.second + 1 );

	return 0;
}
