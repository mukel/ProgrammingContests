/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #109 Div 1
*/
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

typedef unsigned long long hash;

const int
	BASE = 1234567,
	MAXV = 1 << 20;
	
int V, E;
vector< int > G[MAXV];
hash h[MAXV], ans;
hash hPow[MAXV];
int dfsnum[MAXV];
int cnt;

void dfs(int u)
{
	dfsnum[u] = ++cnt;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (!dfsnum[v])
			dfs(v);
			
		if (dfsnum[v] < dfsnum[u])
		{
			hash hu = h[u] - hPow[ v+1 ];
			hash hv = h[v] - hPow[ u+1 ];
			if (hu == hv)
				ans++;
		}
	}
}

int main()
{
	scanf( "%d %d", &V, &E );
	
	hPow[0] = 1;
	for (int i = 1; i <= V; ++i)
	{
		hPow[i] = hPow[i - 1] * BASE;
	}
	
	for (int i = 0; i < E; ++i)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < G[i].size(); ++j)
			h[i] = h[i] + hPow[ G[i][j] + 1 ];
	}
	
	for (int i = 0; i < V; ++i)
	      if (!dfsnum[i])
	            dfs(i);

	sort(h, h + V);
	for (int i = 0, j; i < V; i = j)
	{
		for (j = i + 1; j < V && h[j] == h[i]; ++j);
		int64 n = j - i;
		ans += n * (n - 1) / 2;
	}
	
	cout << ans << endl;

	return 0;
}

