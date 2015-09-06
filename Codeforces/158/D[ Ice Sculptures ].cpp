/*
	Alfonso2 Peterssen (mukel)
	VK Cup 2012 Qualification Round 1
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 15;
	
int N;
int T[MAXN];
int value[MAXN];
int ans;

int main()
{
	cin >> N;
	REP(i, N) cin >> T[i], ans += T[i];

	for (int i = 3; i <= N; ++i)
	      if (N % i == 0)
		{
			int offset = N / i;
			REP(j, offset) value[j] = 0;
			REP(j, N) value[j % offset] += T[j];
			ans = max(ans, *max_element(value, value + offset));
		}
		
	cout << ans << endl;

	return 0;
}
