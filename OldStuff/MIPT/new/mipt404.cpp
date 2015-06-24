/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #404 "Great Combinator"
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
//#include <windows.h>

using namespace std;

typedef unsigned long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXN = 1025;

int64 C[MAXN][MAXN];

int main()
{
	int N, K;
	cin >> N >> K;
	
	FOR(i, 0, N)
	{
		C[i][0] = 1;
		FOR(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	
	cout << C[N][K] << endl;

	return 0;
}
