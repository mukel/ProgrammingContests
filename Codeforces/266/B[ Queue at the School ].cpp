// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
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
#define ALL(c) (c).begin(), (c).end()

int N, T;
string buf;

string replaceAll(string s, string f, string t)
{
	string r;
	for (int p = 0; (p = s.find(f)) != s.npos;)
	{
		r += s.substr(0, p) + t;
		s = s.substr(p + f.size());
	}
	return r + s;
}

int main()
{
	ios::sync_with_stdio(0);

	cin >> N >> T;
	cin >> buf;
	while (T--)
	{
		buf = replaceAll(buf, "BG", "GB");
	}

	cout << buf << endl;


	return 0;
}
