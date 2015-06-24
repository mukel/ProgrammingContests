/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1613. For Fans of Statistics
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 70001;

int N, Q;
int vals[MAXN];
vector< int > T[4 * MAXN];

void build(int x, int lo, int hi)
{
	if (lo > hi) return ;
	if (lo == hi)
	{
		T[x].push_back(vals[lo]);
		return ;
	}
	
	int mid = (lo + hi) / 2;
	build(2 * x, lo, mid);
	build(2 * x + 1, mid + 1, hi);
	
	T[x].resize(T[2 * x].size() + T[2 * x + 1].size());
	merge(ALL(T[2 * x]), ALL(T[2 * x + 1]), T[x].begin());
}

bool query(int x, int lo, int hi, int start, int end, int value)
{
	if (lo > hi || lo > end || hi < start)
	      return 0;
	      
	if (lo >= start && hi <= end)
	      return binary_search(ALL(T[x]), value);

	int mid = (lo + hi) / 2;
	return
		query(2 * x, lo, mid, start, end, value) ||
		query(2 * x + 1, mid + 1, hi, start, end, value);
}

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	      scanf( "%d", &vals[i] );
	
	build(1, 0, N - 1);
	
	scanf( "%d", &Q );
	while (Q--)
	{
		int l, r, x;
		scanf( "%d %d %d", &l, &r, &x );
		l--; r--;
		printf( "%d", (int)query(1, 0, N - 1, l, r, x));
	}

	return 0;
}
