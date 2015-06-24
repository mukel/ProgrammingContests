/*
Alfonso2 Peterssen (mukel)
SPOJ #3409 "Electricity"
17 - 5 - 2009
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
struct date {
	static bool leap( int Y ) {
		return (!(Y % 4) && (Y % 100)) || !(Y % 400);
	}
	
	int D, M, Y, cost;

	date nextDay() {
		if ( D < days[M - 1] || (M == 2 && leap(Y) && D == 28 ) ) {
			D++;
		} else {
			M++; if ( M > 12 ) M = 1, Y++;
			D = 1;
		}
	}
	
	bool operator == ( const date& d ) const {
		return (D == d.D) && (M == d.M) && (Y == d.Y);
	}
};

int main() {

	while (1) {
		int N; scanf( "%d", &N ); if ( !N ) break ;
		int ans = 0, kwh = 0;
		
		date last;
		REP( i, N ) {
			int d, m, y, cost;
			scanf( "%d %d %d %d", &d, &m, &y, &cost );
			date now = (date){ d, m, y, cost };
			if ( i && now == last ) {
				ans++;
				kwh += ( now.cost - last.cost );
			}
			last = now;
			last.nextDay();
		}
		
		printf( "%d %d\n", ans, kwh );
	}

	return 0;
}
