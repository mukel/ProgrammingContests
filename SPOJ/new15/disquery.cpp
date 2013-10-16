/*
Alfonso2 Peterssen(mukel)
SPOJ #3978 "Distance Query"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXV = 1 << 17,
	MAXLGV = 17;
	
int V, E;
int first[MAXV];
struct edge
{
	int v, w, next;
} edges[2 * MAXV];

int level[MAXV];

int lca[MAXLGV][MAXV];
int minPath[MAXLGV][MAXV];
int maxPath[MAXLGV][MAXV];

void preLCA()
{
	queue< int > Q;
	for (Q.push(0), level[0] = 1; !Q.empty(); Q.pop())
	{
		int u = Q.front();
		for (int e = first[u]; e != -1; e = edges[e].next)
		{
			int v = edges[e].v;
			int w = edges[e].w;

			if (level[v]) continue ;
			
			Q.push(v);

			level[v] = level[u] + 1;
			lca[0][v] = u;
			minPath[0][v] = maxPath[0][v] = w;

			for (int i = 1; level[v] - (1 << i) > 0; i++)
			{
				lca[i][v] = lca[i - 1][ lca[i - 1][v] ];
				minPath[i][v] = min(minPath[i - 1][v], minPath[i - 1][ lca[i - 1][v] ]);
				maxPath[i][v] = max(maxPath[i - 1][v], maxPath[i - 1][ lca[i - 1][v] ]);
			}
		}
	}
}

void query(int u, int v, int & low, int & upp)
{
	if (level[v] > level[u]) swap(u, v);
	
	low = minPath[0][u];
	upp = maxPath[0][u];

	for (int i = MAXLGV; i >= 0; i--)
		if (level[u] - (1 << i) >= level[v])
		{
			low = min(low, minPath[i][u]);
			upp = max(upp, maxPath[i][u]);
			u = lca[i][u];
		}

	if (u == v) return ;

	for (int i = MAXLGV; i >= 0; i--)
		if (level[u] - (1 << i) > 0 && lca[i][u] != lca[i][v])
		{
			low = min(low, minPath[i][u]);
			low = min(low, minPath[i][v]);

			upp = max(upp, maxPath[i][u]);
			upp = max(upp, maxPath[i][v]);

			u = lca[i][u];
			v = lca[i][v];
		}

	low = min(low, minPath[0][u]);
	low = min(low, minPath[0][v]);

	upp = max(upp, maxPath[0][u]);
	upp = max(upp, maxPath[0][v]);
}

int main()
{
	scanf( "%d", &V );
	
	fill_n(first, V, -1);
	
	REP(i, V - 1)
	{
		int u, v, w;
		scanf( "%d %d %d", &u, &v, &w );
		u--; v--;
		edges[E] = (edge){v, w, first[u]}; first[u] = E++;
		edges[E] = (edge){u, w, first[v]}; first[v] = E++;
	}
	
	preLCA();
	
	int Q;
	for (scanf( "%d", &Q ); Q--;)
	{
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		int low, upp;
		query(u, v, low, upp);
		printf( "%d %d\n", low, upp );
	}
	
	return 0;
}
