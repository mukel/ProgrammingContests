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
	MAXN = 61;

int N, M, R;
int C[MAXN][MAXN][MAXN];
int B[MAXN][MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> R;
	REP(i, M)
	{
		REP(j, N)
		REP(k, N)
			cin >> C[i][j][k];
	}

	REP(m, M)
	{
		REP(k, N)
		REP(i, N)
		REP(j, N)
			C[m][i][j] = min(C[m][i][j], C[m][i][k] + C[m][k][j]);
	}

	memset(B, 1, sizeof(B)); // INF

	REP(m, M)
	REP(i, N)
	REP(j, N)
		B[1][i][j] =  min(B[1][i][j], C[m][i][j]);

	FOR(p, 2, N)
	{
		REP(k, N)
		REP(i, N)
		REP(j, N)
		{
			B[p][i][j] = min(B[p][i][j], B[p - 1][i][j]);
			B[p][i][j] = min(B[p][i][j], B[1][i][k] + B[p - 1][k][j]);
			B[p][i][j] = min(B[p][i][j], B[p - 1][i][k] + B[1][k][j]);
		}
	}

	REP(i, R)
	{
		int s, t, k;
		cin >> s >> t >> k;
		--s;
		--t;
		k++;
		k = min(k, N);
		cout << B[k][s][t] << endl;
	}

	return 0;
}
