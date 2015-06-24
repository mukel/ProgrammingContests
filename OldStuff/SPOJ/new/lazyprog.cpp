/*
Alfonso2 Peterssen
SPOJ #417 "The lazy programmer"
3 - 9 - 2008
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cmath>
#include <complex>

#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int MAXN = 100000;
const double EPSILON = 1e-9;

int T, N;
double total_time, sol;
struct job {
     	double time;
	int dead_line, money;
	bool operator < ( const job &j ) const { return dead_line < j.dead_line; }
} jobs[MAXN];

struct job_cmp {
	bool operator () ( const job& a, const job& b ) const {
		return a.money > b.money;
	}
};
multiset< job, job_cmp > S;

int main() {

	scanf( "%d", &T );
	while ( T-- ) {

		scanf( "%d", &N );
		REP( i, N ) {
			int a, b, d;
			scanf( "%d %d %d", &a, &b, &d );
			jobs[i].time = b;
			jobs[i].money = a;
			jobs[i].dead_line = d;
		}
		
		sort( jobs, jobs + N );
		S.clear();
		
		sol = total_time = 0.;
		REP( i, N ) {

			S.insert( jobs[i] ); // add current job
			
			total_time += jobs[i].time;
			while ( total_time - jobs[i].dead_line > EPSILON ) {
				job best = *S.begin();
				S.erase( S.begin() );
				
				double kk = min( best.time, total_time - jobs[i].dead_line );
				best.time -= kk;
				total_time -= kk;
				sol += kk / best.money;
				
				if ( best.time > EPSILON )
					S.insert( best );
			}
		}
		
		printf( "%.2lf\n", sol );
	}
	
	return 0;
}
