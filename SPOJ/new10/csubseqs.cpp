/*
Alfonso2 Peterssen (mukel)
SPOJ #2816 "Common Subsequences"
20 - 5 - 2009
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 51;

int la, lb, lc, ld;
char A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int64 dp[MAXN][MAXN][MAXN][MAXN];
int last[MAXN];
int pos[0x100];

int main() {

	scanf( "%s %s %s %s", A + 1, B + 1, C + 1, D + 1 );
	la = strlen( A + 1 ) + 1;
	lb = strlen( B + 1 ) + 1;
	lc = strlen( C + 1 ) + 1;
	ld = strlen( D + 1 ) + 1;
	
	REP( i, la ) {
		last[i] = pos[ A[i] ];
		pos[ A[i] ] = i;
	}
	
	REP( a, la )
	REP( b, lb )
	REP( c, lc )
	REP( d, ld ) {
		int64& val = dp[a][b][c][d];
	      if ( !a || !b || !c || !d ) val = 1;
	      else if ( A[a] == B[b] && A[a] == C[c] && A[a] == D[d] ) {
	            val = dp[a - 1][b][c][d] + dp[a - 1][b - 1][c - 1][d - 1];
	            if ( last[a] )
				val -= dp[ last[a] - 1 ][b - 1][c - 1][d - 1];
		} else
		      val =
			(dp[a - 1][b][c][d] + dp[a][b - 1][c][d] + dp[a][b][c - 1][d] + dp[a][b][c][d - 1]) -
			(dp[a - 1][b - 1][c][d] + dp[a - 1][b][c - 1][d] + dp[a - 1][b][c][d - 1] + dp[a][b - 1][c - 1][d] + dp[a][b - 1][c][d - 1] + dp[a][b][c - 1][d - 1]) +
			(dp[a - 1][b - 1][c - 1][d] + dp[a - 1][b - 1][c][d - 1] + dp[a - 1][b][c - 1][d - 1] + dp[a][b - 1][c - 1][d - 1]) -
			(dp[a - 1][b - 1][c - 1][d - 1]);
	}

	printf( "%lld\n", dp[la - 1][lb - 1][lc - 1][ld - 1] - 1/*empty*/ );

	return 0;
}
