{koder: A^2P}{19 - 3 - 2007}
{PSN 2005 #78 "Guachivaca"}
{$B-,I-,Q-,R-,S+}
{$M 5000000} //Avoid Stack Overflow (5MB)
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
  MaxM = 50000;
type
  edge = record
    A,B,index : longint;
  end;{edge}
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  P,F             : array[0..MaxN] of longint;
  list            : array[0..MaxM * 2] of edge;
  mark            : array[0..MaxM * 2] of boolean;

    var pv,tmp : edge;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; pv := list[(d + h) shr 1];
      repeat
        while list[i].A < pv.A do inc(i);
        while list[j].A > pv.A do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

    procedure eulerize(i: longint);
    var j : longint;
    begin
      if P[i] <> 0 then
      for j:=P[i] to F[i] do
        if not mark[list[j].index] then
        begin
          mark[list[j].index] := true;
          eulerize(list[j].B);
          writeln(fout,i);
        end;{then}
    end;{eulerize}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
  begin
    readln(fin,list[i].A,list[i].B);
    list[M + i].A := list[i].B;
    list[M + i].B := list[i].A;
    list[M + i].index := M + i;
    list[i].index := i;
  end;{for}

  {solve}
  qsort(1,2 * M);
  i := 1;
  repeat
    P[list[i].A] := i;
    while list[i + 1].A = list[i].A do inc(i);
    F[list[i].A] := i;
    inc(i);
  until i > 2 * M;

  {dprint}
  writeln(fout,1);
  eulerize(1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
78ş Guachivaca.                                           Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Bessie ha sido designada para ser la nueva guachivaca para la granja.
En cada noche, su trabajo es recorrer la granja y asegurarse que no
hay roedores da¤inos haciendo da¤os. Ella comienza en el establo, hace
su patrulla, y luego se devuelve al establo cuando su trabajo esta
listo.

Si ella fuera una vaca mas observadora, ella podr¡a ser capaz de
simplemente recorrer cada uno de M (1 <= M <= 50,000) senderos
numerados 1..M entre N (2 <= N <= 10,000) campos numerados 1..N en la
granja una vez y estar segura que ella ha visto todo lo que necesita
ver. Pero como ella no lo es, ella quiere estar segura de que ella
camino por cada sendero exactamente dos veces. Es tambien importante
que sus dos viajes a traves de cada sendero sean en direcciones
opuestas, de tal manera que ella no deje de ver la misma cosa dos
veces.

Un par de campos podr¡an estar conectados por mas de un sendero.
Encuentre un camino que Bessie pueda seguir el cual cumplir  sus
requerimientos. Se garantiza que tal camino existe.

NOMBRE DEL PROBLEMA: watchcow

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros, N y M.

- L¡neas 2..M+1: Dos enteres denotando un par de campos conectados por
         un sendero.

ENTRADA EJEMPLO (archivo watchcow.in):

4 5
1 2
1 4
2 3
2 4
3 4

FORMATO DE SALIDA:

- L¡neas 1..2M+1: Una lista de campos por los que ella pasa, uno por
          l¡nea, comenzando y terminando en el establo en el campo 1.
          Si es posible m s de una soluci¢n de c¢mo salida cualquier
          solucion

SALIDA EJEMPLO (archivo watchcow.out):

1
2
3
4
2
1
4
3
2
4
1

DETALLES DE LA SALIDA:

Bessie comienza en 1 (establo), va a 2, luego a 3, etc...
}
