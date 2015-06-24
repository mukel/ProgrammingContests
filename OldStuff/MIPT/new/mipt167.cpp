/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #167 "Brackets III"
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl


const char* brkts = "<>{}[]()";
const int MAXL = 1 << 20;

stack< char > S;
char buf[MAXL];
int64 dp[MAXL];

int main()
{
	scanf( "%s", &buf );
	int n = strlen(buf);
	
	REP(i, n)
	{
		int p = strchr(brkts, buf[i]) - brkts;
		if (p & 1)
		{
			if (S.empty()) continue ;
			int q = strchr(brkts, buf[S.top()]) - brkts;
			if (q + 1 == p)
			{
				dp[i] = 1;
				if (S.top() > 0) dp[i] += dp[S.top() - 1];
				S.pop();
			} else
			{
				while (!S.empty()) S.pop();
			}
		} else
		      S.push(i);
	}
	
	int64 ans = 0;
	REP(i, n)
	      ans += dp[i];
	
	cout << ans << endl;
	
	return 0;
}
