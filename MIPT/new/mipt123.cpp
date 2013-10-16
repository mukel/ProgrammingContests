/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #123 "LCA problem"
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
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	MAXV = 400001,
	MAXQ = 400001;

int V;
int ancestor[MAXV];
char color[MAXV];
vector< int > G[MAXV];
int ans[MAXQ];
struct query
{
	int v, qid;
	query(int _v, int _qid)
	{
		v = _v;
		qid = _qid;
	}
};

vector< query > queries[MAXV];

int data[MAXV];

int find(int x)
{
	return (data[x] < 0) ? x : data[x] = find(data[x]);
}

int size(int u)
{
	return -data[find(u)];
}

void join(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return ;
	if (size(u) < size(v)) swap(u, v);
	data[u] += data[v];
	data[v] = u;
}

void dfs(int u)
{
	data[u] = -1;
      ancestor[u] = u;

	REP(i, G[u].size())
	{
		dfs(G[u][i]);
		join(u, G[u][i]);
		ancestor[find(u)] = u;
	}

	color[u] = 1;
	
	REP(i, queries[u].size())
	{
		int qid = queries[u][i].qid;
		int v = queries[u][i].v;
		if (color[v])
			ans[qid] = ancestor[ find(v) ];
	}
}

int main()
{
	scanf( "%d", &V ); V++;
	REP(i, V - 1)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		G[v].push_back(u);
	}
	
	int Q;
	scanf( "%d", &Q );
	
	REP(i, Q)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		queries[u].push_back(query(v, i));
		queries[v].push_back(query(u, i));
	}
	
	dfs(0);
	
	REP(i, Q)
	      printf( "%d\n", ans[i] );

	return 0;
}
