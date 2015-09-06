// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <tr1/unordered_map>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).begin()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 20;

struct node
{
	map< char, node* > next;
	node * fail;
	vector< node * > childs;
	int lo, hi;
} * root;

int dtime;
char buf[MAXN];
int Q, N;
bool used[MAXN];

node * lastNode[MAXN];

node * getFail(node * x, char c)
{
	while (x && !x->next.count(c))
		x = x->fail;
	return x ? x->next[c] : root;
}

void insert(char * s, int id)
{
	node * cur = root;
	for (int i = 0; s[i]; ++i)
	{
		node *& nxt = cur->next[ s[i] ];
		if (!nxt) nxt = new node();
		cur = nxt;
	}
	lastNode[id] = cur;
}

void bfs()
{
	root->fail = NULL;

	queue< node * > Q;
	for (Q.push(root); !Q.empty(); Q.pop())
	{
		node * u = Q.front();
		FOREACH(it, u->next)
		{
			char c = it->first;
			node * v = it->second;
			node * f = getFail(u->fail, c);

			v->fail = f;
			f->childs.push_back(v);

			Q.push(v);
		}
	}
}

void dfs(node * x)
{
	x->lo = ++dtime;
	FOREACH(it, x->childs)
		dfs(*it);
	x->hi = dtime;
}

//////////////////////////////////////////////////////////////////////////////

int sum[MAXN];

int lobit(int x)
{
	return x & -x;
}

int query(int x)
{
	int r = 0;
	for (; x > 0;  x -= lobit(x))
		r += sum[x];

	return r;
}

int query(int lo, int hi)
{
	return query(hi) - query(lo - 1);
}

void update(int x, int val)
{
	for (; x < MAXN;  x += lobit(x))
		sum[x] += val;
}

//////////////////////////////////////////////////////////////////////////////

void add(int id)
{
	if (used[id]) return ;
	used[id] = true;
	node * x = lastNode[id];
	update(x->lo, 1);
	update(x->hi + 1, -1);
}

void remove(int id)
{
	if (!used[id]) return ;
	used[id] = false;
	node * x = lastNode[id];
	update(x->lo, -1);
	update(x->hi + 1, +1);
}

long long search(char * s)
{
	node * cur = root;

	long long ans = 0;
	for (int i = 0; s[i]; ++i)
	{
		cur = getFail(cur, s[i]);
		ans += query(cur->lo);
	}

	return ans;
}

int main()
{
	root = new node();
	scanf( "%d %d", &Q, &N );

	REP(i, N)
	{
		scanf( "%s", buf );
		insert(buf, i);
	}

	bfs();
	dfs(root);

	REP(i, N) add(i);

	while (Q--)
	{
		scanf( "%s", &buf );
		if (buf[0] == &#39;+&#39;)
		{
			int n = atoi(buf+1);
			--n;
			add(n);
		}
		else
		if (buf[0] == &#39;-&#39;)
		{
			int n = atoi(buf+1);
			--n;
			remove(n);
		}
		else
			cout << search(buf + 1) << "\n";
	}

	return 0;
}
