#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef long long int64;

#define endl &#39;\n&#39;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)n; ++i)

const int
	MAXN = 1 << 17;

int N;
multiset< pair< int, int > > S[2];


int data[MAXN];

int find(int x)
{
	return (data[x] < 0) ? x : data[x] = find(data[x]);
}

int getSize(int x)
{
	return -data[ find(x) ];
}

void unite(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v) return ;

	if (getSize(u) < getSize(v))
		swap(u, v);

	data[u] += data[v];
	data[v] = u;
}

struct edge
{
	int u, v, w;
};
vector< edge > edges;

int color[MAXN];

int main()
{
	ios::sync_with_stdio(0);

	memset(data, -1, sizeof(data));

	cin >> N;
	REP(i, N)
	{
		int c, w;
		cin >> c >> w;

		color[i] = c;

		if (w > 0)
			S[c].insert(make_pair(w, i));
	}

	while (!S[0].empty() && !S[1].empty())
	{
		auto w0 = *S[0].begin(); S[0].erase(S[0].begin());
		auto w1 = *S[1].begin(); S[1].erase(S[1].begin());

		int edgeCost = min(w0.first, w1.first);
		edges.push_back((edge){w0.second, w1.second, edgeCost});

		unite(w0.second, w1.second);

		w0.first -= edgeCost;
		w1.first -= edgeCost;

		if (w0.first > 0) S[0].insert(w0);
		if (w1.first > 0) S[1].insert(w1);
	}





	REP(i, N) if (i > 0)
		if (color[i] != color[0] && find(i) != find(0))
		{
			unite(i, 0);
			edges.push_back((edge){0, i, 0});
		}

	REP(i, N) if (color[i] != color[0] && find(i) == find(0))
	{
		REP(j, N) if (color[j] != color[i] && find(i) != find(j))
		{
			unite(i, j);
			edges.push_back((edge){i, j, 0});
		}
		break;
	}


	for (auto e : edges)
		cout << e.u + 1 << " " << e.v + 1 << " " << e.w << endl;

	return 0;
}
