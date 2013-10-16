/*
Alfonso2 Peterssen
SPOJ #2277 "Silly Sort"
18 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2000;
	
int N;
bool mark[MAXN];
pair< int, int > ls[MAXN];

int main() {

	for ( int t = 1;;t++ ) {
		scanf( "%d", &N ); if ( !N ) break;
   
		for ( int i = 0; i < N; i++ ) {
			scanf( "%d", &ls[i].first );
			ls[i].second = i;
		}
		
		memset( mark, 0, sizeof( mark ) );
		sort( ls, ls + N );

	int sol = 0;
    for ( int i = 0; i < N; i++ )
        if ( !mark[i] && ls[i].second != i ) {
            int j = i, cnt = 0;
            while ( ls[j].second != i ) {
                j = ls[j].second;
                mark[j] = true;
                sol += ls[j].first;
                cnt++;
            }
            sol += min( cnt * ls[i].first,
                        ls[0].first * ( cnt + 2 ) + 2 * ls[i].first );
        }

	printf( "Case %d: %d\n", t, sol );
}
	return 0;
}
