/*
Alfonso2 Peterssen(mukel) UH++
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>

#include <cstdlib>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); ++i)

typedef long long int64;

typedef complex< int64 > point;

const int
	MAXN = 1 << 17;

int N;
int64 total;
point pnts[MAXN];

int64 cross(point a, point b)
{
	return imag(conj(a) * b);
}

int64 cross(point a, point b, point c)
{
	return cross(b - a, c - a);
}
int64 solve(point target)
{
	int curPos = 0;
	int64 result = 0, cant = 0;
	
	REP(i, N)
		if (cross(target, pnts[i], pnts[(i+1) % N]) > 0)
			return 0;
	
	REP(i, N)
	{
		while (cross(target, pnts[i], pnts[(curPos + 1) % N]) < 0)
		{
			cant++;
			curPos++;
		}
		//printf( "-> %d %d\n", i, curPos );
		int64 k = cant;
		k = k * (k - 1) / 2;
		result += k;
		cant--;
	}
	
	return total - result;
}

int main()
{

	scanf( "%d", &N );
	REP(i, N)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		pnts[i] = point(x, y);
	}
	
	total = N * ((N - 1) * (int64)(N - 2)) / 6;
	
	int Q;
	scanf( "%d", &Q );
	while (Q--)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		cout << solve(point(x, y)) << endl;
	}

      return 0;
}
