/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1671. Anansi's Cobweb
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXV = 1 << 17,
	MAXE = 1 << 17,
	MAXQ = 1 << 17;

int V, E, Q;
struct edge
{
	int u, v, mark;
	edge(int u = 0, int v = 0) : u(u), v(v), mark(0) {}
} edges[MAXE];

int currComps;
int ans[MAXQ];
int queries[MAXQ];

int data[MAXV];

int FIND(int x)
{
	return data[x] < 0 ? x : data[x] = FIND(data[x]);
}

int SIZE(int x)
{
	 return -data[ FIND(x) ];
}

void JOIN(int u, int v)
{
	u = FIND(u);
	v = FIND(v);
	if (u != v)
	{
		currComps--;
		if (SIZE(u) < SIZE(v))
		      swap(u, v);
		
		data[u] += data[v];
		data[v] = u;
	}
}

int main()
{
	scanf( "%d %d", &V, &E );
	REP(i, E)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		edges[i] = edge(u, v);
	}
	
	scanf( "%d", &Q );
	REP(i, Q)
	{
		int e;
		scanf( "%d", &e );
		e--;

		queries[i] = e;
		edges[e].mark = 1;
	}
	
	REP(i, V) data[i] = -1;
	
	currComps = V;
	REP(i, E)
	      if (!edges[i].mark)
	      {
			int u = edges[i].u;
			int v = edges[i].v;
			JOIN(u, v);
		}
	
	for (int i = Q - 1; i >= 0; i--)
	{
		ans[i] = currComps;
		int u = edges[ queries[i] ].u;
		int v = edges[ queries[i] ].v;
		JOIN(u, v);
	}
	
	REP(i, Q)
	      printf( "%d ", ans[i] );

	return 0;
}
