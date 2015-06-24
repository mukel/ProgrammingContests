/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #94 "Resistance PS-scheme"
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

const int MAXL = 300000;

char buf[MAXL];
int pos;

void skipBlanks()
{
	while (buf[pos] == ' ') pos++;
}

double parse();

double parseS()
{
	skipBlanks();
	double ret = 0;
	while (buf[pos] != ')')
	{
		ret += parse();
		skipBlanks();
	}
	return ret;
}

double parseP()
{
	skipBlanks();
	double ret = 0;
	while (buf[pos] != ']')
	{
		ret += 1.0/parse();
		skipBlanks();
	}
	return 1.0/ret;
}

double parse()
{
	skipBlanks();
	if (buf[pos] == '(')
	{
		pos++;
		double ret = parseS();
		skipBlanks();
		pos++;
		return ret;
	}
	else
	if (buf[pos] == '[')
	{
		pos++;
		double ret = parseP();
		skipBlanks();
		pos++;
		return ret;
	}
	else
	{
		string s;
		while (strchr("0123456789.-", buf[pos])) s += buf[pos], pos++;
		return atof(s.c_str());
	}
}

int main()
{
	gets(buf);
	printf( "%lf\n", parse() );

	return 0;
}
