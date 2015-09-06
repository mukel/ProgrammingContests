/*
Alfonso2 Peterssen(mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int MAXL = 1 << 7;

char A[MAXL], B[MAXL];

int main()
{
    gets(A);
    reverse(A, A + strlen(A));
    gets(B);
    
    printf( "%s\n", !strcmp(A, B) ? "YES" : "NO" );

    return 0;
}
