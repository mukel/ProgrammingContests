#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int64;

const int
	DELTA = 1 << 18;


int64 val[2 * DELTA];
int64 sum;

void update(int x, int lo, int hi, int from, int to, int64 value)
{
	if (lo > hi || lo > to || hi < from)
		return ;
	int mid = (lo+hi) / 2;
	if (lo == from && hi == to)
	{
		val[x] += value;
		return ;
	}

	update(2 * x, lo, mid, from, min(mid, to), value);
	update(2 * x + 1, mid + 1, hi, max(mid + 1, from), to, value);
}

int64 result;

void query(int x, int lo, int hi, int pos)
{
	if (lo > pos || hi < pos)
		return ;

	int mid = (lo +hi) / 2;

	result += val[x];

	if (lo == hi) return ;

	query(2 * x, lo, mid, pos);
	query(2 * x + 1, mid + 1, hi, pos);
}

int main() {

	int N;
	cin >> N;

	int elemCount = 1;

	for (int i = 0; i < N; ++i)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int a, k;
			cin >> a >> k;
			update(1, 1, DELTA, 1, a, k);
			sum += k * (int64)a;
		}
		else
		if (op == 2)
		{
			int k;
			cin >> k;
			elemCount++;
			update(1, 1, DELTA, elemCount, elemCount, k);
			sum += k;
		}
		else
		if (op == 3)
		{
			result = 0;
			query(1, 1, DELTA, elemCount);
			update(1, 1, DELTA, elemCount, elemCount, -result);
			sum -= result;
			elemCount--;
		}

		printf( "%.10lf\n", sum / (double)elemCount );
	}
	return 0;
}
