// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = (int)1e7 + 1;

int a, n;
int64 ans;
short int best[MAXN];

int main()
{
	for (int i = 2; i * i <= MAXN; ++i)
	{
		int i2 = i*i;
		for (int k = i2; k < MAXN; k += i2)
			best[k] = i;
	}
	cin >> a >> n;
	for (int i = a; i < a + n; ++i)
	{
		int x = best[i]; if (!x) x = 1;
		ans += i / (x*x);
	}
	cout << ans << endl;
	return 0;
}
