{koder: A^2P}
{PSN 2005 #71 "Suma de d¡gitos hacia atr s"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10;
var
  fin,fout        : text;
  N,M,i,j,k       : word;
  sol             : array[1..MaxN] of byte;
  mark            : array[1..MaxN] of boolean;
  tpas            : array[0..MaxN,0..MaxN] of byte;

    procedure comb(i: byte);
    var j : byte;
    begin
      for j:=1 to N do
        if (not mark[j]) and (k + j * tpas[N,i] <= M) then
          if (i = N) and (k + j * tpas[N,i] = M) then
          begin
            sol[N] := j;
            for i:=1 to N do write(fout,sol[i],' ');
            close(fin); close(fout);
            halt;
          end{then ->}
          else begin
            inc(k,tpas[N,i] * j); mark[j] := true;
            sol[i] := j; comb(i+1);
            dec(k,tpas[N,i] * j); mark[j] := false;
          end;{else}
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M);

  {solve}
  tpas[1,1] := 1;
  for i:=2 to N do
    for j:=1 to i do
      tpas[i,j] := tpas[i-1,j] + tpas[i-1,j-1];
  comb(1);
end.{main}

{
71ş Suma de d¡gitos hacia atr s.                          Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

FJ and his cows enjoy playing a mental game. They write down the
numbers from 1 to N (1 <= N <= 11) in a certain order and then sum
adjacent numbers to produce a new list with one fewer number.  They
repeat this until only a single number is left.  For example, one
instance of the game (when N=4) might go like this:

    3   1   2   4
      4   3   6
        7   9
         16

Behind FJ's back, the cows have started playing a more difficult
game, in which they try to determine the starting sequence from
only the final total and the number N.  Unfortunately, the game is
a bit above FJ's mental arithmetic capabilities.

Write a program to help FJ play the game and keep up with the cows.

Entrada:

- Line 1: Two space-separated integers: N and the final sum.

Ejemplo de Entrada (bds.in):

4 16

Salida:

- Line 1: An ordering of the integers 1..N that leads to the given
        sum.  If there are multiple solutions, choose the one that is
        lexicographically least, i.e., that puts smaller numbers
        first.

Ejemplo de Salida (bds.out):

3 1 2 4

Detalles de la Salida

Hay otras posibles secuencias, tales como 3 2 1 4, pero 3 1 2 4
es lexicograficamente m s peque¤a.
}