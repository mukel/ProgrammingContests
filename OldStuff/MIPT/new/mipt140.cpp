/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #140 "Catalan numbers"
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
	MAXP = 1 << 20;
	
int P;
int prime[MAXP];
bool mark[MAXP];

int fN[MAXP];
int f2N[MAXP];
int fn[MAXP];

int getPFactors(int n, int * pfact)
{
	REP(i, P)
	{
		if (prime[i] > n) break;
		
		int64 pw = prime[i];
		while (pw <= n)
		{
			pfact[i] += n / pw;
			pw *= prime[i];
		}
	}
}

int64 modPow(int a, int n, int mod)
{
	if (!n) return 1;
	int64 ret = modPow(a, n/2, mod);
	ret = (ret * ret) % mod;
	if (n & 1)
	      ret = (ret * a) % mod;
	return ret;
}

int main()
{
	int N, K;
	cin >> N >> K;
	
	for (int i = 2; i <= 2 * N; i++)
	      if (!mark[i])
	      {
			prime[P++] = i;
			for (int j = 2 * i; j <= 2 * N; j += i)
				mark[j] = true;
		}
		
	getPFactors(2 * N, f2N);
	getPFactors(N, fN);
	
	int n = N + 1;
	REP(i, P)
		while (n % prime[i] == 0)
			n /= prime[i], fn[i]++;
	
	int64 ans = 1;
	REP(i, P)
		ans = (ans * modPow(prime[i], f2N[i] - 2 * fN[i] - fn[i], K)) % K;
		
	cout << ans << endl;

	return 0;
}
