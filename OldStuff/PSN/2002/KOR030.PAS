{koder: A^2P}
{PSN 2002 #30 "El nuevo juguete de Melany"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  oo = 65535;
var
  fin,fout        : text;
  N,M,i,j,k,h,sol : word;
  d,last          : array[0..MaxN] of word;
  mark            : array[1..MaxN] of boolean;
  c,p             : array[1..MaxN,0..MaxN] of word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
    for j:=1 to N do c[i,j] := oo;
  for i:=1 to M do
  begin
    readln(fin,j,k,h);
    c[j,k] := h; c[k,j] := h;
  end;{for}

  {solve}{prim}
  mark[1] := true;
  d := c[1]; d[0] := oo;
  for i:=1 to N do last[i] := 1;
  for i:=1 to N-1 do
  begin
    k := 0;
    for j:=1 to N do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    mark[k] := true;
    inc(sol,d[k]);
    h := last[k]; inc(p[h,0]); p[h,p[h,0]] := k;
    for j:=1 to N do
      if (not mark[j]) and (c[k,j] < d[j]) then
      begin
        d[j] := c[k,j]; last[j] := k;
      end;{then}
  end;{for}

  {dprint}
  writeln(fout,sol);
  for i:=1 to N do
    if p[i,0] > 0 then
    begin
      write(fout,i,' ');
      for j:=1 to p[i,0]-1 do write(fout,p[i,j],' ');
      writeln(fout,p[i,p[i,0]]);
    end;{then}

  {fclose}
  close(fin); close(fout);
end.{main}

{
30ş El nuevo juguete de Melany                              Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Melany  es una ni¤a inteligente y traviesa. Sus padres le han comprado
un  nuevo  juguete  que consiste en un puzzle de N piezas. Se sabe que
una  pieza encaja con al menos otra pieza del mismo puzzle, y que unir
estas dos piezas le lleva a Melany algun M tiempo.

Tarea:

Confeccione  un  programa  para  dada  la cantidad de piezas del nuevo
juguete, las piezasa que pueden unirse y el tiempo M que demora Melany
en  unirlas,  determine el menor tiempo en que ella armara su puzzle y
la configuracion del mismo.

Entrada:

La  entrada  es  mediante  el  fichero  texto MELY.IN con la siguiente
estructura:

.  Primera  linea: dos numeros enteros N y K, el primero representa la
  cantidad  de  piezas que tiene el puzzle y el segundo la cantidad de
  parejas de piezas que pueden unirse (4 <= N <= 100).
.  2..K+1 linea: tres enteros A, B y M donde A y B representan numeros
  de  dos  piezas que pueden unirse y M el tiempo que demora Melany en
  unirlas (0 <= M <= 255).

Salida:

La salida se realizara hacia el fichero texto MELY.OUT:

.  Primera  linea: un entero que significa el tiempo que demora Melany
  en armar su puzzle.
. A partir de la segunda linea la configuracion del puzzle, la primera
  pieza  y  a  continuacion todas las que Melany une a esta, separados
  por un espacio en blanco.

ÚÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄ¿
³MELY.IN³  ³MELY.OUT³
ÃÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄ´
³6 10   ³  ³16      ³
³1 2 7  ³  ³1 2 3 4 ³
³1 6 6  ³  ³3 6 5   ³
³4 1 2  ³  ÀÄÄÄÄÄÄÄÄÙ
³2 4 8  ³
³3 1 2  ³
³5 4 7  ³
³3 4 3  ³
³5 3 4  ³
³6 3 1  ³
³6 5 5  ³
ÀÄÄÄÄÄÄÄÙ
}