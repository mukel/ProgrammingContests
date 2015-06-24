/*
Alfonso2 Peterssen
SPOJ #4681 "Twice"
6 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 18;

int N;
char S[MAXN];
int offset;
int sa[MAXN];
int pos[MAXN];
int tmp[MAXN];
int lcp[MAXN];

bool suffixComp(int i, int j)
{
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += offset;
	j += offset;
	if (i < N && j < N)
	      return pos[i] < pos[j];
	return i > j;
}

bool suffixCompTricky(int i, int j)
{
	i += offset;
	j += offset;
	if (i < N && j < N)
	      return pos[i] < pos[j];
	return i > j;
}

int main()
{
	scanf( "%d", &N );
	scanf( "%s", &S );
	
	REP(i, N)
	{
		sa[i] = i;
		pos[i] = S[i];
	}

	sort(sa, sa + N, suffixComp);
	for (offset = 1; offset == 1 || offset < N; offset *= 2)
	{
		for (int i = 0, j; i < N; i = j)
		{
			for (j = i + 1; j < N && pos[ sa[i] ] == pos[ sa[j] ]; j++);
			sort(sa + i, sa + j, suffixCompTricky);
		}
//		sort(sa, sa + N, suffixComp);
		REP(i, N - 1) tmp[i + 1] = tmp[i] + suffixComp(sa[i], sa[i + 1]);
		REP(i, N) pos[ sa[i] ] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}

	int ans = 0;
	for (int i = 0, k = 0; i < N; ++i)
	{
		if (pos[i] == N - 1) continue;
		for (int j = sa[pos[i] + 1]; i+k < N && j+k < N && S[i + k] == S[j + k]; ++k);
		lcp[pos[i]] = k;
		ans = max(ans, k);
		if ( k > 0 ) k--;
	}
	
	printf( "%d\n", ans );

	return 0;
}
