// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 10;

int N;
map< string, int > P;

int main()
{
	cin >> N;
	REP(i, N)
	{
		string name; int p;
		cin >> name >> p;
		P[name] = max(P[name], p);
	}

	N = SZ(P);

	cout << N << endl;

	FOREACH(it, P)
	{
		cout << it->first << " ";

		int l = 0, g = 0, e = 0; //less than i, greater than i, eq to i
		FOREACH(other, P)
		{
			if (other->second == it->second) e++;
			if (other->second <  it->second) l++;
			if (other->second >  it->second) g++;
		}

		// "noob" -- if more than 50% of players have better results;
		if (g * 100 > N * 50)
		{
			cout << "noob";
		}

		// "random" -- if his result is not worse than the result that 50%
		// of players have, but more than 20% of players have better results;
		if ((l + e) * 100 >= 50 * N && g * 100 > N * 20)
		{
			cout << "random";
		}

		// "average" -- if his result is not worse than the
		//result that 80% of players have, but more than 10% of players
		// have better results;
		if ((l + e) * 100 >= N * 80 && g * 100 > N * 10)
		{
			cout << "average";
		}

		// "hardcore" -- if his result is not worse than
		// the result that 90% of players have,
		// but more than 1% of players have better results;
		if ((l + e) * 100 >= N * 90 && g * 100 > N * 1)
		{
			cout << "hardcore";
		}

		// "pro" -- if his result is not worse than the result that 99% of players have.
		if ((l + e) * 100 >= 99 * N)
			cout << "pro";

		cout << endl;
	}

	return 0;
}
