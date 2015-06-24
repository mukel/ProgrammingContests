/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #76 "Bracket structure correction"
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

string S;

int main()
{
	cin >> S;
	int n = S.size();
	
	if (n % 2) cout << "NO" << endl;
	else
	{
		int lvl = 0, flips = 0;
		REP(i, n)
		      if (S[i] == '(') lvl++;
		else
		{
		      if (!lvl) flips++, lvl++;
		      else
		            lvl--;
		}
		      
		printf( "%d\n", lvl / 2 + flips );
	}

	return 0;
}
