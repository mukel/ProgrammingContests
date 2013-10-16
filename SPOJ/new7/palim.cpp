#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
class Tester{
private:
	char str[100001],sec[99];
	int cnt,n;
public:
	Tester(){cnt=0,n=strlen(gets(str)),gets(sec);}
	inline int getN(){return n;}
	inline bool isSame(int a,int b){return ++cnt<=4*n&&a>=0&&a<n&&b>=0&&b<n?str[a]==str[b]:(printf("ERROR while calling isSame()\n"),exit(1),false);}
	inline void answer(int a){printf("%d\n%s\n",a,sec),exit(0);}
}tester;
inline int getN(){return tester.getN();}
inline bool isSame(int a,int b){return tester.isSame(a,b);}
inline void answer(int a){tester.answer(a);}
#define tester _tester_

#include <algorithm>
using namespace std;

const int MAXN = 100000;

int N, i, j, k;
int rad[2*MAXN];

bool _isSame( int i, int j ) {
	if ( i == j ) return true;
	return isSame( i, j );
}

int main() {

	N = getN();
	
	// Manacher O( n )
	for ( i = 0, j = 0; i < 2 * N; i += k, j = max( j - k, 0 ) ) {
		while ( i-j >= 0 && i+j+1 < 2 * N &&
		      _isSame( (i-j)/2, (i+j+1)/2 ) )
			++j;
			rad[i] = j;
		for ( k = 1; i - k >= 0 && rad[i] - k >= 0 && rad[i - k] != rad[i] - k; k++ )
	      	rad[i + k] = min( rad[i - k], rad[i] - k);
	}
	
	answer( *max_element( rad, rad + 2 * N ) );

	return 0;
}
