/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #52 "Permutation complexity"
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
#include <ext/hash_map>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

struct stringHasher
{
	int operator () (const string & s) const
	{
		int h = 0;
		REP(i, s.size()) h = h * 10 + (s[i] - '0');
		return h;
	}
};

int n, ans;

bool ok(const string & s)
{
	int pos = s.find('0');
	REP(i, n - 1)
	{
		if (s[pos % n] != s[(pos + 1) % n] - 1) return 0;
		pos++;
	}
	            
	 return 1;
}

__gnu_cxx::hash_map< string, short, stringHasher > D;

string start;

int main()
{
	cin >> n;
	REP(i, n)
	{
		int x; cin >> x;
		x--;
		stringstream ss; ss << x;
		start += ss.str();
	}
	
	D[start] = 0;
	queue< string > Q;
	
	bool end = ok(start);
	for (Q.push(start); !end && !Q.empty(); Q.pop())
	{
		string top = Q.front();
		int d = D[top];

		REP(i, n)
		{
			swap(top[i], top[(i + 1) % n]);
			if (!D.count(top))
			{
				if (ok(top)) { end = true; ans = d + 1; break; }
				D[top] = d + 1;
				Q.push(top);
			}
			swap(top[i], top[(i + 1) % n]);
		}
	}
	
	printf( "%d\n", ans );

	return 0;
}
