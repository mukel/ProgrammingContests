/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #83 "SAT-2"
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

const int MAXV = 1 << 11;

int V, E;
int dtime, sccCount;
int dfsnum[MAXV];
int low[MAXV];
int scomp[MAXV];
vector< int > G[MAXV];
stack< int > S;
bool ans[MAXV];

#define VAR(x) ((x) < 0 ? (-(x) - 1 + V) : (x) - 1)
#define NOT(x) ((x) < V ? (x) + V : (x) - V)

void addOR(int u, int v)
{
	u = VAR(u);
	v = VAR(v);
//	printf( "%d || %d\n", u, v );
	G[NOT(u)].PB(v);
	G[NOT(v)].PB(u);
}

void dfs(int u)
{
	low[u] = dfsnum[u] = ++dtime;
	S.push(u);
	REP(i, G[u].size())
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

	if (low[u] == dfsnum[u])
	{
		sccCount++;
		while (!scomp[u])
		{
			scomp[S.top()] = sccCount;
			S.pop();
		}
	}
}

bool solve()
{
	REP(u, V)
	{
		if (!dfsnum[u]) dfs(u);
		if (!dfsnum[NOT(u)]) dfs(NOT(u));
		if (scomp[u] == scomp[NOT(u)]) return 0;
		ans[u] = (scomp[u] < scomp[NOT(u)]);
	}
	return 1;
}

int main()
{
	scanf( "%d %d", &V, &E );
	REP(i, E)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		if (!v) v = u; else scanf( "%*d" );
		addOR(u, v);
	}

	if (!solve()) printf( "No\n" );
	else
	{
		printf( "Yes\n" );
		REP(i, V) if (ans[i]) printf( "%d ", i + 1 );
		printf( "0\n" );
	}

	return 0;
}
