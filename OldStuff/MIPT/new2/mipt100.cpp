/*
Alfonso2 Peterssen(mukel)
MIPT #100 "Nim Game -- who is the winner?"
*/
#include <cstdio>
#include <iostream>

using namespace std;

int N, nimSum, x;

int main()
{
	for (cin >> N; N--;)
	{
		cin >> x;
		nimSum ^= x;
	}

	if (nimSum) cout << "First"; else cout << "Second";
	cout << " wins.";
	
	return 0;
}
