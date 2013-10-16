/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #137 "Fibonacci II"
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

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

typedef vector< int64 > array;
typedef vector< array > matrix;

int N, K;

matrix mulMod(matrix a, matrix b, int mod)
{
	matrix ret(a.size(), array(b[0].size(), 0));
	REP(i, SZ(ret))
	REP(j, SZ(ret[i]))
	REP(k, SZ(a[0]))
	      ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
	      
	return ret;
}

matrix modPow(matrix M, int n, int mod)
{
	if (n == 1) return M;
	matrix ret = modPow(M, n/2, mod);
	ret = mulMod(ret, ret, mod);
	if (n & 1)
	      ret = mulMod(ret, M, mod);
	return ret;
}

int main()
{
	matrix F(2, array(2, 1));
	F[1][1] = 0;
	
	cin >> N >> K;
	F = modPow(F, N, K);
	
	cout << F[0][1] % K << endl;

	return 0;
}
