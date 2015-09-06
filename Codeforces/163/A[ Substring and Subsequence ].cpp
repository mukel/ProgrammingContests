// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).begin()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).begin(); ++it)

const int
	MAXN = 5005;

int next[MAXN][26];


char S[MAXN];
char T[MAXN];
int dp[MAXN][MAXN];

int main()
{
	scanf( "%s %s", S + 1, T + 1 );

	int slen = strlen(S+1);
	int tlen = strlen(T+1);

	const int MOD = 1000000007;

	FOR(j, 0, tlen) dp[0][j] = 1;
	FOR(i, 0, slen) dp[i][0] = 1;

	dp[0][0] = 1;
	FOR(i, 1, slen)
	FOR(j, 1, tlen)
	{
		dp[i][j] =  dp[i][j - 1];
		if (S[i] == T[j])
			dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
		//printf( "%d %d -> %d\n", i, j, dp[i][j] );
	}

	long long ans = 0;
	FOR(i, 1, slen) {
		//cout << dp[i][tlen] << endl;
		ans = (ans + dp[i][tlen]) % MOD;
	}

	cout << (ans - slen + MOD) % MOD << endl;

	return 0;
}
