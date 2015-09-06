/*
Alfonso2 Peterssen(mukel)
Yandex Open 2011 - Qualification 1
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXL = 200005;

char buf[MAXL];
stack< int > S;
bool del[MAXL];

int main()
{
	scanf( "%s", &buf );
	int N = strlen(buf);
	
	REP(i, N)
	{
		if (!S.empty() && buf[S.top()] == buf[i])
		{
			del[S.top()] = 1;
			del[i] = 1;
			S.pop();
		} else
		      S.push(i);
	}
	
	REP(i, N) if (!del[i])
	      printf( "%c", buf[i] );

	return 0;
}
