/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #86 (Div. 1 Only)
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

bool endsWith(string s, string end)
{
	if (SZ(end) > SZ(s)) return false;
	return s.substr(SZ(s) - SZ(end), SZ(end)) == end;
}

/*
bool beginsWith(string s, string begin)
{
	if (SZ(begin) > SZ(s)) return false;
	return s.substr(0, SZ(begin)) == begin;
}

*/
int isNoun(string s)
{
	if (endsWith(s, "etr")) return 1;
	if (endsWith(s, "etra")) return 2;
	return 0;
}

int isAdj(string s)
{
	if (endsWith(s, "lios")) return 1;
	if (endsWith(s, "liala")) return 2;
	return 0;
}

int isVerb(string s)
{
	if (endsWith(s, "initis")) return 1;
	if (endsWith(s, "inites")) return 2;
	
	return 0;
}

bool isValid(string s)
{
	return isVerb(s) || isAdj(s) || isNoun(s);
}

int getGender(string s)
{
	int r = isVerb(s);
	if (r) return r;
	r = isAdj(s);
	if (r) return r;
	r = isNoun(s);
	if (r) return r;
	
	return -10;
}

int tp[100001];
int ge[100001];
int cnt;

int main()
{

	bool shit = false;
	
	string s;
	while (cin >> s)
	{
		if (!isValid(s))
		{
			shit = true;
			break;
		}
		
		int t;
		
		if (isVerb(s)) t = 2; else
 		if (isAdj(s)) t = 0; else
  		if (isNoun(s)) t = 1;

  		tp[cnt] = t;
		ge[cnt] = getGender(s);
		
		cnt++;
	}
	
	if (cnt == 1 && !shit)
	{
		printf( "YES\n" );
		return 0;
	}
	
	/*
	REP(i, cnt)
	      printf( "(%d %d) ", tp[i], ge[i] );
	  */
	//printf( " ---> %d\n", (int)shit );

	      
	if (!shit)
	for (int i = 0; i < cnt - 1; ++i)
	      if (tp[i] > tp[i + 1]) shit = true;

	//printf( " ---> %d\n", (int)shit );
	
	if (!shit)
	if (count(tp, tp + cnt, 1) != 1) shit = true;

//	printf( " ---> %d\n", (int)shit );

	if (!shit)
	{
	sort(ge, ge + cnt);
	if (ge[0] != ge[cnt - 1]) shit = true;
}
	
	printf( "%s\n", shit ? "NO" : "YES" );

	return 0;
}

