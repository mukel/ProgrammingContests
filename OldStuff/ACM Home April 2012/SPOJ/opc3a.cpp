#include <cstdio>
#include <cstring>
const int MOD = (int)1e9+7;
struct m22{long long a[2][2];};
m22 mul(m22 & a, m22 & b, int m)
{
m22 r;
memset(&r, 0, sizeof(r));
for (int i = 0; i < 2; ++i)
for (int j = 0; j < 2; ++j)
for (int k = 0; k < 2; ++k)
r.a[i][j] = (r.a[i][j] + (a.a[i][k] * b.a[k][j])) % m;
return r;
}
m22 I()
{
m22 x;
x.a[0][0] = x.a[1][1] = 1;
x.a[0][1] = x.a[1][0] = 0;
return x;
}
m22 mpm(m22 & a, int n, int m){
if (!n) return I();
m22 r = mpm(a,n/2,m);
r=mul(r, r, m);
if (n&1) r=mul(r,a,m);
return r;
}
int fm(int n, int m){
m22 x;x.a[0][0] = x.a[0][1] = x.a[1][0] = 1;
x.a[1][1]=0;return mpm(x,n,m).a[0][0];
}
int powMod(int a, int n, int m){
if(!n)return 1;
long long r=powMod(a,n/2,m);
r=(r*r)%m;
if(n&1)r=(r*a)%m;
return r;
}
int main()
{
int T;for(scanf("%d",&T);T--;){
int N;scanf("%d",&N);
if (!N) printf("1\n"); else
{
int f = fm(N-1,MOD/2);
printf("%d\n", powMod(2,f,MOD));
}
}
return 0;
}
