/*
Alfonso2 Peterssen (mukel)
SPOJ #48 "Glass Beads"
6 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 20000;

int T, N;
char S[MAXN];

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%s", &S );
		N = strlen( S );
		
		int delta = 0, ans = 0, nxt = 1;
		while ( nxt < N && ans + delta < N ) {
		      int sign = S[ans + delta] - S[(nxt + delta) % N];
		      if ( sign < 0 ) { // ans < nxt
				nxt = nxt + delta + 1;
				delta = 0;
			} else
		      if ( sign > 0 ) { // nxt < ans
				int __nxt = nxt;
		            nxt = max( nxt + 1, ans + delta );
		            ans = __nxt;
		            delta = 0;
			} else
			      delta++;
		}
		
		printf( "%d\n", ans + 1 );
	}

	return 0;
}
