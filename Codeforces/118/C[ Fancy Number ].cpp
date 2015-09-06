/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #89 (Div. 2 Only)
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

int n, k;
string num;
int used[10];
vector< int > pos[10];
string bestNum;
int bestCost;
int digCnt[10];

string buildNum(int digit)
{
	string ret = num;
	REP(d, 10)
	{
		if (digit < d)
		{
			for (int i = 0; i < used[d]; ++i)
			      ret[ pos[d][i] ] = (char)(digit + &#39;0&#39;);
		}
		else
		{
			for (int i = 0; i < used[d]; ++i)
			      ret[ pos[d][digCnt[d] - i - 1] ] = (char)(digit + &#39;0&#39;);
		}
	}
	
	return ret;
}

int main()
{
	cin >> n >> k >> num;
	
	REP(i, n)
	{
		int d = num[i] - &#39;0&#39;;
	      digCnt[d]++;
	      pos[d].push_back(i);
	}

	bestCost = (int)1e9;

	REP(digit, 10)
	{
		int curCost = 0;
		int target = k - digCnt[digit];
		
		for (int d = 0; d < 10; ++d)
			used[d] = 0;
		
		for (int i = 1; target > 0 && i < 10; i++)
		{
			int d = digit + i;
			if (d < 10)
			{
				int x = min(target, digCnt[d]);
				curCost += x * abs(digit - d);
				used[d] = x;
				target -= x;
			}

			d = digit - i;
			if (d >= 0)
			{
				int x = min(target, digCnt[d]);
				curCost += x * abs(digit - d);
   				used[d] = x;
				target -= x;
			}
		}
		
		string curNum = buildNum(digit);
		if (curCost < bestCost || (curCost == bestCost && curNum < bestNum))
		{
			bestCost = curCost;
			bestNum = curNum;
		}
	}
	
	printf( "%d\n%s\n", bestCost, bestNum.c_str() );
	
	return 0;
}
