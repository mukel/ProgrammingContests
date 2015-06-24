/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #51 "Strange Tower"
*/
#include <cstdio>
#include <iostream>

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

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define DBG(x) cout << #x << " = " << x << endl;

int main()
{
	int n;
	cin >> n;
	
	int64 block = 1, y = 0, cur = 0;
	while (cur + block * block < n)
	{
		cur += block * block;
		y += block;
		block++;
	}
	
	y += (n - cur + block - 1) / block;
	int64 x = (n - cur - 1) % block + 1;
	
	cout << y << " " << x << endl;

	return 0;
}
