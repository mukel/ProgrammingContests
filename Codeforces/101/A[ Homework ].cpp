/*
Alfonso2 Peterssen(mukel)
Universidad de La Habana
Codeforces Round 79 Beta Div. 1
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
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int ALPHA = 1 << 8;

int N, K;
char buf[1 << 18];
int del[ALPHA];
int freq[ALPHA];
int order[ALPHA];
int cnt;

bool myComp(int i, int j)
{
	return freq[i] < freq[j];
}

int main()
{
	scanf( "%s", &buf );
	scanf( "%d", &K );
	
	int n = strlen(buf);
	
	REP(i, n)
		freq[ buf[i] ]++;
		
	REP(i, ALPHA) if (freq[i])
		order[cnt++] = i;
		
	sort(order, order + cnt, myComp);
		
		
	int remain = cnt;
	
	REP(i, cnt)
	{
		int j = order[i];
		if (K - freq[j] >= 0)
		{
			del[j] = true;
			remain--;
			K -= freq[j];
		}
	}
	
	printf( "%d\n", remain );
	
	REP(i, n)
	      if (!del[ buf[i] ]) printf( "%c", buf[i] );
	      
	printf( "\n" );

	return 0;
}
