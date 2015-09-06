#include <iostream>
using namespace std;

string S;
int pos;

int main() {

	cin >> S;
	for (int i = 0; i < S.size(); ++i)
		if (S[i] == &#39;0&#39;)
		{
			pos = i;
			break;
		}

	for (int i = 0; i < S.size(); ++i)
		if (i != pos) cout << S[i];

	cout << endl;

	return 0;
}
