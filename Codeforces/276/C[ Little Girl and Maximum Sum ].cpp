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
	MAXN = 1 << 18;
	
int N, Q;
int sum[MAXN];
int nums[MAXN];
int order[MAXN];

bool myCmp(int a, int b)
{
	return sum[a] < sum[b];
}

int main()
{
	ios::sync_with_stdio(0);
	
	cin >> N >> Q;
	
	REP(i, N)
		cin >> nums[i];

	REP(i, Q)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;		
		sum[u]++;
		sum[v + 1]--;
	}
	
	REP(i, N)
	{
		if (i) sum[i] += sum[i - 1];
		order[i] = i;
	}
	
	sort(order, order + N, myCmp);	
	sort(nums, nums + N);
	
	int64 ans = 0;
	REP(i, N)
		ans += sum[ order[i] ] * (int64)nums[i];
		
	cout << ans << endl;

	return 0;
}
