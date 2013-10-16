#include <iostream>
#include <cstring>

using namespace std;

const int
	MAXN = 105,
	MAXD = 10105;

double __dp[MAXN][2 * MAXD];

#define dp(i,j) __dp[(i)][(j) + MAXD]

int a[MAXN];
int p[MAXN];

int main()
{
	
	int T;
	for (cin >> T; T--;)
	{
		int N;
		cin >> N;
		
		memset(__dp, 0, sizeof(__dp));
		
		for (int i = 1; i <= N; ++i)
			cin >> a[i];
			
		for (int i = 1; i <= N; ++i)
			cin >> p[i];
			
		dp(0, 0) = 1;
		
		for (int i = 1; i <= N; ++i)
		{
			double r = p[i] * 0.01;
			
			for (int j = -10000; j <= +10000; ++j)
			{
				dp(i, j + a[i]) += dp(i - 1, j) * r;
				dp(i, j - a[i]) += dp(i - 1, j) * (1 - r);
			}
		}
		
		double ans = 0;
		for (int i = 0; i <= 10000; ++i)
			ans += dp(N, i);
			
		cout << ans << endl;
	}

	return 0;
} 
