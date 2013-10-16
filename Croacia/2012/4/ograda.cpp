/*
Alfonso2 Peterssen (mukel)
COCI 2012 Contest #4
Task: OGRADA
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long int64;

const int
	MAXN = 300000;

int N;
int A[MAXN];
int B[MAXN];
int D[MAXN];
int64 totalCost;
bool mark[MAXN];
vector< int > G[MAXN];
vector< int > topOrder;
int ans[MAXN];
map< int , vector< int > > vals;

void dfs(int u)
{
	mark[u] = true;
	if (u > 0 && A[u] > A[u - 1] && !mark[u - 1]) dfs(u - 1);
	if (u + 1 < N && A[u] > A[u + 1] && !mark[u + 1]) dfs(u + 1);
	topOrder.push_back(u);
}

int main()
{
	scanf( "%d", &N );
	for (int i = 0; i < N; ++i)
		scanf( "%d", &A[i] );

	for (int i = 1; i < N; ++i)
	{
		if (A[i] > A[i - 1])
			D[i]++, D[i - 1]--;
		else
			D[i]--, D[i - 1]++;
	}

	for (int i = 0; i < N; ++i)
		if (!mark[i])
			dfs(i);

	reverse(topOrder.begin(), topOrder.end());

	for (int i = 0; i < N; ++i)
		scanf( "%d", &B[i] );

	sort(B, B + N);

	int lo = 0;
	for (int i = -2; i <= +2; ++i)
		for (int j = 0; j < N; ++j)
			if (D[j] == i)
				vals[i].push_back(B[lo++]);

	for (int i = 0; i < N; ++i)
	{
		int x = topOrder[i];
		ans[x] = vals[ D[x] ].back();
		vals[ D[x] ].pop_back();
		totalCost += D[x] * ans[x];
	}

	printf( "%lld\n", totalCost );
	for (int i = 0; i < N; ++i)
		printf( "%d ", ans[i] );

	return 0;
}
