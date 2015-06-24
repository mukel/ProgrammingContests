/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #128 "Anti-plagiarism"
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

int N;
string tmp[1 << 15];
vector< string > doc[1 << 15];
char buf[1 << 17];

int main()
{
	int N = atoi(gets(buf));
	REP(i, N)
	{
		stringstream ss(gets(buf));
		string w;
		while (ss >> w) doc[i].PB(w);
		sort(ALL(doc[i]));
		doc[i].erase(unique(ALL(doc[i])), doc[i].end());
	}
	
	int ans = -1, a, b;
	REP(i, N)
	REP(j, i)
	{
		int cnt = set_intersection(ALL(doc[i]), ALL(doc[j]), tmp) - tmp;
		if (cnt > ans)
		{
			ans = cnt;
			a = j;
			b = i;
		}
	}
	
	printf( "%d\n%d %d\n", ans, a, b );

	return 0;
}
