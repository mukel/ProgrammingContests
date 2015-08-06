#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long int64;
#define endl ('\n')

int N;
bool inside[1 << 20];

int main() {
	ios_base::sync_with_stdio(0);
	#ifndef LOCAL
		cin.tie(0);
	#endif	
	
	cin >> N;	
	
	int maxDelta = 0;
	int minDelta = 0;
	int delta = 0;
	int before = 0;
	for (int i = 0; i < N; ++i) {
		string op;
		int id;
		cin >> op >> id;
		if (op == "+") {
			inside[id] = true;
			delta++;
		}
		else {
			delta--;
			if (!inside[id]) before++;
			inside[id] = false;
		}
		
		maxDelta = max(maxDelta, delta);
		minDelta = max(minDelta, delta);
	}
	
	int after = 0;
	for (int i = 1; i <= 1000000; ++i)
		after += inside[i];
	
	cout << max(before + maxDelta, after) << endl;
	
	return 0;
}
