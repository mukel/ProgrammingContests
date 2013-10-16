/*
Alfonso Alfonso Peterssen
TASK: JEDNAKOST
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int
	MAXN = 1001,
	MAXVALUE = 5001,
	oo = 10000;

int n, result, i, j, k, sol;
char line[2*MAXN];
int number[MAXN][MAXN];
short int dp[MAXN][MAXVALUE];
short int from[MAXN][MAXVALUE];
bool sign[MAXN];

int main() {

	scanf( "%[^=]=%d", &line, &result );

	n = strlen( line );
    for ( i = 0; i < n; i++ ) {
        int value = 0;
		for ( j = 0; i + j < n; j++ ) {
            value = value * 10 + line[i + j] - '0';
            number[i][j] = value;
			if ( value > result )
			    break;
		}
    }

	for ( i = 0; i <= n; i++ )
		fill( dp[i], dp[i] + result + 1, oo );

	dp[0][0] = 0;
    for ( i = 0; i <= n; i++ ) {
        for ( j = 0; j < 4 && i - j >= 0 && line[i - j] == '0'; j++ );
        if ( j == 4 ) continue;
		for ( j = 0; j <= result; j++ )
			if ( dp[i][j] != oo )
				for ( k = 0; i + k < n; k++ ) {
					int value = j + number[i][k];
					if ( value > result ) break;
					if ( dp[i][j] + 1 <= dp[i + k + 1][value] ) {
						dp[i + k + 1][value] = dp[i][j] + 1;
						from[i + k + 1][value] = k;
					}
				}
    }

    i = n;
    j = result;
    while ( i != 0 ) {
        sign[i] = true;
        int last_pos = i - from[i][j] - 1;
	    int last_sum = j - number[ last_pos ][ from[i][j] ];
	    i = last_pos;
	    j = last_sum;
    }

	for ( i = 0; i < n; i++ )
        printf( sign[i] ? "+%c" : "%c", line[i] );
	printf( "=%d\n", result );
	fflush( stdout );

	return 0;
}
