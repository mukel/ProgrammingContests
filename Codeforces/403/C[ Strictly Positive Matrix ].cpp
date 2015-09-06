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
	MAXN = 2000;

int N;
int cnt;
int m[MAXN][MAXN];
bool mark[MAXN];

void dfs(int u)
{
	cnt++;
	mark[u] = true;
	for (int v : range(N))
		if (!mark[v] && m[u][v])
			dfs(v);
}

int main(int argc, char* argv[])
{
	if (argc > 1) freopen(argv[1], "r", stdin);
	if (argc > 2) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i : range(N))
	for (int j : range(N))
		cin >> m[i][j];
		
	dfs(0);

	fill(mark, mark + N, false);
	
	for (int i : range(N))
	for (int j : range(i))
		swap(m[i][j], m[j][i]);

	dfs(0);

	cout << ((cnt == 2*N) ? "YES" : "NO") << endl;
		
	return 0;
}

