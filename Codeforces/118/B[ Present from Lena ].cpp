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

int main()
{
	int n;
	cin >> n;
	
	int m = n;
	
	REP(i, 2*n+1)
	{
		string row;
		
		REP(j, 2*n+1)
		{
			int d = abs(i - n) + abs(j - n);
			bool first = true;
			if (d <= n)
		            row += (char)(n - d + &#39;0&#39;);
			else
				row += &#39; &#39;;
				
			row += &#39; &#39;;
		}
		while (row[SZ(row) - 1] == &#39; &#39;) row = row.substr(0, SZ(row) - 1);
		printf( "%s\n", row.c_str() );
	}
	
	return 0;
}

