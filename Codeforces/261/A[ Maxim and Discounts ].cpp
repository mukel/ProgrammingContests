#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)n; ++i)

const int
	MAXN = 1 << 17;

int N, Q;
int items[MAXN];
int d[MAXN];

int main()
{
	ios::sync_with_stdio(0);

	cin >> Q;
	REP(i, Q)
		cin >> d[i];

	sort(d, d + Q);

	cin >> N;
	REP(i, N)
		cin >> items[i];

	sort(items, items + N);

	reverse(items, items + N);

	long long answer = 0;

	int lo = 0;
	while (lo < N)
	{
		int hi = lo + d[0] - 1;
		if (hi < N)
		{
			while (lo <= hi)
			{
				answer += items[lo++];
			}
			lo++;
			lo++;

		} else
		{
			while (lo < N)
				answer += items[lo++];
		}
	}

	cout << answer << endl;

	return 0;
}

