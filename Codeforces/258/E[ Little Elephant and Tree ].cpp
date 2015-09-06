#include <iostream>
#include <vector>
using namespace std;

const int
	MAXV = 1 << 17;

int V, Q;

vector< int > G[MAXV];
vector< int > qs[MAXV];

pair< int, int > vals[MAXV];
int curStep;

int size[MAXV];

int answer[MAXV];

void dfs(int u, int from = -1)
{
	vals[u].first = ++curStep;

	size[u] = 1;

	for (int i = 0; i < (int)G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == from)
			continue ;
		dfs(v, u);
		size[u] += size[v];
	}

	vals[u].second = ++curStep;
}

bool isUpper(int u, int v)
{
	return vals[u].first < vals[v].first && vals[u].second > vals[v].second;
}

const  int
	MAXS = 3 * (1 << 17);

struct abi
{

	int sums[MAXS];

	int lobit(int x)
	{
		return x & -x;
	}

	void update(int x, int delta)
	{
		while (x < MAXS)
		{
			sums[x] += delta;
			x += lobit(x);
		}
	}

	int query(int x)
	{
		int result = 0;
		while (x > 0)
		{
			result += sums[x];
			x -= lobit(x);
		}
		return result;
	}

	int query(int lo, int hi)
	{
		return query(hi) - query(lo - 1);
	}

} start, end, sums;

int curValue;

int added[MAXS];

void add(pair< int, int > fromTo, int val)
{
	int lo = fromTo.first;
	int hi = fromTo.second;

	added[lo]++;
	if (added[lo] > 1) return ;

	start.update(lo, 1);
	end.update(hi, 1);

	// if not ancestor
	if (start.query(lo - 1) == end.query(lo - 1))
	{
		curValue += val - sums.query(lo, hi);
	}

	sums.update(lo, val);
}

void remove(pair< int, int > fromTo, int val)
{
	int lo = fromTo.first;
	int hi = fromTo.second;

	added[lo]--;
	if (added[lo] > 0) return ;

	start.update(lo, -1);
	end.update(hi, -1);

	sums.update(lo, -val);

	// if not ancestor
	if (start.query(lo - 1) == end.query(lo - 1))
	{
		curValue -= val - sums.query(lo, hi);
	}


}

int query()
{
	return curValue;
}

void solve(int u, int from = -1)
{
	if (!qs[u].empty())
		add(vals[u], size[u]);

	for (int i = 0; i < (int)qs[u].size(); ++i)
	{
		int v = qs[u][i];
		add(vals[v], size[v]);
	}

	answer[u] = query();

	for (int i = 0; i < (int)G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == from)
			continue ;

		solve(v, u);
	}

	for (int i = ((int)qs[u].size()) - 1; i >= 0; --i)
	{
		int v = qs[u][i];
		remove(vals[v], size[v]);
	}

	if (!qs[u].empty()) remove(vals[u], size[u]);
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> V >> Q;
	for (int i = 0; i < V - 1; ++i)
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
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		qs[u].push_back(v);
		qs[v].push_back(u);
	}

	dfs(0);
	solve(0);

	for (int i = 0; i < V; ++i)
	{
		if (answer[i] > 0) answer[i]--;
		cout << answer[i] << " ";
	}

	cout << endl;

	return 0;
}
