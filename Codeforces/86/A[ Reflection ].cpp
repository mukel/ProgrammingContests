/*
Alfonso2 Peterssen(mukel)
Yandex Round 2
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
//#include <tr1/unordered_set>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

int64 reflection(int64 n)
{
	int64 p = 1, ref = 0;
	while(n)
	{
		ref += p * (9 - (n % 10));
		n /= 10;
		p *= 10;
	}
	return ref;
}

int64 function(int64 n)
{
	int64 ans = n;

	return reflection(ans) * ans;
}

int64 find(int64 lo, int64 hi)
{
	int64 ans = 0;
	for(int64 i = lo; i <= hi; i++)
		ans = max(ans, function(i));
	return ans;
}

int64 check(int64 lo, int64 hi, int d)
{
	int64 p = 1; REP(i, d - 1)p *= 10;
	
	int64 vlo = lo / p, vhi = hi / p;
	
	if(vhi < 5)return hi;
	if(vlo > 4)return lo;
	return p * 5;
	
//	cout << "Min " << lo << " Max " << hi << " Amount " << d << endl;
	int64 n = lo;


	
//cout << "Start p " << p << endl;
	REP(i, d)
 	{
//		val = (n % (p * 10)) / p;

//		cout << "N " << n << " VAL " << val << " P " << p << endl;
				
//		if(val < 4)
//			while(n + p <= hi && val < 4)n += p, val++;
//		if(val > 5)
//			while(n - p >= lo && val > 5)n -= p, val--;
		
		p /= 10;
	}
	cout << "Este es el numero " << n << endl;
	return n;
}

int main()
{
//	while(1){

	int64 lo, hi;
	int64 ans;
	
	cin >> lo >> hi;
	
	if(hi <= 10)
		ans = find(lo, hi);
	else
	{
		int64 p = 1, d = 1;
		while(p * 10 <= hi)p *= 10, d++;
		lo = max(lo, p);
		//review
		
		ans = check(lo, hi, d);
//			cout << "Este es el numero " << ans << endl;
		ans = function(ans);
	}
	
	cout << ans << endl;
//}
//	system("pause");
	return 0;
}
