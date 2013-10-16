/*
Alfonso2 Peterssen(mukel)
SPOJ #526 "Divisors"
*/
#include <cstdio>

const int
	MAXN = (int)1e6;

int n;
int pfac[MAXN];
int pcnt[MAXN];

void output(int x)
{
	if (++n % 9 == 0)
		printf( "%d\n", x );
}

int main()
{
	for (int i = 2; i < MAXN; ++i)
		if (!pfac[i])
	     		for (int j = i; j < MAXN; j += i)
	            	pfac[j] = i, pcnt[j]++;

	for (int i = 2; i < MAXN; ++i)
	{
		if (pcnt[i] == 1)
		{
			int pq = 1;
			for (int t = i, d = pfac[i]; t % d == 0; t /= d)
				pq++;

			int p = pfac[pq];
			int q = pq / p;

			if (p != q && q == pfac[q])
				output(i);
		}
		else
		if (pcnt[i] == 2)
		{
			int p = 1, t, d;
			for (t = i, d = pfac[i]; t % d == 0; t /= d)
				p++;

			if (p == pfac[p])
			{
	      	      int q = 1;
				for (d = pfac[t]; t % d == 0; t /= d)
					q++;

				if (p != q && q == pfac[q])
				      output(i);
			}
		}
	}

	return 0;
}
