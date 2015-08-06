#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long int64;
#define endl ('\n')

const int
	MAXN = 1 << 18;

int N;
long long K;
int a[MAXN];
int cntL[MAXN];
int cntR[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	#ifndef LOCAL
		cin.tie(0);
	#endif	
	
	map<long long, int> cnt;
	
	
	long long ans = 0;
	
	cin >> N >> K;	
	for (int i = 0; i < N; ++i)
		cin >> a[i];
		
	for (int i = 0; i < N; ++i) {
		if (a[i] % K == 0)
			cntL[i] = cnt[ a[i] / K ];
		++cnt[ a[i] ];
	}
	
	cnt.clear();
	
	for (int i = N - 1; i >= 0; --i) {
		cntR[i] = cnt[ a[i] * K ];
		++cnt[ a[i] ];
	}
	
	for (int i = 0; i < N; ++i)	
		ans += cntL[i] * (1LL) * cntR[i];
	
	cout << ans << endl;	
	
	return 0;
}
