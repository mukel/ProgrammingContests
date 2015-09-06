/*
Alfonso2 Peterssen(mukel)
Codeforces #62
18 - 3 - 2010
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
//using namespace __gnu_cxx;

typedef long long int64;

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

int main()
{
	int p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	int a, b;
	cin >> a >> b;
	int ans = 0;
	FOR(i, a, b) if (i % p1 % p2 % p3 % p4 == i) ans++;
	cout << ans << endl;

	return 0;
}
