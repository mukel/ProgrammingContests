/*
Alfonso2 Peterssen(mukel)
MIPT #16 "Two rectangles"
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

typedef complex< double > point;
#define xx real()
#define yy imag()

const int MAXN = 105;

namespace std
{
	bool operator < (const point & a, const point & b)
	{
		return (a.xx != b.xx) ? a.xx < b.xx : a.yy < b.yy;
	}
}

int N;
point P[MAXN];
double MAXX, MAXY;
double ans;
double maxL[MAXN];
double maxR[MAXN];

void solve()
{
	sort(P, P + N);
	
	fill_n(maxL, N, 0);
	fill_n(maxR, N, 0);
	
	REP(hi, N)
	REP(lo, hi)
	{
		vector< double > V;
		FOR(i, lo, hi)
			if (P[i].xx > P[lo].xx && P[i].xx < P[hi].xx)
			      V.PB(P[i].yy);

		V.PB(0);
		V.PB(MAXY);
		sort(ALL(V));

	      double curArea = 0;
		REP(i, SZ(V)) if (i)
			curArea = max(curArea, (P[hi].xx - P[lo].xx) * (V[i] - V[i - 1]));

		maxL[hi] = max(maxL[hi], curArea);
		maxR[lo] = max(maxR[lo], curArea);
	}
	
	REP(i, N) if (i) maxL[i] = max(maxL[i], maxL[i - 1]);
	for (int i = N - 2; i >= 0; i--) maxR[i] = max(maxR[i], maxR[i + 1]);
	
	REP(i, N) ans = max(ans, maxL[i] + maxR[i]);
}

int main()
{
	scanf( "%lf %lf", &MAXX, &MAXY );
	scanf( "%d", &N );
	REP(i, N)
	{
		double x, y;
		scanf( "%lf %lf", &x, &y );
		P[i] = point(x, y);
	}
	
	P[N++] = point(0, 0);
	P[N++] = point(MAXX, MAXY);
	
	solve();
	
	swap(MAXX, MAXY);
	REP(i, N)
	      swap(P[i].xx, P[i].yy);
	      
	solve();
	
	printf( "%lf\n", ans );
	
	return 0;
}
