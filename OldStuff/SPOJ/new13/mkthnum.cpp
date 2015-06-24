/*
Alfonso2 Peterssen
SPOJ #3946 "K-th Number"
15 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
	MAXN = 1 << 17;
	
int N, Q;
int val[MAXN];
vector< int > T[3 * MAXN];

void build(int x, int lo, int hi)
{
	if (lo > hi) return ;
	if (lo == hi) { T[x].push_back(val[lo]); return ; }
	int mid = (lo + hi) / 2;
	build(2 * x, lo, mid);
	build(2 * x + 1, mid + 1, hi);
	T[x].resize(T[2 * x].size() + T[2 * x + 1].size());
	merge(ALL(T[2 * x]), ALL(T[2 * x + 1]), T[x].begin());
}

int start, end, value;
int queryLessThan(int x, int lo, int hi)
{
	if (lo > end || hi < start || lo > hi) return 0;
	if (lo >= start && hi <= end)
	      return lower_bound(ALL(T[x]), value) - T[x].begin();
	int mid = (lo + hi) / 2;
	return queryLessThan(2 * x, lo, mid) + queryLessThan(2 * x + 1, mid + 1, hi);
}

int query(int myStart, int myEnd, int kth)
{
	start = myStart; end = myEnd;
	
	int lo = 0, hi = N - 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		
		value = val[mid];
		if (queryLessThan(1, 0, N - 1) <= kth)
			lo = mid + 1;
		else
		      hi = mid - 1;
	}
	
	return val[lo - 1];
}

int main()
{
	scanf( "%d %d", &N, &Q );
	REP(i, N)
	      scanf( "%d", &val[i] );
	      
	build(1, 0, N - 1);
	
	sort(val, val + N); // make it O(n lg n)

	while (Q--)
	{
		int lo, hi, kth;
		scanf( "%d %d %d", &lo, &hi, &kth );
		lo--; hi--; kth--;
		printf( "%d\n", query(lo, hi, kth) );
	}
	
	return 0;
}
