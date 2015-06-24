/*
Alfonso2 Peterssen
SPOJ #5446 "Fishing Net"
6 - 8 - 2010
Testing "chordality"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXV = 1 << 10;
	
int V, E;
vector< int > G[MAXV];
bool adj[MAXV][MAXV];
int peo[MAXV]; // perfect elimination ordering
int idx[MAXV];

struct monoSet
{
	int top;
	int currSet[MAXV];
	vector< int > elems[MAXV];

	monoSet(int n)
	{
		top = 0;
		fill(currSet, currSet + n, 0);
		REP(i, n)
		      elems[0].push_back(i);
	}
	
	int maximum()
	{
		do {
			while (!elems[top].empty() && currSet[ elems[top].back() ] != top)
			      elems[top].pop_back();
			if (!elems[top].empty())
			      return elems[top].back();
			top--;
		} while (top >= 0);
		
		return -1; // empty
	}
	
	void erase(int x)
	{
		currSet[x] = -1;
	}
	
	void increment(int x)
	{
		if (currSet[x] >= 0) // not deleted
		{
			elems[ ++currSet[x] ].push_back(x);
			top = max(top, currSet[x]);
		}
	}
};

int main()
{
	for (;;)
	{
		int V, E;
		scanf( "%d %d", &V, &E );
		if (!V && !E) break;
		
		REP(i, V)
		{
			REP(j, G[i].size())
			      adj[i][ G[i][j] ] = 0;
			G[i].clear();
		}
		
		REP(i, E)
		{
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
			adj[u][v] = adj[v][u] = 1;
		}
		
		monoSet S(V);
		REP(i, V)
		{
			int u = S.maximum();
			S.erase(u);
			
			//printf( "%d ", u + 1 );
			
			peo[i] = u;
			idx[u] = i;
			
			REP(j, G[u].size())
			{
				int v = G[u][j];
				S.increment(v);
			}
		}
		//printf( "\n" );

		bool isChordal = true;
		for (int i = V - 1; i >= 0; i--)
		{
			int u = peo[i];
			int lastPred = -1;
			
			REP(j, G[u].size())
			{
				int v = G[u][j];
				if (idx[v] < idx[u]) // v is a predecesor of u
				{
					if (lastPred < 0 || idx[v] > idx[lastPred])
					      lastPred = v;
				}
			}
			
			if (lastPred < 0) // no predecesors
			      continue ;
			
			REP(j, G[u].size())
			{
				int v = G[u][j];
				if (v == lastPred) continue ;
				
				if (idx[v] < idx[u]) // v is a predecesor of u
				{
					if (!adj[lastPred][v])
					{
						isChordal = false;
						break;
					}
				}
			}
			
			if (!isChordal)
			      break;
		}
		
		printf( isChordal ? "Perfect\n" : "Imperfect\n" );
	}

	return 0;
}
