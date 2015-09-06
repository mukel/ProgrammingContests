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
	MAXN =  1 << 17,
	oo = (int)1e9;

int N, M, K;
int s, t;
bool vol[MAXN];
vector< int > G[MAXN];
int dist[MAXN];

typedef pair< int, int > par;

bool ok(int maxDist)
{
	if (maxDist == 0) return (s == t);

	set< par > S;
	REP(i, N)
		dist[i] = oo;

	dist[s] = 0;
	S.insert( par(dist[s], s) );

	while (!S.empty())
	{
		par top = *S.begin();
		S.erase(S.begin());

		int u = top.second;

		REP(i, SZ(G[u]))
		{
			int v = G[u][i];
			int nw = dist[u] + 1;

			if (nw > maxDist || nw >= dist[v]) continue ;

			if (v == t)
				return true;

			if (vol[v]) nw = 0;

			if (dist[v] != oo)
				S.erase(par(dist[v], v));
			dist[v] = nw;
			S.insert(par(dist[v], v));
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;

	REP(i, K)
	{
		int x;
		cin >> x;
		--x;
		vol[x] = true;
	}

	REP(i, M)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	REP(i, N)
		random_shuffle(ALL(G[i]));

	cin >> s >> t;
	--s;
	--t;

	int lo = 0, hi = N - 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (ok(mid))
			hi = mid - 1;
		else
			lo = mid + 1;

		//cout << mid << " " << ok(mid)<< endl;
	}

	if (lo >= N)
		cout << -1 << endl;
	else
		cout << lo << endl;

	return 0;
}
