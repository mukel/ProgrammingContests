/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #45 "Picture segments"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair< int, int > point;
#define xx first
#define yy second

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

typedef unsigned short	int16u;
typedef int		int32s;
typedef unsigned	int32u;

#pragma pack (push,2)
struct file_header {
	int16u		type;
	int32u		size;
	int16u		reserved1;
	int16u		reserved2;
	int32u		offbits;
} bf;

struct info_header {
	int32u		size;
	int32s		width;
	int32s		height;
	int16u		planes;
	int16u		bit_count;
	int32u		compression;
	int32u		size_image;
	int32s		x_pels_per_meter;
	int32s		y_pels_per_meter;
	int32u		clr_used;
	int32u		clr_important;
} bi;
#pragma pack (pop)

const int
	MAXN = 1026;
	
const int
	offset[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int ans;
int mat[MAXN][MAXN];
int brg;

int main()
{
	//freopen("a.bmp", "r", stdin);
	
	fread(&bf, sizeof(bf), 1, stdin);
	fread(&bi, sizeof(bi), 1, stdin);

	REP(i, bi.height)
	{
		REP(j, bi.width)
		{
			fread(&brg, 3, 1, stdin);
	            mat[i][j] = brg;
		}
	      if (bi.width % 4)
			fread(&brg, bi.width % 4, 1, stdin);
	}
	
	REP(i, bi.height)
	REP(j, bi.width)
		if (mat[i][j] >= 0)
		{
			int curColor = mat[i][j];
			ans++;

			queue< point > Q;
			for (Q.push(point(i, j)); !Q.empty(); Q.pop())
			{
				point top = Q.front();
				REP(k, 4)
				{
					int nx = top.xx + offset[k][0];
					int ny = top.yy + offset[k][1];
					
					if (nx < 0 || nx >= bi.height || ny < 0 || ny >= bi.width || mat[nx][ny] != curColor)
					      continue ;
					      
					mat[nx][ny] = -1;
					Q.push(point(nx, ny));
				}
			}
		}

	printf( "%d\n", ans );

	return 0;
}
