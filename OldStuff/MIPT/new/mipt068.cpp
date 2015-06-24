/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #68 "2x1-paving"
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
	MAXN = 1 << 9,
	offset[4][2] = {{-1,0},{0,-1}};

int N;
char mat[MAXN][MAXN];
int from[MAXN * MAXN];
int mark[MAXN * MAXN];
int ans;
int curMark;
int vId[MAXN][MAXN];
vector< int > G[MAXN * MAXN];

bool dfs(int u)
{
	if (mark[u] == curMark) return 0;
	mark[u] = curMark;
	REP(i, G[u].size())
	{
		int v = G[u][i];
		if (from[v] < 0 || dfs(from[v]))
		{
			from[v] = u;
			return 1;
		}
	}

	return 0;
}

int main()
{
	scanf( "%d", &N );
	
	int cnt = 0;
	REP(i, N)
	REP(j, N)
		vId[i][j] = cnt++;
	
	REP(i, N)
	{
		scanf( "%s", &mat[i] );
		REP(j, N)
		      if (mat[i][j] == '.')
		      {
				REP(k, 2)
				{
					int nx = i + offset[k][0];
					int ny = j + offset[k][1];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
					if (mat[nx][ny] == '.')
					{
						int a = vId[i][j];
						int b = vId[nx][ny];
						if ((i + j) % 2) swap(a, b); // check edge
					      G[a].PB(b);
					}
				}
			}
	}
	
	fill_n(from, N * N, -1);
	REP(i, N * N)
	{
		curMark++;
		if (dfs(i)) ans++;
	}
	
	printf( "%d\n", ans );

	return 0;
}
