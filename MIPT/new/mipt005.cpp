/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #5 "Random descending a tree"
*/
#include <cstdio>
#include <iostream>

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

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int MAXDEPTH = 1 << 10;

char buf[1 << 17];
int n, pos;
int sum[MAXDEPTH];

void skipBlanks()
{
      while (buf[pos] == ' ') pos++;
}

void parse(int pow2 = 0)
{
	skipBlanks();
	if (buf[pos] == '(')
	{
		pos++;
		parse(pow2 + 1);
		parse(pow2 + 1);
		skipBlanks();
		pos++;
	} else
	{
		int sign = +1;
		if (buf[pos] == '-') sign = -1, pos++;
		
		int x = 0;
		while (isdigit(buf[pos])) x = x * 10 + (buf[pos] - '0'), pos++;
		sum[pow2] += x * sign;;
	}
}

int main()
{
	gets(buf);
	parse();
	
	double ans = 0;
	for (int i = MAXDEPTH - 1; i >= 0; i--)
  		ans = ans / 2.0 + sum[i];
	
	printf( "%.2lf\n", ans );

	return 0;
}
