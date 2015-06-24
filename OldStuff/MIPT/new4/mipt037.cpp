/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #37 "Maximum profit"
*/
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int
	MAXN = 101,
	MAXM = 10001,
	oo = (int)1e9;

int N, A, B;
int dp[MAXN][MAXM];
int fr[MAXN][MAXM];
int next[MAXM];
int vals[MAXM];
int mass[MAXN];

void print(int n, int i)
{
	if (n <= 0) return ;
	print(n - 1, i - mass[n] * fr[n][i]);
	printf( "%d\n", fr[n][i] );
}

int main()
{
	scanf( "%d %d %d", &N, &A, &B );
	
	FOR (i, 0, N)
	FOR (j, 0, B) dp[i][j] = -oo;
	
	dp[0][0] = 0;

	FOR(i, 1, N)
	{
		int p, m, l;
		scanf( "%d %d %d", &p, &m, &l );
		mass[i] = m;

		FOR(j, 0, B) next[j] = B + 1;
		FOR(j, 0, B) vals[j] = -oo;

		REP(modulo, m)
		{
			int curPos = modulo;
			int delta = 0;
			int best = curPos;

			stack< int > S;

			while (curPos <= B)
			{
				dp[i][curPos] = dp[i - 1][curPos];
				fr[i][curPos] = 0;

				// adjust
				if (curPos - best > l * m) best = curPos - l * m;
				while (next[best] < curPos) best = next[best];

				int ncost = vals[best] + delta;
				if (ncost > dp[i][curPos])
				{
					dp[i][curPos] = ncost;
					fr[i][curPos] = (curPos - best) / m;
				}
				
				//printf( "%d %d -> %d\n", i, curPos, dp[i][curPos] );

				vals[curPos] = dp[i - 1][curPos] - delta;

				while (!S.empty() && vals[curPos] + delta > vals[S.top()] + delta)
				{
					next[S.top()] = curPos;
					S.pop();
				}
				S.push(curPos);

				delta += p;
				curPos += m;
			}
		}
	}

	int ans = A;
	FOR(i, A, B)
	      if (dp[N][i] > dp[N][ans]) ans = i;

	if (dp[N][ans] < 0) printf( "-1\n" );
	else
	{
		printf( "%d\n", dp[N][ans] );
		print(N, ans);
	}

	return 0;
}

