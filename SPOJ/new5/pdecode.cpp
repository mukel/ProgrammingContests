/*
Alfonso2 Peterssen
SPOJ #2853 "Decode the Strings"
22 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 100;

int N, M;
char line[MAXN];
char sol[MAXN];
int C, pos;
int next[MAXN];
int size[MAXN];
int first[MAXN];
int buff[MAXN];
int cycle[MAXN];
int where[MAXN];

int main() {

	for (;;) {
		scanf( "%d %d\n", &N, &M );
		if ( !N && !M ) break;

		C = pos = 0;
		memset( cycle, -1, sizeof( cycle ) );
		
		REP( i, N ) {
			scanf( "%d%*c", &next[i] );
			next[i]--;
		}
		
		gets( line );
		
		REP( i, N )
		      if ( cycle[i] == -1 ) {
				size[C] = 0;
				first[C] = pos;
				for ( int j = i; cycle[j] == -1; j = next[j] ) {
				      size[C]++;
					buff[pos] = j;
					where[j] = pos;
				      cycle[j] = C;
				      pos++;
				}
				C++;
			}

		REP( i, N ) {
			int ci = cycle[i];
			int pos = ( -M % size[ci] + size[ci] ) % size[ci];
			pos = buff[first[ci] + ( pos + where[i] - first[ci] ) % size[ci]];
			sol[i] = line[pos];
		}
		
		sol[N] = '\0'; printf( "%s\n", sol );
	}

	return 0;
}
