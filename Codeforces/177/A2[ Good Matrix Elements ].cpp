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
	MAXN = 105;

int N;
int M[MAXN][MAXN];
bool _mark[MAXN][MAXN];

void mark(int x, int y, int dx, int dy)
{
	while (x < N && x >= 0 && y < N && y >= 0)
	{
		_mark[x][y] = true;
		x += dx;
		y += dy;
	}
}

int main()
{
	cin >> N;
	REP(i, N)
	REP(j, N) cin >> M[i][j];

	mark(0, 0, 1, 1);
	mark(N - 1, 0, -1, 1);
	mark(N / 2, 0, 0, 1);
	mark(0, N / 2, 1, 0);

	int sum = 0;
	REP(i, N)
	REP(j, N) if (_mark[i][j]) sum += M[i][j];

	cout << sum << endl;

	return 0;
}
