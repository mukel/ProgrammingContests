// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/*inclusive*/template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e+1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

typedef long long int64;

#define all(c) (c).begin(), (c).end()
#define take(c,n) (c).begin(), (c).begin() + (n)
#define drop(c,n) (c).begin() + (n), (c).end()

const int
	MAXP = 1 << 10;

int P;
int ciel;
int sum;
vector< int > piles[MAXP];

int main(int argc, char* argv[])
{
	if (argc > 1) freopen(argv[1], "r", stdin);
	if (argc > 2) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> P;
	for (int i: range(P))
	{
		int len; cin >> len;
		for (int j: range(len))
		{
			int x; cin >> x;
			sum += x;
			piles[i].push_back(x);
		}
	}

	auto rem = vector< int >();

	for (int i: range(P))
	{
		int lo = 0, hi = (int)piles[i].size() - 1;
		for (; lo < hi; ++lo, --hi)
			ciel += piles[i][lo];
		if (lo == hi)
			rem.push_back(piles[i][lo]);
	}

	sort(all(rem));
	for (int i = (int)rem.size() - 1; i >= 0; i -= 2)
		ciel += rem[i];

	cout << ciel << " " << sum - ciel << endl;

	return 0;
}