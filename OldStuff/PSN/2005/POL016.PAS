{koder: A^2P}
{PSN 2005 #16 "HexaSecuencia"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  base = 16;
  digits = 'ABC1DEF2GHI3JKL4';
var
  fin,fout        : text;
  s               : string;
  N,i,j,sol       : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,s);

  {solve}
  for i:=1 to byte(s[0]) do
    N := N * base + pos(s[i],digits) - 1;

  j := 1; i := 1;
  while j * base <= N do
  begin
    inc(sol,j * (base - 1) * i);
    inc(i); j := j * base;
  end;{while}
  inc(sol,(N - j + 1) * i);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
16þ HexaSecuencia.                                        Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un nuevo sistema de numeraci¢n fue creado para las nuevas versiones de
lenguajes de programaci¢n, este  sistema tiene base 16.  Una secuencia
larga  se llama  a la  escritura consecutiva  de los  n£meros de  este
sistema uno  al lado  del otro  desde 1  hasta un  n£mero N.  El nuevo
sistema lo definimos de la siguiente manera:

Base
10        0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
Base 16   A   B   C   1   D   E   F   2   G   H   I   3   J   K   L   4

Ejemplo de una secuencia larga: BC1DEF2GHI3JKL4BABBBCB1

Esta secuencia comienza desde B hasta B1. La longitud de una secuencia
est  definida por la cantidad de caracteres que tenga.

Tarea

Escriba un  programa que dado  el l¡mite de  la secuencia larga  halle
su longitud.

Entrada (hexa.in)

En la primera y £nica l¡nea del fichero de entrada aparece un n£mero N
escrito en la base anterior.

Salida  (hexa.out)

En la primera y £nica l¡nea del fichero de salida escribe la  longitud
de la secuencia larga.

El  50% de los datos :
0 < N <= 1000 000

El 100% de los datos :
0 < N <= 100 000 000. (Nota : Este rango es en base 10)


Ejemplo de Entrada y Salida

Hexa.in
B1

Hexa.out
23
}