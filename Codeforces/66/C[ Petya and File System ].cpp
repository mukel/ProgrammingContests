/*
 * Alfonso2 Peterssen(mukel)
 * Codeforces Round #61 (Div. 2)
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin, (c).end()
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define FOR(i, b, e) for (int (i) = (int)(b); (i) <= (int)(e); ++(i))

const int MAXT = 1 << 18;

string buf;
map< string, int > T[MAXT];
int nodes;

pair< int, int > dfs(int r)
{
	//cout << cur << endl;
	
	int a = 1, b = 0;
	for (typeof(T[r].begin()) it = T[r].begin(); it != T[r].end(); ++it)
	{
		string s = it->first;		
		if (s.find(&#39;.&#39;) != string::npos) b++;
		else
		{
			pair< int, int > nxt = dfs(it->second);
			a += nxt.first;
			b += nxt.second;
		}
	}

	//cout << a << " " << b << endl;

	return make_pair(a, b);
}

vector< string > split(string s)
{
	vector< string > ret;

	s += &#39;\\&#39;;

	int pos = 0; bool first = true;
	REP(i, s.size())
		if (s[i] == &#39;\\&#39;)
		{
			if (first)
			{ first = false; }
			else
			{
				ret.push_back(s.substr(pos, i - pos));
				pos = i + 1;
			}
		}

	return ret;
}

int main()
{	
	while (cin >> buf)
	{
		if (buf == "x") break;
		vector< string > path = split(buf);

		
		int r = 0;
		REP(i, path.size())
		{
			if (!T[r][ path[i] ]) T[r][ path[i] ] = ++nodes;
			r = T[r][ path[i] ];
		}					
	}

	int a = 0, b = 0, r = 0;
	for (typeof(T[r].begin()) it = T[r].begin(); it != T[r].end(); ++it)
	{
		pair< int, int > nxt = dfs(it->second);
		a = max(a, nxt.first);
		b = max(b, nxt.second);
	}	

	printf( "%d %d\n", a - 1, b );
	
	return 0;
}
