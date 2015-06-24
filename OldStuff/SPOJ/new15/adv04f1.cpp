/*
Alfonso2 Peterssen(mukel)
SPOJ #7864 "Four Chips (Hard)"
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

const int MAXN = 100;

typedef vector< char > state;

int val[MAXN];
char dist[MAXN][MAXN][MAXN][MAXN];

int reached(state & s)
{
	return (int)dist[s[0]][s[1]][s[2]][s[3]];
}

void update(state & s, int d)
{
	dist[s[0]][s[1]][s[2]][s[3]] = d;
}

queue< state > Q;

void resumeBFS(state target)
{
	while (!Q.empty())
	{
		state top = Q.front();
		char d = reached(top);
		Q.pop();
		
		REP(i, 4)
		{
			if ((i && top[i] - 1 != top[i - 1]) || (i == 0 && top[i] - 1 >= 0))
			{
				state nxt = top;
				--nxt[i];
				if (!reached(nxt))
				{
					update(nxt, d + 1);
					Q.push(nxt);
				}
			}
			if ((i < 3 && top[i] + 1 != top[i + 1]) || (i == 3 && top[i] + 1 < 70))
			{
				state nxt = top;
				++nxt[i];
				if (!reached(nxt))
				{
					update(nxt, d + 1);
					Q.push(nxt);
				}
			}
		}
		
		REP(i, 4)
		REP(j, 4) if (j != i)
		{
			int npos = top[j] + (top[j] - top[i]);
			if (npos < 0 || npos >= 70) continue ;
			
			bool ok = true;
			REP(k, 4) if (top[k] == npos) { ok = false; break; }
			
			if (!ok) continue ;
			state nxt = top;
			nxt[i] = npos;
			sort(ALL(nxt));
			if (!reached(nxt))
			{
				update(nxt, d + 1);
				Q.push(nxt);
			}
		}
		
		if (reached(target)) break;
	}
}

int main()
{
	state start;
	REP(i, 4) start.push_back(i);
	update(start, 1);
	Q.push(start);

	int T;
	for (scanf( "%d", &T ); T--;)
	{
		state target;
		REP(i, 4)
		{
			int x;
			scanf( "%d", &x );
			x--;
			target.push_back(x);
		}
		sort(ALL(target));
		
		if (!reached(target)) resumeBFS(target);
		printf( "%d\n", reached(target) - 1);
	}

	return 0;
}
