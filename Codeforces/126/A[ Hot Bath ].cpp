/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #93 Div 1
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

bool answerFound;
int64 t0, t1, t2, x1, x2, ansy1, ansy2;

void check(int64 y1, int64 y2)
{
	y1 = min(y1, x1);
	y2 = min(y2, x2);
	y1 = max(y1, 0LL);
	y2 = max(y2, 0LL);
	
	
	
	if (t0 * (y1 + y2) > t1*y1 + t2*y2)
	      return  ;

	if (!answerFound)
	{
		ansy1 = y1;
		ansy2 = y2;
		answerFound = true;
	}
	else
	{

		int64 l = (t1*y1 + t2*y2) * (ansy1+ansy2);
		int64 r = (t1*ansy1 + t2*ansy2) * (y1+y2);
		
		if (l < r)
		{
			ansy1 = y1;
			ansy2 = y2;
			answerFound = true;
		}
		else
		if (l == r && y1 + y2 > ansy1 + ansy2)
		{
			ansy1 = y1;
			ansy2 = y2;
			answerFound = true;
		}
	}
}

int64 divUp(int64 a, int64 b)
{
	return (a + b - 1) / b;
}

int main()
{
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	
	check(0, 0);
	check(0, 1);
	check(1, 0);
	
	for (int64 y1 = 0; y1 <= x1; ++y1)
	{
		check(y1, x2);
		if (t2 != t0)
		{
			int64 y2 = divUp(t0*y1 - t1*y1, t2 - t0);
			check(y1, y2);
		}
	}

	for (int64 y2 = 0; y2 <= x2; ++y2)
	{
		check(x1, y2);
		if (t1 != t0)
		{
			int64 y1 = (t2*y2 - t0*y2) / (t0 - t1);
			check(y1, y2);
		}
	}
	
	cout << ansy1 << " " << ansy2 << endl;

	return 0;
}
