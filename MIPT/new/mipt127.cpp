/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #127 "Pythagorean triples"
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

const int
	MAXC = 281104,
	MAXN = 1000000;
	
int N;
pair< int, pair< int, int > > P[MAXN];

int main()
{
	FOR(n, 1, 531)
	FOR(m, n + 1, 531)
	if (__gcd(n, m) == 1 && ((n%2)^(m%2))) // primitive triple
	{
		int a = 2*n*m;
		int b = m*m - n*n;
		int c = m*m + n*n;
		for (int k = 1; k * c < MAXC; k++)
		{
			P[N++] = MP(k*c, MP(k*a,k*b));
			P[N++] = MP(k*c, MP(k*b,k*a));
		}
	}

	int K; cin >> K; K--;
	nth_element(P, P + K, P + N);
	cout << P[K].second.first << " " << P[K].second.second << " " << P[K].first << endl;

	return 0;
}
