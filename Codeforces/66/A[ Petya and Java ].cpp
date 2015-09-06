/*
 * Alfonso2 Peterssen(mukel)
 * Codeforces Round #61 (Div. 2)
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin, (c).end()
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define FOR(i, b, e) for (int (i) = (int)(b); (i) <= (int)(e); ++(i))

bool isLess(string a, string b)
{
	if (a[0] == &#39;-&#39; && b[0] == &#39;-&#39;)
		return isLess(b.substr(1, b.size() - 1), a.substr(1, a.size() - 1));

	if (a[0] == &#39;-&#39;) return 1;
	if (b[0] == &#39;-&#39;) return 0;
	
	if (a.size() != b.size())
		return a.size() < b.size();
		
	return a < b;
}

bool fit(string x, string lo, string hi)
{
	return !isLess(x, lo) && !isLess(hi, x);
}

int main()
{
	string x;
	cin >> x;
	
	if (fit(x,"-128", "127")) printf( "byte" );
	else
	if (fit(x, "-32768", "32767")) printf( "short" );
	else
	if (fit(x, "-2147483648", "2147483647")) printf( "int" );
	else
	if (fit(x, "-9223372036854775808", "9223372036854775807")) printf( "long" );
	else
		printf( "BigInteger" );
	
	return 0;
}
