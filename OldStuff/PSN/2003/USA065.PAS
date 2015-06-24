{koder: A^2P}{5 - 5 - 2007}
{PSN 2003 #65 "Avi¢n"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,i,j,sol       : longint;
  sit,pos,bag     : array[0..MaxN] of longint;
  mark            : array[0..MaxN] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,sit[i]);

  {solve}
  j := N;
  repeat
    inc(sol);
    for i:=1 to N do
      if pos[i] = sit[i] then
      begin
        inc(bag[i]);
        if bag[i] = 5 then
        begin
          dec(j);
          mark[sit[i]] := false;
        end;{then}
      end{then ->}
      else if not mark[pos[i] + 1] then
      begin
        mark[pos[i]] := false;
        inc(pos[i]);
        mark[pos[i]] := true;
      end;{then}
  until j = 0;

  {dprint}
  writeln(fout,sol - 1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
65ş Avi¢n.                                                    USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Imagine un avi¢n en el que existe s¢lo un pasillo a trav‚s de las
filas de asientos y pasajeros, los cuales est n entrando en el pasillo
y buscando sus asientos. Cada pasajero debe sentarse en su asiento, y
la entrada al avi¢n est  al principio, justamente delante de la
primera fila de asientos. Los pasajeros est n entrando uno detr s de
otro, sin ninguna parada innecesaria.

Los pasajero caminan a trav‚s del pasillo en la direcci¢n de su
asiento y en cada fila ‚l permanece exactamente un segundo (o m s, si
delante de ‚l otro pasajero est ) hasta que ‚l llegue a su fila y
entonces ‚l permanece en la entrada de su fila durante cinco segundos
(para colocar su equipaje). En cada segundo en el pasillo en una fila
pueda estar s¢lo un pasajero.

Tarea

Escriba un programa que calcular  cu nto tiempo se necesita para que
el pasillo quede libre, es decir que todos los pasajeros est‚n
sentados en sus asientos.

Entrada

En la primera l¡nea del archivo de entrada AIRPLANE.IN hay un entero N,
el n£mero de pasajeros, 1 <= N <= 1000.
En la (i + 1)-l¡nea esta un entero Ri, n£mero de fila donde el
pasajero numero i debe sentarse, 1 <= Ri <= 1000.
Se numeran los pasajeros con n£mero de 1 a N, y ellos est n entrando
en ese orden. N£mero de pasajeros que est n sentando en la misma fila
no est n limitados.

Salida

En la primera y £nica l¡nea del archivo de salida AIRPLANE.OUT usted
debe escribir el tiempo (en segundos) que se necesita para que todos los
pasajeros est‚n sentados en sus asientos.

Ejemplos de Entrada y Salida


  Ejemplo # 1           Ejemplo # 2           Ejemplo # 3
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ AIRPLANE.IN ³       ³ AIRPLANE.IN ³       ³ AIRPLANE.IN ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 1           ³       ³ 2           ³       ³ 4           ³
³ 3           ³       ³ 3           ³       ³ 4           ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ       ³ 3           ³       ³ 4           ³
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ       ³ 1           ³
³ AIRPLANE.OUT ³      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿      ³ 5           ³
³ 7            ³      ³ AIRPLANE.OUT ³      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
                      ³ 12           ³      ³ AIRPLANE.OUT ³
                      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
                                            ³ 19           ³
                                            ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
