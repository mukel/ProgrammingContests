{koder: A^2P}{3 - 5 - 2007}
{PSN 2004 #10 "Tachando N£meros"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,sol         : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);

  {solve}
  dec(M); sol := 1;
  while sol + (sol + M - 1) div M <= N
    do inc(sol,(sol + M - 1) div M);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
10þ Tachando N£meros                                       Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

  Se escriben los n£meros del 1 al N en una fila uno al lado del otro.
Comenzando por el primer n£mero en la fila se numera  desde 1 hasta M:
1, 2, ..., M, 1, 2, ..., M, 1, 2, ..., M, 1, 2, ... y as¡ susecivamen-
te hasta  el £ltimo n£mero  de la fila y se tachan los  que coincidie-
ron con el n£mero 1 en la numeraci¢n. Los n£meros que no fueron tacha-
dos se vuelven a escribir en una fila uno al lado del otro y se repite
el mismo proceso hasta que no queden  n£meros sin tachar. ¨Cu l fue el
£ltimo n£mero sin tachar?

Ejemplo:
Se escriben los n£meros del 1 al 5 y se numera del 1 al 3.
1û 2ý 3ü 4û 5ý  se tachan los que coincidieron con 1 en la numeraci¢n.
2û 3ý 5ü        se vuelven a escribir los n£meros que no se tacharon.
3û 5ý
5û              el 5 fue el £ltimo.


Tarea

Escriba un programa que:
-Lea del fichero de entrada TACHADO.IN los n£meros N y M.
-Calcule cu l fue el £ltimo n£mero tachado con el m‚todo descrito.
-Escriba el resultado para el fichero de salida TACHADO.OUT.

Entrada

El fichero de entrada TACHADO.IN contiene dos enteros N(1<=N<=1000000)
y M(1<=M<=N) en la primera l¡nea separados por un espacio.

Salida

El fichero de salida TACHADO.OUT  debe contener una £nica l¡nea con un
entero: el £ltimo n£mero tachado de acuerdo con el rpoblema descrito.

Ejemplo #1 de Entrada y Salida          Ejemplo #2 de Entrada y Salida

TACHADO.IN         TACHADO.OUT          TACHADO.IN         TACHADO.OUT
ÚÄÄÄÄÄÄÄ¿           ÚÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄ¿           ÚÄÄÄÄÄÄÄÄ¿
³ 5 3   ³           ³ 5      ³          ³ 13 4  ³           ³ 11     ³
ÀÄÄÄÄÄÄÄÙ           ÀÄÄÄÄÄÄÄÄÙ          ÀÄÄÄÄÄÄÄÙ           ÀÄÄÄÄÄÄÄÄÙ
}