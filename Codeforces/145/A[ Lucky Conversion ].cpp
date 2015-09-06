// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 17;

int p1, p2;
char a[MAXN];
char b[MAXN];

int main()
{
	scanf( "%s %s", &a, &b );
	int n = strlen(a);

	REP(i, n) if (a[i] == &#39;4&#39; && b[i] == &#39;7&#39;) p1++;
	REP(i, n) if (a[i] == &#39;7&#39; && b[i] == &#39;4&#39;) p2++;

	cout << max(p1, p2) << endl;


	return 0;
}
