/*
Alfonso2 Peterssen(mukel)
SPOJ #5294 "Recurrence"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

const int MAXL = 1 << 7;

char sa[MAXL];
char sb[MAXL];
char sn[MAXL];

int intMod(char * s, int MOD)
{
	int ret = 0;
	for (int i = 0; s[i]; i++)
		ret = (ret * 10 + (s[i] - '0')) % MOD;
	return ret;
}

const int MAXMOD = 1 << 17;

int f[MAXMOD];

int curMark;
int mrk[MAXMOD];
int pos[MAXMOD];

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		int a, b, MOD;
		scanf( "%s %s %s %d", &sa, &sb, &sn, &MOD );
		a = intMod(sa, MOD);
		b = intMod(sb, MOD);

		int ans;

		f[0] = 1;
		pos[ f[0] ] = 0;
		mrk[ f[0] ] = ++curMark;

		for (int i = 1;; i++)
		{
		      f[i] = (f[i - 1] * (int64)a + b) % MOD;

		      if (mrk[ f[i] ] == curMark)
		      {
				int gap = i - pos[ f[i] ];
				int p = intMod(sn, gap);
				ans = f[p + pos[ f[i] ]];
				break;
			}
			else
			{
			      pos[ f[i] ] = i;
				mrk[ f[i] ] = curMark;
			}
		}

		printf( "%d\n", ans );
	}

	return 0;
}
