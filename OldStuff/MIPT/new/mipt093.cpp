/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #93 "What is the number (Part II)?"
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

const int MAXN = 1 << 21;

int N;
int phi[MAXN];

int main()
{
	cin >> N;
	
	FOR(i, 2, N) phi[i] = i;

	FOR(i, 2, N)
	      if (phi[i] == i)
			for (int j = i; j <= N; j += i)
				phi[j] = (phi[j] / i) * (i - 1);

	int64 sum = 0;
	FOR(i, 2, N) sum += phi[i];
	
	int ans = 0;
	while ((1LL << ans) < sum) ans++;
				
	cout << ans << endl;

	return 0;
}
