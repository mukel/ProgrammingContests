/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #110 Div 1
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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

string A, B;
int ans;

int main()
{
	cin >> A >> B;

	ans = SZ(B);
	for (int i = -SZ(B); i < SZ(A); ++i)
	{
		int dif = 0;
		for (int j = 0; j < SZ(B); ++j)
		{
			if (i + j >= 0 && i + j < SZ(A))
			{
		      	if (A[i + j] != B[j])
					dif++;
			}
			else
				dif++;
		}
		ans = min(ans, dif);
	}
	
	cout << ans << endl;
	
	return 0;
}
