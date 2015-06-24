/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #104 "Camomile Game -- who is the winner?"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXP = 1 << 8;

int N, nimSum;
int sg[MAXP];

int calcSG(int n)
{
	if (n == 0) return 0;
	
	if (sg[n] >= 0) return sg[n];

	vector< int > V;
	REP(i, n)
	{
		V.push_back(calcSG(i) ^ calcSG(n - i - 1));
		if (n - i - 2 >= 0) V.push_back(calcSG(i) ^ calcSG(n - i - 2));
	}

	sort(ALL(V));
	V.erase(unique(ALL(V)), V.end());
	
	REP(i, V.size())
	      if (V[i] != i)
	      {
			sg[n] = i;
			break;
		}
		
	if (sg[n] < 0) sg[n] = V.size();
	
	return sg[n];
}

int main()
{
	memset(sg, -1, sizeof(sg));

	for (scanf( "%d", &N ); N--;)
	{
		int x; scanf( "%d", &x );
		nimSum ^= calcSG(x);
	}
	
	if (nimSum) printf( "First" );
	else printf( "Second" );
	
	printf( " wins.\n" );

	return 0;
}
