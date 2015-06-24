/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1261. Tips
*/
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long int64;

const int MAXP = 16;

int64 N, A, B;
int64 pow3[MAXP];

int main()
{
	pow3[0] = 1;
	for (int i = 1; i < MAXP; i++)
	      pow3[i] = pow3[i - 1] * 3;

	cin >> N;
	
	int pos = 0;
	while (N > 0)
	{
		if (N % 3 == 1)
			A += pow3[pos];
		else
		if (N % 3 == 2)
		{
			N += 3;
			B += pow3[pos];
		}
		pos++;
		N /= 3;
	}
	
	if (B == 0)
	{
		A += pow3[MAXP - 1];
		B += pow3[MAXP - 1];
	}
	cout << A << " " << B << endl;

	return 0;
}
