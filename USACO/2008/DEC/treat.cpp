/*
Alfonso2 Peterssen (mukel)
27 - 12 - 2008
USACO DEC08 "Trick or Treat on the Farm"
*/
#include <cstdio>
#include <stack>

using std::stack;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXV = 100000;

int V;
int dtime, last;
int sol[MAXV];
int next[MAXV];
int dfsnum[MAXV];
bool cycle[MAXV];
stack< int > S, stk;

int main() {

	scanf( "%d", &V );
	REP( i, V ) {
	      scanf( "%d", &next[i] );
	      next[i]--;
	}

	/* Iterative DFS ( to avoid stack overflow ) */
	REP( i, V ) if ( !dfsnum[i] ) {

		stk.push( i );
		while ( !stk.empty() ) {

			int x = stk.top();
			int nxt = next[x];
			if ( !dfsnum[x] ) { // process current node
				S.push( x );
				dfsnum[x] = ++dtime;

				if ( !dfsnum[nxt] ) {
					stk.push( nxt );
					continue; // dfs call
				} else
				if ( dfsnum[nxt] > last ) { // same dfs tree ( cycle found )
					sol[nxt] = dfsnum[x] - dfsnum[nxt] + 1;
					for ( int y = -1; y != nxt; S.pop() )
						cycle[y = S.top()] = true;
				}
			}

			stk.pop();
			sol[x] = sol[nxt];
			if ( !cycle[x] )
				sol[x]++;
		}

		last = dtime;
	}

	REP( i, V )
		printf( "%d\n", sol[i] );

	return 0;
}
