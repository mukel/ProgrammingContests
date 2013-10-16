/*
Alfonso Alfonso Peterssen
31 - 12 - 2007
USACO 2007 DEC Silver "Mud Puddles"
*/
#include <iostream>
#include <queue>

using namespace std;

const int
    OFFSET = 501,
    MAXF = 1005,
    mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int X, Y, N, i, j, k;
bool puddle[MAXF][MAXF];
int dist[MAXF][MAXF];
queue< pair< int, int > > Q;

int main() {

    cin >> X >> Y >> N;
    X += OFFSET; Y += OFFSET;
    for ( i = 0; i < N; i++ ) {
        cin >> j >> k;
        puddle[j + OFFSET][k + OFFSET] = true;
    }

    /* BFS */
    puddle[OFFSET][OFFSET] = true;
    Q.push( make_pair( OFFSET, OFFSET ) );
    while ( !Q.empty() && !puddle[X][Y] ) {

        int x = Q.front().first,
            y = Q.front().second;

        Q.pop();

        for ( i = 0; i < 4; i++ ) {

            int nx = x + mov[i][0],
                ny = y + mov[i][1];

            if ( nx < 0 || nx >= MAXF ||
                 ny < 0 || ny >= MAXF ||
                 puddle[nx][ny] )
                 continue;

            if ( dist[nx][ny] == 0 ) {
                puddle[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                Q.push( make_pair( nx, ny ) );
            }
        }
    }

    cout << dist[X][Y] << endl;

    return 0;
}

/*
Problem 8: Mud Puddles [Jeffrey Wang, 2007]

Farmer John is leaving his house promptly at 6 AM for his daily
milking of Bessie. However, the previous evening saw a heavy rain,
and the fields are quite muddy. FJ starts at the point (0, 0) in
the coordinate plane and heads toward Bessie who is located at (X,
Y) (-500 <= X <= 500; -500 <= Y <= 500). He can see all N (1 <= N
<= 10,000) puddles of mud, located at points (A_i, B_i) (-500 <= A_i
<= 500; -500 <= B_i <= 500) on the field. Each puddle occupies only
the point it is on.

Having just bought new boots, Farmer John absolutely does not want
to dirty them by stepping in a puddle, but he also wants to get to
Bessie as quickly as possible. He's already late because he had to
count all the puddles. If Farmer John can only travel parallel to
the axes and turn at points with integer coordinates, what is the
shortest distance he must travel to reach Bessie and keep his boots
clean? There will always be a path without mud that Farmer John can
take to reach Bessie.

PROBLEM NAME: mud

INPUT FORMAT:

* Line 1: Three space-separate integers: X, Y, and N.

* Lines 2..N+1: Line i+1 contains two space-separated integers: A_i
        and B_i

SAMPLE INPUT (file mud.in):

1 2 7
0 2
-1 3
3 1
1 1
4 2
-1 1
2 2

INPUT DETAILS:

Bessie is at (1, 2). Farmer John sees 7 mud puddles, located at (0,
2); (-1, 3); (3, 1); (1, 1); (4, 2); (-1, 1) and (2, 2). Pictorially:

   4 . . . . . . . .
   3 . M . . . . . .
Y  2 . . M B M . M .
   1 . M . M . M . .
   0 . . * . . . . .
  -1 . . . . . . . .
    -2-1 0 1 2 3 4 5
           X

OUTPUT FORMAT:

* Line 1: The minimum distance that Farmer John has to travel to reach
        Bessie without stepping in mud.

SAMPLE OUTPUT (file mud.out):

11

OUTPUT DETAILS:

The best path for Farmer John is (0, 0); (-1, 0); (-2, 0); (-2, 1);
(-2, 2); (-2, 3); (-2, 4); (-1, 4); (0, 4); (0, 3); (1, 3); and (1,
2), finally reaching Bessie.

   4 ******* . . . .
   3 * M . * . . . .
Y  2 * . M B M . M .
   1 * M . M . M . .
   0 ***** . . . . .
  -1 . . . . . . . .
    -2-1 0 1 2 3 4 5

           X
*/
