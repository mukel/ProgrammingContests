/*
	Alfonso2 Peterssen (mukel)
	VK Cup 2012 Qualification Round 1
*/
#include <iostream>

using namespace std;

int N, cnt[5];

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x; cin >> x;
		cnt[x]++;
	}
	
	int ans = cnt[4];
	while (cnt[2] >= 2) cnt[2] -= 2, ans++;
	while (cnt[1] && cnt[3]) cnt[1]--, cnt[3]--, ans++;
	
	while (cnt[1] >= 2 && cnt[2]) cnt[1] -= 2, cnt[2]--, ans++;
	
	if (cnt[1] == 1 && cnt[2]) cnt[1]--, cnt[2]--, ans++;
	while (cnt[1]) cnt[1] -= min(cnt[1], 4), ans++;
	
	ans += cnt[3];
	ans += cnt[2];
	
	cout << ans << endl;

	return 0;
}
