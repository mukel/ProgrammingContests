/*
Alfonso2 Peterssen(mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

#include <cstring>
#include <cstdlib>
//#include <cmath>
//#include <complex>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int MAXN = 1 << 18;
const int64 MODULO = 1000000007;

int n;
int P;
int prime[MAXN];
bool mark[MAXN];

int getPrimes(int nfact, int p)
{
	int ans = 0;
	for (int64 pp = p; pp <= nfact; pp *= p)
		ans += (nfact / pp);
	
	return ans;
}

int64 powMod(int64 a, int n)
{
	if (!n) return 1;
	int64 ans = powMod(a, n / 2);
	ans = (ans * ans) % MODULO;
	if (n % 2)
		ans = (ans * a) % MODULO;
	return ans;
}

int main()
{
	for (int i = 2; i < MAXN; i++)
	      if (!mark[i])
	      {
			prime[P++] = i;
			for (int j = 2 * i; j < MAXN; j += i)
			      mark[j] = true;
		}

	scanf( "%d", &n );

	int64 ans = 1;
	REP(i, P)
	{
		int p = prime[i];
		if (p > 2 * n - 1) break;
		ans *= powMod(p, getPrimes(2 * n - 1, p) - getPrimes(n, p) - getPrimes(n - 1, p));
		ans %= MODULO;

	}
	
	ans = (ans * 2 - n) % MODULO;
	ans = (ans + MODULO) % MODULO;
	
	cout << ans << endl;
	
	return 0;
}
