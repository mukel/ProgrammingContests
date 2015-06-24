/*
Alfonso2 Peterssen(mukel)
SPOJ #7969 "A Knights’ Tale"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 50;
	
const int64 oo = (int64)1e15;

int n;
int E;
int src, snk;
int64 totalCost;
int testCase;
struct edge
{
	int u, v, cap, next;
	int64 w;
	edge() {}
	edge(int _u, int _v, int64 _w, int _cap, int _next)
	{
		u = _u;
		v = _v;
		w = _w;
		cap = _cap;
		next = _next;
	}
} edges[2 * MAXN * MAXN];

int first[MAXN];
int64 best[MAXN];
int from[MAXN];

struct point
{
	int64 x, y;
} pnts[MAXN];

// taken from TopCoder forums
int64 dist(int64 x1, int64 y1, int64 x2, int64 y2)
{
	int64 dx = abs(x2-x1);
	int64 dy = abs(y2-y1);
	int64 lb=(dx+1)/2;
	lb = max(lb, (dy+1)/2);
	lb = max(lb, (dx+dy+2)/3);
	while ((lb%2)!=(dx+dy)%2) lb++;
	if (abs(dx)==1 && dy==0) return 3;
	if (abs(dy)==1 && dx==0) return 3;
	if (abs(dx)==2 && abs(dy)==2) return 4;
	return lb;
}

void addEdge(int u, int v, int64 w)
{
	edges[E] = edge(u, v, +w, 1, first[u]); first[u] = E++;
	edges[E] = edge(v, u, -w, 0, first[v]); first[v] = E++;
}

bool augment()
{
	queue< int > Q;
	
	fill_n(best, 2 * n + 2, oo);
	
	best[src] = 0;
	for (Q.push(src); !Q.empty(); Q.pop())
	{
		int u = Q.front();
		for (int e = first[u]; e != -1; e = edges[e].next)
		if (edges[e].cap)
		{
			int v = edges[e].v;
			int64 w = edges[e].w;
			if (best[u] + w < best[v])
			{
				best[v] = best[u] + w;
				from[v] = e;
				Q.push(v);
			}
		}
	}
	
	if (best[snk] == oo) return false;

	totalCost += best[snk];
	for (int e = from[snk]; ; e = from[ edges[e].u ])
	{
		edges[e].cap--;
		edges[e^1].cap++;
		if (edges[e].u == src) break;
	}

	return true;
}

int main()
{
	while (scanf( "%d", &n ), n)
	{
		testCase++;

		REP(i, 2 * n)
		{
			int x, y;
			scanf( "%d %d", &x, &y );
			pnts[i].x = x;
			pnts[i].y = y;
		}

		E = 0;
		fill_n(first, 2 * n + 2, -1);
		
		REP(i, n)
		REP(j, n)
			addEdge(i, j + n, dist(pnts[i].x, pnts[i].y, pnts[j + n].x, pnts[j + n].y));
			
		src = 2 * n;
		snk = 2 * n + 1;
		
		REP(i, n)
		{
			addEdge(src, i, 0);
			addEdge(i + n, snk, 0);
		}
		
		totalCost = 0;
		REP(i, n)
			augment();
		
		cout << testCase << ". " << totalCost << endl;
	}

	return 0;
}
