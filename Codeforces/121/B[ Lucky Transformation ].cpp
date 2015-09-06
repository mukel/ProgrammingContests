/*
	Alfonso2 Peterssen(mukel)
	Codeforces Beta Round #91 (Div. 1 Only)
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)

int N, K;
string S;
set< int > pos;

int main()
{
	cin >> N >> K >> S;
	REP(i, N - 1)
	      if (S[i] == &#39;4&#39; && S[i + 1] == &#39;7&#39;)
			pos.insert(i);
	
	while (K--)
	{
		if (pos.empty()) break;
		
		int x = *pos.begin();
		pos.erase(pos.begin());

		if ((x + 1) % 2 == 1) // odd
		{
			if (x + 2 < N && S[x] == &#39;4&#39; && S[x + 1] == &#39;7&#39; && S[x + 2] == &#39;7&#39;)
			{
				S[x] = &#39;4&#39;;
   				S[x + 1] = (K%2) ? &#39;7&#39; : &#39;4&#39;;
     				S[x + 2] = &#39;7&#39;;
				break;
			}

			S[x] = &#39;4&#39;;
  			S[x + 1] = &#39;4&#39;;
  			if (x + 2 < N && S[x+2] == &#39;7&#39;)
  			      pos.insert(x + 1);
		}
		else // even
		{
			S[x] = &#39;7&#39;;
  			S[x + 1] = &#39;7&#39;;
  			if (x - 1 >= 0 && S[x-1] == &#39;4&#39;)
  			      pos.insert(x - 1);
		}
	}

	cout << S << endl;

	return 0;
}

