#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int K, sum;
char S[1 << 20];
int dp[1 << 20];
long long ans;
int main(){
	scanf("%d %s", &K, S);
	dp[0] = 1;
	for (int i = 0; S[i]; ++dp[sum], ++i)
		if ((sum += (S[i] - '0'))>= K)ans += dp[sum] - K;
	cout << ans << endl;
	return 0;
}
