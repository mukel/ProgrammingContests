// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int N;
int allSum;
int targetSum;
bool mark[16];
int low;
int colSum[4];
vector< vector< int > > tuples;
int a[16];

bool myLessComp(vector< int > x, vector< int > y)
{
	REP(i, N)
	{
		x[i] = a[ x[i] ];
		y[i] = a[ y[i] ];
	}
	return x < y;
}

bool myEqualComp(vector< int > x, vector< int > y)
{
	REP(i, N)
	{
		x[i] = a[ x[i] ];
		y[i] = a[ y[i] ];
	}
	return x == y;
}

int sDiag, dDiag;
int ans[4];

void comb(int curRow)
{
	if (curRow >= N)
	{
		if (sDiag != targetSum || dDiag != targetSum)
			return ;

		REP(i, N)
			if (colSum[i] != targetSum)
				return ;

		cout << targetSum + N * low << endl;

		REP(i, N)
		{
			int r = ans[i];
			REP(j, N) cout << a[ tuples[r][j] ] + low << " ";
			cout << endl;
		}

		exit(0);
	}

	REP(i, SZ(tuples))
	{
		bool used = false;

		REP(j, N)
		{
			if (mark[ tuples[i][j] ])
			{
				used = true;
				break;
			}
		}

		if (used) continue ;

		bool colSumsOK = true;

		REP(j, N)
		{
			int id = tuples[i][j];
			colSum[j] += a[id];

			if (colSum[j] > targetSum)
				colSumsOK = false;

			mark[id] = 1;
		}

		ans[curRow] = i;

		sDiag += a[tuples[i][ curRow ]];
		dDiag += a[tuples[i][N - curRow - 1]];

		if (colSumsOK && sDiag <= targetSum && dDiag <= targetSum)
			comb(curRow + 1);

		sDiag -= a[tuples[i][ curRow ]];
		dDiag -= a[tuples[i][N - curRow - 1]];

		REP(j, N)
		{
			int id = tuples[i][j];
			colSum[j] -= a[id];
			mark[id] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	low = (int)1e9;

	cin >> N;
	REP(i, N*N)
	{
		cin >> a[i];
		low = min(low, a[i]);
	}

	if (N == 1)
	{
		cout << a[0] << endl << a[0] << endl;
		exit(0);
	}

	REP(i, N*N)
	{
		a[i] -= low;
		allSum += a[i];
	}

	targetSum = allSum / N;

	random_shuffle(a, a + (N * N));

	if (N == 2)
	{
		REP(i1, N*N)
		REP(i2, N*N)
		if (i1 != i2)
		{
			if (a[i1] + a[i2] == targetSum)
			{
				vector< int > v;
				v.push_back(i1);
				v.push_back(i2);
				tuples.push_back(v);
			}
		}
	}
	else
	if (N == 3)
	{
		REP(i1, N*N)
		REP(i2, N*N)
		REP(i3, N*N)
		if (i1 != i2 && i1 != i3 && i2 != i3)
		{
			if (a[i1] + a[i2] + a[i3] == targetSum)
			{
				vector< int > v;
				v.push_back(i1);
				v.push_back(i2);
				v.push_back(i3);
				tuples.push_back(v);
			}
		}
	}
	else
	if (N == 4)
	{
		REP(i1, N*N)
		REP(i2, N*N)
		REP(i3, N*N)
		REP(i4, N*N)
		if (i1 != i2 && i1 != i3 && i1 != i4 && i2 != i3 && i2 != i4 && i3 != i4)
		{
			if (a[i1] + a[i2] + a[i3] + a[i4] == targetSum)
			{
				vector< int > v;
				v.push_back(i1);
				v.push_back(i2);
				v.push_back(i3);
				v.push_back(i4);
				tuples.push_back(v);
			}
		}
	}

	sort(ALL(tuples), myLessComp);
	unique(ALL(tuples), myEqualComp);

	comb(0);

	return 0;
}
