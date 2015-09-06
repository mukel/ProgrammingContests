/*
	Alfonso2 Peterssen (mukel)
	VK Cup 2012 Qualification Round 1
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define SZ(c) ((int)(c).size())
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 6;

int N, K;
int score[MAXN];
vector< string > path;

vector< string > split(string s, string t)
{
	vector< string > v;
	for (int p = 0; (p = s.find(t)) != s.npos;)
	{
		string d = s.substr(0, p);
		if (!d.empty()) v.push_back(d);
		s = s.substr(p + t.size());
	}
	if (!s.empty()) v.push_back(s);
	return v;
}

int main()
{
	int Q;
	for (cin >> Q; Q--;)
	{
		string op; cin >> op;
		if (op == "pwd")
		{
			cout << "/"; REP(i, SZ(path)) cout << path[i] << "/"; cout << endl;
		}
		else
		{
			string arg; cin >> arg;
			if (arg[0] == &#39;/&#39;) path = vector< string >();
			vector< string > s = split(arg, "/");
			REP(i, SZ(s))
				if (s[i] == "..") path.pop_back();
				else path.push_back(s[i]);
		}
	}

	return 0;
}
