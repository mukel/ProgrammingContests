/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>

#include <cstdlib>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); ++i)

typedef long long int64;

const int MAXC = 60;

int R, C;
int sum[MAXC][MAXC];

int getSum(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int test(int a, int b)
{
	int ans = R * C;
	FOR(i, 1, R)
	FOR(j, 1, C)
		 if (i + a - 1 <= R && j + b - 1 <= C )
			ans = min(ans, getSum(i, j, i + a - 1, j + b - 1));
	
	return ans;
}

int main()
{
	cin >> R >> C;
	FOR(i, 1, R)
	FOR(j, 1, C)
	{
		int x;
		cin >> x;
		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
	}
	
	int a, b;
	cin >> a >> b;
	
	cout << min(test(a, b), test(b, a)) << endl;

      return 0;
}
