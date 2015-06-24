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

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		int N; scanf( "%d", &N );
		double x = N ? 1./N : 0;
		printf( "%0.8lf\n", x*(1./(N+1)) + x * (N-1));
	}

	return 0;
}
