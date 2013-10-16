/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #64 "Max product"
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
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

typedef pair< int, int > pii;

const int
	MAXN = 1 << 20;
	
int val[MAXN];

set< pii, less<pii> > absUp;
set< pii, greater<pii> > absDn;
set< pii, less<pii> > up;
set< pii, greater<pii> > dn;

int main()
{
	int N;
	scanf( "%d", &N );
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		val[i] = x;
		absUp.insert(MP(abs(x), i)); while (absUp.size() > 10) absUp.erase(absUp.begin());
		absDn.insert(MP(abs(x), i)); while (absDn.size() > 10) absDn.erase(absDn.begin());
		up.insert(MP(x, i)); while (up.size() > 10) up.erase(up.begin());
		dn.insert(MP(x, i)); while (dn.size() > 10) dn.erase(dn.begin());
	}
	
	vector< pii > V;
	V.insert(V.end(), ALL(absUp));
	V.insert(V.end(), ALL(absDn));
	V.insert(V.end(), ALL(up));
	V.insert(V.end(), ALL(dn));

	int a = V[0].second, b = V[1].second, c = V[2].second;
	int64 ans = val[a] * val[b] * (int64)val[c];
	
	int n = V.size();
	REP(i, n)
	REP(j, i)
	REP(k, j)
	      if (V[i].second != V[j].second && V[j].second != V[k].second && V[i].second != V[k].second)
	      {
			int64 t = val[ V[i].second ] * val[ V[j].second ] * (int64)val[ V[k].second ];
			if (t > ans)
			{
				ans = t;
				a = V[i].second;
				b = V[j].second;
				c = V[k].second;
			}
		}

	cout << val[a] << " " << val[b] << " " << val[c] << endl;

	return 0;
}

