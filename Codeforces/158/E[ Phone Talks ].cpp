/*
	Alfonso2 Peterssen (mukel)
	VK Cup 2012 Qualification Round 1
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 4004,
	INF = (int)1e6;
	
int K, N;
int T[MAXN];
int D[MAXN];
int memo[MAXN][MAXN];
int ans;

int bestTime(int n, int k)
{
	if (k < 0) return INF;
	if (n < 0) return 0;
	
	int & r = memo[n][k];
	if (r != -1) return r;

	r = bestTime(n - 1, k - 1);
	r = min(r, max(bestTime(n - 1, k) + 1, T[n]) + D[n] - 1);

	return r;
}

int main()
{
	memset(memo, -1, sizeof(memo));

	cin >> N >> K;
	REP(i, N) cin >> T[i] >> D[i];

	T[N++] = 60 * 60 * 24 + 1;

	REP(i, N)
		ans = max(ans, T[i] - bestTime(i - 1, K) - 1);

	cout << ans << endl;

	return 0;
}
