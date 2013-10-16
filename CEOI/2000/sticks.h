/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
#define ALL( c ) (c).begin(), (c).end()

namespace sticks { // define library namespace


	static const int
		MAXN = 10,
		MAXVAL = 10;

	int SG[1 << MAXVAL];
	vector< int > V;

	void calc_SG() {
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
	}

	vector< int > getPiles( int& player ) {

		calc_SG();

		int n, x;
		cin >> n;
		while ( n-- ) {
			cin >> x;
			V.push_back( (1 << x) - 1 );
		}
		
		cin >> player;
		
		return V;
	}
	
	void putMove( int pile, int lo, int hi ) {

		printf( "Human remove [%d,%d] from pile %d\n", lo, hi, pile );

		pile--; lo--; hi--;
		assert( pile >= 0 && pile < V.size() );
		assert( lo <= hi );
		int mask = (1 << (hi - lo + 1)) - 1;
		mask = (mask << lo);
		assert( (V[pile] & mask) == mask );
		V[pile] -= mask;
		
		if ( count( ALL( V ), 0 ) == V.size() ) {
			printf( "You win!!!\n" );
			exit( 0 );
		}
	}
	
	void getMove( int& pile, int& lo, int& hi ) {

		int sgval = 0;
		REP( i, V.size() )
		      sgval ^= SG[ V[i] ];
		      
		if ( sgval ) { // find winning move
		
		      // You loose
			// printf( "You loose stupid!!!\n" );
			// exit( 0 );
			
			int leftcol = 31 - __builtin_clz( sgval );
		      
			REP( i, V.size() )
				if ( SG[ V[i] ] & (1 << leftcol) ) {
					vector< int > nxt;
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
		
		} else { // do anything
			REP( i, V.size() )
			      if ( V[i] > 0 ) {
					pile = i;
					lo = hi = __builtin_ctz( V[i] );
				}
		}

		int mask = (1 << (hi - lo + 1)) - 1;
		mask = (mask << lo);
		assert( (V[pile] & mask) == mask );
		V[pile] -= mask;
		
		// 1-based
		pile++; lo++; hi++;
		printf( "Machine remove [%d,%d] from pile %d\n", lo, hi, pile );
		
		if ( count( ALL( V ), 0 ) == V.size() ) {
			printf( "You loose stupid!!!\n" );
			exit( 0 );
		}
	}
	
};

using sticks::getPiles;
using sticks::putMove;
using sticks::getMove;
