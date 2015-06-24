/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1126. Magnetic storm
*/
#include <cstdio>
#include <stack>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 25000;

int N, M;
int vals[MAXN];
int next[MAXN];
std::stack< int > S;

int main()
{
	scanf( "%d", &M );
	while (1)
	{
		int x;
		scanf( "%d", &x ); if (x == -1) break;
		vals[N++] = x;
	}

	REP(i, N)
	{
		next[i] = -1;
		while (!S.empty() && vals[i] > vals[ S.top() ])
		{
		      next[S.top()] = i;
		      S.pop();
		}
		S.push(i);
	}
	
	int best = 0;
	REP(i, N)
	{
		if (best < i - M + 1) best = i - M + 1;
		while (next[best] != -1 && next[best] <= i)
		      best = next[best];
		if (i >= M - 1)
			printf( "%d\n", vals[best] );
	}

	return 0;
}
