/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #146 "Display"
*/
#include <cstdio>
#include <cstring>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int code[10][5] =
{
	{1,3,0,3,1},
	{0,1,0,1,0},
	{1,1,1,2,1},
	{1,1,1,1,1},
	{0,3,1,1,0},
	{1,2,1,1,1},
	{1,2,1,3,1},
	{1,1,0,1,0},
	{1,3,1,3,1},
	{1,3,1,1,1}
};

int K, S;
char buf[1 << 10];

int main()
{
	scanf( "%d %d", &K, &S );
	scanf( "%s", &buf );

	REP(i, 5)
	{
		if (i & 1)
		{
			REP(j, K)
			{
				for (int k = 0; buf[k]; k++)
				{
					if (k) REP(l, S) printf( " " ); // space
					int x = code[buf[k] - '0'][i];
					if (x & 2) printf( "|" ); else printf( " " );
					REP(l, K) printf( " " );
					if (x & 1) printf( "|" ); else printf( " " );
				}
				printf( "\n" );
			}
		} else
		{
			for (int j = 0; buf[j]; j++)
			{
				if (j) REP(k, S) printf( " " ); // space
				printf( " " );
				int x = code[buf[j] - '0'][i];
				REP(k, K) if (x) printf( "-" ); else printf( " " );
				printf( " " );
			}
			printf( "\n" );
		}

	}

	return 0;
}
