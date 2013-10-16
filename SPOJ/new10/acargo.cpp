/*
Alfonso2 Peterssen (mukel)
SPOJ #1873 "Accumulate Cargo"
20 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 1 << 18;

int N, L;
int64 C[MAXN];

int main() {

	while (1) {
		scanf( "%d %d", &N, &L );
		if ( !N && !L ) break ;

		REP( i, N )
			scanf( "%d", &C[i] );

		sort( C, C + N );
		REP( i, N )
			C[i + N] = C[i] + L;

		int64 ans, cost = 0;
		REP( i, N )
			cost += C[i] - C[0] - i;
			
		ans = cost;

		int lo = 0, hi = N - 1;
		for ( int i = 1; i < 2 * N; i++ ) {
			cost += (i - lo) * (C[i] - C[i - 1] - 1);
  			cost -= (hi - i + 1) * (C[i] - C[i - 1] - 1);
  			
  			while ( hi < 2 * N - 1 ) {
				int L = C[i] - C[lo] - (i - lo);
				int R = C[hi + 1] - C[i] - (hi + 1 - i);
				if ( R < L ) {
					cost -= L;
					cost += R;
					lo++; hi++;
				} else
				      break ;
			}
			
			ans = min( ans, cost );
		}
		
		printf( "%lld\n", ans );
	}

	return 0;
}
