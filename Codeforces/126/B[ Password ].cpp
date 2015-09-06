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

const int
	MAXL = 1 << 20;
	
int N;
char S[MAXL];
int pref[MAXL];
int cnt[MAXL];

int main()
{
	scanf( "%s", &S );

	N = strlen(S);

	pref[0] = N;
	for (int i = 1, end = 0, f; i < N; i++ )
		// end = f + pref[f]
		if (i < end && pref[i - f] != end - i) pref[i] = min(pref[i - f], end - i);
		else
		{
			end = max(end, i);
			f = i;
			while (S[end] == S[end - f]) ++end;
			pref[i] = end - f;
		}
		
	for (int i = 1; i < N; ++i)
	      cnt[ pref[i] ]++;
	      
	for (int i = N; i >= 0; --i)
	      cnt[i] += cnt[i + 1];

	int ans = 0;
	for (int i = N - 1; i > 0; --i)
	{
		if (pref[N - i] == i)
		{
			// possible candidate
			if (cnt[i] > 1)
			{
				S[i] = &#39;\0&#39;;
				printf( "%s\n", S );
				exit(0);
			}
		}
	}
	
	printf( "Just a legend\n" );

	return 0;
}
