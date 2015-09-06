// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define SZ(c) ((int)(c).size())
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); c != (c).end(); ++it)

const int
	MAXN = 4005,
	MAXV = 1000005;

int N;
int64 b[MAXN];
int answer;
vector< int > pos[MAXV];

bool seenAs1[MAXV];
int seenAs2[MAXV];
int curMark;

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	REP(i, N)
	{
		cin >> b[i];
		pos[ b[i] ].push_back(i);
	}

	if (N == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	if (N == 2)
	{
		cout << 2 << endl;
		return 0;
	}

	answer = 2;

	for (int i = 0; i < N; ++i)
		if (!seenAs1[b[i]])
		{
			int64 a1 = b[i];

			seenAs1[a1] = true;

			curMark++;

			for (int j = i + 1; j < N; ++j)
				if (seenAs2[ b[j] ] != curMark)
				{
					seenAs2[ b[j] ] = curMark;
					int64 a2 = b[j];

					int curPos = j;
					for (int k = 3; ; ++k)
					{
						int64 nextA = (k % 2) ? a1 : a2;
						int offset = lower_bound(ALL(pos[ nextA ]), curPos + 1) - pos[nextA].begin();
						if (offset == SZ(pos[ nextA ]))
							break;
						curPos = pos[ nextA ][offset];
						answer = max(answer, k);
					}
				}
		}

	cout << answer << endl;

	return 0;
}
