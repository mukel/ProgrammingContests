{koder: A^2P}{11 - 5 - 2007}
{USACO dec04 Silver "Tree Cutting"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
type
  node = record
    B,next : longint;
  end;{node}
var
  fin,fout        : text;
  found           : boolean;
  N,i,j,k         : longint;
  cant,max        : array[0..MaxN] of longint;
  list            : array[0..MaxN * 2] of node;
  P               : array[0..MaxN * 2] of longint;

    procedure dfs(i: longint);
    var j,k : longint;
    begin
      cant[i] := 1; j := P[i];
      while j <> 0 do
      begin
        k := list[j].B;
        if cant[k] = 0 then
        begin
          dfs(k);
          if cant[k] > max[i] then max[i] := cant[k];
          cant[i] := cant[i] + cant[k];
        end;{then}
        j := list[j].next
      end;{while}
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N - 1 do
  begin
    readln(fin,j,k);
    list[i].B := k;
    list[i].next := P[j];
    P[j] := i;

    list[N + i].B := j;
    list[N + i].next := P[k];
    P[k] := N + i;
  end;{for}

  {solve}
  for i:=1 to N do
    if cant[i] = 0 then dfs(i);
  for i:=1 to N do
    if (N - cant[i] <= N div 2) and (max[i] <= N div 2) then
    begin
      writeln(fout,i);
      found := true;
    end;{then}

  {check}
  if not found then
    writeln(fout,'NONE');

  {fclose}
  close(fin); close(fout);
end.{main}

{
Problem 8: Tree Cutting [Hal Burch, 2004]

After Farmer John realized that Bessie had installed a "tree-shaped"
network among his N (1 <= N <= 10,000) barns at an incredible cost,
he sued Bessie to mitigate his losses.

Bessie, feeling vindictive, decided to sabotage Farmer John's network
by cutting power to one of the barns (thereby disrupting all the
connections involving that barn).  When Bessie does this, it breaks
the network into smaller pieces, each of which retains full
connectivity within itself.  In order to be as disruptive as possible,
Bessie wants to make sure that each of these pieces connects together
no more than half the barns on FJ.

Please help Bessie determine all of the barns that would be suitable
to disconnect.

PROBLEM NAME: treecut

INPUT FORMAT:

* Line 1: A single integer, N.  The barns are numbered 1..N.

* Lines 2..N: Each line contains two integers X and Y and represents a
        connection between barns X and Y.

SAMPLE INPUT (file treecut.in):

10
1 2
2 3
3 4
4 5
6 7
7 8
8 9
9 10
3 8

INPUT DETAILS:

The set of connections in the input describes a "tree": it connects all the
barns together and contains no cycles.

OUTPUT FORMAT:

* Lines 1..?: Each line contains a single integer, the number (from
        1..N) of a barn whose removal splits the network into pieces
        each having at most half the original number of barns.  Output
        the barns in increasing numerical order.  If there are no
        suitable barns, the output should be a single line containing
        the word "NONE".

SAMPLE OUTPUT (file treecut.out):

3
8

OUTPUT DETAILS:

If barn 3 or barn 8 is removed, then the remaining network will have one
piece consisting of 5 barns and two pieces containing 2 barns.  If any
other barn is removed then at least one of the remaining pieces has size at
least 6 (which is more than half of the original number of barns, 5).
}
