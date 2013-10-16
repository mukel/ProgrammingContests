/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #35 "Camelot"
*/
#include <cstdio>
#include <iostream>

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

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int
	MAXC = 52,
	MAXK = 200,
	offset[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

int C, K;
int kX, kY;
struct point
{
	int x, y;
} knights[MAXK];

int dist[MAXC][MAXC][MAXC][MAXC];
int val[MAXC];

queue< point > Q;

void BFS(int srcX, int srcY, int dist[MAXC][MAXC])
{
	for (Q.push((point){srcX, srcY}), dist[srcX][srcY] = 0; !Q.empty(); Q.pop())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		REP(i, 8)
		{
			int nx = x + offset[i][0];
			int ny = y + offset[i][1];
			if (nx < 0 || nx >= C || ny < 0 || ny >= C) continue ;
			if (dist[nx][ny] < 0)
			{
				dist[nx][ny] = dist[x][y] + 1;
				Q.push((point){nx, ny});
			}
		}
	}
}

int main()
{
	scanf( "%d %d %d %d", &C, &K, &kX, &kY );
	kX--;
	kY--;
	
	REP(i, K)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		x--;
		y--;
		knights[i].x = x;
		knights[i].y = y;
	}

	memset(dist, -1, sizeof(dist));
	REP(i, C)
	REP(j, C)
	      BFS(i, j, dist[i][j]);
	      
	REP(i, C) val[i] = i;
	random_shuffle(val, val + C);

	int ans = (int)1e9;
	REP(a, C)
	REP(b, C) // (x1, y1) sink point
	{
		int x1 = val[a];
		int y1 = val[b];

		int kMoves = 0;
		REP(i, K)
			kMoves += dist[ knights[i].x ][ knights[i].y ][x1][y1];
		
		ans = min(ans, kMoves + max(abs(kX - x1), abs(kY - y1)));
		
		if (kMoves - 80 > ans) continue ;
		
		REP(x2, C)
		REP(y2, C) // (king + knight)
		{
			if (abs(kX - x2) + abs(kY - y2) >= 40) continue ;
			REP(i, K)
			{
				int tmp = kMoves -
					dist[ knights[i].x ][ knights[i].y ][x1][y1] +
					dist[ knights[i].x ][ knights[i].y ][x2][y2] +
					max(abs(kX - x2), abs(kY - y2)) +
					dist[x1][y1][x2][y2];
				
				if (tmp < ans)
				      ans = tmp;
			}
		}
	}
	
	printf( "%d\n", ans );

	return 0;
}
