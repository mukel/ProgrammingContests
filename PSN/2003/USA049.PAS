{koder: A^2P}{5 - 5 - 2007}
{PSN 2003 #49 "Dos"}
{
  Esto es despues de ver la solucion oficial,
  la primera que me funcion¢ tenia 157 lineas... Pig Pascal
  Deberia decir que A < B en la entrada
}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
type
  node = record
    B,len,next  : longint;
  end;{node}
var
  fin,fout        : text;
  N,S,i,j,sol     : longint;
  list            : array[0..MaxN] of node;
  P               : array[0..MaxN] of longint;

    function dfs(nod: longint): longint;
    var tmp,max : longint;
    begin
      max := 0;
      nod := P[nod];
      while nod <> 0 do
      begin
        tmp := dfs(list[nod].B) + list[nod].len;
        if tmp + max > sol then sol := tmp + max;
        if tmp > max then max := tmp;
        nod := list[nod].next;
      end;{while}
      dfs := max;
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N - 1 do
  begin
    readln(fin,j,list[i].B,list[i].len);
    inc(S,list[i].len);
    list[i].next := P[j];
    P[j] := i;
  end;{for}

  {solve}
  dfs(1);

  {dprint}
  writeln(fout,2 * S - sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
49ş Dos.                                                      USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La  ciudad  consiste  de  intersecciones  y  calles que las conectan a
ellas.  Una nieve espeza cubre la ciudad tal que el mayor Milan di¢ al
servicio  de  invierno  una  lista  de  las  calles que tienen que ser
limpiadas  de  nieve.  Estas  calles son elegidas tal que el n£mero de
calles  sea  tan  peque¤o  como  sea  posibles  pero  todav¡a cada dos
intersecciones    habr   exactamente  un  camino  es  decir  cada  dos
interseccones  habr   exactamente  un  camino. El servicio de invierno
consiste  de dos m quinas barredoras de nieve y dos conductores, Mirko
y Slavko, y su posici¢n  de comienzo en una de las intersecciones.

Las  m quinas barredoras de nieve consumen un litro de combustible por
metro  (aun si este est  atravesando una calle que ya ha sido limpiada
de  nieve)  y estos tienen que limpiar todas las calles de la lista en
un orden tal que el combustible total gastado sea m¡nimo. Cuando todas
las calles son limpiadas de nieve, las m quinas barredoras de nieve son
parqueadas  en  la  £ltima  intersecci¢n  que ellas visitaron. Mirko y
Slavko no tienen que finalizar su trabajo en la misma intersecci¢n.

Tarea

Escriba  un  programa que calcule la cantidad total de combustible que
las m quinas barredoras de nieve gastar¡an.

Entrada

La primera l¡nea  del fichero de entrada TWO.IN contiene dos enteros:
N  y  S,  1  <=  N  <=  100000,  1  <=  S <=N, N es el n£mero total de
intersecciones,  S es el n£mero ordinal de la intersecci¢n de comienzo
de las dos m quinas. Las intersecciones est n marcada con n£meros 1..N.
Cada  una de las pr¢ximas N-1 l¡neas contienen tres enteros: A, B y C,
representando   que  las  intersecciones  A  y  B  est n  directamente
conectadas  por una calle y que la longitud de la calle  es  C metros,
1 <= C <= 1000.

Salida

Escriba  hacia el fichero de salida TWO.OUT la cantidad de combustible
necesario para limpiar todas las calles.

Ejemplos de Entrada y Salida

  Ejemplo  # 1            Ejemplo # 2            Ejemplo # 3
ÚÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄ¿
³ TWO.IN ³³ TWO.OUT ³   ³ TWO.IN ³³ TWO.OUT ³   ³ TWO.IN ³³ TWO.OUT ³
ÃÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄ´
³ 5 2    ³³ 6       ³   ³ 5 1    ³³ 5       ³   ³ 4 1    ³³ 11      ³
³ 1 2 1  ³ÀÄÄÄÄÄÄÄÄÄÙ   ³ 1 2 1  ³ÀÄÄÄÄÄÄÄÄÄÙ   ³ 1 3 2  ³ÀÄÄÄÄÄÄÄÄÄÙ
³ 2 3 2  ³              ³ 2 3 1  ³              ³ 1 2 3  ³
³ 3 4 2  ³              ³ 3 5 1  ³              ³ 1 4 4  ³
³ 4 5 1  ³              ³ 3 4 1  ³              ÀÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÙ              ÀÄÄÄÄÄÄÄÄÙ
}
