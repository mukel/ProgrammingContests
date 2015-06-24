/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #77 "Queens"
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
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	MAXN = 1 << 4;

int N, ans;
int row[MAXN];
int d1[2 *  MAXN];
int __d2[2 *  MAXN], *d2 = __d2 + MAXN;

void srch(int c)
{
	if (c >= N) { ans++; return ; }
	REP(i, N)
	      if (!row[i] && !d1[i + c] && !d2[i - c])
	      {
			row[i] = 1;
			d1[i + c] = 1;
			d2[i - c] = 1;
			
			srch(c + 1);
			
			row[i] = 0;
			d1[i + c] = 0;
			d2[i - c] = 0;
		}
}

int main()
{
	scanf( "%d", &N );
	//srch(0);
	
	int preAns[] = {0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184};
	
	printf( "%d\n", preAns[N] );

	return 0;
}
