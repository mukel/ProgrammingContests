{koder: A^2P}{11 - 5 - 2007}
{USACO dec04 Gold "Cow Ski Area"}
{$B-,I-,Q-,R-,S-}
{$M 10000000} //Avoid stack overflow
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 501;
  mov : array[0..1,1..4] of shortint =
  ((-1,0,0,1),(0,1,-1,0));
var
  fin,fout        : text;
  N,M,S,i,j,
  a,b,sol         : longint;
  mark            : array[0..MaxN,0..MaxN] of boolean;
  mat,comp        : array[0..MaxN,0..MaxN] of longint;
  ph              : array[0..1,0..MaxN * MaxN] of boolean;

    procedure dfs(x,y: integer);
    var k : byte;
    begin
      comp[x,y] := S;
      for k:=1 to 4 do
      begin
        a := x + mov[0,k]; b := y + mov[1,k];
        if ((a > 0) and (b > 0) and (a <= N) and (b <= M)) and
           (comp[a,b] = 0) and (mat[a,b] = mat[x,y])
           then dfs(a,b);
      end;{for}
    end;{dfs}

    procedure dfs1(x,y: integer);
    var k : byte;
    begin
      mark[x,y] := true;
      for k:=1 to 4 do
      begin
        a := x + mov[0,k]; b := y + mov[1,k];
        if (a > 0) and (b > 0) and (a <= N) and (b <= M) then
        begin
          if mat[a,b] < mat[x,y] then
          begin
            ph[0,comp[x,y]] := true;
            ph[1,comp[a,b]] := true;
          end;{then}
          if (not mark[a,b]) and (mat[a,b] = mat[x,y])
            then dfs1(a,b);
        end;{then}
      end;{for}
    end;{dfs1}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,M,N);
  for i:=1 to N do
    for j:=1 to M do read(fin,mat[i,j]);

  {solve}
  for i:=1 to N do
    for j:=1 to M do
      if comp[i,j] = 0 then
      begin
        inc(S); dfs(i,j);
      end;{then}

  for i:=1 to N do
    for j:=1 to M do
      if not mark[i,j] then dfs1(i,j);

  j := 0;
  for i:=1 to S do
  begin
    if not ph[0,i] then inc(j);
    if not ph[1,i] then inc(sol);
  end;{for}
  if j > sol then sol := j;
  if S = 1 then sol := 0;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
Problem 3: Cow Ski Area [Adam Rosenfield, 2004]

Farmer John's cousin, Farmer Ron, who lives in the mountains of
Colorado, has recently taught his cows to ski.  Unfortunately, his
cows are somewhat timid and are afraid to ski among crowds of people
at the local resorts, so FR has decided to construct his own private
ski area behind his farm.

FR's ski area is a rectangle of width W and length L of 'land
squares' (1 <= W <= 500; 1 <= L <= 500).  Each land square is an
integral height H above sea level (0 <= H <= 9,999).  Cows can ski
horizontally and vertically between any two adjacent land squares,
but never diagonally.  Cows can ski from a higher square to a lower
square but not the other way and they can ski either direction
between two adjacent squares of the same height.

FR wants to build his ski area so that his cows can travel between
any two squares by a combination of skiing (as described above) and
ski lifts.  A ski lift can be built between any two squares of the
ski area, regardless of height. Ski lifts are bidirectional.  Ski
lifts can cross over each other since they can be built at varying
heights above the ground, and multiple ski lifts can begin or end
at the same square.  Since ski lifts are expensive to build, FR
wants to minimize the number of ski lifts he has to build to allow
his cows to travel between all squares of his ski area.

Find the minimum number of ski lifts required to ensure the cows
can travel from any square to any other square via a combination of
skiing and lifts.

TIME LIMIT: 0.4 seconds

PROBLEM NAME: skiarea

INPUT FORMAT:

* Line 1: Two space-separated integers: W and L

* Lines 2..L+1: L lines, each with W space-separated integers
        corresponding to the height of each square of land.

SAMPLE INPUT (file skiarea.in):

9 3
1 1 1 2 2 2 1 1 1
1 2 1 2 3 2 1 2 1
1 1 1 2 2 2 1 1 1

OUTPUT FORMAT:

* Line 1: A single integer equal to the minimal number of ski lifts FR
        needs to build to ensure that his cows can travel from any
        square to any other square via a combination of skiing and ski
        lifts

SAMPLE OUTPUT (file skiarea.out):

3

OUTPUT DETAILS:

FR builds the three lifts.  Using (1, 1) as the lower-left corner,
the lifts are (3, 1) <-> (8, 2), (7, 3) <-> (5, 2), and (1, 3) <->
(2, 2).  All locations are now connected.  For example, a cow wishing
to travel from (9, 1) to (2, 2) would ski (9, 1) -> (8, 1) -> (7,
1) -> (7, 2) -> (7, 3), take the lift from (7, 3) -> (5, 2), ski
(5, 2) -> (4, 2) -> (3, 2) -> (3, 3) -> (2, 3) -> (1, 3), and then
take the lift from (1, 3) - > (2, 2).  There is no solution using
fewer than three lifts.
}
