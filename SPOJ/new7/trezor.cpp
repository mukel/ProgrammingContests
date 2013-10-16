/*
Alfonso2 Peterssen (mukel)
21 - 1 - 2009
COCI 2009 Contest 4 TREZOR
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) \
	for ( int i = (b); i <= (e); i++ )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int
	MAXA = 5000;

int A, B, L;
int64 ans[3];
vector< int > factors[MAXA];
bool mark[MAXA];

void prime_sieve() {
	for ( int i = 2; i < MAXA; i++ )
		if ( !mark[i] )
			for ( int j = i; j < MAXA; j += i ) {
				mark[j] = true;
				factors[j].push_back( i );
			}
}

// returns how many x -> ( x % fact[i] ) != 0 holds for all i's
int64 incl_excl( vector< int >& fact, int L ) {
	int N = fact.size();
	int val[1 << N];
	val[0] = -1;

	int ans = 0;
	for ( int i = 1; i < (1 << N); i++ )  {
		val[i] = -val[i - (i & -i)] * fact[ __builtin_ctz( i ) ];
		ans += L / val[i];
	}

	return L - ans;
}

void process( int y ) {

	int a = A + y;
	int b = B - y;

	int cntA, cntB, both;

	if ( a == 0 )
		cntA = 1;
	else if ( a == 1 )
		cntA = L;
	else
		cntA = incl_excl( factors[a], L );

	if ( b == 0 )
		cntB = 1;
	else if ( b == 1 )
		cntB = L;
	else
		cntB = incl_excl( factors[b], L );

	if ( a == 0 || b == 0 ) both = 1; else
	if ( a == 1 && b == 1 ) both = L;
	else
	if ( a == 1 && b > 1 ) both = cntB; else
	if ( a > 1 && b == 1 ) both = cntA;
	else {
		vector< int > ab;
		ab.insert( ab.end(), ALL( factors[a] ) );
		ab.insert( ab.end(), ALL( factors[b] ) );
		sort( ALL( ab ) );
		ab.erase( unique( ALL( ab ) ), ab.end() );
		both = incl_excl( ab, L );
	}

	ans[0] += L - ( cntA + cntB - both );
	ans[1] += ( cntA + cntB - 2 * both );
	ans[2] += both;
}

int main() {

	scanf( "%d %d %d", &A, &B, &L );

	prime_sieve();

	FOR( i, -A, +B )
	      process( i );

	REP( i, 3 )
	      printf( "%lld\n", ans[i] );

	return 0;
}
