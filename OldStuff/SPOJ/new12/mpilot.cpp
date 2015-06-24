/*
Alfonso2 Peterssen
SPOJ #4259 "Pilots"
9 - 8 - 2010
*/
#include <cstdio>
#include <iostream>
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


const int
	MAXN = 1 << 15;

int N, cap, ass;
int dp[2][MAXN + 1];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> cap >> ass;
		for (int j = 0; j <= i; ++j)
		{
			dp[i & 1][j] = (int)1e9;
			if (j < i - 1)
				dp[i & 1][j] = dp[i & 1 ^ 1][j + 1] + cap;
			if (j > 0)
				dp[i & 1][j] = min(dp[i & 1][j], dp[i & 1 ^ 1][j - 1] + ass);
		}
	}

	cout << dp[N & 1][0] << endl;

	return 0;
}
