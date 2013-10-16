/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #61 "Reconstructing permutation"
*/
#include <cstdio>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 15;

int N;
int gLeft[MAXN];
bool used[MAXN];
int ans[MAXN];

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	      scanf( "%d", &gLeft[i] );
	      
	REP(i, N)
	{
		if (gLeft[i] < 0 || gLeft[i] >= N - i)
		{
			printf( "-1\n" );
			return 0;
		}
		for (int j = N; j > 0; j--)
		      if (!used[j])
				if (!gLeft[i]) { ans[i] = j; used[j] = true; break; }
				else gLeft[i]--;
	}

	REP(i, N)
	      printf( "%d ", ans[i] );

	printf( "\n" );

	return 0;
}
