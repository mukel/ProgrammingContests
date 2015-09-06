/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #86 (Div. 1 Only)
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <tr1/unordered_set>

using namespace std;

typedef unsigned long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)

const int
	MAXL = 1 << 13;
	
char S[MAXL];
char beg[MAXL];
char end[MAXL];
int ocBeg[MAXL];
int ocEnd[MAXL];

const int64 BASE = 537;

int64 hash[MAXL];
int64 basePow[MAXL];

tr1::unordered_set< int64 > ss;

int main()
{
	scanf( "%s %s %s", &S, &beg, &end );
	
	int b = strlen(beg);
	int e = strlen(end);
	
	
	
	for (int i = 0; S[i]; ++i)
	{
		int k;
		for (k = 0; S[k + i] && beg[k] && S[k + i] == beg[k]; ++k);
		if (k == b)
			ocBeg[i]++;
	}

	for(int i = 0; S[i]; ++i)
	{
		int k;
		for (k = 0; S[k + i] && end[k] && S[k + i] == end[k]; ++k);
		if (k == e)
		      ocEnd[i + k - 1]++;
	}
	
	hash[0] = S[0];
	basePow[0] = 1;
	for (int i = 1; S[i]; ++i)
	{
		hash[i] = (hash[i - 1] * BASE) + S[i];
		basePow[i] = basePow[i - 1] * BASE;
	}
	
	for(int i = 0; S[i]; ++i)
	for(int j = i + max(e, b) - 1; S[j]; ++j)
	      if (ocBeg[i] && ocEnd[j])
	      {
			//cout << string(S + i, S + j + 1) << endl;
			ss.insert(hash[j] - ((i ? hash[i - 1] : 0) * basePow[j - i + 1]));
		}
	
	cout << ss.size() << endl;

	return 0;
}

