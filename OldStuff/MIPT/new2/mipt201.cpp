/*
Alfonso2 Peterssen(mukel)
MIPT #201 "Number of solutions"
*/
#include <iostream>

using namespace std;

typedef long long int64;

int N;
int64 ans;
int cant[1 << 21];

int main()
{
	cin >> N;
	
	for (int i = 0; i <= N; i++)
	for (int j = 0; 2 * j + i <= N; j++)
	      cant[2 * j + i]++;
	      
	for (int i = 0; 3 * i <= N; i++)
	for (int j = 0; 4 * j + 3 * i <= N; j++)
		ans += cant[N - (4 * j + 3 * i)];
	      
	cout << ans << endl;
	
	return 0;
}
