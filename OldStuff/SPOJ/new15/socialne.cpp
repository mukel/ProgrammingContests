/*
Alfonso2 Peterssen(mukel)
SPOJ #8042 "Possible Friends"
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
#include <tr1/unordered_map>

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

const int MAXN = 60;

int N;
bool F[MAXN][MAXN];
char buf[MAXN];
int posFriends[MAXN];

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		scanf( "%s", &buf );
		
		N = strlen(buf);
		REP(j, N) F[0][j] = (buf[j] == 'Y');
		for (int i = 1; i < N; i++)
		{
			scanf( "%s", &buf );
			REP(j, N)
				F[i][j] = (buf[j] == 'Y');
		}
		      
		REP(i, N)
		{
			posFriends[i] = 0;
			REP(j, N) if (i != j)
				if (!F[i][j])
				{
					bool ok = false;
					REP(k, N)
					      if (F[i][k] && F[k][j])
					      {
					            ok = true;
					            break;
						}
					if (ok) posFriends[i]++;
				}
		}
		
		int x = max_element(posFriends, posFriends + N) - posFriends;
		printf( "%d %d\n", x, posFriends[x] );
	}
	return 0;
}

