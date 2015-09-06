// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()

int n;
int64 ans;

int64 gcd(int64 a, int64 b)
{
	return b ? gcd(b, a % b) : a;
}

int64 lcm(int64 a, int64 b)
{
	return a / gcd(a, b) * b;
}

int64 solve(int64 a, int64 b, int64 c)
{
	return lcm(lcm(a, b), c);
}

int main()
{	
	cin >> n;	
	
	FOR(a, max(n - 50, 1), n)
		FOR(b, a, n)
			FOR(c, b, n)
				ans = max(ans, solve(a, b, c));
	
	cout << ans << endl;
	
	return 0;
}
