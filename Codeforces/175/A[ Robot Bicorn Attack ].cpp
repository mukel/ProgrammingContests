// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main()
{
	string S;
	cin >> S;

	const int
		MAXV = (int)1e6;

	int ans = -1;

	FOR(l1, 1, 7)
	FOR(l2, 1, 7)
	FOR(l3, 1, 7)
	if (l1 + l2 + l3 == SZ(S))
	{
		// 0 .. i
		string s1 = S.substr(0, l1);
		string s2 = S.substr(l1, l2);
		string s3 = S.substr(l1 + l2, l3);

		if (SZ(s1) > 1 && s1[0] == &#39;0&#39;) continue ;
		if (SZ(s2) > 1 && s2[0] == &#39;0&#39;) continue ;
		if (SZ(s3) > 1 && s3[0] == &#39;0&#39;) continue ;

		int n1 = atoi(s1.c_str());
		int n2 = atoi(s2.c_str());
		int n3 = atoi(s3.c_str());

		if (n1 > MAXV) continue ;
		if (n2 > MAXV) continue ;
		if (n3 > MAXV) continue ;

		ans = max(ans, n1 + n2 + n3);
	}

	cout << ans << endl;

	return 0;
}
