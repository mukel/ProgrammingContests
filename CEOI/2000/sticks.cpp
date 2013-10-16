/*
Alfonso2 Peterssen (mukel)
28 - 1 - 2009
CEOI 2000 day 2 "Sticks"
*/
#include "sticks.h"
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
#define ALL( c ) (c).begin(), (c).end()

const int
	MAXN = 10,
	MAXVAL = 10;

int N;
int player;
vector< int > V;
int SG[1 << MAXVAL];

int main() {

	/* Sprague-Grundy */
	SG[0] = 0; // P-position
	REP( i, (1 << MAXVAL) ) {
		if ( !i ) continue;
		
		vector< int > nxt;
		REP( j, 3 )
		REP( k, MAXVAL ) {
			int mask = ((1 << (j+1)) - 1) << k;
			if ( (i & mask) == mask )
				nxt.push_back( SG[i - mask] );
		}
		
		sort( ALL( nxt ) );
		nxt.erase( unique( ALL( nxt ) ), nxt.end() );
		
		int ans = 0;
		while ( ans < nxt.size() && nxt[ans] == ans )
			ans++;
		SG[i] = ans;
	}

	V = getPiles( player );
	
	/* let's play */
	for (;;) {
		int pile, lo, hi;
		if ( player ) {
			getMove( pile, lo, hi );
			pile--; lo--; hi--;
		} else {

			int sgval = 0;
			REP( i, V.size() )
				sgval ^= SG[ V[i] ];
			      
			if ( sgval ) { // N-position -> there is a winning move
			
				int leftcol = 31 - __builtin_clz( sgval );
				
				REP( i, V.size() )
					if ( SG[ V[i] ] & (1 << leftcol) ) {
						REP( j, 3 ) // sticks to remove
						REP( k, MAXVAL ) { // first stick
							int mask = ((1 << (j+1)) - 1) << k;
							if ( (V[i] & mask) == mask ) {
								int sgnxt = (sgval ^ SG[ V[i] ]) ^ SG[ V[i] - mask ];
								if ( sgnxt == 0 ) { // move to a P-position
									lo = k;
									hi = k + j;
									pile = i;
									goto finish;
								}
							}
						}
						finish:;
						break;
					}

			} else { // P-position -> do anythings
				REP( i, V.size() )
					if ( V[i] != 0 ) {
						lo = hi = __builtin_ctz( V[i] );
						pile = i;
						break;
					}
			}

			putMove( pile + 1, lo + 1, hi + 1 );
		}
		
		int mask = (1 << (hi - lo + 1)) - 1;
		mask <<= lo;
		assert( (V[pile] & mask) == mask );
		V[pile] -= mask;
		
		player ^= 1;
	}

	return 0;
}
