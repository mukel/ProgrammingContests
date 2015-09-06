#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)n; ++i)

const int
	MAXN =  1 << 17;

int N, last;
int64 box[MAXN];
int64 minFromLast[MAXN];
int64 minFromEnd[MAXN];
int64 minFromStart[MAXN];

int main()
{
	ios::sync_with_stdio(0);

	cin >> N >> last;
	--last;

	REP(i, N)
		cin >> box[i];

	int64 lowest = *min_element(box, box + N);

	minFromLast[last] = box[last];
	for (int i = last - 1; i >= 0; --i)
		minFromLast[i] = min(minFromLast[i + 1], box[i]);

	REP(i, last)
		if (box[i] == lowest)
		{
			if (minFromLast[i + 1] - (lowest + 1) < 0)
				continue ;
			int64 firstBox = lowest * N + last - i;

//			cout << "Start at " << i + 1 << endl;

			REP(j, N)
			{
				if (j == i)
					cout << firstBox << " ";
				else
					cout << box[j] - lowest - (j > i && j <= last) << " ";
			}
			cout << endl;

			return 0;
		}

	if (box[last] == lowest)
	{
		int64 firstBox = lowest * N;

//		cout << "Start at " << last + 1 << endl;

		REP(j, N)
		{
			if (j == last)
				cout << firstBox << " ";
			else
				cout << box[j] - lowest << " ";
		}
		cout << endl;

		return 0;
	}

	minFromEnd[N] = 1LL << 60;
	minFromEnd[N - 1] = box[N - 1];
		for (int i = N - 2; i >= 0; --i)
			minFromEnd[i] = min(minFromEnd[i + 1], box[i]);

	minFromStart[0] = box[0];
		for (int i = 1; i < N; ++i)
			minFromStart[i] = min(minFromStart[i - 1], box[i]);

	for (int i = last + 1; i < N; ++i)
	if (box[i] == lowest)
	{
		int64 firstBox = lowest * N + last + N - i;

		if (minFromEnd[i + 1] - (lowest + 1) < 0)
			continue ;

		if (minFromStart[last] - (lowest + 1) < 0)
			continue ;

//		cout << "Start at " << i + 1 << endl;

		REP(j, N)
		{
			if (j == i)
				cout << firstBox << " ";
			else
				cout << box[j] - lowest - (j <= last || j > i) << " ";
		}
		cout << endl;

		return 0;
	}

	return 0;
}
