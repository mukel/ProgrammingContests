	#include <bits/stdc++.h>
	using namespace std;
	
	int N, Q;
	int d[1 << 10];
	
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	
		
		scanf( "%d", &N );
		
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			int x;
			scanf("%d", &x);
			if (i == j)
				d[i] = x;
		}
		
		int ans = count(d, d + N, 1) & 1;
			
		scanf( "%d", &Q);
		while (Q--)
		{
			int op; scanf( "%d", &op );
			if (op <= 2)
			{
				int x;
				scanf( "%d", &x );
				ans ^= 1;
			} else
				printf("%d", ans);
		}
		
		printf("\n");
		
		return 0;
	}
