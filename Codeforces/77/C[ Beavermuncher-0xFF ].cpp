/*
Alfonso2 Peterssen(mukel)
Codeforces Round 69 Beta Div. 1
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

const int MAXN = 1 << 17;

int N;
int B[MAXN];
vector< int > G[MAXN];
int64 profit[MAXN];

bool profitComp(int i, int j)
{
	return profit[i] > profit[j];
}

int64 dfs(int u, int from = -1)
{
	B[u]--;
	profit[u]++; // just for reach
	
	vector< int64 > childProfit;
	REP(i, G[u].size())
	{
		int v = G[u][i];
		if (v == from) continue ;
		int64 p = dfs(v, u);
		if (p != 0) childProfit.push_back(v);
	}

	sort(ALL(childProfit), profitComp);

	REP(i, SZ(childProfit))
	{
		if (!B[u]) break;
		profit[u] += profit[ childProfit[i] ];
		
		B[u]--;
		profit[u]++;
	}

	REP(i, SZ(childProfit))
	{
		if (!B[u]) break;
		int v = childProfit[i];
		int d = min(B[u], B[v]);
		B[u] -= d;
		B[v] -= d;
		profit[u] += 2 * d;
	}

	return profit[u];
}

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	      scanf( "%d", &B[i] );
	      
	REP(i, N - 1)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int root; scanf( "%d", &root );
	root--;
	
	B[root]++;
	
	cout << dfs(root) - 1 << endl;

	return 0;
}
