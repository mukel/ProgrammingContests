/*
Alfonso2 Peterssen(mukel)
Codeforces Round 85 Div. 1
Task: A
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

int main()
{
	int64 N, X, Y;
	cin >> N >> X >> Y;
	
	if (Y < N) printf( "-1\n" );
	else
	{
		int64 kk = Y - (N - 1);
		int64 sum = kk * kk + N - 1;
		if (sum >= X)
		{
			printf( "%I64d", kk );
			REP(i, N - 1) printf( " 1" );
			printf( "\n" );
		} else
		      printf( "-1\n" );
	}

	return 0;
}
