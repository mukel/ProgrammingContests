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

int a, b, m, r;
int pos[1 << 17];

int main()
{
	cin >> a >> b >> m >> r;
	int i = 0;
	do pos[r] = i++, r = (r * a + b) % m; while (!pos[r]);
	printf( "%d\n", i - pos[r] );

	return 0;
}
