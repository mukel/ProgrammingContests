/*
Alfonso2 Peterssen (mukel)
O( P * lg S * (100/5) * S * S ) -> 100/5 for 5% mentioned in task description
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXP = 100,
	MAXS = 201,
	oo = (int)1e9;

int V, P, S;
int freeVotes;
int votes[MAXP];
int dp[MAXS];
int val[MAXS];
int idx[MAXP];
int seats[MAXP];

int udiv( int a, int b ) { // ceil(a/b)
	return (a+(b-1)) / b;
}

int to5( int id ) { // minimum needed votes to reach 5% -> party id
	int val = udiv( V, 20 ) - votes[id];
	if ( val > freeVotes )
	      val = oo; // can't reach 5%
	return max( 0, val );
}

// minimum votes needed(X) by party i
// (votes[i] + X) / ikth > (votes[j] / jkth)
int resolve( int i, int ikth, int j, int jkth ) {
	int val = udiv( votes[j] * ikth, jkth ) - votes[i];
	if ( (votes[i] + val) * jkth == votes[j] * ikth )
	      if ( i > j ) // remember -> the lower numbered party gets the seat
			val++;
	return max( 0, val );
}

bool possible( int party, int seats ) {
	seats++;
	int top = S - seats + 1;

	fill( dp, dp + top + 1, oo );
	dp[0] = 0;

	// only 20 largest parties(most votes) considered
	for ( int i = P - 1; i >= max( 0, P - 20 ); i-- ) {
		int id = idx[i];
		if ( id == party )
			continue ;

		// preprocess here to discharge inner cycle
		for ( int k = 1; k <= top; k++ )
			val[k] = max( resolve( id, k, party, seats ), to5( id ) );

		for ( int j = top; j > 0; j-- )
			for ( int k = 1; k <= top; k++ )
			      dp[j] = min( dp[j], dp[max( 0,j - k)] + val[k] );

		if ( dp[top] <= freeVotes )
		      return true;
	}

	return false;
}

int solve20( int i ) {
	votes[i] += freeVotes;
	fill( seats, seats + P, 0 );
	REP( j, S ) {
		int best = -1;
		REP( k, P ) {
			if ( to5(k) > 0 ) continue ;
			if ( best == -1 ) best = k;
			int val1 = votes[best] * (seats[k]+1);
			int val2 = votes[k] * (seats[best]+1);
		      if ( val2 > val1 )
		            best = k;
		}
		seats[best]++;
	}
	votes[i] -= freeVotes;
	return seats[i];
}

int solve80( int i ) {
	if ( to5(i) > 0 )
	      return 0;
	int lo = 0, hi = S;
	while ( lo <= hi ) {
		int mid = ( lo + hi ) / 2;
		if ( possible( i, mid ) )
		      hi = mid - 1;
		else
		      lo = mid + 1;
	}
	return hi + 1;
}

bool votes_cmp( const int& i, const int& j ) {
	if ( votes[i] != votes[j] )
		return votes[i] < votes[j];
	return i > j;  // remember -> the lower numbered party gets the seat
}

int main() {

	scanf( "%d %d %d", &V, &P, &S );

	freeVotes = V;
	REP( i, P ) {
	      scanf( "%d", &votes[i] );
		idx[i] = i;
		freeVotes -= votes[i];
	}

	sort( idx, idx + P, votes_cmp );

	REP( i, P ) printf( "%d ", solve20( i ) ); printf( "\n" );
	REP( i, P ) printf( "%d ", solve80( i ) ); printf( "\n" );

	return 0;
}
