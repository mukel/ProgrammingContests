{koder: A^2P}{2 - 4 - 2007}
{PSN 2007 #55 "Alineamiento Balanceado Oro"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
  MaxM = 30;
var
  fin,fout        : text;
  N,M,i,j,sol     : longint;
  cow,vector      : array[0..MaxN] of longint;
  t               : array[0..MaxN,0..MaxM] of longint;

    function equal(i,j: longint): boolean;
    var k : longint;
    begin
      for k:=1 to M - 1 do
        if t[vector[i],k] <> t[vector[j],k]
          then exit(false);
      exit(true);
    end;{equal}

    function lowest(i,j: longint): boolean;
    var k : longint;
    begin
      for k:=1 to M - 1 do
        if t[vector[i],k] <> t[vector[j],k]
          then exit(t[vector[i],k] < t[vector[j],k]);
      exit(vector[i] < vector[j]);
    end;{lowest}

    var tmp : longint;
    procedure qsort(d,h: longint);
    var i,j: longint;
    begin
      i := d; j := h; vector[0] := vector[(d + h) shr 1];
      repeat
        while lowest(i,0) do inc(i);
        while lowest(0,j) do dec(j);
        if i <= j then
        begin
          tmp := vector[i];
          vector[i] := vector[j];
          vector[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do readln(fin,cow[i]);

  {init}
  for i:=1 to N do
    for j:=1 to M do
      if odd(cow[i] shr (j - 1))
        then t[i,j] := t[i - 1,j] + 1
        else t[i,j] := t[i - 1,j] - 1;

  for i:=1 to N do
    for j:=1 to M do
      t[i,j] := t[i,j + 1] - t[i,j];

  for i:=1 to N do vector[i] := i;

  {solve}
  qsort(1,N);
  i := 1; vector[0] := 0;
  repeat
    j := i;
    while (j < N) and (equal(j,j + 1))
      do inc(j);
    if vector[j] - vector[i] > sol
      then sol := vector[j] - vector[i];
    i := j + 1;
  until i > N;

  for i:=1 to N do
    if (equal(i,0)) and (vector[i] > sol)
      then sol := vector[i];

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
55ş Alineamiento Balanceado Oro.                          Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las N vacas  del Granjero Juan  (1 <= N  <= 100,000) comparten  muchas
similitudes.  De  hecho, GJ  ha  sido capaz  de  resumir la  lista  de
similitudes compartidas  por sus  vacas a  una lista  de K similitudes
diferentes  (1 <=  K <=  30). Por  ejemplo, las  vacas exhibiendo  la
similitud #1 podr¡an tener manchas, las vacas exhibiendo la  similitud
#2 podr¡an preferir C a Pascal, y as¡ sucesivamente.

GJ ha dise¤ado una forma concisa de describir cada vaca en t‚rminos de
su “ID  de similitud”,  un solo  entero de  K bits cuya representaci¢n
binaria nos dice el conjunto  de similitudes exhibidas por las  vacas.
Por ejemplo suponga que una vaca tiene un ID  1101, esto significa que
nuestra vaca tiene  las similitudes 1,  3, y 4  (leyendo de derecha  a
izquierda), pero no la similitud 2. M s generalmente, encontramos un 1
en la posici¢n 2^(i-1) si una vaca tiene la similitud i.

Siendo un tipo sensible, GJ aline¢ las vacas 1..N en una fila larga  y
se  di¢ cuenta  que ciertos  rangos de  vacas est n  de alguna  manera
“balanceadas”  en t‚rminos  de las  similitudes que  ellas tienen.  Un
rango contiguo  de vacas  1..j est   balanceado si  cada una  de las K
similitudes posibles es compartida por el mismo n£mero de vacas en  el
rango. GJ tiene curiosidad del tama¤o del rango balanceado m s  grande
de vacas. Vea si usted puede determinarlo.

NOMBRE DEL PROBLEMA: lineup

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por enteros, N y K.

- L¡neas 2..N+1: La l¡nea i+1 contiene un solo entero de K bits
       especificando las similitudes presentes en la vaca i. El bit
       menos significativo de este entero es 1 si la vaca tiene la
       similitud  #1, y el bit m s significativo es 1 si la vaca tiene
       la similitud #K.

ENTRADA EJEMPLO (archivo lineup.in):

7 3
7
6
7
2
1
4
2


DETALLES DE LA ENTRADA:

La l¡nea tiene 7 vacas con 3 similitudes, la tabla de a continuaci¢n resume
la correspondencia:

              Similitud 3:   1   1   1   0   0   1   0
              Similitud 2:   1   1   1   1   0   0   1
              Similitud 1:   1   0   1   0   1   0   0
              Llave:         7   6   7   2   1   4   2
              Vaca #:        1   2   3   4   5   6   7


FORMATO DE LA SALIDA:

- L¡nea 1: Un solo entero dando el tama¤o del grupo balanceado mas
        grande de vacas.

SALIDA EJEMPLO (archivo lineup.out):

4

DETALLES DE LA SALIDA:

En el rango de la vaca #3 a la vaca #6 (de rango 4), cada similitud aparece
en exactamente 2 vacas en el rango:
              Similitud 3:     1   0   0   1  -> total dos
              Similitud 2:     1   1   0   0  -> total dos
              Similitud 1:     1   0   1   0  -> total dos
              Llave:           7   2   1   4
              Vaca #:          3   4   5   6
}
