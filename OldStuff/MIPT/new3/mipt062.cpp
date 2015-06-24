/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #62 "Regular Expression II"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXL = 1 << 10;

string R, P;
int memo[MAXL][MAXL];
int nextBr[MAXL];

bool match(int r, int p)
{
	if (r >= R.size() && p >= P.size()) return 1;
	if (r >= R.size() && p < P.size()) return 0;

	if (memo[r][p] != -1) return memo[r][p];

	memo[r][p] = false;

	if (R[r] == '[')
	{
		bool ret = match(nextBr[r] + 1, p) || match(r + 1, p);
		if (ret) return memo[r][p] = ret;
	}

	if (R[r] == ']') return memo[r][p] = match(r + 1, p);
	if (p < P.size() && R[r] == P[p]) memo[r][p] = match(r + 1, p + 1);
	
	return memo[r][p];
}

int main()
{
	cin >> R >> P;
	
	stack< int > S;
	REP(i, R.size())
	      if (R[i] == '[') S.push(i);
	      else if (R[i] == ']')
	            nextBr[S.top()] = i, S.pop();
	            
	memset(memo, -1, sizeof(memo));

	printf( "%s\n", match(0, 0) ? "YES" : "NO" );

	return 0;
}

