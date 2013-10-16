/*
Alfonso Alfonso Peterssen
1 - 12 - 2007
SPOJ #1840 "Printer Queue"
*/
#include <iostream>
using namespace std;

const int MAXN = 100;

int T, N, M, i, j, k, sol;
int job[MAXN];

int main() {

    for ( cin >> T; T; T-- ) {

        scanf("%d %d", &N, &M );
        for ( i = 0; i < N; i++ )
            cin >> job[i];

        /* Solve */
        sol = 0;
        for ( i = 0; job[M]; i = ( i + 1 ) % N )
            if ( job[i] ) {
                /* .. */
            	for ( j = k = 0; j < N; j++ )
                    k >?= job[j];

            	/* Do the job */
            	if ( k <= job[i] ) {
                    sol++;
                    job[i] = 0; // 0 rank
            	}
            }

        cout << sol << endl;
    }

    return 0;
}
