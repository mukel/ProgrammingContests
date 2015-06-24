/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1523. K-inversions
*/
#include <cstdio>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 20001,
	MAXK = 11,
	MOD = (int)1e9;
	
int N, K;
int S[MAXK][MAXN];

int lobit(int x) { return x & -x; }

void update(int id, int x, int amount)
{
	for (; x > 0; x -= lobit(x))
	      S[id][x] = (S[id][x] + amount) %  MOD;
}

int query(int id, int x)
{
	int sum = 0;
	for (; x < MAXN; x += lobit(x))
		sum = (sum + S[id][x]) % MOD;
	return sum;
}

int main()
{
	scanf( "%d %d", &N, &K );
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		for (int j = K; j > 0; j--)
		{
			int tmp = query(j - 1, x);
			if (tmp)
				update(j, x, tmp);
		}
		update(1, x, 1);
	}

	printf( "%d\n", query(K, 1) );
	
	return 0;
}
