{koder: A^2P}{27 - 2 - 2007}
{PSN 2007 #20 "STOL"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 400;
var
  fin,fout        : text;
  ch              : char;
  N,M,i,j,k,h,sol : longint;
  t               : array[0..MaxN,0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    for j:=1 to M do
    begin
      read(fin,ch);
      t[i,j] := t[i - 1,j] + t[i,j - 1] -
                t[i - 1,j - 1] + byte(ch = 'X');
    end;{for}
    readln(fin);
  end;{for}

  {solve}
  for i:=1 to N do
    for j:=i to N do
    begin
      k := 1;
      while k <= M do
      begin
        h := k;
        while
          (h <= M) and
          (t[j,h] - t[i - 1,h] - t[j,k - 1] + t[i - 1,k - 1] = 0)
            do inc(h);
        if h > k then
          if (j + h - i - k) * 2 + 1 > sol then
            sol := (j + h - i - k) * 2 + 1;
        k := h + 1;
      end;{while}
    end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
20ş STOL                                                  Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mirko has bought an  apartment and wants to  invite to dinner as  many
people as possible to  celebrate with him. For  this he needs a  large
rectangular wooden table for which  he will sit down with  his guests.
The number of people a table can accommodate is equal to its perimeter
(the sum of the lengths of all four sides). Mirko wants to buy a table
such that it fits in his apartment and that as many people as possible
can sit down with him for dinner. The table must be placed so that its
edges are parallel to the edges of the apartment. Given the layout  of
the apartment, find the number  of people Mirko can invite  to dinner.
Input The first line contains two integers  R and C (1 = R, S  = 400),
the dimensions of the apartment. Each of the following R rows contains
exactly S characters (without spaces), whether a square is free  ('.')
or blocked ('X'). Mirko can put his table only in free squares. Output
Output the number of guests Mirko  can invite to dinner after he  buys
his table on a single line.

Sample test data

input 2 2 .. .. output 7
input 4 4 X.XX X..X ..X. ..XX output 9 	input 3 3 X.X .X. X.X output 3
}