/*
	Alfonso2 Peterssen (mukel)
	VK Cup 2012 Qualification Round 1
*/
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 6;

int N, K;
int score[MAXN];

int main()
{
	cin >> N >> K;
	REP(i, N) cin >> score[i];
	
	int i = 0;
	while (i < N && score[i] > 0 && score[i] >= score[K - 1])
		++i;

	cout << i << endl;

	return 0;
}
