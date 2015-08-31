#include <bits/stdc++.h>
using namespace std;

int N;
int a[1 << 17];

int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		while (a[i] % 2 == 0) a[i] /= 2;
		while (a[i] % 3 == 0) a[i] /= 3;		
	}
	
	for (int i = 0; i < N; ++i)
				if (a[i] != a[0]) {
					cout << "No" << endl;
					return 0;
				}
				
	cout << "Yes" << endl;
	
	return 0;
}
