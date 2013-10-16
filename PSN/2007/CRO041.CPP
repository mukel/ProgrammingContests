/*
Alfonso Alfonso Peterssen
24 - 6 - 2007
PSN 2007 #41 "Protecting the Flowers"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 100000

long long sol;
int N, i, flowers;
struct cow {
  int T, D;
  bool operator < ( const cow &x ) const {
    return D * x.T < x.D * T;
  }
} ls[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {
  fin >> N;
  for ( i = 0; i < N; i++ ) {
    fin >> ls[i].T >> ls[i].D;
    flowers += ls[i].D;
  }

  sort( ls, ls + N );

  for ( i = N - 1; i >= 0; i-- ) {
    flowers -= ls[i].D;
    sol += flowers * ls[i].T * 2;
  }

  fout << sol << endl;

  return 0;
}

/*
41þ Protecting the Flowers.                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Farmer John went to cut some wood and left N (2 <= N <= 100,000)  cows
eating the grass, as usual. When  he returned, he found to his  horror
that  the cluster  of cows  was in  his garden  eating his  beautiful
flowers. Wanting to minimize the subsequent damage, FJ decided to take
immediate action and transport each cow back to its own barn.

Each cow i is at a location that is Ti minutes (1 <= Ti <=  2,000,000)
away from its own barn. Furthermore, while waiting for transport,  she
destroys Di (1 <= Di <= 100) flowers per minute. No matter how hard he
tries, FJ  can only  transport one  cow at  a time  back to  her barn.
Moving cow i to its barn requires 2*Ti minutes (Ti to get there and Ti
to return). FJ starts at the  flower patch, transports the cow to  its
barn, and then walks back to the flowers, taking no extra time to  get
to the next cow that needs transport.

Write a program to determine the order in which FJ should pick up  the
cows so that the total number of flowers destroyed is minimized.

PROBLEM NAME: flowers

INPUT FORMAT:

* Line 1: A single integer N

* Lines 2..N+1: Each line contains two space-separated integers, Ti
        and Di, that describe a single cow's characteristics

SAMPLE INPUT (file flowers.in):

6
3 1
2 5
2 3
3 2
4 1
1 6


OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of destroyed
        flowers

SAMPLE OUTPUT (file flowers.out):

86

OUTPUT DETAILS:

FJ returns the cows in the following order: 6, 2, 3, 4, 1, 5. While he
is transporting cow 6 to the barn, the others destroy 24 flowers; next
he will take  cow 2, losing  28 more of  his beautiful flora.  For the
cows 3,  4, 1  he loses  16, 12,  and 6  flowers respectively. When he
picks cow 5 there are no  more cows damaging the flowers, so  the loss
for that cow is zero. The total flowers lost this way is 24 + 28 +  16
+ 12 + 6 = 86.
*/
