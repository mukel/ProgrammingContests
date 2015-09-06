/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #110 Div 1
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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 17;

int N, M;
int guilts;
int totalGoods;
int good[MAXN];
int bad[MAXN];
bool mark[MAXN];
int A[MAXN];

int main()
{
	scanf( "%d %d", &N, &M );
	FOR(i, 1, N)
	{
		scanf( "%d", &A[i] );
		
		//G[A[i]].push_back(i);

		if (A[i] < 0) good[ -A[i] ]++, totalGoods++;
		else bad[ A[i] ]++;
	}
	
	FOR(i, 1, N) // assume i is guilty
	{
		int mm = bad[i] + totalGoods - good[i];
		if (mm != M) continue ; // impossible
		// i is suspect
		//printf( "-> %d\n", i );
		
		mark[i] = true;
		guilts++;
	}
	
	if (guilts == 1)
	{
		FOR(i, 1, N)
		{

			if (A[i] > 0)
			{
				if (mark[A[i]])
			      	printf( "Truth\n" );
				else
					printf( "Lie\n" );
			}
			else
			if (!mark[-A[i]])
				printf( "Truth\n" );
			else
			      printf( "Lie\n" );
		}
		return 0;
	}

	FOR(i, 1, N)
	{
            if (A[i] > 0)
            {
			if (mark[A[i]])
		      	printf( "Not defined\n" );
			else
				printf( "Lie\n" );
		}
		else
		{
                  if (!mark[-A[i]])
                  	printf( "Truth\n" );
			else
				printf( "Not defined\n" );
				
		}
	}

	return 0;
}
