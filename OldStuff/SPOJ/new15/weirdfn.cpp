/*
Alfonso2 Peterssen(mukel)
SPOJ #5977 "Weird Function"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int64;

const int
	MOD = 1000000007;
	
int main()
{
	int T;
	for (cin >> T; T--;)
	{
		int a, b, c, n;
		cin >> a >> b >> c >> n;

		int f1 = 1;
		int f2 = (a + 2 * (int64)b + c) % MOD;
		
		priority_queue< int, vector< int >, greater< int > > R;
		priority_queue< int, vector< int >, less< int > > L;

		L.push(min(f1, f2));
		R.push(max(f1, f2));

		int64 ans = f1 + f2;
		for (int i = 3; i <= n; i++)
		{
			int med = L.top();
			int f = (a*(int64)(med) + b*(int64)i + c) % MOD;
			ans += f;
			
			// insert
			if (f > L.top()) R.push(f); else L.push(f);
			while (R.size() > L.size()) L.push(R.top()), R.pop();
			while (L.size() > R.size() + 1) R.push(L.top()), L.pop();
		}

		cout << ans << endl;
	}

	return 0;
}
