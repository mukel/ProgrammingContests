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

typedef vector< int64 > array;
typedef vector< array > matrix;

const int64
	MOD = 1000000007;

matrix operator * (const matrix & a, const matrix & b)
{
	matrix r(2, array(2));

	REP(i, 2)
	REP(j, 2)
	REP(k, 2)
		r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % MOD;

	return r;
}

matrix id()
{
	matrix r(2, array(2));
	REP(i, 2) r[i][i] = 1;
	return r;
}

matrix fastPow(matrix & m, int64 n)
{
	if (!n) return id();
	matrix r = fastPow(m, n/2);
	r = r * r;
	if (n % 2)
		r = r * m;
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);

	//int64 u = 1, d = 0;

	int64 N; cin >> N;
	/*
	for (int i = 1; i <= N; ++i)
	{
		int64 _u = u * 3 + d;
		int64 _d = u + d * 3;
		u = _u;
		d = _d;
	}
	*/

	matrix m(2, array(2));
	m[0][0] = m[1][1] = 3;
	m[0][1] = m[1][0] = 1;

	matrix r = fastPow(m, N);

	cout << r[0][0] << endl;

	return 0;
}
