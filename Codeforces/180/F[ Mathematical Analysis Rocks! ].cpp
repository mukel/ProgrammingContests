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

const int
	MAXN = 1 << 17;

int N;
int p[MAXN];
int p3[MAXN];
int p4[MAXN];

int main()
{
	cin >> N;
	REP(i, N) (cin >> p3[i]), p3[i]--;
	REP(i, N) (cin >> p4[i]), p4[i]--;


	REP(i, N) p[ p3[i] ] = p4[i];
	REP(i, N) cout << p[i]+1 << "\n";

	return 0;
}
