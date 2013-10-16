{koder: A^2P}
{PSN 2004 #102 "Limpieza de albergue"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N               : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  repeat
    readln(fin,N);
    if odd(N) then writeln(fout,'No')
      else writeln(fout,'Yes');
  until seekeof(fin);

  {fclose}
  close(fin); close(fout);
end.{main}

{
102þ Limpieza de albergue.                                 Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

A usted y otro  estudiante  (el contrario)  se  le  ha  sido  dada  la
responsabilidad  de  limpiar  el  albergue.  La  limpieza del albergue
consiste  en recoger todos los papeles que hay en el piso del albergue
Usted  y el contrario convienen desempe¤ar la tarea teniendo en cuenta
las  reglas de un juego que acaban de inventar. El juego se desarrolla
de la siguiente forma :

-Usted es el primero que juega.

-El jugador al cual le toca jugar recoge del piso una  cantidad  k  de
papeles tal que k divida m (k > 0), donde m es la cantidad de  papeles
que hay en el piso en ese instante.

-El jugador que recoja todos los papeles que queden en el piso pierde.


Tarea

Se  le  dar n  cinco  n£meros,  y debe decir para cada uno de ellos si
usted puede asegurar que ganar  para esa cantidad  de  papeles  en  el
piso.

Fichero de Entrada

El nombre del fichero de entrada ser  CLEANING.IN.  El cual consistir 
de  cinco  l¡neas conteniendo cada una un entero n (1<=n<=2147483647).

Fichero de Salida

El  nombre del fichero de salida ser  CLEANING.OUT. Este consistir  de
cinco l¡neas. Cada l¡nea contendr  se deber  poner la palabra "Yes" si
usted puede garantizar ganar el  juego  sin  importar  la  jugada  del
contrario,  si  usted  no puede garantizar esto entonces debe imprimir
la palabra "No".  La i-‚sima l¡nea de la salida corresponde al  n£mero
de la i-‚sima l¡nea de la entrada.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ CLEANING.IN ³      ³ CLEANING.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 2           ³      ³ Yes          ³
³ 3           ³      ³ No           ³
³ 30          ³      ³ Yes          ³
³ 1           ³      ³ No           ³
³ 13          ³      ³ No           ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


Ejemplo de juego para cuando hay 30 papeles en el piso :

   Jugador     Cant de papeles en el piso   Cant de papeles que recoge

   usted                    30                       15
   contrario                15                       5
   usted                    10                       5
   contrario                5                        5

Y como se acabaron los papeles y el contrario fue el £ltimo  en  jugar
entonces usted gana.

En  la  primera jugada del contrario puede ser que no recoja 5, pudiera
recoger 1, 3, ¢ 15,  pero  de  todas  formas  usted  puede asegurar que
ganar  al final.
}