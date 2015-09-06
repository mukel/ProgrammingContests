/*
Alfonso2 Peterssen(mukel) UH++
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

typedef vector< int64 > state;

int64 ans;
string op[4];

void dfs(state& src, int pos)
{
	if (src.size() == 1)
	{
		if (ans < 0 || src[0] < ans)
			ans = src[0];
		return ;
	}
	
	REP(i, src.size())
	REP(j, i)
	{
		int64 x;
		if (op[pos] == "*")
			x = src[i] * src[j];
		else
			x = src[i] + src[j];
			
		state nxt;
		REP(k, 4 - pos)
		{
			if (k != i && k != j)
			{
				nxt.push_back(src[k]);
			}
		}

		nxt.push_back(x);
		dfs(nxt, pos + 1);
	}
}



int main()
{
	state src;
	REP(i, 4)
	{
		int x;
		cin >> x;
		src.push_back(x);
	}
	
	REP(i, 3) cin >> op[i];
	
	ans = -1;
	dfs(src, 0);
	
	cout << ans << endl;

      return 0;
}
