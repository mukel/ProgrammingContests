/*
Alfonso2 Peterssen(mukel)
SPOJ #120 "Solitaire"
Bidirectional Search
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <tr1/unordered_set>

using namespace std;

typedef tr1::unordered_set< int > fastSet;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXC = 8,
	delta[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

// (int) casteable
struct state
{
	char pos[4];
	int x(int p) { return pos[p] >> 3; }
	int y(int p) { return pos[p] & 7; }
	void set(int p, int x, int y) { pos[p] = x * 8 + y; }
	void normalize() { sort(pos, pos + 4); }
};

fastSet bfs(state src)
{
	fastSet used;

	queue< state > now, next;
	now.push(src);

	REP(steps, 4)
	{
		for (;!now.empty(); now.pop())
		{
			state top = now.front();

			REP(i, 4) // ith piece
			REP(j, 4) // jth move
			{
				int nx = top.x(i) + delta[j][0];
   				int ny = top.y(i) + delta[j][1];
				if (nx < 0 || nx >= MAXC || ny < 0 || ny >= MAXC)
					continue ;
   				
   				bool jump = false;
   				REP(k, 4) if (nx == top.x(k) && ny == top.y(k))
				{
					jump = true;
					break;
				}

				if (jump)
				{
					nx += delta[j][0];
    					ny += delta[j][1];
					if (nx < 0 || nx >= MAXC || ny < 0 || ny >= MAXC)
						continue ;
						
					bool occup = false;
        				REP(k, 4) if (nx == top.x(k) && ny == top.y(k))
					{
						occup = true;
						break;
					}
					
					if (occup) continue ;
				}

				state t = top;
				t.set(i, nx, ny);
   				t.normalize();
   				
   				int tVal = *((int*)(&t));
   				
   				if (used.count(tVal))
					continue ;

				next.push(t);
   				used.insert(tVal);
			}
		}

		now = next;
	}
	
	return used;
}

state readState()
{
      state ret;
	REP(i, 4)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		x--;
		y--;
		ret.set(i, x, y);
	}
	ret.normalize();
	
	return ret;
}

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		fastSet f = bfs(readState()); // forward
		fastSet b = bfs(readState()); // backward

		bool reach = false;
		FOREACH(it, f) if (b.count(*it))
		{
			reach = true;
			break;
		}

		printf( "%s\n", reach ? "YES" : "NO" );
	}

	return 0;
}
