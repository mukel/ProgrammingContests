/*
	Alfonso2 Peterssen(mukel)
	Codeforces Beta Round #91 (Div. 1 Only)
*/
#include <cstdio>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 17,
	MAXV = 10001;

int N, Q;
int S[MAXN];
int val[MAXN];
bool lucky[MAXV];

void dfs(int x)
{
	if (x >= 1 && x <= MAXV) lucky[x] = true;
	if (x > MAXV) return ;
	dfs(x * 10 + 4);
	dfs(x * 10 + 7);
}

int lobit(int x) { return x & -x; }

void update(int x, int amount)
{
	for (x++; x <= N; x += lobit(x))
	      S[x] += amount;
}

int query(int x)
{
	int ret = 0;
	for (x++; x > 0; x -= lobit(x))
	      ret += S[x];
	return ret;
}

int query(int lo, int hi)
{
	return query(hi) - query(lo - 1);
}

int main()
{
	scanf( "%d %d", &N, &Q );
	
	dfs(0);
	
	REP(i, N)
	{
	      scanf( "%d", &val[i] );
	      if (lucky[ val[i] ])
			update(i, +1);
	}

	while (Q--)
	{
            char op[10];
		int lo, hi;
		scanf( "%s %d %d", &op, &lo, &hi );
		lo--;
		hi--;

		if (op[0] == &#39;c&#39;)
			printf( "%d\n", query(lo, hi) );
		else
		{
			int delta;
			scanf( "%d", &delta );
			for (int i = lo; i <= hi; ++i)
			{
			      if (lucky[ val[i] ]) update(i, -1);
			      val[i] += delta;
			      if (lucky[ val[i] ]) update(i, +1);
			}
		}
	}

	return 0;
}
