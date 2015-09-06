/*
Alfonso2 Peterssen(mukel)
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

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXSQ = 1 << 10;

struct state
{
	int x; bool used;
};


int N;
int boxCount;

int offset[MAXSQ];
int64 sum[MAXSQ][5];
vector< state > boxes[MAXSQ];
map< int, int > getBox;
int compr[1 << 17];

struct query
{
	char op;
	int value;
} queries[1 << 17];

void update(int b)
{
	REP(i, 5) sum[b][i] = 0;
	
	int cnt = 0;
	REP(i, SZ(boxes[b]))
	{
		if (boxes[b][i].used)
		{
			sum[b][cnt % 5] += boxes[b][i].x;
			cnt++;
		}
	}
}

void add(int x)
{
	int box = getBox[x];
	
//	printf( "-> add %d -> box %d\n", x, box );
	
	for (int i = box + 1; i < boxCount; i++)
	{
		offset[i]++;
	}
	
	REP(i, SZ(boxes[box]))
		if (boxes[box][i].x == x)
	      {
			boxes[box][i].used = 1;
			break;
		}

	update(box);
}

void del(int x)
{
	int box = getBox[x];
	for (int i = box + 1; i < boxCount; i++)
	{
		offset[i]--;
	}
	
	REP(i, SZ(boxes[box]))
	      if (boxes[box][i].x == x)
	      {
			boxes[box][i].used = 0;
			break;
		}
	
	update(box);
}

int64 getSum()
{
	int64 medSum = 0;
	REP(i, boxCount)
	{
		int d = (2 - offset[i]) % 5;
		d = (d + 5) % 5;
		medSum += sum[i][d];
	}
	return medSum;
}

char op[1 << 4];

int main()
{
	int Q;
	scanf( "%d", &Q );
	REP(i, Q)
	{
		scanf( "%s", &op );
		if (op[0] == &#39;a&#39;)
		{
			int x; scanf( "%d", &x );
			queries[i] = (query){&#39;a&#39;, x};
			compr[N++] = x;
		}
		if (op[0] == &#39;d&#39;)
		{
			int x; scanf( "%d", &x );
			queries[i] = (query){&#39;d&#39;, x};
		}
		if (op[0] == &#39;s&#39;)
		{
			queries[i] = (query){&#39;s&#39;, 0};
		}
	}
	
	sort(compr, compr + N);
	
	N = unique(compr, compr + N) - compr;
	
	int sq = sqrt(N) + 2;
	
//	printf( "sq -> %d\n", sq );
	
	int pos = 0;
	while (pos < N)
	{
		for (int j = 0; j < sq && pos < N; j++)
		{
			int x = compr[pos];
			getBox[x] = boxCount;
			boxes[boxCount].push_back((state){x, false});
			pos++;
		}
		boxCount++;
	}

	REP(i, Q)
	{
		if (queries[i].op == &#39;a&#39;) add(queries[i].value);
		if (queries[i].op == &#39;d&#39;) del(queries[i].value);
		if (queries[i].op == &#39;s&#39;) cout << getSum() << endl;
	}

	return 0;
}


