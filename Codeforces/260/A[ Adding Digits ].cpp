#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define endl &#39;\n&#39;
#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)n; ++i)

int a, b, n;
string answer;

int main()
{
	ios::sync_with_stdio(0);

	cin >> a >> b >> n;

	int m = a % b;

	REP(i, n)
	{
		m = (m * 10) % b;

		if (m == 0)
			m = b;

		if (b - m > 9)
		{
			cout << -1 << endl;
			return 0;
		}

		answer += (char)(b - m + &#39;0&#39;);

		m = 0;
	}

	cout << a << answer << endl;

	return 0;
}
