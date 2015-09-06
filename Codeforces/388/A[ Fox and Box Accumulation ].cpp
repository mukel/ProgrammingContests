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

int N;
int x[1 << 10];

int main(int argc, char* argv[])
{
	if (argc > 1) freopen(argv[1], "r", stdin);
	if (argc > 2) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i: range(N))
		cin >> x[i];

	sort(x, x + N);

	cout << lower_bound(all(range(1, N)), -1,
		[](int value, int pp)
		{
			for (int i: range(N))
				if (x[i] < i/value)
					return true;
			return false;
		}
	) << endl;

	return 0;
}