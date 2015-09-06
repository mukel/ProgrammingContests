#include <bits/stdc++.h>
using namespace std;
	
int N;
bool used[1 << 20];
vector< int > y;
int cnt;
	
int main()
{
		ios::sync_with_stdio(0);
		cin.tie(0);	
		
		scanf( "%d", &N );
		
		for (int i = 0; i < N; ++i)
		{
			int x;
			scanf( "%d", &x );
			used[ x ] = true;
		}

		for (int lo = 1, hi = (int)1e6; lo < hi; ++lo, --hi)
		{
			if (used[lo] && used[hi])
			{
				cnt++;
			}
			else
			if (!used[lo] && !used[hi])
			{
				//
			} else
			{
				if (used[lo])
				{
					used[hi] = true;
					y.push_back(hi);
				}else
				if (used[hi])
				{
					used[lo] = true;
					y.push_back(lo);
				} 
			}
		}
		
		for (int lo = 1, hi = (int)1e6; lo < hi && cnt > 0; ++lo, --hi)
		{
			if (!used[lo] && !used[hi])
			{
				y.push_back(lo);
				y.push_back(hi);
				cnt--;
			}
		}
		
		assert(cnt == 0);
		
		printf( "%d\n", y.size() );
		for (int i = 0; i < y.size(); ++i)
			printf("%d ", y[i]);
		
		return 0;
	}
