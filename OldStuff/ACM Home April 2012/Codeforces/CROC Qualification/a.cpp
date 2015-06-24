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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int n, answer;
string S[1 << 20];

int main()
{
	cin >> n;
	REP(i, n) cin >> S[i];

	while (answer < SZ(S[0]))
	{
		REP(i, n) if (S[i][answer] != S[0][answer])
			goto finish;
		answer++;
	}

	finish:;

	printf( "%d\n", answer );

	return 0;
}
