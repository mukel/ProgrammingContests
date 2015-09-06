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
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 17;

int N, M;
int f[MAXN];
vector< int > G[MAXN];
bool markG[MAXN];

vector< int > H[MAXN];
bool markH[MAXN];

void dfs(int u)
{
	markG[u] = 1;
	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (!markG[v] && f[v] != 1)
			dfs(v);
	}
}

void dfs2(int u)
{
	markH[u] = 1;
	REP(i, SZ(H[u]))
	{
		int v = H[u][i];
		if (f[v] == 1)
		{
			markH[v] = true;
		}
		else
		if (!markH[v])
			dfs2(v);
	}
}

int main()
{
	scanf( "%d %d", &N, &M );
	REP(i, N)
		scanf( "%d", &f[i] );

	REP(i, M)
	{
		int a, b;
		scanf( "%d %d", &a, &b );
		--a;
		--b;
		G[a].push_back(b);
		H[b].push_back(a);
	}

	REP(i, N) if (f[i] == 1 && !markG[i]) dfs(i);
	REP(i, N) if (f[i] == 2 && !markH[i]) dfs2(i);

	REP(i, N)
	{
		//printf( "%d %d\n", markG[i], markH[i] );
		printf( "%d\n", (int)(markG[i] && markH[i]) );
	}

	return 0;
}
