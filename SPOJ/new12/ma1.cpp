/*
Alfonso2 Peterssen
SPOJ #4160 "A1 Road"
9 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>

using namespace std;

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

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 1 << 17;

int N, M;
int a[MAXN], pos[MAXN];

int main()
{
	cin >> M >> N;
	REP(i, N)
	{
		cin >> pos[i];
		pos[i]--;
	}

	int b = 1;
	for (int i = 1; i < N; i++)
		if (pos[i] - pos[i - 1] < M)
		{
			a[(pos[i - 1] + 1) % M]++;
			a[(pos[i] + 1) % M]--;
			if (pos[i - 1] / M != pos[i] / M)
				b++;
		} else
			b++;

	a[0] = b;
	for (int i = 1; i < M; i++)
		a[i] += a[i - 1];
	 	
	int ans = *min_element(a, a + M);
	 
	cout << ans << endl;
	REP(i, M)
		if (a[i] == ans)
			cout << i + 1 << " ";
			
	cout << endl;

	return 0;
}
