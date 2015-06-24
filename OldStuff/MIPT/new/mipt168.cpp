/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #168 "brackets 2"
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

const char *br = "[]{}()<>";

const int
	MAXN = 1 << 21;
	
char buf[MAXN];
stack< int > S;
bool op[MAXN], cl[MAXN];
int next[MAXN];
int data[MAXN];

int find(int u) { return data[u] < 0 ? u : data[u] = find(data[u]); }
int size(int u) { return -data[find(u)]; }

void join(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return ;
	if (size(u) < size(v)) swap(u, v);
	data[u] += data[v];
	data[v] = u;
}

int main()
{
	scanf( "%s", &buf );
	int n = strlen(buf);
	
	memset(data, -1, sizeof(data));

	REP(i, n)
	{
		int p = strchr(br, buf[i]) - br;
		if (p & 1)
		{
			if (S.empty()) continue ;
			int q = strchr(br, buf[S.top()]) - br;
			if (q + 1 == p)
			{
				next[S.top()] = i;
				op[S.top()] = true;
				cl[i] = true;
				
				S.pop();
			} else
			{
				while (!S.empty()) S.pop();
			}
		}
		else
			S.push(i);
	}

	REP(i, n)
	{
		if (!next[i]) continue ;
		join(i, next[i]);
		if (op[next[i] + 1]) join(i, next[i] + 1);
	}
	
	int Q;
	for (scanf( "%d", &Q); Q--; )
	{
		int l, h;
		scanf( "%d %d", &l, &h );
		l--; h--;
		printf( "%s\n", (op[l] && cl[h] && find(l) == find(h)) ? "Y" : "N" );
	}

	return 0;
}
