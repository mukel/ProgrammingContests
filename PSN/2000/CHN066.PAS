{koder: A^2P}
{PSN 2000 #66 "Faenas"}{k^2}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  N,i,j,k,sol     : longint;
  c               : array[0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    read(fin,j,k);
    repeat
      read(fin,j);
      if c[j] + k > c[i] then c[i] := c[j] + k;
    until j = 0;
    if c[i] > sol then sol := c[i];
  end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 66ş Faenas                                                 China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los  peones  del  Rey  del  Ganado abarcan todas las faenas durante el
orde¤o.  Ellos  reunen  todas  las  vacas,  las ponen en los establos,
lavan  sus  ubres  y  ejecutan  otras tareas. Los peones organizan las
faenas  de  manera  que puedan cumplir con estas lo m s r pido posible
para poder continuar con otras.

Por   supuesto,	algunas  faenas  no pueden comenzar hasta que otras no
sean  completadas.  Por  ejemplo,  es imposible lavar las ubres de las
vacas   hasta	que  no  est‚n en el establo, y no se le puede poner las
m quinas de orde¤o hasta que no est‚n lavadas las ubres.

El  Rey  del  Ganado  tiene  una  lista  de  N faenas  que  deben  ser
completadas.    Cada  una  de las faenas requiere de  un n£mero entero
de  minutos  para  realizarse.  Cada  faena  tiene una lista de faenas
anteriores  a  ella,  que deben  completarse antes que  esa  faena sea
hecha.

Al  menos  una faena no tiene faenas anteriores que deban hacerse: por
ejemplo la primera, numerada con '1'.  La  lista de los peones del Rey
del  Ganado  est  sutilmente ordenada, la faena K (K  > 1) puede tener
solamente 1 ... K-1 faenas en esta lista de dependencia.

Escribir	un programa que:

- Lea la lista de faenas desde  la 1 hasta la N con el tiempo asociado
	y una lista de prerequisitos.

- Calcule el menor tiempo que tomar  completar todas las N faenas.

Por  supuesto,  faenas  que no  dependan  unas   de  otras  pueden  ir
realiz ndose  simult neamente  en    paralelo.  Esto  significa que un
n£mero grande de faenas pueden ser realizadas simult neamente.

Fichero de Entrada

L¡nea 1: un n£mero entero N, el n£mero de faenas (1 ó N ó 10000).

L¡nea 2 .. N+1: N l¡neas, con enteros diferentes cada una:

. El n£mero  de  la  faena (1..N suministrado en  el orden del fichero
	de entrada.

. La duraci¢n    de   la  faena en  minutos (un n£mero  entre 1 y 100,
	incluidos ambos).

. Una  lista no mayor de 100 faenas anteriores, terminando con un 0.
  Algunas faenas  no  tienen  faenas  anteriores  a  ella  y por tanto
	solamente aparece el n£mero 0.

Fichero de Salida

El  fichero  de  salida  contendr   en  una sola l¡nea el menor tiempo
calculado, que tomar  completar todas las N faenas.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo de Entrada³³Ejemplo de Salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 7 							 ³³ 23							³
³ 1 5 0 					 ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 2 2 1 0 				 ³
³ 3 3 2 0 				 ³
³ 4 6 1 0 				 ³
³ 5 1 2 4 0 			 ³
³ 6 8 2 4 0 			 ³
³ 7 4 3 5 6 0 		 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
