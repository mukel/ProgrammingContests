#include <bits/stdc++.h>
using namespace std;


typedef long long int64;

const int64 MOD = 1000000007;

const int
	MAXN = 1 << 11,
	MAX_SUM = 1 << 20;

int K;
int a[MAXN];

int64 fact[MAX_SUM];
int64 inv[MAX_SUM];
int64 invFact[MAX_SUM];
int64 sum;
int64 ans;

int64 ways(int n, int k) {	
	return fact[n + k - 1] * invFact[n] % MOD * invFact[k - 1] % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	
	inv[1] = 1;
	for (int i = 2; i < MAX_SUM; ++i)
		inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
		
	fact[0] = invFact[0] = 1;
	
	for (int i = 1; i < MAX_SUM; ++i) {		
		fact[i] = fact[i - 1] * i % MOD;
		invFact[i] = invFact[i - 1] * inv[i] % MOD;
	}
	
	cin >> K;
	ans = 1;
	for (int i = 1; i <= K; ++i) {
		cin >> a[i];		
		ans = ans * ways(a[i] - 1, sum + 1) % MOD;
		sum += a[i];
	}
	
	cout << ans << endl;

	return 0;
}
