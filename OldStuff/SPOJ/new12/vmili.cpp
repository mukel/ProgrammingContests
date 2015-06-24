/*
Alfonso2 Peterssen
SPOJ #3870 "Military Story"
5 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 1 << 15;

int N;
int ans;
int mark[MAXN];
int hull[MAXN];
struct point
{
	int x, y;
} pnts[MAXN];

bool operator < (const point a, const point b)
{
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool ccw(point& o, point& c, point& m)
{
	return (c.x - o.x) * (m.y - o.y) > (m.x - o.x) * (c.y - o.y);
}

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		pnts[i] = (point){x, y};
	}
	
	sort(pnts, pnts + N);
	while (N > 2)
	{
		int H = 0, limit = 1;
		for (int i = 0; i < N; hull[H++] = i++)
			while (H > limit && ccw(pnts[hull[H - 2]], pnts[hull[H - 1]], pnts[i]))
			      H--;
		limit = H - 1;
		for (int i = N - 2; i >= 0; hull[H++] = i--)
			while (H > limit && ccw(pnts[hull[H - 2]], pnts[hull[H - 1]], pnts[i]))
			      H--;
		H--;

		REP(i, H) mark[ hull[i] ] = ans + 1;
			
		int cnt = 0;
		REP(i, N)
		      if (mark[i] != (ans+1))
				pnts[cnt++] = pnts[i];
				
		N -= H;
		ans++;
	}
	
	printf( "%d\n", ans );

	return 0;
}
