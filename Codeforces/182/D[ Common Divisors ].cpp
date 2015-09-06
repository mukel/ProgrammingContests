// Alfonso2 Peterssen (mukel)
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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

string A, B;
int answer;

vector< int > zFunc(string s)
{
	int S = SZ(s);
	vector< int > pref(S + 1);

	pref[0] = S;
	for (int i = 1, end = 0, f; i < S; i++ )
		if (i < end && pref[i - f] != end - i)
			pref[i] = min(pref[i - f], end - i);
		else
		{
			end = max(end, i);
			f = i;
			while (s[end] == s[end - f]) ++end;
			pref[i] = end - f;
		}

	return pref;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> A >> B;
	vector< int > za = zFunc(A);
	vector< int > zb = zFunc(B);

	for (int i = 1; i <= min(SZ(A), SZ(B)) && A[i - 1] == B[i - 1]; ++i)
		if (SZ(A) % i == 0)
		if (SZ(B) % i == 0)
		{
			if (za[i] == SZ(A) - i)
			if (zb[i] == SZ(B) - i)
				answer++;
		}

	cout << answer << endl;

	return 0;
}
