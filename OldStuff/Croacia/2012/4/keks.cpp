/*
Alfonso2 Peterssen (mukel)
COCI 2012 Contest #4
Task: KEKS
*/
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int
	MAXN = 1 << 20;

int N, K;
int pos;
char D[MAXN];
int next[MAXN];

int main()
{
	scanf( "%d %d %s", &N, &K, &D );

	stack< int > S;
	for (int i = 0; i < N; ++i)
	{
		while (!S.empty() && D[i] > D[S.top()])
		{
		      next[S.top()] = i;
		      S.pop();
		}
		S.push(i);
	}

	while (K > 0)
	{
		int from = pos;
		while (next[pos] && next[pos] <= from + K)
			pos = next[pos];

		printf( "%c", D[pos] );

		K -= (pos - from);
		pos++;
	}

	while (pos < N)
		printf( "%c", D[pos++] );

	return 0;
}
