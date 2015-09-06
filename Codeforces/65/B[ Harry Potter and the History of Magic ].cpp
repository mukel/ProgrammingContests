/*
 * Alfonso2 Peterssen(mukel)
 * Codeforces Round #60
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin, (c).end()
#define REP(i, n) for (int (i) = 0; i < (int)(n); ++(i))
#define FOR(i, b, e) for (int (i) = (int)(b); i <= (int)(e); ++(i))

const int MAXN = 1001;

int n;
int nums[MAXN];

int main()
{			
	int pow10[] = {1, 10, 100, 1000, 10000};
	
	cin >> n;	
	FOR(i, 1, n)
	{
		int x;
		cin >> x;
		
		int dig[4];
		
		int t = x;
		REP(j, 4)
			dig[j] = t % 10, t /= 10;
			
		nums[i] = (int)1e9;			
		REP(j, 4)
		{			
			REP(k, 10)
			{
				int nx = x - dig[j] * pow10[j] + k * pow10[j];
				if (nx >= 1000 && nx <= 2011 && nx >= nums[i - 1])
					nums[i] = min(nums[i], nx);
			}
		}
	}	
	
	if (nums[n] != (int)1e9)
		FOR(i, 1, n) printf( "%d\n", nums[i] );
	else
		printf( "No solution\n" );
	
	return 0;
}

