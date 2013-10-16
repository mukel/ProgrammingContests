/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #87 "Tautology"
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
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXN = 100000;

int n, pos;
char buf[MAXN];
bool var[MAXN];

void skipBlanks()
{
	while (buf[pos] == ' ') pos++;
}

bool eval();

bool nextValue()
{
	skipBlanks();
	if (buf[pos] == '(')
	{
		pos++;
		bool ret = eval();
		skipBlanks();
		pos++;
		return ret;
	}
	if (buf[pos] == '!')
	{
		pos++;
		return !nextValue();
	}
	if (buf[pos] == 'x')
	{
		pos++; // skip x
		int x = 0;
		while (pos < n && strchr("1234567890", buf[pos])) x = x * 10 + (buf[pos] - '0'), pos++;
		x--;

		return var[x];
	}
}

bool nextAND()
{
	bool ret = nextValue();
	skipBlanks();
	while (pos < n && buf[pos] == '&')
	{
		pos++; // skip &
		bool other = nextValue();
		ret = ret && other;
		skipBlanks();
	}
	return ret;
}


bool nextOR()
{
	bool ret = nextAND();
	
	skipBlanks();
	while (pos < n && buf[pos] == '|')
	{
		pos++;
		bool other = nextAND();
		ret = ret || other;
		skipBlanks();
	}
	return ret;
}

bool eval()
{
	return nextOR();
}

int main()
{
	int V = atoi(gets(buf));
	gets(buf);
	n = strlen(buf);
	
	REP(i, (1 << V))
	{
		REP(j, V) var[j] = (i >> j) & 1;

		pos = 0;
		if (!eval())
		{
			printf( "NO\n" );
			REP(j, V) printf( "%d ", var[j] );
			return 0;
		}
	}
	
	printf( "YES\n" );

	return 0;
}
