/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #89 (Div. 2 Only)
*/
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cctype>

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

int main()
{
	string line, ans;
	cin >> line;
	
	REP(i, SZ(line))
	{
		if (strchr("AEIYOUaeiyou", line[i]));
		else
		{
			ans += &#39;.&#39;;
			ans += tolower(line[i]);
		}
	}
	
	cout << ans << endl;

	return 0;
}

