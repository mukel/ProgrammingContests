/*
Alfonso2 Peterssen
SPOJ #4568 "Rotating Rings"
7 - 8 - 2010
*/
#include <cstdio>
//#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;


#include <iostream>
using namespace std;


struct IO{
#define S inline IO& operator
#define P return*this
#define O(vt)S<<(register vt v){if(v<0){p('-');v=-v;}int i=0;do t[i++]=(v%10)+'0';while(v/=10);while(i)p(t[--i]);P;}
#define J(vt)S>>(vt&v){if(sb()){v=0;bool n=(*ip=='-');if(*ip=='-'||*ip=='+')ip++;char ch;while((ch=g())>' '){v*=10;v+=ch-'0';}if(n)v=-v;}P;}
const static int BL=1<<20;bool f;char t[BL],ib[BL],*ip,*ie,ob[BL],*op,*oe;void fb(){ie=ib+fread(ib,1,sizeof(ib),stdin);ip=ib;if(ie==ib)*ip='\0';}char g(){if(ip>=ie)fb();return*ip++;}bool sb(){for(;;){if(ip>=ie)fb();if(!*ip){f=true;return 0;}if(*ip>' ')return 1;ip++;}}void ff(){fwrite(ob,1,op-ob,stdout);op=ob;}IO(){f=false;fb();op=ob;oe=ob+sizeof(ob);}~IO(){ff();}S>>(char&v){if(!(v=g()))f=true;P;}S>>(char*b){if(sb())while((*b=g())>' ')b++;*b='\0';P;}S>>(string&s){if(*this>>t)s=string(t);P;}S<<(char v){p(v);P;}S<<(const char*b){while(*b)p(*b++);P;}S<<(const string&s){P<<s.c_str();}operator bool(){return!f;}void p(char v){if(op>=oe)ff();*op++=v;}O(int)O(unsigned int)O(long long)O(unsigned long long)J(int)J(unsigned int)J(long long)J(unsigned long long)
#undef S
#undef P
#undef O
#undef J
#define cin io
#define cout io
#define endl ('\n')
}io;


#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int MAXN = 1 << 10;

int mat[MAXN][MAXN];
int tmp[MAXN * MAXN];

int main()
{
	for (int test = 1;; test++)
	{
		int N;
		cin >> N; if (!N) break;

		REP(i, N)
			REP(j, N)
			{
			      cin >> mat[i][j];
				--mat[i][j];
			}
		
		REP(i, (N + 1) / 2)
		{
			int cnt = 0;
			for (int j = i; j < N - 1 - i; j++)	tmp[cnt++] = mat[i][j];
			for (int j = i; j < N - 1 - i; j++) tmp[cnt++] = mat[j][N - 1 - i];
			for (int j = N - 1 - i; j > i; j--) tmp[cnt++] = mat[N - 1 - i][j];
			for (int j = N - 1 - i; j > i; j--) tmp[cnt++] = mat[j][i];
			
			rotate(tmp, find(tmp, tmp + cnt, N * i + i), tmp + cnt);

			cnt = 0;
			for (int j = i; j < N - 1 - i; j++)	mat[i][j] = tmp[cnt++];
			for (int j = i; j < N - 1 - i; j++) mat[j][N - 1 - i] = tmp[cnt++];
			for (int j = N - 1 - i; j > i; j--) mat[N - 1 - i][j] = tmp[cnt++];
			for (int j = N - 1 - i; j > i; j--) mat[j][i] = tmp[cnt++];
		}

		int num = 0;

		bool ok = true;
		REP(i, N)
		REP(j, N)
		      if (mat[i][j] != num++)
		      {
				ok = false;
				break;
			}
			
		printf( "%d. %s\n", test, ok ? "YES" : "NO" );
	}

	return 0;
}
