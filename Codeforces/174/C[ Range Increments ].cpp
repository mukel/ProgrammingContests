#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REPI(i,c) for (typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define ALL(c) c.begin(), c.end()

#define MP make_pair
#define FF first
#define SS second

#define DB(x) cout << #x << " = " << x << endl;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 100005;
const int INF = 1 << 30;
const double EPS = 1e-7;

int N;
vector< int > hpos[MAX];
int data[MAX];
bool mark[MAX];

int lo[MAX];
int hi[MAX];
set< int > groups;
vector< pair< int, int >  > ans;

int find(int x)
{
	return data[x] < 0 ? x : data[x] = find(data[x]);
}

int getSize(int x)
{
	return -data[find(x)];
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return ;
	if (getSize(x) < getSize(y))
		swap(x, y);

	lo[x] = min(lo[x], lo[y]);
	hi[x] = max(hi[x], hi[y]);

	data[x] += data[y];
	data[y] = x;
	groups.erase(y);
}

void add(int pos)
{
	data[pos] = -1;
	groups.insert(pos);

	lo[pos] = pos;
	hi[pos] = pos;

	mark[pos] = 1;
	if (pos > 0 && mark[pos - 1])
		join(pos, pos - 1);
	if (pos + 1 < N && mark[pos + 1])
		join(pos, pos + 1);
}

int main()
{

    scanf( "%d", &N );
    REP(i, N)
    {
    	int x;
    	scanf( "%d", &x );
    	hpos[x].push_back(i);
    }

    for (int i = MAX - 1; i > 0; --i)
    {
    	REP(j, hpos[i].size())
    		add(hpos[i][j]);
    	REPI(it, groups)
    		ans.push_back(make_pair(lo[*it], hi[*it]));
    }

    printf( "%d\n", ans.size() );
    REP(i, ans.size())
		printf( "%d %d\n", ans[i].first + 1, ans[i].second + 1 );

    return 0;
}// (++UH)++ :: agarwaen
