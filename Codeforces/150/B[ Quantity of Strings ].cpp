/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #107 Div 1
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)

const int64
	MOD = 1000000007;
	
int n, m, k;
int up[2012];
	
int64 modPow(int a, int n, int m)
{
	if (!n) return 1;
	
	int64 ret = modPow(a, n/2, m);
	ret = (ret * ret) % m;
	
	if (n % 2) ret = (ret * a) % m;
	
	return ret;
}

int find(int x)
{
	if (up[x] < 0) return x;
	return up[x] = find(up[x]);
}

int size(int x)
{
	return -up[find(x)];
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return ;
	if (size(a) < size(b)) swap(a, b);
	up[a] += up[b];
	up[b] = a;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; ++i)
		up[i] = -1;
	
	for (int i = 0; i + k - 1 < n; ++i)
	{
		int lo = i, hi = i + k - 1;
		while (lo < hi)
		{
			join(lo, hi);
			++lo;
			--hi;
		}
	}
	
	int p = 0;
	for (int i = 0; i < n; ++i)
	      if (find(i) == i) p++;
	      
	printf( "%d\n", modPow(m, p, MOD) );

	return 0;
}
