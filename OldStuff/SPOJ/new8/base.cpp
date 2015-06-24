/*
Alfonso2 Peterssen (mukel)
SPOJ #870 "Basically Speaking"
6 - 3 - 2009
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int JLEN = 7;
const char* digit = "0123456789ABCDEF";

string st;
int from, to;

string toString( int64 x, int64 base = 10 ) {
	if ( x == 0 )
		return "0";
	string ans;
	while ( x > 0 ) {
		ans = digit[x % base] + ans;
		x /= base;
	}
	return ans;
}

int64 toNumber( string x, int64 base = 10 ) {
	int64 ans = 0;
	REP( i, x.size() )
	      ans = ans * base + ( strchr( digit, x[i] ) - digit );
	return ans;
}

int main() {

	while ( cin >> st >> from >> to ) {
		string ans = toString( toNumber( st, from ), to );
		if ( ans.size() > JLEN )
		      ans = "ERROR";
		while ( ans.size() < JLEN )
		      ans = " " + ans;
		cout << ans << endl;
	}

	return 0;
}
