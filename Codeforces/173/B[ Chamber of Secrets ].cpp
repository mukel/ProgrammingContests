// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	delta[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

const int
	MAXN = 1005;

int R, C;
struct state
{
	int x, y, dir;
};
char mat[MAXN][MAXN];
int dist[MAXN][MAXN][4];

int main()
{
	scanf( "%d %d", &R, &C );
	REP(i, R)
		scanf( "%s", &mat[i] );

	queue< state > Q;

	dist[0][0][2] = 1;
	Q.push((state){0, 0, 2});

	while (!Q.empty())
	{
		state top = Q.front();
		Q.pop();

		//printf( "%d %d %d\n", top.x, top.y, top.dir );

		int nx = top.x + delta[top.dir][0];
		int ny = top.y + delta[top.dir][1];
		int ndir = top.dir;

		if (!(nx < 0 || nx >= R || ny < 0 || ny >= C))
		{
			if (!dist[nx][ny][ndir])
			{
				dist[nx][ny][ndir] = dist[top.x][top.y][top.dir];
				Q.push((state){nx, ny, ndir});
			}
		}

		if (mat[top.x][top.y] == &#39;#&#39;)
		REP(ndir, 4)
		{
			int nx = top.x;
			int ny = top.y;
			if (!(nx < 0 || nx >= R || ny < 0 || ny >= C))
			{
				if (!dist[nx][ny][ndir])
				{
					dist[nx][ny][ndir] = dist[top.x][top.y][top.dir] + 1;
					Q.push((state){nx, ny, ndir});
				}
			}
		}
	}

	int ans = dist[R - 1][C - 1][2] - 1;
	printf( "%d\n", ans );

	return 0;
}
