{koder: A^2P}{7 - 5 - 2007}
{PSN 1998 #14 "Problema de la triangulaci¢n"}
{ = China42 }
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
  oo = 1000000.0;
var
  fin,fout        : text;
  N,i,j,k,h       : longint;
  X,Y             : array[0..MaxN] of integer;
  C,dt            : array[0..MaxN,0..MaxN] of real;
  last            : array[0..MaxN,0..MaxN] of longint;

    function cross(o,c,m: longint): longint;
    begin
      cross := (X[c] - X[o]) * (Y[m] - Y[o]) -
               (X[m] - X[o]) * (Y[c] - Y[o]);
    end;{cross}

    var tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h;
      X[0] := X[(d + h) shr 1];
      Y[0] := Y[(d + h) shr 1];
      repeat
        while cross(1,0,i) < 0 do inc(i);
        while cross(1,0,j) > 0 do dec(j);
        if i <= j then
        begin
          tmp := X[i]; X[i] := X[j]; X[j] := tmp;
          tmp := Y[i]; Y[i] := Y[j]; Y[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

    procedure print(i,j: longint);
    begin
      if last[i,j] = 0 then exit;
      if (j - i > 1) and (j - i < N - 1) then
        writeln(fout,X[i],' ',Y[i],' ',X[j],' ',Y[j]);
      print(i,last[i,j]);
      print(last[i,j],j);
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,X[i],Y[i]);

  {init}
  j := 1;
  for i:=2 to N do
    if (Y[i] < Y[j]) or ((Y[i] = Y[j]) and (X[i] < X[j])) then j := i;
  tmp := X[1]; X[1] := X[j]; X[j] := tmp;
  tmp := Y[1]; Y[1] := Y[j]; Y[j] := tmp;
  qsort(2,N);
  for i:=1 to N do
    for j:=i + 2 to N do
      dt[i,j] := sqrt(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]));

  {solve}
  for h:=2 to N - 1 do
    for i:=1 to N - h do
    begin
      j := i + h;
      C[i,j] := oo;
      for k:=i to j do
        if C[i,k] + C[k,j] + dt[i,k] + dt[k,j] < C[i,j] then
        begin
          C[i,j] := C[i,k] + C[k,j] + dt[i,k] + dt[k,j];
          last[i,j] := k;
        end;{then}
    end;{for}

  {dprint}
  writeln(fout,C[1,N]:0:2);
  writeln(fout,N - 3);
  print(1,N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 14þ Problema de la triangulaci¢n                         Set£bal 1998
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Este problema consiste en dividir un pol¡gono convexo  por  medio  de
 sus diagonales. Estas diagonales no se pueden cortar y la suma de sus
 distancias dada por la f¢rmula de distancia  en  el  plano  debe  ser
 m¡nima.

 Fichero de entrada:

 Ser  encabezado por un n£mero N que indicar  el  n£mero  de  v‚rtices
 del  pol¡gono  y   a   continuaci¢n  N  l¡neas  con  las  coordenadas
 cartesianas enteras (X,Y) de  los puntos. Un registro  en  blanco  lo
 separar  del pr¢ximo juego de datos.

 Fichero de salida:

 En la primera l¡nea aparecer   la  suma  de  las  longitudes  de  las
 diagonales con dos lugares despu‚s de la coma.
 En la segunda l¡nea aparecer  la cantidad  de  diagonales  utilizadas
 para dividir el pol¡gono y en las pr¢ximas l¡neas las n diagonales en
 la forma x,y,x1,y1.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ Ejemplo de entrada ³ ³ Ejemplo de salida ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 4									³ ³ 1.41							³
 ³ 0 0								³ ³ 1 								³
 ³ 0 1								³ ³ 0 0 1 1 					³
 ³ 1 1								³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 1 0								³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
