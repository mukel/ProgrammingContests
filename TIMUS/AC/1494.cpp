/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1494. Monobilliards
*/
#include <cstdio>
#include <stack>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
const int
	MAXN = 100000;

int N;
int vals[MAXN];
stack< int > S;

int main()
{
	scanf( "%d", &N );
	REP(i, N)
		scanf( "%d", &vals[i] );

	int currBall = 1, pos = 0;
	while (currBall <= N)
	{
		S.push(currBall);
		while (!S.empty() && pos < N && S.top() == vals[pos])
		{
		      S.pop();
		      pos++;
		}
		currBall++;
	}

	printf( "%s\n", S.empty() ? "Not a proof" : "Cheater" );

	return 0;
}
