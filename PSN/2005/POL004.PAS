{koder: A^2P}{1 - 5 - 2007}
{IOI 2004 Day 2 Task 1}
{PSN 2005 #4 "Phidias"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxF = 600;
var
  fin,fout        : text;
  F,C,N,i,j,k     : longint;
  R               : array[0..MaxF,0..MaxF] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,F,C);
  for i:=1 to F do
    for j:=1 to C do R[i,j] := i * j;
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,j,k);
    R[j,k] := 0;
  end;{for}

  {solve}
  for i:=1 to F do
    for j:=1 to C do
    begin
      for k:=1 to i shr 1 do
        if R[k,j] + R[i - k,j] < R[i,j]
          then R[i,j] := R[k,j] + R[i - k,j];
     for k:=1 to j shr 1 do
        if R[i,k] + R[i,j - k] < R[i,j]
          then R[i,j] := R[i,k] + R[i,j - k];
    end;{for}

  {dprint}
  writeln(fout,R[F,C]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
4þ Phidias                                                Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Famous ancient Greek sculptor Phidias is making preparations to build
another marvelous monument. For this purpose he needs rectangular marble
plates of sizes W1 x H1, W2 x H2, ..., WN x HN. Recently, Phidias has
received a large rectangular marble slab. He wants to cut the slab to
obtain plates of the desired sizes. Any piece of marble (the slab or the
plates cut from it) can be cut either horizontally or vertically into two
rectangular plates with integral widths and heights, cutting completely
through that piece. This is the only way to cut pieces and pieces cannot
be joined together. Since the marble has a pattern on it, the plates
cannot be rotated: if Phidias cuts a plate of size A x B then it cannot
be used as a plate of size B x A unless A = B. He can make zero or more
plates of each desired size. A marble plate is wasted if it is not of any
of the desired sizes after all cuts are completed. Phidias wonders how to
cut the initial slab so that as little of it as possible will be wasted.
As an example, assume that in the figure below the width of the original
slab is 21 and the height of the original slab is 11, and the desired
plate sizes are 10 x 4, 6 x 2, 7 x 5, and 15 x 10. The minimum possible
area wasted is 10, and the figure shows one sequence of cuts with total
waste area of size 10.


             ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
             ³                   ³±³                   ³
             ³      10 x 4       ³±³     10 x 4        ³
             ³                   ³±³                   ³
             ÃÄÄÄÄÄÄÄÄÄÄÄÂÄÂÄÄÄÄÄÁÄÁÄÄÄÂÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄ´                                         ³
             ³   6 x 2   ³±³   6 x 2   ³±³   6 x 2   ³±³
             ÃÄÄÄÄÄÄÄÄÄÄÄÁÄÅÄÄÄÄÄÄÄÄÄÄÄÁÄÅÄÄÄÄÄÄÄÄÄÄÄÁÄ´
             ³             ³             ³             ³
             ³    7 x 5    ³    7 x 5    ³    7 x 5    ³
             ³             ³             ³             ³
             ³             ³             ³             ³
             ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Your task is to write a  program that, given the size of  the original
slab and the desired plate sizes, calculates the minimum total area of
the original slab that must be wasted.

INPUT

The input file  name is phidias.in.  The first line  of input contains
two integers: first W, the width of the original slab, and then H, the
height of the original slab.  The second line contains one  integer N:
the number of desired plate  sizes. The following N lines  contain the
desired plate sizes. Each of these lines contains two integers:  first
the width Wi and then the height Hi of that desired plate size (1 <= i
<= N).

OUTPUT

The output file name is phidias.out.  The file is to contain one  line
with a  single integer:  the minimum  total area  of the original slab
that must be wasted.

phidias.in            phidias.out
21 11                  10
4
10 4
6 2
7 5
15 10


CONSTRAINTS
In all inputs,
1 <= W<= 600,
1 <= H<= 600,
0 < N <= 200,
1 <= Wi <= W,
1 <= Hi <= H.

Additionally, in 50% of the inputs, W<= 20, H<= 20 and N<= 5.
}