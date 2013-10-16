/*
Alfonso Alfonso Peterssen
TASK: PLATAFORME
*/
#include <cstdio>

const int
    MAXN = 1000,
    MILLION = 1000000;

int n, i, j, k, sol;
int height[MAXN];
int x1[MAXN], x2[MAXN];

int main() {

	scanf( "%d", &n );
	for ( i = 0; i < n; i++ )
		scanf( "%d %d %d", &height[i], &x1[i], &x2[i] );

    x2[n++] = MILLION;
	for ( i = 0; i < n - 1; i++ ) {

		/* start */
		k = MILLION;
		for ( j = 0; j < n; j++ )
			if ( height[j] < height[i] )
			if ( x2[j] > x1[i] && x1[j] <= x1[i] )
				k <?= height[i] - height[j];
	    sol += k;

	    /* end */
	    k = MILLION;
		for ( j = 0; j < n; j++ )
			if ( height[j] < height[i] )
			if ( x2[j] >= x2[i] && x1[j] < x2[i] )
				k <?= height[i] - height[j];
	    sol += k;
	}

	printf( "%d\n", sol );
	fflush( stdout );

	return 0;
}
