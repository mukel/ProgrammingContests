{koder: A^2P}{18 - 3 - 2007}
{PSN 2004 #89 "Cartero"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 200;
  MaxM = 1000;
type
  edge = record
    index,node : word;
  end;{edge}
var
  fin,fout        : text;
  N,M,i,j,k,sol   : longint;
  size            : array[0..MaxN] of byte;
  cam             : array[0..MaxM] of byte;
  mark            : array[0..MaxM] of boolean;
  list            : array[0..MaxN,0..MaxM] of edge;

    procedure eulerize(i: byte);
    var j : byte;
    begin
      for j:=1 to size[i] do
        if not mark[list[i,j].index] then
        begin
          mark[list[i,j].index] := true;
          eulerize(list[i,j].node);
          inc(sol); cam[sol] := i;
        end;{then}
    end;{eulerize}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do readln(fin);
  for i:=1 to M do
  begin
    readln(fin,j,k);
    inc(size[j]); list[j,size[j]].node := k;
    list[j,size[j]].index := i;
    inc(size[k]); list[k,size[k]].node := j;
    list[k,size[k]].index := i;
  end;{for}

  {solve}{euler-tour}
  eulerize(1);

  {dprint}
  writeln(fout,sol);
  cam[0] := 1;
  for i:=0 to sol do
    write(fout,cam[i],' ');

  {fclose}
  close(fin); close(fout);
end.{main}

{
89ş Cartero.                                               Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En un distrito rural un cartero tiene que entregar env¡os por correos
a clientes que viven en pueblos y junto a cada uno de los caminos que
conectan los pueblos.

Su tarea es ayudar al cartero a dise¤ar una ruta que vaya a cada
pueblo y a cada camino al menos una vez. Los datos de la entrada son
tales que siempre es posible. Sin embargo, cada ruta tambi‚n tiene un
costo. Las personas en los pueblos desean que el cartero visite su
pueblo tan pronto como sea posible. Por consiguiente cada pueblo tiene
hecho el siguiente trato con el correo: si el pueblo i es visitado
como el k-‚simo pueblo diferente en el viaje y k <= w(i), el pueblo
paga w(i)-k euros al correo, sin embargo, si k > w(i), el correo
acepta pagar k-w(i) euros al pueblo. Adem s, el correo paga al cartero
1 euro por cada camino en el viaje.

Hay N pueblos, numerados desde 1 hasta N. El correo est  localizado en
el pueblo 1, de esta manera la ruta comienza y termina en este pueblo.
Cada pueblo est  asentado en el cruce de 2 caminos, en el cruce de
4 caminos o est  en un camino que va directo al pueblo (por
ejemplo, hay 2, 4 u 8 caminos que salen de cada pueblo). Pueden haber
varios caminos conectando los mismos pueblos o un camino puede
hacer un lazo, es decir, conectar un pueblo con el mismo.

Tarea

Su tarea es escribir un programa que:

. Lea la descripci¢n de los pueblos y la conexi¢n de los caminos,
  desde el fichero de entrada POS.IN.
. Dise¤ar tal ruta que valla a trav‚s de cada pueblo y camino al
  menos una vez y maximice la ganancia total (o miniminice las
  p‚rdidas) del correo.
. Escriba el resultado en el fichero de salida POS.OUT.

Si hay varias soluciones posibles, su programa debe escribir
cualquiera de ellas.

Entrada

En la primera l¡nea del fichero de entrada POS.IN hay dos enteros N
y M, separados por un espacio simple, N es el n£mero de pueblos (1 <=
N <= 200) y M es el n£mero de caminos. En cada una de las
siguientes N l¡neas hay un entero positivo. La i+1-‚sima l¡nea
contiene w(i), 1 <= w(i) <= 1000, especificando los honorarios pagados
por el pueblo i. En cada una de las siguientes w l¡neas hay dos
enteros positivos separados por un espacio simple. Pueblos conectados
por caminos sucesivos.

Salida

El programa debe de escribir un entero positivo K, el largo de la
ruta, en la primera l¡nea del fichero de salida POS.OUT. La
siguiente l¡nea contendr  K+1 n£meros, los pueblos consecutivos en la
ruta P1, P2, ... Pk+1, separados por un espacio en blanco, con P1 =
Pk+1 = 1

Ejemplo de entrada y salida

ÚÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ POS.IN   ³  ³ POS.OUT         ³
ÃÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 6 7      ³  ³ 7               ³
³ 1        ³  ³ 1 5 4 2 1 6 3 1 ³
³ 7        ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 4        ³                          7          10
³ 10       ³                       ÚÄÄ¿       ÚÄÄ¿
³ 20       ³                       ³2 ÃÄÄÄÄÄÄÄ³4 ³
³ 5        ³                       ÀÂÄÙ       ÀÂÄÙ
³ 2 4      ³                        ³          ³
³ 1 5      ³            5           ³ 1        ³  20
³ 2 1      ³           ÚÄÄ¿        ÚÁÄ¿       ÚÁÄ¿
³ 4 5      ³           ³6 ÃÄÄÄÄÄÄÄÄ´1 ÃÄÄÄÄÄÄÄ´5 ³
³ 3 6      ³           ÀÂÄÙ        ÀÂÄÙ       ÀÄÄÙ
³ 1 6      ³            ³           ³
³ 1 3      ³            ³           ³
ÀÄÄÄÄÄÄÄÄÄÄÙ            ³           ³  4
                        ³          ÚÁÄ¿
                        ÀÄÄÄÄÄÄÄÄÄÄ´3 ³
                                   ÀÄÄÙ
}