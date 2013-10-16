{koder: A^2P}{26 - 2 - 2007}
{PSN 2007 #11 "Estante de  altura m¡nima"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  cost,last,sum   : array[0..MaxN] of longint;
  max             : array[0..MaxN,0..MaxN] of integer;

    procedure print(i,j: integer);
    begin
      if i = 0 then writeln(fout,j) {cant}
      else begin
        print(last[i],j + 1);
        writeln(fout,i - last[i]);
      end;{else}
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    readln(fin,max[i,i],sum[i]);
    inc(sum[i],sum[i - 1]);
  end;{for}

  {init}
  for i:=1 to N do
  begin
    k := 0;
    for j:=i to N do
    begin
      if max[j,j] > k then k := max[j,j];
      max[i,j] := k;
    end;{for}
  end;{for}

  {solve}{dp}
  for i:=1 to N do
    for j:=1 to i do
      if sum[i] - sum[j - 1] <= M then
        if (cost[j - 1] + max[j,i] < cost[i]) or (cost[i] = 0) then
        begin
          last[i] := j - 1;
          cost[i] := cost[j - 1] + max[j,i];
        end;{then}

  {dprint}
  write(fout,cost[N],' ');
  print(N,0);

  {fclose}
  close(fin); close(fout);
end.{main}

{
11þ Estante de  altura m¡nima.                           Croacia  2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los habitantes de IslaGrande  tienen muchos libros y  ellos decidieron
construir un estante con maderas preciosas. Con esas maderas se  puede
construir un estante que estrictamente  va a tener un ancho  fijo pero
cualquier altura. El  estante tendr  divisiones  y los libros  en cada
divisi¢n se van a colocar parados.

Cada libro est  correctamente  identificado por su n£mero de  cat logo
y ellos deben ser  colocados seg£n el orden  de su cat logo o  sea que
delante del libro i en una divisi¢n solo se puede colocar el libro con
n£mero de cat logo i-1 y a la derecha en una divisi¢n solamente  puede
estar el libro con n£mero de cat logo i+1.

Inicialmente los libros se encuentran  apilados uno encima del otro  y
queremos ubicarlos en el orden de su n£mero de cat logo. De cada libro
se conoce su altura y su ancho.

Para poner los  libros en el  estante se necesitan  colocar divisiones
cuya altura corresponder   a la del  libro m s alto.  Todos los libros
deben  ser  colocados  en  el  estante.  Se  pueden  utilizar   tantas
divisiones como se deseen,  pero la suma de  los anchos de los  libros
colocados en una misma divisi¢n  no debe sobrepasar el ancho  fijo del
estante.

Dada una colecci¢n  de N libros  el problema consiste  en ubicar todos
los  libros  en  el   estante,  colocando  las  divisiones   que  sean
necesarias,  del tal manera que la altura del mismo sea lo m s peque¤a
posible.

Tarea

Hacer  un  programa que  permita:

- Leer  desde  fichero de  entrada ESTANTE.IN el ancho de estante y la
  altura y el ancho de cada uno de los N libros.

- Determinar   la altura m¡nima del estante.

- Escribir hacia el fichero  de salida ESTANTE.OUT  el valor de  la
  altura m¡nima encontrada y la cantidad de libros en cada divisi¢n.

Entrada

El fichero de entrada ESTANTE.IN contiene: L¡nea 1: N (1 <= N <=  100)
y W (2 <=  W <= 10000), separados  entre si por un  espacio en blanco,
los cuales  representan la  cantidad de  libros y  ancho del  estante.
L¡nea 2..N+1: Se escribir  en cada una de estas l¡neas la  descripci¢n
de cada libro de la siguiente manera: un entero Hi (1 <= Hi <=  10000)
que representa la altura de i-‚simo libro  y Wi (1 <= Wi <= 10000)  el
cual representa el ancho del i-‚simo libro.

Salida

El fichero de salida ESTANTE.OUT  contiene: L¡nea 1: HM y  R separados
entre si por un  espacio. Ellos representan respectivamente  la altura
m¡nima del estante y la cantidad de divisiones del mismo.

L¡nea 2..R+1: en cada una de  ellas se colocar  la cantidad de  libros
por divisiones.

Ejemplo de Entrada y Salida

ESTANTE.IN

16 14
5 4
4 3
5 4
6 1
3 2
1 1
3 5
8 3
4 1
5 3
4 1
6 2
5 2
2 2
5 3
6 1


ESTANTE.OUT

19 3
3
6
7

Note que en la primera divisi¢n fueron colocados los libros 1, 2 y  3.
En la segunda divisi¢n los  libros 4, 5, 6, 7,  8, y 9. En la  tercera
divisi¢n  los libros 10, 11, 12, 13, 1 4, 15 y 16.

Las  alturas  de  cada   una  de  las   divisiones   son  5,  8  y   6
respectivamente, Obteni‚ndose as¡ una altura  total del estante de 19.


}