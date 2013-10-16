#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1 << 17;
#define all( v ) (v).begin(), (v).end()

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

int N;
char buff[1 << 16];
long long ans;

int idx[MAXN], idx1[MAXN], idx2[MAXN];
char st[MAXN][16];

int T[MAXN];

inline int lobit( int x ) { return x & -x; }
int query( int x ) {
	int sum = 0;
	for ( ; x >= 0; x -= lobit(x + 1) )
	      sum += T[x];
	return sum;
}

void update( int x ) {
	for ( ; x < N; x += lobit(x + 1) )
		T[x]++;
}

bool cmp_st( const int& i, const int& j ) {
	return strcmp( st[i], st[j] ) < 0;
}

int main() {

	N = atoi( gets( buff ) );
	REP( i, N ) {
		gets( st[i] );
		idx1[i] = i;
		idx2[i] = i;
	}

	sort( idx1, idx1 + N, cmp_st );
	
	REP( i, N )
		reverse( st[i], st[i] + strlen( st[i] ) );
		
	sort( idx2, idx2 + N, cmp_st );
	
	REP( i, N )
	      idx[ idx2[i] ] = i;
	
	REP( i, N ) {
		int ii = idx1[i];
		ans += i - query( idx[ii] );
		update( idx[ii] );
	}
	
	printf( "%I64lld\n", ans );

	return 0;
}

