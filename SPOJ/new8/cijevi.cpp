/* from a chinese guy */
#include <cstdio>
#include <iostream>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAFC = 100;
const string ans = "###-#14##23#|##+";

int F, C;
char mat[MAFC][MAFC];

int main() {

	scanf("%d %d",&F,&C);
	REP( i, F )
		scanf( "%s", &mat[i] );
		
	REP( x, F )
	REP( y, C ) {
		if ( mat[x][y] != '.' ) continue;
		bool up = x > 0 && string("|+14").find(mat[x - 1][y]) != -1;
		bool dn = x < F - 1 && string("|+23").find(mat[x + 1][y]) != -1;
		bool lf = y > 0 && string("-+12").find(mat[x][y - 1]) != -1;
		bool rt = y < C - 1 && string("-+34").find(mat[x][y + 1]) != -1;
		char mis = ans[(up << 3) + (dn << 2) + (lf << 1) + rt];
		if ( mis != '#' ) {
			printf("%d %d %c\n", x + 1, y + 1, mis);
			return 0;
		}
	}
}

