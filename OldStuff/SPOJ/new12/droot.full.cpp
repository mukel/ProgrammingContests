/*
Alfonso2 Peterssen
SPOJ #4172 "Multiplicative digital root"
8 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned long long int64;
typedef vector< int64 > big;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
	MAXMOD = (int)1e4,
	BASELEN = 8;
	
const int64
	BASE = (int64)1e8;
	
int digitProd[MAXMOD];
int nums[1 << 16];

big& normalize(big& a)
{
	int64 carry = 0;
	REP(i, a.size())
	{
		int64 t = a[i] + carry;
		a[i] = t % BASE;
		carry = t / BASE;
	}

	while (carry > 0)
		a.push_back(carry % BASE), carry /= BASE;

	while (a.size() > 1 && a.back() == 0)
		a.pop_back();

	return a;
}

big operator * (const big& a, const big& b)
{
	big ans(a.size() + b.size());
	REP(i, a.size())
	REP(j, b.size())
	      ans[i + j] += a[i] * b[j];
	return normalize(ans);
}

big fromInt(int64 x)
{
	big a;
	a.push_back(x);
	return normalize(a);
}


big parseBig(const char* digits)
{
	int n = strlen(digits);
	int i = n % BASELEN;
	if (i > 0) i -= BASELEN;

	big ans;
	for (; i < n; i += BASELEN)
	{
		int64 t = 0;
		for (int j = 0; j < BASELEN; j++)
		      t = t * 10 + ((i + j >= 0) ? digits[i + j] - '0' : 0);

		ans.push_back(t);
	}

	reverse(ALL(ans));
	return ans;
}

big fastMul(int lo, int hi)
{
	if (lo == hi)
		return fromInt(nums[lo]);
		
	int mid = (lo + hi) / 2;
	return fastMul(lo, mid) * fastMul(mid + 1, hi);
}

int64 digitalRoot(int64 n) // n < MAXMOD ^ 2
{
	return digitProd[n / MAXMOD] * digitProd[n % MAXMOD];
}

big digitalRoot(big& n)
{
	int64 currDr = 1;
	
	int cnt = 0;
	REP(i, n.size())
	{
		int64 dr = digitalRoot(n[i]);
		if (currDr * dr >= BASE)
		{
			nums[cnt++] = currDr;
			currDr = dr;
		} else
		      currDr *= dr;
	}
	
	if (currDr > 1)
	      nums[cnt++] = currDr;
	      
	if (!cnt)
	      return fromInt(1);
	
	return fastMul(0, cnt - 1);
}

char buff[1 << 15];

int main()
{
	digitProd[0] = 1; // just a catch
	for (int i = 1; i < MAXMOD; i++)
	{
		digitProd[i] = 1;
		
		int x = i;
		for (int x = i; x > 0; x /= 10)
			if (x % 10)
				digitProd[i] *= (x % 10);
	}

	for (int T = atoi(gets(buff)); T--;)
	{
		big n = parseBig(gets(buff));
		while (n.size() > 1 || n.front() >= 10)
		      n = digitalRoot(n);

		printf( "%d\n", n.front() );
	}

	return 0;
}
