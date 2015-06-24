/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #120 "Is This Integration?"
El compilador en vez de truncar la salida, la redondea y
el texto no menciona un margen de error.
*/
#include <cstdio>
#include <cmath>

#define problem "d"

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  double B, C, S, x;

  while ( scanf( "%lf\n", &x ) != EOF ) {
    S = x * x;
    C = S * ( 4 - sqrt( 3 ) - 2 * M_PI / 3 );
    B = S * ( 4 - M_PI ) - 2 * C;
    printf( "%.3lf %.3lf %.3lf\n", S - B - C, B, C );
  }

  return 0;
}

/*
120þ Is This Integration?                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

In the image below you can see a square ABCD, where AB = BC = CD =  DA
= a.  Four arcs  are drawn  taking the  four vertexes  A, B,  C, D  as
centers and a as the radius. The arc that is drawn taking A as center,
starts at neighboring vertex B  and ends at neighboring vertex  D. All
other arcs are drawn in a similar fashion. Regions of three  different
shapes are  created in  this fashion.  You will  have to determine the
total area if these different shaped regions.

Input

The  input  file  contains  a  floating-point  number  a  (a>=0
a<=10000) in each line which indicates  the length of one side of  the
square. Input is terminated by end of file.

Output

For each line of input, output in a single line the total area of  the
three types  of region  (filled with  different patterns  in the image
above). These three numbers will  of course be floating point  numbers
with three digits  after the decimal  point. First number  will denote
the area  of the  striped region,  the second  number will  denote the
total area of the dotted regions and the third number will denote  the
area of the rest of the regions.

Sample Input:
0.1
0.2
0.3
Sample Output:
0.003 0.005 0.002
0.013 0.020 0.007
0.028 0.046 0.016

Specifications:
Problem Name:       integ
Input File Name:     integ.in
Output File Name:  integ.out
Time Limit:             0.5 s
*/
