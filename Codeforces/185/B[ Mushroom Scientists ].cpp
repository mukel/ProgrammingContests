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

#define double long double

double S, a[3];
const double EPS = 1e-9;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> S;
	REP(i, 3) cin >> a[i];

	double x = a[0] + a[1] + a[2];

	if (x < EPS)
	{
		cout << "0 0 0" << endl;
		exit(0);
	}

	x = S / x;
	cout.precision(15);
	cout << fixed << a[0] * x << " " << a[1] * x << " " << a[2] * x << endl;

	return 0;
}
