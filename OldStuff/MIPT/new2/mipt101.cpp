/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #101 "Stone Game -- who is the winner?"
*/
#include <cstdio>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

// SG = n % 3
int calcSG(string n)
{
	// bignum % 3
	int m3 = 0;
	REP(i, n.size()) m3 = (m3 * 10 + (n[i] - '0')) % 3;
	return m3;
}

int N, nimSum;

int main()
{
	for (cin >> N; N--;)
	{
		string x; cin >> x;
		nimSum ^= calcSG(x);
	}
	
	if (nimSum) printf( "First" );
	else printf( "Second" );
	
	printf( " wins.\n" );

	return 0;
}
