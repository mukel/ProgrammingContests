#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long int64;
#define endl ('\n')

const int
	MAXM = 1 << 18;

int N, K, A;
int M;
int x[MAXM];
int s[MAXM];

bool ok(int m) {	
	for (int i = 1; i <= N; ++i)
		s[i] = 0;

	for (int i = 0; i <= m; ++i)
		s[ x[i] ]++;

	int curStreak = 0;
	int total = 0;
	for (int i = 1; i <= N; ++i)
		if (s[i] > 0) {
			total += (curStreak+1) / (A+1);
			curStreak = 0;
		} else
			curStreak++;
	
	total += (curStreak+1) / (A+1);
	
	return total < K;
}

int main() {
	ios_base::sync_with_stdio(0);
	#ifndef LOCAL
		cin.tie(0);
	#endif

	cin >> N >> K >> A;	
	cin >> M;
	for (int i = 0; i < M; ++i)
		cin >> x[i];	

	int lo = 0, hi = M - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ok(mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	
	int ans = hi + 1;	
	if (ans >= M) cout << -1 << endl;
	else
		cout << ans+1 << endl;
	
	
	return 0;
}
