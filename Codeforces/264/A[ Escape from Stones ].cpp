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

deque< int > F, B;

int main()
{
	ios::sync_with_stdio(0);

	string buf;
	cin >> buf;

	REP(i, SZ(buf))
	{
		if (buf[i] == &#39;l&#39;)
			B.push_front(i);
		else
			F.push_back(i);
	}

	REP(i, SZ(F))
		cout << F[i] + 1 << endl;

	REP(i, SZ(B))
		cout << B[i] + 1 << endl;

	return 0;
}
