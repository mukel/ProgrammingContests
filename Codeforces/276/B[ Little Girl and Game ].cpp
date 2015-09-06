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

int cnt[0xFF];

int main()
{
	ios::sync_with_stdio(0);
	
	string line;
	cin >> line;
	
	for (char c : line)
		cnt[c]++;
	
	int odd = 0;
	FOR(c, &#39;a&#39;, &#39;z&#39;)
		if (cnt[c] % 2)
			odd++;
			
	if (odd == 0 || odd % 2)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	
	return 0;
}
