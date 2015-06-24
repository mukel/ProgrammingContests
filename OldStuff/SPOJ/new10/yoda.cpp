#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <iostream>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int
	MAXN = 100,
	MAXLEN = 1 << 10,
	ALPHA = 26;

char line[MAXLEN];
int freq[ALPHA];
int64 C[MAXN][MAXN];

int main() {

	for ( int i = 0; i < MAXN; i++ ) {
		C[i][0] = 1;
		for ( int j = 1; j <= i; j++ )
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}

	while ( gets(line) ) {

		memset( freq, 0, sizeof( freq ) );

		for ( int i = 0; line[i]; i++ ) {
			char ch = line[i];
			if ( islower(ch) ) ch -= 32;
			if ( isupper(ch) )
				freq[ch - 'A']++;
		}
		
		int odds = 0;
		int N = 0;
		REP( i, ALPHA ) {
		      odds += freq[i] % 2;
		      N += freq[i];
		}
		      
		if ( odds > 1 ) {
			printf( "0\n" );
			continue ;
		}
		
		N /= 2;
		
		// Now calculate permutations with repetitions
		int64 ans = 1;
		REP( i, ALPHA ) {
			freq[i] /= 2;
			ans *= C[N][ freq[i] ];
			N -= freq[i];
		}
		
		cout << ans << endl;
	}

	return 0;
}
