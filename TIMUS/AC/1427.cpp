/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1427. SMS
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

typedef long long int64;

#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int
	MAXN = 1 << 17;
	
int N, M;
char S[MAXN];
int dp[MAXN];

char buff[0xff];

int main()
{
	gets(buff); sscanf(buff, "%d %d", &N, &M); // avoid reading mistakes
	gets(S + 1);
	
	int len = strlen(S + 1);

	dp[0] = 0;
	int nonLatin = 0;

	FOR(i, 1, len)
	{
		if (!isalpha(S[i]) && !isspace(S[i]))
			nonLatin = i;
		dp[i] = dp[max(0, i - N)] + 1;
		dp[i] = min(dp[i], dp[max(i - M, nonLatin)] + 1);
	}

	printf( "%d\n", dp[len] );

	return 0;
}
