/*
 * Alfonso2 Peterssen(mukel)
 * Codeforces Round #61 (Div. 2)
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
#include <cassert>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin, (c).end()
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define FOR(i, b, e) for (int (i) = (int)(b); (i) <= (int)(e); ++(i))

const int MAXP = 10000;

int N;
int P;
int prime[MAXP];
bool mark[MAXP];
bool ans[100][MAXP];

int gcd(int a, int b)
{
	REP(i, P)
		if (ans[a][i] && ans[b][i])
			return true;
	return false;
}

typedef vector< int > big;

void norm(big & a)
{
	int carry = 0;
	REP(i, a.size())
	{
		int t = a[i] + carry;
		a[i] = t % 10;
		carry = t / 10;
	}

	while (carry > 0) a.push_back(carry % 10), carry /= 10;	
}

void mul(big & a, int b)
{
	REP(i, a.size()) a[i] *= b; norm(a);
}

int main()
{
	for (int i = 2; i < MAXP; i++)
		if (!mark[i])
		{
			prime[P++] = i;
			for (int j = 2 * i; j < MAXP; j += i)
				mark[j] = true;
		}

	cin >> N;

	REP(i, N) ans[i][i % 2] = true;

	int cur = 3;
	int cnt = 0;

	REP(i, N)
	{		
		REP(j, i)
			if (i != j)
			if (!gcd(i, j))
			{
				if (cnt + 2 >= N) cur++, cnt = 0;
				ans[i][cur] = true;
				ans[j][cur] = true;
				cnt += 2;
			}
		cur++;
	}

	if (N == 2) printf( "-1" );
	else
	{
		REP(i, N)
		{
			big x; x.push_back(1);
			REP(j, P)
				if (ans[i][j]) mul(x, prime[j]);
			printf( "%d", x.back() );
			for (int i = x.size() - 2; i >= 0; i--)
				printf( "%d", x[i] );
			printf( "\n" );
		}
	}
		
	return 0;
}
