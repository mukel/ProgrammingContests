/*
Alfonso2 Peterssen
18 - 4 - 2008
TASK: ACRONYM
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int
	MAXS = 101,
	MAXN = 151;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

int T, S, N, L, i, j, k;
char abr[MAXN];
char insig[MAXS][MAXN];
char words[MAXN][MAXN];
int __ways[MAXN][MAXN];
int __dp[MAXN][MAXN];

char line[10000];

#define ways( j, k ) __ways[(j) + 1][(k) + 1]
#define dp( i, j ) __dp[(i) + 1][(j) + 1]

void solve() {
	dp( -1, -1 ) = 1;
	REP( i, N ) {
		memset( __ways, 0, sizeof( __ways ) );
		REP( j, L )
            	ways( j, j - 1 ) = 1;
            	
		int len = strlen( words[i] );
		REP( j, len ) {
			for ( int a = i; a < L; a++ )
			for ( int b = L - 1; b >= a; b-- )
				if ( words[i][j] == abr[b] )
				ways( a, b ) += ways( a, b - 1 );
		}
    
		for ( int j = i; j < L; j++ ) {
			dp( i, j ) = 0;
			for ( int k = j - 1; k >= i - 1; k-- )
				dp( i, j ) += dp( i - 1, k ) * ways( k + 1, j );
		}
	}

	/* to_upper */
	REP( i, L )
		abr[i] = abr[i] - ( 'a' - 'A' );

	if ( dp( N - 1, L - 1 ) == 0 )
		printf( "%s is not a valid abbreviation\n", abr );
	else
		printf( "%s can be formed in %d ways\n", abr, dp( N - 1, L - 1 ) );
}

int main() {

	for (;;) {
		scanf( "%d\n", &S );
		if ( !S ) break;
		REP( i, S )
		      scanf( "%s\n", &insig[i] );
		for (;;) {
			gets( line );
			if ( strcmp( line, "LAST CASE" ) == 0 )
				break;
				
			int len = strlen( line );
			
			L = 0;
			int pos;
			for ( pos = 0; pos < len && line[pos] != ' '; pos++ )
			      abr[L++] = line[pos];
			abr[L] = '\0';
			
			N = 0;
			for (;;) {
				if ( pos == len ) break;
				pos++;
				int kk = 0;
				while ( pos < len && line[pos] != ' ' ) {
				      words[N][kk++] = line[pos];
					pos++;
				}
				      
				words[N][kk] = '\0';
				bool found = false;
				REP( i, S )
				      if ( strcmp( insig[i], words[N] ) == 0 ) {
						found = true;
						break;
					}
				if ( !found ) N++;
			}
			// to_lower
			REP( i, L )
				abr[i] = abr[i] - ( 'A' - 'a' );
			solve();
		}
	}

	return 0;
}
