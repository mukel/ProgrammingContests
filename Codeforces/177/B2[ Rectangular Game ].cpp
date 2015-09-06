// Alfonso2 Peterssen (mukel)
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

int N;
vector< int > f;

int main()
{
	cin >> N;

	for (int i = 2; i * i <= N; ++i)
		while (N % i == 0)
		{
			N /= i;
			f.push_back(i);
		}

	if (N > 1)
		f.push_back(N);

	int64 ans = 0, prod = 1;
	for (int i = SZ(f) - 1; i >= 0; --i)
	{
		prod *= f[i];
		ans += prod;
	}

	cout << ans + 1 << endl;

	return 0;
}
