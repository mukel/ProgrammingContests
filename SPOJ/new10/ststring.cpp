/*
Alfonso2 Peterssen (mukel)
SPOJ #3112 "Strings"
18 - 5 - 2009
thanks to Ivan Katanic
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )

#define ALL( c ) (c).begin(), (c).end()

string stA, stB;
vector< int > vals[7];

// check if j is "C"
bool check( int x, int i ) {
	int last = -2;
	REP( k, i ) {
		int d = x % 10;
		if ( abs(d - last) <= 1 )
		      return false;
		last = d;
		x /= 10;
	}
	return true;
}

int main() {

	int pow10[7];
	pow10[0] = 1;
	FOR( i, 1, 6 ) {
		pow10[i] = pow10[i - 1] * 10;
		REP( j, pow10[i] )
			if ( check( j, i ) )
				vals[i].push_back( j );
	}

	while ( cin >> stA >> stB ) {
		int A = 0, B = 0;
		REP( i, stA.size() ) A = A * 10 + stA[i] - 'A';
 		REP( i, stB.size() ) B = B * 10 + stB[i] - 'A';
 		
 		int ans = 0;
 		FOR( i, stA.size() + 1, stB.size() - 1 )
 		      ans += vals[i].size();
 		      
		vector< int >& vlo = vals[ stA.size() ];
 		vector< int >& vhi = vals[ stB.size() ];
 		      
		int lo = lower_bound( ALL( vlo ), A ) - vlo.begin();
 		int hi = lower_bound( ALL( vhi ), B ) - vhi.begin();
 		
 		if ( !check( A, stA.size() ) ) lo--;

		if ( stA.size() != stB.size() ) {
			ans += hi + vlo.size() - lo - 1;
		} else
		      ans = hi - lo - 1;

		cout << max( 0, ans ) << endl;
	}

	return 0;
}
