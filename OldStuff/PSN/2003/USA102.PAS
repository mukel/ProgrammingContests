{koder: A^2P}{13 - 3 - 2003}
{PSN 2003 #102 "Tr¡os de puntos colineales"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 2000;
var
  fin,fout        : text;
  N,i,j,k,h,sol   : longint;
  x,y             : array[0..MaxN] of longint;

    function cross(o,c,m: longint): longint;
    begin
      cross := (x[c] - x[o]) * (y[m] - y[o]) -
               (x[m] - x[o]) * (y[c] - y[o]);
    end;{cross}

    var p,tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h;
      x[0] := x[(d + h) shr 1];
      y[0] := y[(d + h) shr 1];
      repeat
        while cross(1,0,i) < 0 do inc(i);
        while cross(1,0,j) > 0 do dec(j);
        if i <= j then
        begin
          tmp := x[i]; x[i] := x[j]; x[j] := tmp;
          tmp := y[i]; y[i] := y[j]; y[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    readln(fin,x[i],y[i]);

  {solve}
  j := 1;
  for i:=2 to N do
    if (y[i] < y[j]) or ((y[i] = y[j]) and (x[i] < x[j]))
      then j := i;

  tmp := x[1]; x[1] := x[j]; x[j] := tmp;
  tmp := y[1]; y[1] := y[j]; y[j] := tmp;

  for i:=1 to N - 2 do
  begin
    x[1] := x[i]; y[1] := y[i];
    qsort(i + 1,N);
    k := i + 1;
    repeat
      j := k;
      while (j < N) and (cross(i,j,j + 1) = 0)  do inc(j);
      sol := sol + (j - k + 1) * (j - k) div 2;
      k := j + 1;
    until k >= N;
  end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
102ş Tr¡os de puntos colineales.                              USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dadas las cordenadas enteras x;y (0 <= x,y <= 32767) de N ptos en el
plano, usted debe decir la cantidad de tr¡os de ptos colineales
(alineados) que existen en el plano.


 Ejemplo

    ³                                  En la figura hay 4 tr¡os de ptos
  4 Å                                  colineales :
    ³       z
  3 Å       *                               1. (v,w,x)
    ³                                       2. (v,w,y)
  2 Å                                       3. (v,x,y)
    ³   v   w       x   y                   4. (w,x,y)
  1 Å   *   *       *   *
    ³
 ÄÄÄÅÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÄ
    ³   1   2   3   4   5

  Aclaraci¢n  :  (v,w,x), (v,x,w), (w,v,x), (w,x,v), (x,v,w), y
                 (x,w,v) son el mismo tr¡o; por lo tanto debe contarse
                 una sola vez.

Entrada

El fichero de entrada se llamar  GEO.IN  En la 1ra l¡nea aparecer  el
valor de N (3 <= N <= 2000). Cada una de las siguiente N l¡neas
representa la descripci¢n de un punto. En cada l¡nea se encontrar n
dos enteros separados por un espacio en blanco representando las
cordenadas x;y de un punto.

Salida

El fichero de salida se llamar  GEO.OUT  En la 1ra y £nica debe estar
un entero que representar  la cantidad de puntos colineales.

 Ejemplos de entrada y salida

  ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
  ³ GEO.IN ³  ³ GEO.OUT ³        ³ GEO.IN ³  ³ GEO.OUT ³
  ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
  ³ 5      ³  ³ 4       ³        ³ 9      ³  ³ 8       ³
  ³ 1 1    ³  ÀÄÄÄÄÄÄÄÄÄÙ        ³ 1 1    ³  ÀÄÄÄÄÄÄÄÄÄÙ
  ³ 2 1    ³                     ³ 1 2    ³
  ³ 2 3    ³                     ³ 1 3    ³
  ³ 4 1    ³                     ³ 3 2    ³
  ³ 5 1    ³                     ³ 3 3    ³
  ÀÄÄÄÄÄÄÄÄÙ                     ³ 2 3    ³
                                 ³ 2 1    ³
                                 ³ 3 1    ³
                                 ³ 2 2    ³
                                 ÀÄÄÄÄÄÄÄÄÙ
}
