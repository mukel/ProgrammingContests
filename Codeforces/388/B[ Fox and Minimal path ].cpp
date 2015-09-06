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
	MAXV = 1 << 10;

int V;
int tail, length;
vector< int > G[MAXV];

void addPath(int from, int to, int length)
{
	//cout << from << " " << to << " -> " << length << endl;
	int cur = from;
	for (int i: range(length - 1))
	{
		//cout << "(" << cur << ", " << V << ")" << endl;
		G[cur].push_back(V);
		G[V].push_back(cur);
		cur = V++;
	}//cout << "(" << cur << ", " << to << ")" << endl;
	G[cur].push_back(to);
	G[to].push_back(cur);
}

int main(int argc, char* argv[])
{
	if (argc > 1) freopen(argv[1], "r", stdin);
	if (argc > 2) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k; cin >> k;

	int hiBit = 31 - __builtin_clz(k);

	V = 2;
	for (int i = hiBit - 1; i >= 0; --i)
	{
		// times 2
		int nTail = V++;
		addPath(tail, nTail, 2);
		addPath(tail, nTail, 2);
		tail = nTail;
		length += 2;
		// plus 1
		if (k & (1 << i)) addPath(0, tail, length);
	}

	addPath(tail, 1, 1);

	cout << V << endl;

	for (int u: range(V))
	{
		string s = string(V, &#39;N&#39;);
		
		for (int v: G[u])
			s[v] = &#39;Y&#39;;

		cout << s << endl;
	}

	return 0;
}
