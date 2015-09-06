#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main()
{
	{
		string s;
		cin >> s;
		for (char d : s)
			cnt[d - &#39;0&#39;]++;
	}



	vector< int > used = {1, 6, 8, 9};

	for (auto d: used)
		cnt[d]--;

	vector< int > mark(7);

	do {
		int m = used[0] + used[1] * 10 + used[2] * 100 + used[3] * 1000;
		mark[m % 7] = m;
	} while (next_permutation(used.begin(), used.end()));

	int modulo = 0;

	for (int i = 9; i > 0; --i)
	{
		int l = cnt[i];
		for (int j = 0; j < l; ++j)
		{
			modulo = (modulo * 10 + i) % 7;
			cout << (char)(i + &#39;0&#39;);
		}
	}

	modulo = (modulo * 10000) % 7;

	cout << mark[ (14 - modulo) % 7 ];
	for (int j = 0; j < cnt[0]; ++j)
		cout << &#39;0&#39;;
	cout << endl;

	return 0;
}
