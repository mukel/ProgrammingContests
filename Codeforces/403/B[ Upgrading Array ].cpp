// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/*inclusive*/template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e+1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

typedef long long int64;

#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

const int
	MAXN = 5005;
	
int N, M;
int a[MAXN];
int b[MAXN];
int g[MAXN];
int sum;
int best;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

bool isBad(int p)
{
	return binary_search(b, b + M, p);
}

vector< int > factorize(int n)
{
	vector< int > r;
	for (int i = 2; i *i <= n; ++i)
	{
		while (n % i == 0)
		{
			r.push_back(i);
			n /= i;
		}
	}
	
	if (n > 1) r.push_back(n);
	
	return r;
}

int main(int argc, char* argv[])
{
	if (argc > 1) freopen(argv[1], "r", stdin);
	if (argc > 2) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i : range(N))
		cin >> a[i];
		
	for (int i : range(M))
		cin >> b[i];
		
	sort(b, b + M);
	
	for (int i : range(N))
	{
		//cerr << "factor " << a[i] << " -> ";
		for (int p : factorize(a[i]))
		{
			//cerr << p << " ";
			if (isBad(p)) sum--; else sum++;
		}
		//cerr << endl;
	}
	
	//cerr << sum << endl;
	
	best = sum;
	
	g[0] = a[0];
	for (int i : range(N))
	{
		if (i) g[i] = gcd(g[i - 1], a[i]);
	}
	
	for (int i = N - 1; i >= 0; --i)
	{
		//cerr << (i+1) << " g " << g[i] << endl;
	
		int t = 0;
		for (int p : factorize(g[i]))
		{
			if (isBad(p)) t--; else t++;
		}

		best = max(best, sum - (i+1)*t);
		best = max(best, sum);
		
		if (t < 0)
		{
			//cerr << "remove " << g[i] << " on " << i+1 << endl;
		
			sum -= (i+1)*t;
			
			for (int j = i-1; j >= 0; --j)
				g[j] /= g[i];
		}
	}
	
	cout << best << endl;

	return 0;
}

