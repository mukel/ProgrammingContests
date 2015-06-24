/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #300 "Algorithm Complexity"
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

typedef deque< int > poly;

const int
	MAXT = 100000;

int n;
string tok[MAXT];
int pos;

poly parse()
{
	if (tok[pos] == "BEGIN")
	{
		pos++; // skip BEGIN
		poly ret = parse();
		pos++; // skip END
		return ret;
	}

	poly ret;
	ret.push_back(0); // nothing

      while (tok[pos] != "END")
      {
		if (tok[pos] == "OP")
		{
			pos++; // skip OP
			int num = atoi(tok[pos].c_str());
			pos++; // skip NUM
			ret[0] += num;
		}
		else
		if (tok[pos] == "LOOP")
		{
			poly other;
			pos++; // skip LOOP
			if (tok[pos] == "n")
			{
				pos++; // skip n
				other = parse();
				pos++; // skip END
				other.push_front(0);
			}
			else
			{
				int num = atoi(tok[pos].c_str());
				pos++; // skip NUM
				other = parse();
				pos++; // skip END
				REP(i, other.size()) other[i] *= num;
			}

			if (other.size() > ret.size()) ret.resize(other.size());
			REP(i, other.size()) ret[i] += other[i];
		}
	}

	while (!ret.empty() && ret.back() == 0) ret.pop_back();
	return ret;
}

int main()
{
	while (cin >> tok[n]) n++;

	poly ans = parse();

	printf( "Runtime = " );

	if (ans.empty())
		printf( "0" );
	else
	{
		bool first = true;
		int sz = ans.size();
		for (int i = sz - 1; i >= 0; i--)
		{
			if (!ans[i]) continue ;
			if (!first) printf("+");

			first = false;
			if (ans[i] > 1 || (ans[i] && !i)) printf( "%d", ans[i] );

			if (ans[i] > 1 && i > 0) printf( "*" );

			if (i > 1) printf( "n^%d", i );
			else
			if (i == 1) printf( "n" );
		}
	}

	printf( "\n" );

	return 0;
}
