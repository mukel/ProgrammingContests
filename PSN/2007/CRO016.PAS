{koder: A^2P}{26 - 2 - 2007}
{PSN 2007 #16 "Modulo"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  i,j,sol         : longint;
  mark            : array[0..41] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  for i:=1 to 10 do
  begin
    readln(fin,j);
    if not mark[j mod 42] then
    begin
      mark[j mod 42] := true;
      inc(sol);
    end;{then}
  end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
16ş Modulo.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Given two integers A and B, A modulo B is the remainder when  dividing
A by B. For example, the numbers 7,  14, 27 and 38 become 1, 2, 0  and
2, modulo  3. Write  a program  that accepts  10 numbers  as input and
outputs the number  of distinct numbers  in the input,  if the numbers
are considered modulo 42. Input The input will contain 10 non-negative
integers, each  smaller than  1000, one  per line.  Output Output  the
number of distinct values when considered modulo 42 on a single  line.
Sample tests input 1 2 3  4 5 6 7 8 9  10 output 10 	input 42 84  252
420 840 126 42 84 420 126 output 1 	 input 39 40 41 42 43 44 82 83  84
85 output 6

Clarification: In the first example,  the numbers modulo 42 are  1, 2,
3, 4, 5, 6, 7, 8, 9  and 10. In the second example all  numbers modulo
42 are 0. In the third example, the numbers modulo 42 are 39, 40,  41,
0, 1, 2, 40, 41, 0 and 1. There are 6
}