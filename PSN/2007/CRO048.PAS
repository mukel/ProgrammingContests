{koder: A^2P}{3 - 4 - 2007}
{PSN 2007 #48 "Fiesta Vacuna Plata"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,M,P,i,j,k,sol : longint;
  d,d1            : array[0..MaxN] of longint;
  mark            : array[0..MaxN] of boolean;
  c               : array[0..MaxN,0..MaxN] of longint;

    procedure dijkstra(node: longint);
    var i,j,k: longint;
    begin
      mark[node] := true; d[0] := oo;
      for i:=1 to N do d[i] := c[node,i];
      for i:=1 to N - 1 do
      begin
        k := 0;
        for j:=1 to N do
          if (not mark[j]) and (d[j] < d[k]) then k := j;
        mark[k] := true;
        for j:=1 to N do
          if (not mark[j]) and (d[k] + c[k,j] < d[j])
            then d[j] := d[k] + c[k,j];
      end;{for}
    end;{dijktra}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M,P);
  for i:=1 to N do
    for j:=1 to N do c[i,j] := oo;
  for i:=1 to M do
  begin
    read(fin,j,k);
    readln(fin,c[j,k]);
  end;{for}

  {solve}
  dijkstra(P);
  d1 := d;
  for i:=1 to N do
    for j:=i + 1 to N do
    begin
      k := c[i,j]; c[i,j] := c[j,i]; c[j,i] := k;
    end;{for}
  fillchar(mark,sizeof(mark),false);
  dijkstra(P);

  for i:=1 to N do
    if ((d[i] <> oo) and (d1[i] <> oo)) and
       (d[i] + d1[i] > sol) then sol := d[i] + d1[i];

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
48ş Fiesta Vacuna Plata.                                  Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una vaca de cada  una de N granjas  (1 <= N <=  1000) convenientemente
numeradas 1..N van a ir a  una gran fiesta vacuna que tendr   lugar en
la granja  #X (1  <= X  <= N).  Un total  de  M  (1 <=  M <=  100,000)
carreteras unidireccionlaes (de un sentido) conectan pares de granjas;
la carretera i requiere  Ti (1 <= Ti  <= 100) unidades de  tiempo para
recorrerse.

Cada vaca debe caminar a la fiesta, y luego cuando se acabe la fiesta,
volver a su granja. Cada vaca es  floja y por lo tanto elige una  ruta
¢ptima con el tiempo m s corta. La ruta de regreso de una vaca  podr¡a
ser diferente de su ruta original  debido a que las carreteras son  de
un sentido.

De todas las vacas, cu l es  la cantidad m s grande de tiempo  que una
vaca debe gastar caminando a la fiesta y devolvi‚ndose?

NOMBRE DEL PROBLEMA: sparty

FORMATO DE ENTRADA:

- L¡nea 1: Tres enteros separados por espacios, respectivamente N y M
      y x.

- L¡neas 2..M+1: La l¡nea i+1 describe la carretera i con tres enteros
      separados por espacios: Ai, Bi,  y Ti. La carretera descrita  va
      de la  granja Ai  a la  granja Bi,  requiriendo Ti unidades para
      recorrerse

ENTRADA EJEMPLO (archivo sparty.in):

4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

DETALLES DE LA ENTRADA:

Cuatro vacas, ocho carreteras: la fiesta es en la granja 2.

FORMATO DE LA SALIDA:

- L¡nea 1: Un entero: La m xima cantidad de tiempo que cualquier vaca
      debe caminar.

SALIDA EJEMPLO (archivo sparty.out):

10

DETALLES DE LA SALIDA:

La vaca 4 va directamente a  la fiesta (3 unidades) y se  devuelve via
las  granjas 1  y 3  (7 unidades),  para un  total de  10 unidades  de
tiempo.
}
