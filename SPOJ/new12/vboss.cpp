/*
Alfonso2 Peterssen
SPOJ #3867 "Who is The Boss"
5 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 1 << 16;

vector< int > G[MAXN];
int boss[MAXN];
int sub[MAXN];
bool mark[MAXN];

map< int, int > empFromId;

int id[MAXN];
int salary[MAXN];
int height[MAXN];
int order[MAXN];

struct heightComp
{
	bool operator () (const int i, const int j)
	{
		return (height[i] != height[j]) ? height[i] < height[j] : salary[i] < salary[j];
	}
};

struct salaryComp
{
	bool operator () (const int i, const int j)
	{
		return salary[i] < salary[j];
	}
};

void dfs(int u)
{
	mark[u] = true;
	
	REP(i, G[u].size())
	{
		if (!mark[ G[u][i] ])
		      dfs( G[u][i] );
		      
	      sub[u] += sub[ G[u][i] ] + 1;
	}
}

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		int N, Q;
		scanf( "%d %d", &N, &Q );
		
		empFromId.clear();
		fill(sub, sub + N, 0);
		fill(mark, mark + N, false);
		
		REP(i, N)
		{
			scanf( "%d %d %d", &id[i], &salary[i], &height[i] );
			empFromId[ id[i] ] = i;
			G[i].clear();
			
			order[i] = i;
		}

		sort(order, order + N, heightComp());
		
		set< int, salaryComp > S;
		for (int i = N - 1; i >= 0; i--)
		{
			int u = order[i];
			set< int, salaryComp >::iterator it = S.upper_bound(u);
			if (it != S.end())
			{
				boss[u] = *it;
				G[*it].push_back(u);
			} else
			      boss[u] = -1;

			S.insert(u);
		}

		REP(i, N)
		      if (!mark[i])
		            dfs(i);

		while (Q--)
		{
			int emp;
			scanf( "%d", &emp );
			int u = empFromId[emp];
			if (boss[u] < 0)
			      printf( "0 %d\n", sub[u] );
			else
				printf( "%d %d\n", id[ boss[u] ], sub[u] );
		}
	}

	return 0;
}
