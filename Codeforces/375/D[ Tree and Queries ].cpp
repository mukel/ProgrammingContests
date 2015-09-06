#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define endl (&#39;\n&#39;)

const int
	MAXV = 1 << 17,
	MAXQ = 1 << 17;

typedef pair< int, int > query;

int V, Q;
int color[MAXV];
vector< int > G[MAXV];
vector< query > queries[MAXV];

int answer[MAXQ];

unordered_map< int, int > colorCount[MAXV];
vector< int > fenwick[MAXV];

inline int lobit(int x)
{
	return x & -x;
}

int queryGreaterEqualThan(const vector< int > & f, register int x)
{
	int sum = 0;
	for (; x < f.size(); x += lobit(x + 1))
		sum += f[x];
	return sum;
}

void update(vector< int > & f, register int x, int value)
{
	if (x >= f.size())
		f.resize(x + 1);

	for (; x >= 0; x -= lobit(x + 1))
		f[x] += value;
}

// keep result on u
void unite(int u, int v)
{
	// normalize
	if (colorCount[v].size() > colorCount[u].size())
	{
		colorCount[u].swap(colorCount[v]);
		fenwick[u].swap(fenwick[v]);
	}

	for (auto p : colorCount[v])
	{
		int & r = colorCount[u][ p.first ];

		if (r > 0)
			update(fenwick[u], r, -1);

		r += p.second;

		update(fenwick[u], r, +1);
	}

	// clear v
	colorCount[v].clear();
	fenwick[v].clear();
}

void dfs(int u, int from)
{
	// update color[u]
	colorCount[u][ color[u] ] = 1;
	update(fenwick[u], 1, 1);

	for (int v : G[u]) if (v != from)
	{
		dfs(v, u);
		unite(u, v);
	}

	for (auto q : queries[u])
	{
		int k = q.first;
		int id = q.second;
		answer[id] = queryGreaterEqualThan(fenwick[u], k);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> V >> Q;

	for (int i = 0; i < V; ++i)
		cin >> color[i];

	for (int i = 1; i < V; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 0; i < Q; ++i)
	{
		int v, k;
		cin >> v >> k;
		--v;

		queries[v].push_back(make_pair(k, i));
	}


	dfs(0, -1);

	for (int i = 0; i < Q; ++i)
		cout << answer[i] << endl;


	return 0;
}
