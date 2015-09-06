// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define endl &#39;\n&#39;
#define SZ(c) ((int)((c).size()))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
	MAXN = 1 << 17;

int N, K;
int a[MAXN];

int main()
{
	ios::sync_with_stdio(0);

	cin >> N >> K;

	if (K == 1)
	{
		cout << N << endl;
		return 0;
	}

	REP(i, N) cin >> a[i];

	sort(a, a + N);

	vector< int > ans;

	REP(i, N)
		if (a[i] % K == 0)
		{
			if (!binary_search(ALL(ans), a[i] / K))
				ans.push_back(a[i]);
		}
		else
			ans.push_back(a[i]);

	cout << SZ(ans) << endl;

	return 0;
}
