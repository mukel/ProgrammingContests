/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #86 "Anti-factorial"
*/
#include <iostream>
#include <cmath>

using namespace std;
int ans;

int main()
{
	string f; cin >> f;
	if (f == "1") ans = 1; else
	if (f == "2") ans = 2; else
	if (f == "6") ans = 3; else
	if (f == "24") ans = 4; else
	if (f == "120") ans = 5; else
	if (f == "720") ans = 6; else
	{
		for (double l = 0; l < f.size(); l += log10(++ans));
		ans--;
	}
	
	cout << ans << endl;

	return 0;
}
