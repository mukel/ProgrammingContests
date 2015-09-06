/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #88
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

typedef long long int64;


#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)

const int
	MAXV = 5005;

int V;
char mark[MAXV];
char G[MAXV][MAXV];

vector< int > S, C;

bool dfs(int u)
{
	mark[u] = 1;
	S.push_back(u);
	
	REP(v, V)
		if (G[u][v] == &#39;1&#39;)
		{
			if (mark[v] == 1)
			{
				for (int i = S.size() - 1; i >= 0; --i)
				{
					C.push_back(S[i]);
					if (S[i] == v) break;
				}

				return 1;
			}
			if (!mark[v]) if (dfs(v)) return 1;
		}
		
	mark[u] = 2;
	S.pop_back();
	
	return 0;
}

int main()
{
	scanf( "%d", &V );
	REP(i, V)
		scanf( "%s", &G[i] );
		
	if (V < 3)
	{
		printf( "-1\n" );
		return 0;
	}
		
	bool ok = false;

	REP(i, V)
	      if (!mark[i])
			if (dfs(i))
			{
				ok = true;
				break;
			}
			
	if (!ok)
	{
		printf( "-1\n" );
		return 0;
	}
	
	reverse(ALL(C));

	while (SZ(C) > 3)
	{
            int n = SZ(C);
            
		for (int i = 0; i + 2 < n; ++i)
		{
			int a = C[i], b = C[i + 1], c = C[i + 2];
			if (G[c][a] == &#39;1&#39;)
			{
				printf( "%d %d %d\n", a + 1, b + 1, c + 1 );
				return 0;
			}
		}
		swap(C[n - 2], C[n - 1]);
		C.pop_back();
	}

	REP(i, 3)
		printf( "%d ", C[i] + 1 );
		
	printf( "\n" );

	return 0;
}

