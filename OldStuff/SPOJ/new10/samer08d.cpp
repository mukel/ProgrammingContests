/*
Alfonso2 Peterssen (mukel)
SPOJ #3408 "DNA Sequences"
20 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )

const int MAXN = 1 << 11;

int K;
int la, lb;
char A[MAXN], B[MAXN];
int dp[MAXN][MAXN];
int seg[MAXN][MAXN];

int main() {

	while (1) {
		scanf( "%d", &K ); if ( !K ) break ;
		
		A[0] = B[0] = '$';
		scanf( "%s", A + 1 ); la = strlen( A ) - 1;
		scanf( "%s", B + 1 ); lb = strlen( B ) - 1;
 		
		FOR( i, 1, la )
 		FOR( j, 1, lb ) {
			dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
  			seg[i][j] = 0;
			if ( A[i] == B[j] )
				seg[i][j] = seg[i - 1][j - 1] + 1;
			FOR( k, K, seg[i][j] )
                  	dp[i][j] = max( dp[i][j], dp[i - k][j - k] + k );
            }
            
            printf( "%d\n", dp[la][lb] );
	}

	return 0;
}
