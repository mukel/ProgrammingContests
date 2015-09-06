#include <bits/stdc++.h>
#include <cstring>
using namespace std;

const int
	MAXC = 5005;

int R, C;
char board[MAXC][MAXC];
int to[MAXC][MAXC];
int cnt[MAXC];

int main()
{
	ios::sync_with_stdio(false);

	memset(to, -1, sizeof(to));

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = C - 1; j >= 0; --j)
			if (board[i][j] == &#39;1&#39;)
			{
				int r = to[i][j + 1];
				if (r < 0)
					r = j;

				to[i][j] = r;
			}
	}


	int ans = 0;
	for (int lo = 0; lo < C; ++lo)
	{
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < R; ++i)
		{
			int t = to[i][lo];
			if (t >= 0)
				cnt[t]++;
		}

		for (int i = C - 1; i >= 0; --i)
			cnt[i] += cnt[i + 1];

		for (int hi = lo; hi < C; ++hi)
			ans = max(ans, (hi - lo + 1) * cnt[hi]);
	}

	cout << ans << endl;

	return 0;
}
