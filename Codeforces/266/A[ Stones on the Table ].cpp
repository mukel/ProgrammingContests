// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define endl &#39;\n&#39;
#define SZ(c) ((int)((c).size()))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

int answer;

int main()
{
	ios::sync_with_stdio(0);

	int N; cin >> N;
	string buf; cin >> buf;

	REP(i, N)
		while (i + 1 < N && buf[i] == buf[i + 1])
		{
			buf.erase(i, 1);
			N--;
			answer++;
		}

	cout << answer << endl;

	return 0;
}
