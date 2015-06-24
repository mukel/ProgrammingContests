/*
Alfonso2 Peterssen
SPOJ #1704 "Countdown"
9 - 10 - 2008
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef pair< int, string > par;

const int
	MAXV = 1000,
	MAXLEN = 100;

int T, V, D;
char line[MAXLEN];
int father[MAXV];
int cant[MAXV];
int idx[MAXV];
map< string, int > M;
string S[MAXV];

bool comp( const int& i, const int& j ) {
	if ( cant[i] != cant[j] )
	      return cant[i] > cant[j];
	return S[i] < S[j];
}

int main() {

	scanf( "%d", &T );
	for ( int tc = 1; tc <= T; tc++ ) {

		M.clear();
		int nodes = 0;

		scanf( "%d %d", &V, &D );
		
		memset( father, -1, sizeof( father ) );
		memset( cant, 0, sizeof( cant ) );
		
		REP( i, V ) {
			int sons;
			scanf( "%s %d", &line, &sons );
			string parent( line );
			if ( M.find( parent ) == M.end() ) {
				S[nodes] = parent;
			      M[parent] = nodes;
			      nodes++;
			}
			while ( sons-- ) {
				scanf( "%s", &line );
				string child( line );
				if ( M.find( child ) == M.end() ) {
					S[nodes] = child;
				      M[child] = nodes;
					nodes++;
				}
				father[ M[child] ] = M[parent];
			}
		}
		
		REP( i, nodes ) {
			idx[i] = i;
			int x = i;
			REP( j, D ) {
				x = father[x];
				if ( x == -1 ) break;
			}
			if ( x != -1 )
			      cant[x]++;
		}
		
		sort( idx, idx + nodes, comp );
		
		printf( "Tree %d:\n", tc );
		int changes = 0;
		REP( i, nodes ) {
			int id = idx[i];
			if ( cant[id] == 0 ) break;
			if ( i && cant[id] != cant[ idx[i - 1] ] )
			      changes++;
			if ( i && cant[id] != cant[ idx[i - 1] ] && i >= 3 )
			      break;
			if ( changes == 3 ) break;
			printf( "%s %d\n", S[id].c_str(), cant[id] );
		}
	}

	return 0;
}

