/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>

#include <cstdlib>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); ++i)

typedef long long int64;

string move[3];
string name = "FMS";
map< string, map< string, bool > > win;

int main()
{
	REP(i, 3) cin >> move[i];
	
	win["scissors"]["paper"] = true;
	win["rock"]["scissors"] = true;
	win["paper"]["rock"] = true;
	
	REP(i, 3)
		if (win[ move[i] ][ move[(i + 1) % 3] ] && win[ move[i] ][ move[(i + 2) % 3] ])
		{
			cout << name[i] << endl;
			return 0;
		}
	
	printf( "?\n" );

      return 0;
}
