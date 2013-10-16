/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 10000;

int T, N;
char line[1 << 8];
string V[MAXN];

struct str_comp {
	int N;
	str_comp( int N ) : N( N ) {}
	bool operator () ( const string& A, const string& B ) {
		return strncmp( A.c_str(), B.c_str(), N ) < 0;
	}
};

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &N );
		REP( i, N ) {
			scanf( "%s", &line );
			V[i] = line;
		}
		sort( V, V + N );
		REP( i, N ) {
			str_comp cmp( V[i].size() );
			if (
				binary_search( V, V + i, V[i], cmp ) ||
				binary_search( V + i + 1, V + N, V[i], cmp ) ) {
					printf( "NO\n" );
					goto next_case;
				}
		}
		printf( "YES\n" );
		next_case:;
	}

	return 0;
}
