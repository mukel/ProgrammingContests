	#include <iostream>
	#include <cstring>

	using namespace std;

	const int
		MAXN = 50,
		MOD = 1000000007;

	int upper, d, m, N;

	int modPow(int a, int d)
	{
		if (d == 0) return 1 % N;
		int r = modPow(a, d / 2);
		r = r * r % N;
		if (d % 2)
			r = r * a % N;
		return r;
	}

	long long cnt[MAXN];

	int main()
	{	
		
		int T;
		for (cin >> T; T--;)
		{
			cin >> upper >> d >> m >> N;
			
			memset(cnt, 0, sizeof(cnt));

			for (int i = 0; i < N && i <= upper; ++i)
			{
				int xd = modPow(i, d);
				
				cnt[xd] += upper / N;
				
				if (i <= upper % N)
					cnt[xd]++;
			}
			
			for (int i = 0; i < N; ++i)
				cnt[i] %= MOD;

			long long ans = 0;
			for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				if ((i + j + k) % N == m % N)
			{
				ans = ans + cnt[i] * cnt[j] % MOD * cnt[k] % MOD;
				ans %= MOD;
			}
			
			cout << ans << endl;
		}

		return 0;
	} 
