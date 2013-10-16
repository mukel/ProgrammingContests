/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cmath>
#include <complex>

#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long int64;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) for ( int i = (e); i >= (s); i-- )

#define FOREACH( it, c ) \
	for ( typeof( (c).begin() ) it = (c).begin(); it != (c).end(); it++ )

#define ALL( c ) (c).begin(), (c).end()

string A, B, op, ans;

int main() {

	cin >> A;
	cin >> op;
	cin >> B;
	
	if ( op == "*" ) {
		ans = string( A.size() + B.size() - 1, '0' );
		ans[0] = '1';
	} else {
		if ( A.size() == B.size() ) {
		      ans = A;
		      ans[0] = '2';
		} else {
		      ans = string( max( A.size(), B.size() ), '0' );
		      ans[ A.size() - 1 ] = '1';
		      ans[ B.size() - 1 ] = '1';
		      reverse( ALL( ans ) );
		}
	}
	
	cout << ans << endl;

	return 0;
}
