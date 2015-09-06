#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define endl &#39;\n&#39;
#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)n; ++i)

map< string, int > dates;

int parse(string num)
{
	int val = 0;
	REP(i, SZ(num))
	{
		if (num[i] == &#39;-&#39;)
			return -1;
		val = val * 10 + (num[i] - &#39;0&#39;);
	}
	return val;
}

int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	ios::sync_with_stdio(0);

	string line;

	cin >> line;

	REP(i, SZ(line) - 9)
	{
		string cur = string(line.begin() + i, line.begin() + i + 10);

		//cout << cur << endl;

		if (cur[2] != &#39;-&#39; || cur[5] != &#39;-&#39;)
			continue ;
		int d = parse(string(cur.begin(), cur.begin() + 2));
		int m = parse(string(cur.begin() + 3, cur.begin() + 5));
		int y = parse(string(cur.begin() + 6, cur.begin() + 10));

		if (y < 2013 || y > 2015) continue ;
		if (m < 1 || m > 12) continue ;
		if (d < 1 || d > days[m]) continue ;
		++dates[cur];
	}

	pair< int, string > best = make_pair(-1, "");

	for (auto p : dates)
		best = max(best, make_pair(p.second, p.first));

	cout << best.second << endl;

	return 0;
}
