/*
Alfonso2 Peterssen(mukel)
Codeforces Round 69 Beta Div. 1
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

const string heroNames[] = {
	"Anka",
	"Chapay",
	"Cleo",
	"Troll",
	"Dracul",
	"Snowy",
	"Hexadecimal"
};

int N;
bool L[7][7];
char buf1[0xff];
char buf2[0xff];
int evilExp[3];
int order[3];
vector< int > team[3];
map< string, int > id;

int main()
{
	REP(i, 7) id[heroNames[i]] = i;

	scanf( "%d", &N );
	REP(i, N)
	{
		scanf( "%s %*s %s", &buf1, &buf2 );
		int u = id[buf1];
		int v = id[buf2];
		L[u][v] = 1;
	}
	
	REP(i, 3) scanf( "%d", &evilExp[i] );
	
	int minDiff = (int)2e9 + 1, maxLikes = -1;

	REP(i, 2187)
	{
		int x = i;
		REP(j, 3) team[j].clear(), order[j] = j;
		
		REP(j, 7) team[x % 3].push_back(j), x /= 3;
		
		bool ok = true;
		REP(j, 3) if (team[j].empty()) ok = false;
		if (!ok) continue ;
		
		int likes = 0;
		REP(j, 3)
		{
			REP(a, team[j].size())
			REP(b, team[j].size())
			      if (L[ team[j][a] ][ team[j][b] ]) likes++;
		}
		
		int diff = (int)2e9 + 1;
		do
		{
			int low = (int)2e9 + 1;
			int upp = -1;
			
			REP(k, 3)
			{
				low = min(low, evilExp[order[k]] / (int)team[k].size());
				upp = max(upp, evilExp[order[k]] / (int)team[k].size());
			}
			
			diff = min(diff, upp - low);

		} while (next_permutation(order, order + 3));
		
		if (diff < minDiff) minDiff = diff, maxLikes = likes;
		if (diff == minDiff) maxLikes = max(maxLikes, likes);

	}
	
	printf( "%d %d\n", minDiff, maxLikes );
	
	return 0;
}
