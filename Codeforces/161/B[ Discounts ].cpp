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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 10;

int N, K;
vector< int > carts[MAXN];

struct item
{
	int cost, type, id;
};

double totalCost;
bool hasStool[MAXN];

int C[MAXN], T[MAXN];

vector< item > items[2];
vector< int > cart[MAXN];

bool operator < (const item& a, const item & b)
{
	return a.cost < b.cost;
}

bool costCmp(int i, int j)
{
	return C[i] < C[j];
}

int main()
{
	scanf( "%d %d", &N, &K );
	REP(i, N)
	{
		scanf( "%d %d", &C[i], &T[i] );
		--T[i];
		items[T[i]].push_back((item){C[i], T[i], i});
	}

	REP(i, 2)
		sort(ALL(items[i]));

	reverse(ALL(items[0]));

	int cur = 0;
	REP(i, SZ(items[0]))
	{
		if (cur < K)
		{
			hasStool[cur] = 1;
			cart[cur].push_back(items[0][i].id);
			cur++;
		}
		else
			cart[K - 1].push_back(items[0][i].id);
	}

	REP(i, SZ(items[1]))
	{
		if (cur < K)
			cart[cur++].push_back(items[1][i].id);
		else
			cart[K - 1].push_back(items[1][i].id);
	}

	REP(i, K)
		sort(ALL(cart[i]), costCmp);

	REP(i, K)
	{
		REP(j, SZ(cart[i]))
		{
			int x = cart[i][j];
			totalCost += C[x];
		}
		if (hasStool[i])
			totalCost -= C[cart[i][0]]/2.0;
	}

	printf( "%.1lf\n", totalCost );
	REP(i, K)
	{
		printf( "%d", SZ(cart[i]) );
		REP(j, SZ(cart[i]))
			printf( " %d", cart[i][j] + 1 );
		printf( "\n" );
	}

	return 0;
}
