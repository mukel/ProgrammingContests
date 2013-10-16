/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #59 "CD"
*/
#include <cstdio>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 20;

int T, N, ans;
int track[MAXN];
int sum[1 << MAXN];

int main()
{
	cin >> T >> N;
	REP(i, N) cin >> track[i];
	
	REP(i, (1 << N)) if (i)
	{
		int pos = __builtin_ctz(i);
		sum[i] = sum[i - (1 << pos)] + track[pos];
		if (sum[i] <= T) ans = max(ans, sum[i]);
	}
	
	cout << ans << endl;

	return 0;
}
