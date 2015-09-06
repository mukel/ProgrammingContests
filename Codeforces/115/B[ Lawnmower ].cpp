/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #87 (Div. 1 Only)
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

const int
	MAXC = 1 << 10;

int R, C;
char buf[MAXC];
int beg[MAXC];
int end[MAXC];
int ans;

int main()
{
	scanf( "%d %d", &R, &C );
	REP(i, R)
	{
		scanf( "%s", &buf );
		
		beg[i] = -1;
		REP(j, C) if (buf[j] == &#39;W&#39;) end[i] = j;
 		REP(j, C) if (buf[j] == &#39;W&#39;) { beg[i] = j; break; }
	}
	
	int lastRow = 0;
	int curCol = 0;
	
	if (beg[0] >= 0)
	{
		beg[0] = 0;
	}
	
	REP(i, R)
	{
		if (beg[i] >= 0)
		{
			ans += i - lastRow;
			lastRow = i;
		} else
		      continue ;
		      
		//printf( "%d -> ", i );
		//printf( "  %d %d .. %d  ", beg[i], end[i], curCol );
		
		if (i%2 == 1)
		{
			if (lastRow % 2 == 0)
				while (curCol < end[i]) curCol++, ans++;
			else
				while (curCol < end[i]) curCol++, ans++;
		} else
		{
			if (lastRow % 2 == 0)
				while (curCol > beg[i]) curCol--, ans++;
			else
				while (curCol > beg[i]) curCol--, ans++;
		}
		
		if (i & 1)
			while (curCol > beg[i]) curCol--, ans++;
		else
			while (curCol < end[i]) curCol++, ans++;
		      
		//printf( " curCol = %d, ans = %d\n", curCol, ans );
  	}
	
	printf( "%d\n", ans );

	return 0;
}

