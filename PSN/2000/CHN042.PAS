{koder: A^2P}{3 - 3 - 2007}
{PSN 2000 #42 "Triangulaci¢n de costo m¡nimo"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,i,j,k,h,tmp   : longint;
  x,y             : array[0..MaxN] of longint;
  d,c             : array[0..MaxN,0..MaxN] of real;
  last            : array[0..MaxN,0..MaxN] of longint;

    function cross(o,c,m: longint): longint;
    begin
      cross := (x[c] - x[o]) * (y[m] - y[o]) -
               (x[m] - x[o]) * (y[c] - y[o]);
    end;{cross}

    procedure print(i,j: longint);
    begin
      if last[i,j] = 0 then exit;
      if (j - i > 1) and (j - i < N - 1) then
        writeln(fout,x[i],' ',y[i],' ',x[j],' ',y[j]);
      print(i,last[i,j]);
      print(last[i,j],j);
    end;{print}

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
    if (x[i] < x[j]) or ((x[i] = x[j]) and (y[i] < y[j]))
      then j := i;
  tmp := x[1]; x[1] := x[j]; x[j] := tmp;
  tmp := y[1]; y[1] := y[j]; y[j] := tmp;

  {sort}
  for i:=2 to N do
    for j:=i + 1 to N do
      if cross(1,i,j) > 0 then
      begin
        tmp := x[i]; x[i] := x[j]; x[j] := tmp;
        tmp := y[i]; y[i] := y[j]; y[j] := tmp;
      end;{then}

  for i:=1 to N do
    for j:=i + 2 to N do
      d[i,j] := sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));

  {triangulate}
  for h:=2 to N - 1 do
    for i:=1 to N - h do
    begin
      j := i + h; c[i,j] := oo;
      for k:=i to j - 1 do
        if c[i,k] + c[k,j] + d[i,k] + d[k,j] < c[i,j] then
        begin
          last[i,j] := k;
          c[i,j] := c[i,k] + c[k,j] + d[i,k] + d[k,j];
        end;{then}
    end;{for}

  {dprint}
  writeln(fout,c[1,N]:0:2);
  writeln(fout,N - 3);
  print(1,N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
  42þ Triangulaci¢n de costo m¡nimo                         China 2000
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Un  pol¡gono  convexo  se  puede  dividir  en  triangulos si trazamos
 convenientemente  varias  de  sus  diagonales.  Una  diagonal  es  un
 segmento de recta que une dos v‚rtices no adyacentes del pol¡gono.

 El  problema  consiste  en  dividir un pol¡gono convexo en tri ngulos
 trazando  algunas  de  sus diagonales de forma tal que la suma de sus
 distancias  sea  m¡nima.  Las diagolales trazadas no se pueden cortar
 entre s¡.

 Fichero de Entrada:

 Ser  encabezado por un n£mero N que indicar  el  n£mero  de  v‚rtices
 del    pol¡gono    y  acontinuaci¢n  N  l¡neas  con  las  coordenadas
 cartesianas  enteras (X,Y) de los v‚rtices del pol¡gono. Los v‚rtices
 del pol¡gono aparecer n en cualquier orden.

 Fichero de Salida:

 En la primera l¡nea aparecer   la  suma  de  las  longitudes  de  las
 diagonales trazadas con dos lugares despu‚s de la coma.
 En la segunda l¡nea aparecer  la cantidad  de  diagonales  utilizadas
 para dividir el pol¡gono y en las pr¢ximas l¡neas las n diagonales en
 la forma x,y,x1,y1.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada³ ³Ejemplo de Salida³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 14               ³ ³ 79.89           ³
 ³ 0 3              ³ ³ 11              ³
 ³ -4 0             ³ ³ 10 -4 2 -7      ³
 ³ 12 1             ³ ³ 7 -6 2 -7       ³
 ³ 3 -7             ³ ³ 2 -7 5 4        ³
 ³ 2 -7             ³ ³ 2 -7 0 3        ³
 ³ 5 4              ³ ³ -3 -5 0 3       ³
 ³ 10 3             ³ ³ -3 -5 -4 0      ³
 ³ -5 -3            ³ ³ -4 0 0 3        ³
 ³ 7 -6             ³ ³ 0 3 5 4         ³
 ³ 3 4              ³ ³ 5 4 10 -4       ³
 ³ -3 -5            ³ ³ 10 3 10 -4      ³
 ³ -2 2             ³ ³ 10 3 12 -1      ³
 ³ 10 -4            ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 12 -1            ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
