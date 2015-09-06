/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #109 Div 1
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
#include <cassert>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)

const int
	MAXN = 1 << 17;

int N, Q;
vector< int > f[MAXN];
set< int > cnt[MAXN];
bool used[MAXN];

int main()
{
	for (int i = 2; i < MAXN; ++i)
	{
		int x = i;
		for (int j = 2; j * j <= x; ++j)
		{
			int e = 0;
			while (x % j == 0)
			{
			      e++;
			      x /= j;
			}
			if (e > 0)
			      f[i].push_back(j);
		}
		if (x > 1)
		      f[i].push_back(x);
	}

	scanf( "%d %d", &N, &Q );
	while (Q--)
	{
		char sg[10]; int x;
		scanf( "%s %d", &sg, &x );
		if (sg[0] == &#39;-&#39;) // remove
		{
			if (used[x])
			{
				for (int i = 0; i < f[x].size(); ++i)
				      cnt[ f[x][i] ].erase(x);
	                  used[x] = 0;
    				printf( "Success\n" );
			}
			else
				printf("Already off\n");
		}
		else // insert
		{
			if (used[x]) printf("Already on\n");
			else
			{
				bool conflict = 0;
				for (int i = 0; i < f[x].size(); ++i)
				      if (!cnt[ f[x][i] ].empty())
				      {
						conflict = 1;
						printf( "Conflict with %d\n", *(cnt[ f[x][i] ].begin()) );
						assert(used[*(cnt[ f[x][i] ].begin())]);
						break;
					}

				if (!conflict)
				{
					used[x] = 1;
					for (int i = 0; i < f[x].size(); ++i)
					      cnt[ f[x][i] ].insert(x);
					printf( "Success\n" );
				}
			}
		}
	}

	return 0;
}
