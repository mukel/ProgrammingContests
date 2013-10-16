/*
Alfonso2 Peterssen(mukel)
SPOJ #4168 "Square-free integers"
*/
#include <iostream>
using namespace std;

typedef unsigned long long int64;

const int MAXP = (int)1e7 + 100;

int64 n, ans;
int P;
int64 primeSq[MAXP / 8];
int mark[MAXP / 32];

void fastSieve()
{
	#define getBit(x) (mark[x >> 5] & (1 << (x & 31)))
	#define setBit(x) (mark[x >> 5] |= (1 << (x & 31)))
	for (int i = 6; (i+1) * (i+1) < MAXP; i += 6)
	{
		int a = i - 1;
		if (!getBit(a)) for (int j = a * a, a2 = a << 1; j < MAXP; j += a2) setBit(j);
		a = i + 1;
		if (!getBit(a)) for (int j = a * a, a2 = a << 1; j < MAXP; j += a2) setBit(j);
	}

	primeSq[P++] = 2*2;
	primeSq[P++] = 3*3;
	for (int i = 6;; i += 6)
	{
		int a = i - 1;
		if (a >= MAXP) break;
		if (!getBit(a)) primeSq[P++] = a * (int64)a;
		a = i + 1;
		if (a >= MAXP) break;
		if (!getBit(a)) primeSq[P++] = a * (int64)a;
	}
}

void search(int64 curValue = 1, int curPrime = 0, int pUsed = 0)
{
	if (curValue > n) return ;
	if (pUsed & 1) ans -= n / curValue; else ans += n / curValue;
	for (int i = curPrime; primeSq[i] <= n ; i++)
	{
		int64 pi = primeSq[i];
		if (curValue > n / pi + 1) break;
		search(curValue * pi, i + 1, pUsed + 1);
	}
}

int main()
{
	fastSieve();

	int T;
	for (cin >> T; T--;)
	{
		cin >> n;
		ans = 0;
		search();
		cout << ans << endl;
	}
	
	return 0;
}
