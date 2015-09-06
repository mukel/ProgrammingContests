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

const int
	MAXN = 1 << 10;

int data[MAXN];

int find(int a)
{
	return (data[a] < 0) ? a : data[a] = find(data[a]);
}

int size(int a)
{
	return -data[find(a)];
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return ;
	data[b] += data[a];
	data[a] = b;
}

int N;
char S[MAXN];
char ans[MAXN];
bool mark[MAXN];
int cnt[256];

void noAnswer()
{
	printf( "NO\n" );
	exit(0);
}

int main()
{
	memset(data, -1, sizeof(data));

	scanf( "%s", S + 1 );
	N = strlen(S + 1);
	
	FOR(i, 1, N)
	      cnt[ S[i] ]++;
	
	FOR(i, 2, N)
	      if (!mark[i])
	      {
			for (int j = i; j <= N; j += i)
			      join(i, j);

			for (int j = i; j <= N; j += i)
			      mark[j] = true;
		}
		
	typedef pair< int, int > par;
	set< par > P;
		
	FOR(i, 1, N)
	      if (data[i] < 0)
			P.insert(make_pair(data[i], i));
			
	while (!P.empty())
	{
		par top = *P.begin();
		P.erase(P.begin());
		
		int pos = top.second;
		int need = -top.first;
		
		int best = 0;
		REP(i, 256)
		      if (cnt[i] > cnt[best])
		            best = i;
		            
		if (!best)
		      noAnswer();
		      
		if (cnt[best] < need)
		      noAnswer();
		
		cnt[best] -= need;
		
		FOR(i, 1, N)
		      if (find(i) == pos)
				ans[i] = best;
	}
	
	printf( "YES\n%s\n", ans + 1 );

	return 0;
}
