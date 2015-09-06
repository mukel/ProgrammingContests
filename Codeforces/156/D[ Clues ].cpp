/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #110 Div 1
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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 17;
	
int N, M, MODULO;
int P[MAXN];
int n;

int find(int x)
{
	if (P[x] < 0) return x;
	return P[x] = find(P[x]);
}

int size(int x)
{
	return -P[find(x)];
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return ;
	if (size(a) < size(b)) swap(a, b);
	P[a] += P[b];
	P[b] = a;
}

int64 modPow(int a, int n)
{
	if (!n) return 1;
	
	int64 r = modPow(a, n/2);
	r = (r * r) % MODULO;
	if (n % 2)
	      r = (r * a) % MODULO;
	return r;
}

int main()
{
	memset(P, -1, sizeof(P));
	
	scanf( "%d %d %d", &N, &M, &MODULO );
	REP(i, M)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		--u;
		--v;
		join(u, v);
	}
	
	int64 ans = 1;

	REP(i, N)
	      if (find(i) == i)
	      {
			ans = (ans * size(i)) % MODULO;
			n++;
		}
	
	if (n < 2)
	{
		printf( "%d\n", 1 % MODULO );
		return 0;
	}
	
	ans = (ans * modPow(N, n - 2)) % MODULO;
	
	printf( "%d\n", ans % MODULO );
	
	return 0;
}
