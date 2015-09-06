/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #72 (Div. 1 Only)
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
#include <tr1/unordered_map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXN = 1 << 17;

int N;
int64 K, sum;
int val[MAXN];
multiset< pair< int, int > > S;

int main()
{
	cin >> N >> K;
	REP(i, N)
	{
		cin >> val[i];
		S.insert(MP(val[i], i));
		sum += val[i];
	}
	
	if (K > sum)
	{
		printf( "-1\n" );
		return 0;
	} else
	if (sum == K)
	{
		printf( "\n" );
		return 0;
	}
	
	int64 totalLaps = 0;
	while (1)
	{
		int n = S.size();
		int top = (*S.begin()).second;
		
		if (totalLaps >= val[top])
		{
			S.erase(S.begin());
			continue ;
		}
		
//		cout << n << " " << K << endl;

		if (K < n) break;
		int64 laps = min(val[top] - totalLaps, K / n);

		K -= laps * n;
		totalLaps += laps;
	}
	
	vector< int > ans;

	int pos = 0;
	REP(i, N)
	{
	      if (val[i] > totalLaps && K)
	      {
			val[i]--;
			K--;
			if (!K)
			{
                        if (val[i] > totalLaps) pos = ans.size() + 1;
                        else pos = ans.size();
			}
		}
		if (val[i] > totalLaps) ans.PB(i);
	}

	pos %= ans.size();

	rotate(ans.begin(), ans.begin() + pos, ans.end());
	
	REP(i, SZ(ans))
	      printf( "%d ", ans[i] + 1 );
	      
	printf( "\n" );
	
	return 0;
}
