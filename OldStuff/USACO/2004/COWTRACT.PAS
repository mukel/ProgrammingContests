{koder: A^2P}{11 - 5 - 2007}
{USACO dec04 Silver "Bad Cowtractors"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,M,i,j,k,h,sol : longint;
  mark            : array[0..MaxN] of boolean;
  d               : array[0..MaxN] of longint;
  C               : array[0..MaxN,0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
  begin
    readln(fin,j,k,h);
    if h > C[j,k] then
    begin
      C[j,k] := h; C[k,j] := h;
    end;{then}
  end;{for}

  {solve}
  mark[1] := true;
  for i:=1 to N do d[i] := C[1,i];
  for i:=1 to N - 1 do
  begin
    k := 0;
    for j:=2 to N do
      if (not mark[j]) and (d[j] > d[k]) then k := j;
    if k = 0 then
    begin
      sol := -1;
      break;
    end;{then}
    inc(sol,d[k]);
    mark[k] := true;
    for j:=2 to N do
      if (not mark[j]) and (C[k,j] > d[j])
        then d[j] := C[k,j];
  end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
Problem 7: Bad Cowtractors [Tim Abbott, 2004]

Bessie has been hired to build a cheap internet network among Farmer
John's N (2 <= N <= 1,000) barns that are conveniently numbered
1..N. FJ has already done some surveying, and found M (1 <= M <=
20,000) possible connection routes between pairs of barns.  Each
possible connection route has an associated cost C (1 <= C <=
100,000).  Farmer John wants to spend the least amount on connecting
the network; he doesn't even want to pay Bessie.

Realizing Farmer John will not pay her, Bessie decides to do the
worst job possible.  She must decide on a set of connections to
install so that (i) the total cost of these connections is as large
as possible, (ii) all the barns are connected together (so that it
is possible to reach any barn from any other barn via a path of
installed connections), and (iii) so that there are no cycles among
the connections (which Farmer John would easily be able to detect).
Conditions (ii) and (iii) ensure that the final set of connections
will look like a "tree".

PROBLEM NAME: cowtract

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..M+1: Each line contains three space-separated integers A,
        B, and C that describe a connection route between barns A and
        B of cost C.

SAMPLE INPUT (file cowtract.in):

5 8
1 2 3
1 3 7
2 3 10
2 4 4
2 5 8
3 4 6
3 5 2
4 5 17

OUTPUT FORMAT:

* Line 1: A single integer, containing the price of the most expensive
        tree connecting all the barns.  If it is not possible to
        connect all the barns, output -1.

SAMPLE OUTPUT (file cowtract.out):

42

OUTPUT DETAILS:

The most expensive tree has cost 17 + 8 + 10 + 7 = 42.  It uses the following
connections: 4 to 5, 2 to 5, 2 to 3, and 1 to 3.
}
