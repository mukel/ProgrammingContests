// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define SZ(c) ((int)(c).size())
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); c != (c).end(); ++it)

typedef long long hash;

const hash
	BASE = 123,
	MODULO = 12345678901;

string line;

int64 fmod(int64 a, int64 b)
{
	return a;
}


vector<int> val(5000001);

int main(int argc, char ** argv)
{
	if (argc > 0) freopen(argv[1], "r", stdin);
	if (argc > 1) freopen(argv[2], "w", stdout);

	ios::sync_with_stdio(false);

	cin >> line;

    hash h1 = 0;
    hash h2 = 0;
    hash pBase = 1;
	long long res = 0;

	val.resize(line.size() / 2 + 1);

	for (int i = 0; i < line.size(); ++i)
	{
		h1 = h1 * BASE + line[i];
	    h2 = h2 + line[i] * pBase;
        pBase = pBase * BASE;
        int cur = 0;
        if (h1 == h2)
        {
        	cur = val[(i + 1) / 2] + 1;
	    }
	    res += cur;
	    if (i + 1 < val.size())
	    	val[i + 1] = cur;
    }

    cout << res << endl;

	return 0;
}
