/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #403 "Arithmetica 1.0"
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

int n, pos;
char buf[1 << 10];

void skipBlanks()
{
	while (pos < n && buf[pos] == ' ') pos++;
}

int factor()
{
	skipBlanks();
	if (buf[pos] == '-')
	{
		pos++;
		return -factor();
	}
	int x = 0;
	while (isdigit(buf[pos])) x = x * 10 + buf[pos] - '0', pos++;
	return x;
}

int term()
{
	int result = factor();

	skipBlanks();
	while (pos < n && strchr("*/", buf[pos]))
	{
		char op = buf[pos];
		pos++;
		int other = factor();
		if (op == '*') result *= other;
		else result /= other;
		skipBlanks();
	}
	return result;
}

int expression()
{
	int result = term();

	skipBlanks();
	while (pos < n && strchr("+-", buf[pos]))
	{
		char op = buf[pos];
		pos++;
		int other = factor();
		if (op == '+') result += other;
		else result -= other;
		skipBlanks();
	}
	return result;
}

int main()
{
	gets(buf);
	n = strlen(buf);
	
	cout << expression() << endl;

	return 0;
}
