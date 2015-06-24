/*
Alfonso2 Peterssen(mukel)
SPOJ #5294 "Recurrence"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)((c).size()))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

typedef vector< int64 > array;
typedef vector< array > matrix;

matrix modMul(const matrix & a, const matrix & b, int MOD)
{
	int r = SZ(a);
	int c = SZ(b[0]);
	
	matrix ret(r, array(c));
	REP(i, r)
	REP(j, c)
	REP(k, SZ(b))
	      ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
	return ret;
}

matrix identity(int n)
{
	matrix I(n, array(n));
	REP(i, n) I[i][i] = 1;
	return I;
}

typedef vector< int > big;

big div(const big & b, int x)
{
	big ret = b;
	for (int i = SZ(b) - 1; i >= 0; i--)
	{
		if (i && ret[i] % x) ret[i - 1] += 10;
		ret[i] /= x;
	}
	while (SZ(ret) > 1 && !ret.back()) ret.pop_back();
	return ret;
}

matrix modPow(const matrix & M, big n, int MOD)
{
	if (SZ(n) == 1 && !n[0]) return identity(2);

	matrix ret = modPow(M, div(n, 2), MOD);
	ret = modMul(ret, ret, MOD);
	if (n[0] & 1)
	      ret = modMul(ret, M, MOD);
	      
	return ret;
}

const int MAXL = 1 << 7;

char sa[MAXL];
char sb[MAXL];
char sn[MAXL];

int intMod(char * s, int MOD)
{
	int ret = 0;
	for (int i = 0; s[i]; i++)
		ret = (ret * 10 + (s[i] - '0')) % MOD;
	return ret;
}

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		int a, b, MOD;
		scanf( "%s %s %s %d", &sa, &sb, &sn, &MOD );
		a = intMod(sa, MOD);
		b = intMod(sb, MOD);
		
		big n;
		for (int i = 0; sn[i]; i++)
		      n.push_back(sn[i] - '0');
		      
		reverse(ALL(n));

		matrix M(2, array(2));
		M[0][0] = a;
		M[0][1] = 1;
		M[1][1] = 1;
	
		matrix V(2, array(1));
		V[0][0] = 1;
		V[1][0] = b;
	
		matrix ans = modMul(modPow(M, n, MOD), V, MOD);
	
		cout << ans[0][0] << endl;
	}

	return 0;
}
