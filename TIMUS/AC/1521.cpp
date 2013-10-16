/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1521. War games 2
*/
#include <cstdio>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 17;

int N, K;
int T[2 * MAXN];

void update(int x, int amount) // 0 based
{
	for (x += MAXN; x > 0; x /= 2)
	      T[x] += amount;
}

int findKth(int x, int kth) // 1 based
{
	while (x < MAXN)
	{
		x *= 2;
		if (kth > T[x]) kth -= T[x++];
	}
	return x - MAXN;
}

int main()
{
	scanf( "%d %d", &N, &K );
	
	REP(i, N)
		update(i, 1);
	      
	int currPos = K - 1;
	REP(i, N)
	{
		int pos = findKth(1, currPos + 1);
		update(pos, -1);
		printf( "%d ", pos + 1 );
		
		if (i < N - 1) // avoid % 0
			currPos = (currPos - 1 + K) % (N - i - 1);
	}
	
	printf( "\n" );

	return 0;
}
