/*
Alfonso2 Peterssen (mukel)
COCI 2012 Contest #4
Task: KRIPTOGRAM
Hashing(=42) solves everything!!!
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long hash;

const int
	MAXN = 1 << 20;

const hash
	BASE = 1007;

vector< string > A, B;
char buf[MAXN];
hash hA, hB, hPow[MAXN];
map< string, int > lastPos;
int next[MAXN];

int main()
{
	hPow[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		hPow[i] = hPow[i - 1] * BASE;

	while (scanf( "%s", buf ), buf[0] != '$')
		A.push_back(buf);

	while (scanf( "%s", buf ), buf[0] != '$')
		B.push_back(buf);

	for (int i = 0; i < B.size(); ++i)
	{
		hB *= BASE;
		if (lastPos.count(B[i]))
			hB += (i - lastPos[ B[i] ]);
		lastPos[ B[i] ] = i;
	}

	lastPos.clear();

	for (int i = 0; i < A.size(); ++i)
	{
		hA *= BASE;
		if (lastPos.count(A[i]) && lastPos[ A[i] ] > i - (int)B.size())
		{
			next[ lastPos[ A[i] ] ] = i;
			hA += (i - lastPos[ A[i] ]);
		}
		lastPos[ A[i] ] = i;
		int p = i - (int)B.size();
		if (p >= 0 && next[p]) hA -= (next[p] - p) * hPow[i - next[p]];
		if ((int)(i - B.size() + 2) > 0 && hA == hB)
		{
			printf( "%d\n", i - B.size() + 2 );
			break;
		}
	}

	return 0;
}
