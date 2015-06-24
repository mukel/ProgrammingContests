(*
Alfonso Alfonso Peterssen
23 - 5 - 2007
USACO 2005 OPEN Silver "Navigating the City"
*)
const
  problem = 'd';
  MaxF = 101;
  mov : array[0..1, 1..4] of longint =
  ( ( -1, 0, 0, 1 ), ( 0, -1, 1, 0 ) );
  dir = 'NWES';
var
  ch            : char;
  sol           : ansistring;
  F, C, i, j, k,
  tarX, tarY,
  X, Y, a, b    : longint;
  size          : array[0..1] of longint;
  mat           : array[0..MaxF, 0..MaxF] of char;
  last          : array[-1..MaxF, -1..MaxF] of longint;
  qX, qY        : array[0..1, 0..MaxF * 8] of longint;

begin

  assign( input, problem + '.in' ); reset( input );
  assign( output, problem + '.out' ); rewrite( output );

  readln( F, C );
  for i := 1 to 2 * F - 1 do
  begin
    for j := 1 to 2 * C - 1 do
    begin
      read( mat[i,j] );

      if mat[i,j] = 'S' then
      begin
        size[a] := 1;
        qX[a,1] := i; qY[a,1] := j;
      end; { then }

      if mat[i,j] = 'E' then
      begin
        tarX := i; tarY := j;
      end; { then }
    end; { for }
    readln;
  end; { for }

  b := 1;
  last[ qX[a,1], qY[a,1] ] := -1;
  repeat

    a := a xor 1; b := b xor 1;
    size[a] := 0;

    for i := 1 to size[b] do
      for j := 1 to 4 do
      begin
        X := qX[b,i] + 2 * mov[0,j];
        Y := qY[b,i] + 2 * mov[1,j];
        ch := mat[ X - mov[0,j], Y - mov[1,j] ];
        if ( last[X,Y] = 0 ) and ( ( ch = '|' ) or ( ch = '-' ) ) then
        begin
          inc( size[a] );
          qX[a, size[a] ] := X;
          qY[a, size[a] ] := Y;
          last[X,Y] := j;
        end; { then }
      end; { for }
  until last[tarX,tarY] <> 0;

  i := tarX; j := tarY;
  repeat
    sol := dir[ last[i,j] ] + sol;
    k := i - 2 * mov[0, last[i,j] ];
    j := j - 2 * mov[1, last[i,j] ];
    i := k;
  until last[i,j] = -1;

  i := 1;
  repeat
    j := i;
    write( sol[i], ' ' );
    while ( i < length( sol ) ) and ( sol[i] = sol[i + 1] )
      do inc( i );
    writeln( i - j + 1 );
    inc( i );
  until i > length( sol );

end. { main }

{
Problem 7: Navigating the City [Woburn Contest, 2005]

A dip in the milk market has forced the cows to move to the city.
The only employment available is in the venerable field of taxi-driving.
Help the cows learn their way around the city.

Given a city map with E (1 <= E <= 40) east/west street locations
and N (1 <= N <= 30) north/south street locations, create instructions
for a taxi driver to navigate from the start of his route (marked
'S') to the end (marked 'E'). Each instruction is a direction (one
of 'N', 'E', 'S', or 'W') followed by a space followed by an integer
that tells how many blocks to drive in that direction. If multiple
routes are available, your program should output the shortest route.
The shortest route is guaranteed to exist and be unique.

The map is depicted as a grid of '+'s that represent intersections
and a set of roads depicted as '-' and '|'.  Buildings and other
obstacles are shown as '.'s. Here is a typical map:

+-+-+.+-+-+
|...|.....|
+-+.+-+-+-+
..|.......|
S-+-+-+.E-+

The taxi should go east, north, west, north, east two blocks, and so on.
See the output format and sample solution below for its complete route.

PROBLEM NAME: navcit

INPUT FORMAT:

* Line 1: Two space-separated integers, N and E.

* Lines 2..2*N: These lines each contain 2*E-1 characters and encode
        the map of the street. Every other input line gives the data
        for the east/west streets; the remaining lines show the
        north/south streets. The format should be clear from the
        example.

SAMPLE INPUT (file navcit.in):

3 6
+-+-+.+-+-+
|...|.....|
+-+.+-+-+-+
..|.......|
S-+-+-+.E-+

OUTPUT FORMAT:

* Lines 1..?: Each line contains a direction letter and a number of
        blocks to travel in that direction.

SAMPLE OUTPUT (file navcit.out):

E 1
N 1
W 1
N 1
E 2
S 1
E 3
S 1
W 1
}