/*
Alfonso Alfonso Peterssen
TASK: KUHAR
*/
#include <cstdio>

const int
	MAXN = 100,
    MAXM = 100001;

#define REP( i, n ) \
    for ( i = 0; i < (n); i++ )

int n, money, i, j, k, sol;
int lo, hi, mid;
int need[MAXN], avail[MAXN];
int sz[2][MAXN], price[2][MAXN];
int cost[MAXM];

bool check( int value ) {
    int m = money;
    REP( i, n ) {
		cost[0] = avail[i];
        REP( j, m + 1 ) {
            if ( j ) cost[j] = cost[j - 1];
            REP( k, 2 )
				if ( j - price[k][i] >= 0 )
					cost[j] >?= cost[ j - price[k][i] ] + sz[k][i];
			if ( cost[j] >= value * need[i] )
				break;
    	}
        if ( ( m -= j ) < 0 )
            break;
	}
	return m >= 0;
}

int main() {

	scanf( "%d %d", &n, &money );
    REP( i, n ) {
		scanf( "%d %d", &need[i], &avail[i] );
        REP( j, 2 )
            scanf( "%d %d", &sz[j][i], &price[j][i] );
	}

	hi = money;
	while ( lo <= hi ) {
		mid = ( lo + hi ) / 2;
		if ( check( mid ) )
			 lo = mid + 1;
		else hi = mid - 1;
	}

	printf( "%d\n", lo - 1 );
	fflush( stdout );

	return 0;
}
