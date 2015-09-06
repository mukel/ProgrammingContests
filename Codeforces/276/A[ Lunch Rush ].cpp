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

int N, K;
int64 ans = -(int64)1e12;

int main()
{
	ios::sync_with_stdio(0);	
	
	cin >> N >> K;
	REP(i, N)
	{
		int64 f, t;	cin >> f >> t;
		if (t > K) ans = max(ans, f - (t - K));
		else
			ans = max(ans, f);
	}
	
	cout << ans << endl;
	
	return 0;
}
