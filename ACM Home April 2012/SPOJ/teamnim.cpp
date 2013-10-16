// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int x, y, z;
string name[4];

// classic Nim
bool solveABAB() { return x ^ y ^ z; } // ok

bool solveAABB()
{
	return !(x % 2 == 0 && x == y && (z == y || z == y + 1));
}

bool solveABBA()
{
	// pick from y (x x x+1)
	if (x % 2 == 0 && y == x + 1 && y == z) return 1;

	// pick from z (x x x)
	if (x % 2 == 0 && x == y && z > y) return 1;

	// pick from z (x x+1 x)
	if (x % 2 == 0 && x + 1 == y && z > x) return 1;

	return 0;
}

#define EN(i) (name[(i)][0] == 'E' || name[(i)][0] == 'N')
#define AB(i) (name[(i)][0] == 'A' || name[(i)][0] == 'B')

int main()
{
	int T; for (cin >> T; T--;)
	{
		cin >> x >> y >> z;

		if (y < x) swap(x, y);
		if (z < x) swap(x, z);
		if (z < y) swap(y, z);

		REP(i, 4) cin >> name[i];

		bool ans;
		if (EN(0)) // start EN
		{
			if (EN(1)) ans = solveAABB();
			if (EN(2)) ans = solveABAB();
			if (EN(3)) ans = solveABBA();
		}
		else // if (AB(0)) // start AB
		{
			if (AB(1)) ans = !solveAABB();
			if (AB(2)) ans = !solveABAB();
			if (AB(3)) ans = !solveABBA();
		}

		cout << (ans ? "Elayne/Nynaeve" : "Aviendha/Birgitte") << "\n";
	}

	return 0;
}
