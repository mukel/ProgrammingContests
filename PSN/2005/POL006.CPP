/*
Alfonso Alfonso Peterssen
6 - 10 - 2007
PSN 2005 #6 "Farmer"
IOI 2004 Day 2 Task 3
*/
#include <cstdio>
#include <algorithm>
#include <functional> /* greater< T >() */
using namespace std;

#define MAXQ 160000
#define MAXFS 2000

int T, Q, S, F, i, j, k, sum, sol;
int field[MAXFS], strip[MAXFS];
bool mark[MAXQ];

int main() {

  scanf( "%d %d %d", &Q, &F, &S );

  for ( i = 0; i < F; i++ ) {
    scanf( "%d", &field[i] );
    sum += field[i];
  }

  for ( i = 0; i < S; i++ )
    scanf( "%d", &strip[i] );

  if ( sum < Q ) {

    sort( strip, strip + S, greater< int >() );

    for ( i = 0; i < S && sum < Q; i++ )
      sum += strip[i];

    sol = Q - i;
  }
  else if ( sum > Q ) {

    mark[0] = true;
    sort( field, field + F );

    for ( i = k = 0; i < F && !mark[Q]; i++ ) {

      for ( j = k; j >= 0; j-- )
        if ( mark[j] )
          mark[ j + field[i] ] = true;

      if ( k < Q )
        k += field[i];
    }
   sol = Q - !mark[Q];
  }
  else sol = Q;

  printf( "%d\n", sol );

  return 0;
}

/*
6¦ Farmer                                                 Polonia 2005
----------------------------------------------------------------------

A farmer has a set of  fields, each of which is surrounded  by cypress
trees. Also, the farmer has a set of strips of land, each of which has
a row of cypress trees. In  both fields and strips, between every  two
consecutive cypress trees is a single olive tree. All of the  farmer's
cypress trees either surround a field or are in a strip and all of the
farmer's olive trees  are between two  consecutive cypress trees  in a
field or in a  strip. One day the  farmer became very ill  and he felt
that he was going to die. A  few days before he passed away he  called
his eldest son and told him, "I  give you any Q cypress trees of  your
choice and all the olive  trees which are between any  two consecutive
cypress trees you have chosen."  >From each field and from  each strip
the son can  pick any combination  of cypress trees.  Since the eldest
son loves olives he wants to pick the Q cypress trees which will allow
him to inherit as many olive trees as possible.

   0-----0-----0-----0\
   ¦                    \
   ¦                      0                  0---------0
   0                        \                ¦         ¦
   ¦                          0              ¦         ¦
   ¦                            \            ¦         ¦
   0-----0-----0-----0-----0-----0           0---------0
   Field 1 has 13 cypress trees       Field 2 has 4 cypress trees


     0------0------0------0
     ¦                    ¦
     ¦                    ¦
     0------0------0------0
   Field 3 has 8 cypress trees


     0------0------0------0
     Strip 1 has 4 cypress trees

     0------0------0------0------0------0------0------0
     Strip 2 has 8 cypress trees

     0------0------0------0------0------0
     Strip 3 has 6 cypress trees

Figure 1. An example setting of cypress trees; olive trees are
not shown.

In Figure  1, assume  that the  son is  given Q=17  cypress trees.  To
maximize his olive inheritance he should choose all the cypress  trees
in Field 1 and Field 2, inheriting 17 olive trees.

You are  to write  a program  which, given  the information  about the
fields and  the strips  and the  number of  cypress trees  the son can
pick, determines the  largest possible number  of olive trees  the son
may inherit.

INPUT

The input file  name is farmer.in.  The first line  contains first the
integer Q: the number of cypress trees the son is to select; then  the
integer M, the number of fields; and then the integer K, the number of
strips.  The second  line contains  M integers  N1, N2,...  NM, :  the
numbers of cypress trees in fields. The third line contains K integers
R1, R2,... RK: the numbers of cypress trees in strips.

OUTPUT

The output file name  is farmer.out. The file  is to contain one  line
with one integer: the largest  possible number of olive trees  the son
may inherit.

EXAMPLE INPUTS AND OUTPUTS

farmer.in    farmer.out
17 3 3        17
13 4 8
4 8 6

CONSTRAINTS

In all inputs, 0<=Q<=150000, 0<=M<=2000, 0<=K<=2000,
3<=N1<=150, 3<=N2<=150,... 3<=NM<=150, 2<=R1<=150,
2<=R2<=150,... 2<=RK<=150. The total number of cypress trees in
the fields and strips is at least Q. Additionally, in 50% of the
inputs, Q<=1500.
*/
