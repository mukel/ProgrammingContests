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
#define RFOREACH(it, c) for (typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); ++it)

const int
	MAXN = 1 << 17;

int N, L, K;
int A[MAXN];

multiset< int > cuco, pk;
int64 cucoSum;
int64 curSum;

void addTocuco(int val)
{
	pk.insert(val);
	cucoSum += val;

	if (SZ(pk) > K)
	{
		cuco.insert(*pk.begin()); // min element
		cucoSum -= *pk.begin();
		pk.erase(pk.begin());
	}
}

void remTocuco(int val)
{
	if (pk.find(val) != pk.end())
	{
		pk.erase( pk.find(val) );
		cucoSum -= val;

		if (!cuco.empty() && SZ(pk) < K) // try to refill
		{
			cucoSum += *cuco.rbegin(); // add max element
			pk.insert(*cuco.rbegin());

			typeof(cuco.begin()) it = cuco.end();
			it--;
			cuco.erase(it);
		}
	} else
		cuco.erase(cuco.find(val));
}

int64 solve()
{
	cuco.clear();
	pk.clear();

	cucoSum = 0;
	curSum = 0;

	REP(i, L)
	{
		if (A[i] > 0) addTocuco(A[i]);
		curSum += A[i];
	}

	int64 answer = abs(curSum -  2 * cucoSum);

	//cout << answer << endl;

	for (int i = L; i < N; ++i)
	{
		int toDel = A[i - L];

		if (toDel > 0) remTocuco(toDel);
		curSum -= toDel;

		int toAdd = A[i];
		if (toAdd > 0) addTocuco(toAdd);
		curSum += toAdd;
		answer = max(answer, abs(curSum -  2 * cucoSum));
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> L;
	REP(i, N) cin >> A[i];
	cin >> K;

	int64 ans = solve(); // solve();
	REP(i, N) A[i] *= -1;
	ans = max(ans, solve());

	cout << ans << endl;

	return 0;
}
