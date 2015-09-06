/*
Alfonso2 Peterssen(mukel)
Codeforces Round 85 Div. 1
Task: D

Stirling Numbres of the Second Kind
S(n, m) =
The number of ways of partitioning a set of n
elements into m nonempty sets.
*/
#include <iostream>

using namespace std;

typedef unsigned long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int64
	MAXN = 1 << 10,
	MAXK = 1 << 20,
	MOD = (int)1e9 + 7;
	
int64 N, M, K;
int64 fact[MAXK];
int64 invFact[MAXK];
int64 S2[MAXN][MAXN]; // Stirling 2nd Kind
int64 cPow[MAXN];
int64 ans;

int64 modPow(int64 x, int64 n, int64 m)
{
	if (!n) return 1;
	int64 ret = modPow(x, n/2, m);
	ret = (ret * ret) % m;
	if (n & 1) ret = (ret * x) % m;
	return ret;
}

int64 modInverse(int64 x, int64 m)
{
	return modPow(x, m - 2, m);
}

int64 comb(int n, int k)
{
	return fact[n] * invFact[k] % MOD *	invFact[n - k] % MOD;
}

int main()
{
	cin >> N >> M >> K;

	if (M == 1)
	{
		cout << modPow(K, N, MOD) << endl;
		return 0;
	}

	fact[0] = invFact[0] = 1;
	for (int i = 1; i < MAXK; ++i)
	{
	      fact[i] = (fact[i - 1] * i) % MOD;
	      invFact[i] = modInverse(fact[i], MOD);
	}
	
	REP(i, MAXN)
		cPow[i] = modPow(i, N * (M - 2), MOD);

	S2[0][0] = 1;
	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j <= i; j++)
			S2[i][j] = (S2[i - 1][j - 1] + S2[i - 1][j] * j) % MOD;

	for (int c = 1; c <= N && c <= K; ++c)
	{
		int64 arrangeWays = S2[N][c] * S2[N][c] % MOD * fact[c] % MOD * fact[c] % MOD;

		for (int s = 0; s <= c; ++s)
		      if (s + 2 * (c - s) <= K)
			{
				int64 colorWays = comb(K, s) * comb(K - s, c - s) % MOD * comb(K - c, c - s) % MOD;
				ans = (ans + arrangeWays * colorWays % MOD * cPow[s]) % MOD;
			}
	}

	cout << ans << endl;

	return 0;
}
