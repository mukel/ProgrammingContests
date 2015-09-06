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

int D, N;
int A[1 << 17];
int answer;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> D >> N;

	REP(i, N) cin >> A[i];

	int curDay = 1;
	REP(i, N)
	{
		if (curDay != 1)
		{
			answer += D - curDay + 1;
			curDay = 1;
		}
		curDay = A[i] + 1;
		if (curDay > D) curDay = 1;
	}

	cout << answer << endl;

	return 0;
}
