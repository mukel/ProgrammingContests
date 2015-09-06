/*
Alfonso2 Peterssen(mukel) UH++
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>

#include <cstdlib>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); ++i)
#define FORD(i, s, e) for (int i = (int)(s); i >= (int)(e); --i)

typedef long long int64;

const int MAXC = 400;

int R, C;
char mat[MAXC][MAXC];

bool test(int x, int y)
{
	map< string, bool > S;
	int i = x, j = y;
	for (int a = 0; a + i - 1 < R; a += i)
	for (int b = 0; b + j - 1 < C; b += j)
	{
		string cad1;
		FOR(p, a, a + i - 1)
		{

			FOR(q, b, b + j - 1)
				cad1 += mat[p][q];
			cad1 += "$";
		}
		
		string cad2;
		FORD(q, b + j - 1, b)
		{
			FOR(p, a, a + i - 1)
				cad2 += mat[p][q];
			cad2 += "$";
		}
		
		string cad3;
		FORD(p, a + i - 1, a)
		{
			FORD(q, b + j - 1, b)
				cad3 += mat[p][q];
   			cad3 += "$";
		}
		
		string cad4;
		FOR(q, b, b + j - 1)
		{
			FORD(p, a + i - 1, a)
				cad4 += mat[p][q];
   			cad4 += "$";
		}
			
		if (S[cad1] || S[cad2] || S[cad3] || S[cad4])
			return false;

		S[cad1] = S[cad2] = S[cad3] = S[cad4] = true;
	}
	
	return true;
}

int main()
{

	scanf( "%d %d", &R, &C );
	REP(i, R)
		scanf( "%s", &mat[i] );
		
	int ans = 0, ansX = R, ansY = C;
	FOR(i, 1, R) if (R % i == 0)
	FOR(j, 1, C) if (C % j == 0)
	{
		if (test(i, j))
		{
			//printf( "%d %d\n", i, j );
			ans++;
			if (i*j < ansX*ansY || (i*j == ansX*ansY && i < ansX))
				ansX = i, ansY = j;
		}
	}

	printf( "%d\n", ans );
	printf( "%d %d\n", ansX, ansY );

      return 0;
}
;
