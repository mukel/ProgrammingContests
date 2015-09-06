/*
Alfonso2 Peterssen(mukel)
Codeforces Round 85 Div. 1
Task: B
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

#define SZ(c) ((int)((c).size()))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)


int X[1 << 17];
int pos[1 << 17];

int main()
{
	int Q; scanf( "%d", &Q );
	
	for (int i = 1; i <= Q; ++i)
	{
		int ans = 0, Y;
		scanf( "%d %d", &X[i], &Y );

		for (int d = 1; d * d <= X[i]; ++d)
		{
			if (X[i] % d) continue ;
			
			int a = d;
			if (pos[a] < i - Y) ans++;

			if (d * d != X[i])
			{
				int b = X[i] / d;
				if (pos[b] < i - Y) ans++;
			}
		}
		
 		for (int d = 1; d * d <= X[i]; ++d)
		{
			if (X[i] % d) continue ;
			pos[d] = i;
			pos[X[i] / d] = i;
		}
		
		printf( "%d\n", ans );
	}

	return 0;
}
