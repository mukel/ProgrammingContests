{koder: A^2P}{28 - 2 - 2007}
{PSN 2007 #14 "Lamparas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxG = 100;
  MaxN = 10000;
var
  fin,fout        : text;
  N,M,G,i,j,sol   : longint;
  s               : string[3];
  a,d,rounds      : array[0..MaxG] of longint;
  mark            : array[0..2 * MaxN] of boolean;
  guard           : array[0..MaxG] of string[3];

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,G,M);
  for i:=1 to G do
    readln(fin,guard[i],a[i],d[i]);

  {solve}
  for i:=1 to M do
  begin
    readln(fin,s);
    for j:=1 to G do
      if guard[j] = s then break;
    rounds[j] := rounds[j] xor 1;
  end;{for}

  for i:=1 to G do
    if rounds[i] <> 0 then
      for j:=0 to N div d[i] do
        mark[j * d[i] + a[i]] := not mark[j * d[i] + a[i]];

  for i:=1 to N do
    if mark[i] then inc(sol);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

(*
14ş Lamparas.                                             Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un edificio tiene un largo  corredor con L l mparas etiquetadas  desde
1, 2,  3, ...,  L. cada  l mpara tiene  un interruptor individual para
apagarla (off) o  encenderla (on). Los  encargados del edificio  son G
guardias de seguridad (no dos  guardias tienen el mismo nombre),  cuyo
trabajo  por  la  noches  es patrullar  el  corredor  y  verificar las
l mparas  encendidas  y  apagadas.  A cada  guardia  se  le  asigna un
subconjunto de l mparas. Durante una  ronda, un guardia caminar  a  lo
largo del corredor, y verifica las l mparas asignadas a  ‚l (es decir,
si una l mpara est  en on,  el interruptor est  en off; si  la l mpara
est  en off el interruptor est  en on). Despu‚s otro guardia  verifica
cada l mpara asignada a ‚l exactamente una vez, el guardia no  volver 
a patrullar  hasta su  pr¢xima ronda.  Un guardia  puede tener  m s de
ronda en una noche. El orden de patrullar para los guardias es dictado
por una lista de nombres.

Todas las l mparas est n en off antes que los guardias comiencen hacer
su ronda, y solo un guardia patrulla en cualquier momento.

La asignaci¢n  de  las l mparas para  los guardia es  especificado por
dos  enteros  positivos, a0  y d.  El subconjunto  de l mparas  de los
guardias se verificar como: {a0, a0 + d, a0 + 2d, ..., a0 + kd}  donde
k es el entero m s largo tal que a0 + kd = L.

Dado  la asignaci¢n  de l mparas  parar cada  guardia y  la lista  de
nombres, encuentre  cu ntas l mparas  hay encendida despu‚s que  todos
los guardias han terminado todas sus rondas.

Ejemplo

Supongamos que  hay 10  l mparas, dos   guardias de  seguridad (Edi  y
Lou), y  tres rondas  de patrulla.  Las l mparas  asignadas a Edi's es
(a0, d) = (1, 4) y las l mparas asignadas a Lou's es (a0, d) = (2, 3).
El orden de patrullar es Edi, Lou, Edi.

Despu‚s  de la  primera ronda  por Edi,  las l mparas  1, 5,  y 9  son
encendidas. Durante la segunda ronda, Lou verifica las l mparas 2,  5,
y 8. Por consiguiente en la segunda  ronda, las l mparas 1, 2, 8, y  9
est n en on pero  la l mpara 5 cambia  su estado a off.  En la tercera
ronda, Edi  patrulla de  nuevo, y  verifica las  l mparas 1,  5, y  9.
Consecuentemente, despu‚s  de todas  las rondas  especificadas por  la
lista de nombres, las l mparas que quedan en on son 2, 5, y 8.

El n£mero de l mparas que quedan en on despu‚s que todos los  guardias
terminan sus rondas es 3.

Entrada

La  primera l¡nea  del fichero  de entrada  LAMP.IN consiste  de tres
enteros positivos, separados por un caracter espacio. El primer n£mero
L <= 10000 es el n£mero de l mparas. El segundo n£mero G <= 100 es  el
n£mero de guardias de  seguridad, y el tercer  n£mero R <= 1000  es el
n£mero total de rondas. Las  pr¢ximas G l¡neas contienen los  nombre y
l mpara asignadas a los guardias. Cada una de estas G l¡neas consisten
en el nombre (exactamente 3 letras en el alfabeto ingles), a0 y d, (a0
= N) separado con un  espacio. Las siguientes R l¡neas  especifican la
lista de  nombres a  patrullar. Cada  l¡nea continene  el nombre de un
guardia (se garantiza que  todos tienen l mparas asignadas).  El orden
de los guardias aparecer  en la  lista de nombres dictada en el  orden
de patrullar.

Salida

El fichero de salida LAMP.OUT contiene un entero el cual es el  n£mero
de l mparas que quedan encendidas  despu‚s de todas las rondas  de los
guardias

Entrada/Salida Ejemplo

Para el ejemplo de arriba la entrada y salida son los siguientes

Ejemplo Entrada
                10 2 3
                Edi 1 4
                Lou 2 3
                Edi
                Lou
                Edi
Ejemplo Salida
                3
*)
