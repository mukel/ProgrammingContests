/*
	Alfonso2 Peterssen(mukel)
	Codeforces Round 96(Div. 1)
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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)((c).size()))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) (cout << #x << " = " << x << endl)

const int
	MAXL = 1 << 17;

char buf[MAXL];
int prev;

int rev(int x)
{
	int ret = 0;
	REP(i, 8)
		if (x & (1 << i))
		      ret |= 1 << (7 - i);
	return ret;
}

int main()
{
	gets(buf);
	
	for (int i = 0; buf[i]; ++i)
	{
		int r = rev(buf[i]);
		printf( "%d\n", (prev - r + 256) % 256 );
		prev = r;
	}

	return 0;
}

