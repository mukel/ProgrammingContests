/*
Alfonso2 Peterssen(mukel)
SPOJ #3981 "Shortest Regular Bracket"
*/
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXN = 1 << 17;

deque< int > S;

char buf[3 * MAXN];
int l = MAXN - 1, r = MAXN;

int match(char a, char b)
{
	return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int insert(bool right, char br)
{
	int cost = 0;
	if (right)
	{
		if (S.empty() || !match(buf[S.back()], br)) S.push_back(r);
		else
		{
			cost = abs(r - S.back()) + 1;
			S.pop_back();
		}
		buf[r++] = br;
	}
	else
	{
		if (S.empty() || !match(br, buf[S.front()])) S.push_front(l);
		else
		{
			cost = abs(l - S.front()) + 1;
			S.pop_front();
		}
		buf[l--] = br;
	}
	return cost;
}

int main()
{
	scanf( "%s", &buf );
	for (int i = 0; buf[i]; i++) insert(1, buf[i]);

	int Q;
	for (scanf( "%d", &Q ); Q--;)
	{
		int op; char br[10];
		scanf( "%d %s", &op, &br );
		printf( "%d\n", insert(op, br[0]) );
	}

	return 0;
}
