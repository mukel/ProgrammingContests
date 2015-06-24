/*
Alfonso2 Peterssen
SPOJ #1774 "All Discs Considered"
7 - 8 - 2010
*/
#include <cstdio>
#include <queue>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 1 << 17;

int N1, N2, D;
int dep[MAXN];
int tmpDep[MAXN];
queue< int > Q[2];
vector< int > G[MAXN];

int solve(int curr)
{
	int ans = 0;
	while (1)
	{
		if (!Q[curr].empty())
			ans++;
		while (!Q[curr].empty())
		{
			int u = Q[curr].front(); Q[curr].pop();
			REP(i, G[u].size())
			{
				int v = G[u][i];
				tmpDep[v]--;
				if (!tmpDep[v])
					Q[1 - curr].push(v);
			}
		}
		if (Q[1 - curr].empty())
		      break;
		      
		curr = 1 - curr;
	}
	
	return ans;
}

int main()
{
	for (;;)
	{
		scanf( "%d %d %d", &N1, &N2, &D );
		if (!N1 && !N2 && !D)
		      break;
		      
	      REP(i, N1 + N2)
	      {
			G[i].clear();
			dep[i] = 0;
		}
		
		REP(i, D)
		{
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			if ((u < N1) == (v < N1))
			      continue ;

			G[v].push_back(u);
			dep[u]++;
		}
		
		REP(i, N1 + N2)
		{
			tmpDep[i] = dep[i];
			if (!tmpDep[i]) Q[i < N1].push(i);
		}
		
		int ans = solve(0);
		
		REP(i, N1 + N2)
		{
			tmpDep[i] = dep[i];
			if (!tmpDep[i]) Q[i < N1].push(i);
		}
		
		ans = min(ans, solve(1));
		
		printf( "%d\n", ans + 1);
	}

	return 0;
}
