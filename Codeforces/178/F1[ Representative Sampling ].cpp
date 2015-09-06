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
	MAXN = 20;

int N, K;
int lcp[MAXN][MAXN];
int dp[1 << MAXN];
string S[MAXN];
int ans;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	REP(i, N) cin >> S[i];

	REP(i, N)
	REP(j, N) if (i != j)
	{
		int k = 0;
		while (k < SZ(S[i]) && k < SZ(S[j]) && S[i][k] == S[j][k])
			++k;
		lcp[i][j] = k;
	}

	REP(i, (1 << N)) if (i)
	{
		REP(j, N)
			if (i & (1 << j))
			{
				dp[i] = dp[i - (1 << j)];
				REP(k, N) if (k != j && (i & (1 << k)))
					dp[i] += lcp[j][k];
				break ;
			}

		if (__builtin_popcount(i) == K)
			ans = max(ans, dp[i]);
	}

	cout << ans << endl;



	return 0;
}
