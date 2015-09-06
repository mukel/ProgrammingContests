/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #107 Div 1
*/
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

typedef pair< int64, int > par;

vector< par > factorize(int64 n)
{
	vector< par > f;
	
	for (int64 i = 2; i * i <= n; ++i)
	{
		int e = 0;
		while (n % i == 0)
		{
		      e++;
		      n /= i;
		}
		if (e > 0)
			f.push_back(make_pair(i, e));
	}
	
	if (n > 1) f.push_back(make_pair(n, 1));
	
	return f;
}

int main()
{
	int64 n; cin >> n;
	
	if (n == 1)
	{
		printf( "1\n0\n" );
		return 0;
	}
	
	vector< par > f = factorize(n);
	
	if (SZ(f) == 1 && f[0].second == 1)
	      printf( "1\n0\n" );
	else
	{
		if (f[0].second > 1)
		{

                  int64 nn = f[0].first * f[0].first;
                  if (nn != n)
                  {
				cout << "1\n";
				cout << nn << endl;
			}
			else
			{
				cout << "2\n";
			}
		}
		else
		{
                  int64 nn = f[0].first * f[1].first;
                  if (nn != n)
                  {
				cout << "1\n";
				cout << nn << endl;
			}
			else
			{
				cout << "2\n";
			}
		}
	}

	return 0;
}
