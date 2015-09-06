/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #111 Div 2
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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1000;

int N;
string num;

int main()
{
	cin >> N;
	cin >> num;
	
	sort(num.begin(), num.begin() + N);
	sort(num.begin() + N, num.begin() + 2*N);

	if (num[0] < num[N])
	{
		REP(i, N)
		      if (num[i] >= num[i + N])
		      {
				printf( "NO\n" );
				return 0;
			}
		printf( "YES\n" );
		return 0;
	}
	else
	if (num[0] > num[N])
	{
		REP(i, N)
		      if (num[i] <= num[i + N])
		      {
				printf( "NO\n" );
				return 0;
			}
		printf( "YES\n" );
		return 0;
	}
	
	printf( "NO\n" );
			
	return 0;
}
