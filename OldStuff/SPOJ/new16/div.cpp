/*
Alfonso2 Peterssen(mukel)
SPOJ #526 "Divisors"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define SZ(c) ((int)(c).size())

const int
	MAXN = (int)1e6;

vector< int > pfac[MAXN];
vector< int > ans;

int main()
{
	for (int i = 2; i < MAXN; ++i)
	      if (pfac[i].empty())
	     		for (int j = i; j < MAXN; j += i)
	            	pfac[j].push_back(i);

	for (int i = 2; i < MAXN; ++i)
	{
	      if (SZ(pfac[i]) == 1)
	      {
			int pq = 1;
			for (int t = i; t % pfac[i][0] == 0; t /= pfac[i][0])
				pq++;

			if (SZ(pfac[pq]) == 2 && pq == pfac[pq][0] * pfac[pq][1])
			      ans.push_back(i);
		}
		else
		if (SZ(pfac[i]) == 2)
	      {
                  int p = 1;
			for (int t = i; t % pfac[i][0] == 0; t /= pfac[i][0]) p++;

                  int q = 1;
			for (int t = i; t % pfac[i][1] == 0; t /= pfac[i][1]) q++;
			
			if (p != q && p == pfac[p][0] && q == pfac[q][0])
			      ans.push_back(i);
		}
	}
	
	for (int i = 8; i < SZ(ans); i += 9)
	      printf( "%d\n", ans[i] );

	return 0;
}
