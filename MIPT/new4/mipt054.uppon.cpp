/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #54 "Mine field"
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

typedef complex< double > point;
#define xx real()
#define yy imag()

const double
	EPS = 1e-4;

const int
	MAXN = 30;

int N;
double R;
point pnts[MAXN];
point src, snk;
int mark[MAXN];

double cross(const point& a, const point& b)
{
	return imag(conj(a) * b);
	return a.xx * b.yy - a.yy * b.xx;
}

double area2(const point& a, const point& b, const point& c)
{
	return cross(b - a, c - a);	
}

namespace std
{
	bool operator < (const point& a, const point& b)
	{
		return (a.xx != b.xx) ? a.xx < b.xx : a.yy < b.yy;
	}
}

point rotate(const point& p, double a)
{
	return point(
		p.xx * cos(a) - p.yy * sin(a),
		p.xx * sin(a) + p.yy * cos(a)
	);
}

point readPoint()
{
	double x, y;
	scanf( "%lf %lf", &x, &y );
	return rotate(point(x, y), 123.56789); // disturb
}

double dist(point a, point b)
{
	return hypot(a.xx - b.xx, a.yy - b.yy);
}

bool uppon(point p, point q, point s)
{
	if (q < p) swap(p, q);
	if (s.xx < p.xx || s.xx > q.xx) return false;
	return (area2(p, q, s) < 0);
}

bool dfs(int u, bool flag)
{
	if (mark[u] != -1) return (mark[u] != flag);

	mark[u] = flag;

	REP(v, N)
		if (v != u && dist(pnts[u], pnts[v]) < 2 * R)
		{
			bool f = flag;
			if (uppon(pnts[u], pnts[v], src) ^ uppon(pnts[u], pnts[v], snk))
				f = !f;

			if (dfs(v, f))
				return true;
		}

	return false;
}

bool reach(double rad)
{
	R = rad;
	memset(mark, -1, sizeof(mark));

	REP(i, N)
		if (mark[i] < 0)
			if (dfs(i, 0)) return false;

	return true;
}

int main()
{
	src = readPoint();
	snk = readPoint();

	scanf( "%d", &N );
	REP(i, N)
		pnts[i] = readPoint();

	double lo = 0, hi = 1e5;

	REP(i, N)
		hi = min(hi, min(dist(src, pnts[i]), dist(snk, pnts[i])));

	while (hi - lo > EPS)
	{
		double mid = (lo + hi) / 2.0;

		if (reach(mid)) lo = mid;
		else
			hi = mid;
	}

	printf( "%lf\n", lo );

	return 0;
}
