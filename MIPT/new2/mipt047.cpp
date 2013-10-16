/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #47 "Self-describing sequence"
*/
#include <cstdio>

using namespace std;

const int
	MAXN = 1 << 20;

int K;
int f[MAXN];

int main()
{
	scanf( "%d", &K );

	int cur = 1;
	f[cur++] = 1; // 1
	f[cur++] = 2; // 2
	f[cur++] = 2; // 3
	
	for (int i = 1;; i++)
	{
		if ((K -= f[i]) <= 0)
		{
			printf( "%d\n", i );
			break;
		}
		if (i >= 3)
		for (int j = 0; cur < MAXN && j < f[i]; j++)
		      f[cur++] = i;
	}

	return 0;
}
