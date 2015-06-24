/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1613. For Fans of Statistics
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int N, Q;
map< int, vector< int > > pos;

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		pos[x].push_back(i);
	}
	
	scanf( "%d", &Q );
	while (Q--)
	{
		int l, r, x;
		scanf( "%d %d %d", &l, &r, &x );
		l--; r--;
		printf( "%d", (int)(pos.count(x) && lower_bound(ALL(pos[x]), l) != upper_bound(ALL(pos[x]), r)));
	}

	return 0;
}
