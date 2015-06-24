/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1306. Sequence Median
*/
#include <cstdio>
#include <queue>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int N;
std::priority_queue< int > pq;

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		pq.push(x);
		while (pq.size() > N / 2 + 1)
		      pq.pop();
	}

	if (N & 1)
	      printf( "%d.0\n", pq.top() );
	else
      {
		int a = pq.top(); pq.pop();
		int b = pq.top();
	      printf( "%.1lf\n", ((double)a + b) / 2 );
	}

	return 0;
}
