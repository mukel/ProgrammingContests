/*
Alfonso2 Peterssen(mukel)
SPOJ #8106 "Normalized Form"
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

string expr;
int pos;
int testCase;
int maxLevel;

void getLevel(int curLevel = 0)
{
	maxLevel = max(maxLevel, curLevel);
	while (pos < SZ(expr) && expr[pos] != ')')
		if (expr[pos] == '(')
		{
			pos++; // skip (
			getLevel(curLevel + 1);
			pos++; // skip )
		} else
			pos++; // skip literal
}

bool eval(bool);

bool evalChild(bool doAnd)
{
	bool result;
	if (expr[pos] == '(')
	{
		pos++;
		result = eval(!doAnd);
	} else
		result = (expr[pos] == 'T');
		
	pos++;
	
	return result;
}

bool eval(bool doAnd)
{
	bool result = evalChild(doAnd);
	while (pos < SZ(expr) && expr[pos] != ')')
	{
		if (doAnd) result &= evalChild(doAnd);
		else result |= evalChild(doAnd);
	}
	return result;
}

char buf[1 << 17];

int main()
{
	while ((expr = gets(buf)) != "()")
	{
		testCase++;

		pos = 0;
		maxLevel = 0;
		getLevel();

		pos = 0;
		printf( "%d. %s\n", testCase, eval(!(maxLevel & 1)) ? "true" : "false" );
	}

	return 0;
}
