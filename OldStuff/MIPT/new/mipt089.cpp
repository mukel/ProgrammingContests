/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #89 "8-puzzle"
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
#include<ext/hash_map>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	offset[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

struct stringHasher
{
	int operator () (const string & s) const
	{
		int h = 0;
		REP(i, s.size()) h = h * 9 + (s[i] - '0');
		return h;
	}
};

__gnu_cxx::hash_map< string, char, stringHasher > D;

int main()
{
	string start;
	REP(i, 9)
	{
		string num;
		cin >> num;
		start += num;
	}
	
	D[start] = 0;
	
	queue< string > Q;
	for (Q.push(start); !Q.empty(); Q.pop())
	{
		string top = Q.front(); if (top == "123456780") break;
		int d = D[top];
		
		int pos = top.find('0');
		int x = pos / 3;
		int y = pos % 3;

		REP(i, 4)
		{
			int nx = x + offset[i][0];
			int ny = y + offset[i][1];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue ;
			int npos = nx * 3 + ny;
			
			swap(top[pos], top[npos]);
			if (!D.count(top))
			{
				D[top] = d + 1;
				Q.push(top);
			}
			swap(top[pos], top[npos]);
		}
	}
	
	if (D.count("123456780"))
		printf( "Yes\n%d\n", D["123456780"] );
	else
	      printf( "No\n" );

	return 0;
}
