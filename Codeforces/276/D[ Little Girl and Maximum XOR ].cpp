// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
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
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ALL(c) (c).begin(), (c).end()

int64 L, R;

int main()
{
	ios::sync_with_stdio(0);
	
	cin >> L >> R;
	
	if (L == R)
	{
		cout << 0 << endl;
		return 0;
	}			
	
	
	int bit; 
	for (bit = 63; bit >= 0; --bit)
		if ((L & (1LL << bit)) xor ((R & (1LL << bit))))
		{
			cout << ((1LL << (bit+1)) -1) << endl;
			break;			
		}		
	return 0;
}
