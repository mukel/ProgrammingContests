/*
Alfonso2 Peterssen
SPOJ #1685 "Grocery store"
22 - 9 - 2008
*/
#include <cstdio>

#define FOR( i, s, e ) for ( int i = (s); i <= (e); i++ )
	
long long S, P;

int main() {
	FOR( a, 8, 125 )
	FOR( b, a, 592 ) {
	if (a+b>600 || a*b>20000) break;
	FOR( c, b, 884 ) {
		S = a+b+c; if (S>1225) break;
		P = a*b*c; if (P>3500000) break;
		S *= 1000000;
		P -= 1000000;
		if (P<=0 || S%P) continue;
		long long d = S / P;
		if (d<c) break;
		if (a*b*c*d > 2000000000) continue;
		printf( "%.2lf %.2lf %.2lf %.2lf\n", a/100., b/100., c/100., d/100. );
	}
	}
	return 0;
}
