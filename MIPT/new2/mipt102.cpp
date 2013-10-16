/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #102 "Stone Game II -- who is the winner?"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXP = 1 << 17;

int N, nimSum;
int sg[MAXP];

// O(1)
int cleverSG(int n)
{
	return (n/(~n&-~n)/2); // copied from Jin Bin
}

// brute SG calculation O(n^2)
int bruteSG(int n)
{
	if (n == 1) return 0;
	if (sg[n] >= 0) return sg[n];

	vector< int > V;
	for (int i = 1; i <= n/2; i++)
		V.push_back(bruteSG(n - i));

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

// precalculate SG O(n lg n)
void calcSG(int n)
{
	multiset< int > S;

	int pos = 1;
	for (int i = 1; i < n; i++)
	{
		while (i - pos > i/2) S.insert(sg[pos++]);
		if (S.empty()) sg[i] = i/2;
		else sg[i] = *(S.begin()), S.erase(S.begin());
	}
}

int main()
{
//	memset(sg, -1, sizeof(sg));

	calcSG(MAXP);

	for (scanf( "%d", &N ); N--;)
	{
		int x; scanf( "%d", &x );
		nimSum ^= sg[x];
	}
	
	if (nimSum) printf( "First" );
	else printf( "Second" );
	
	printf( " wins.\n" );

	return 0;
}
