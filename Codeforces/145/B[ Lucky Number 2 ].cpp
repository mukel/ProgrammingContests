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
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	string ans;
	if (a3 == a4)
	{
		// try 4 ... 4
		if (a1 - a3 - 1 >= 0 && a2 - a4 >= 0)
		{
			REP(i, a1 - a3 - 1) cout << "4";
			REP(i, a3) cout << "47";
			REP(i, a2 - a4) cout << "7";
			cout << "4";
			cout << endl;
			exit(0);
		}
		// try 7 ... 7
		if (a1 - a3 >= 0 && a2 - a4 - 1 >= 0)
		{
			REP(i, a4) cout << "74";
			REP(i, a1 - a3) cout << "4";
			REP(i, a2 - a4 - 1) cout << "7";
			cout << "7";
			cout << endl;
			exit(0);
		}
	}
	else if (a3 == a4 + 1)
	{
		// try 4 ... 7
		if (a1 - a3 >= 0 && a2 - a3 >= 0)
		{
			REP(i, a1 - a3) cout << "4";
			REP(i, a3) cout << "47";
			REP(i, a2 - a3) cout << "7";
			cout << endl;
			exit(0);
		}

	}
	else if (a3 + 1 == a4)
	{
		// try 7 ... 4
		if (a1 - a4 + 1 > 0 && a2 - a4 + 1 > 0)
		{
			cout << "7";
			REP(i, a1 - a4 + 1) cout << "4";
			REP(i, a4 - 2) cout << "74";
			REP(i, a2 - a4 + 1) cout << "7";
			cout << "4";

			cout << endl;
			exit(0);
		}
	}

	printf( "-1\n" );

	return 0;
}
