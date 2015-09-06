/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #111 Div 2
*/
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

int N;
int curSum;
int sum;
int a[1000];
int ans;

int main()
{
	cin >> N;
	REP(i, N)
	{
	      cin >> a[i];
	      sum += a[i];
	}
	sort(a, a + N);
	for (int i = N - 1; i >= 0; --i)
	{
		curSum += a[i];
		ans++;
		if (curSum > (sum - curSum)) break;
	}
	cout << ans << endl;

	return 0;
}
