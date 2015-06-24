/*
Alfonso Alfonso Peterssen
22 - 6 - 2007
IOI 2006 Day 1 Problem 1
PSN 2007 #1 "Writing"
*/
#include <cstdio>

#define problem "d"

#define MAXP 10000
#define MAXT 3000000
#define ALPHA 256

#define CMP( i ) ( freq[ text[i] ] == target[ text[i] ] )

int P, T, i, diff, sol;
int freq[ALPHA], target[ALPHA];
char pat[MAXP], text[MAXT];

int main() {
  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d\n", &P, &T );
  scanf( "%s\n", &pat ); scanf( "%s\n", &text );

  for ( i = 0; i < P; i++ )
    target[ pat[i] ]++, freq[ text[i] ]++;

  for ( i = 0; i < ALPHA; i++ )
    if ( freq[i] != target[i] ) diff++;

  if ( !diff ) sol++;
  for ( i = P; i < T; i++ ) {
    if CMP(i) diff++;     freq[ text[i] ]++;     if CMP(i) diff--;
    if CMP(i - P) diff++; freq[ text[i - P] ]--; if CMP(i - P) diff--;
    if ( !diff ) sol++;
  }

  printf( "%d\n", sol );

  return 0;
}

/*
1þ Writing.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El desciframiento/descifrado de la  escritura Maya ha probado  ser m s
dif¡cil de lo que se  esperaba luego de las primeras  investigaciones.
Despu‚s de  casi doscientos  a¤os, muy  poco es  lo que  se ha logrado
entender. Reci‚n en las £ltimas  tres d‚cadas se han obtenido  avances
significativos.

La  escritura  maya est   basada  en peque¤os  dibujos  conocidos como
glifos que representan sonidos.  Las palabras mayas est n  normalmente
escritas como glifos puestos juntos en varias posiciones.

Uno de los tantos problemas  en descifrar la escritura Maya  surge del
orden  de lectura.  Cuando acomodaron  varios glifos  para formar  una
palabra, los escribas mayas a veces decidieron las posiciones  basados
m s en  la propia  est‚tica que  en alguna  regla en  particular. Esto
lleva  al  hecho que,  aun  cuando el  sonido  para varios  glifos  es
conocido, a veces los arque¢logos no est n seguros de c¢mo  pronunciar
una palabra escrita.

Los arque¢logos est n buscando  una palabra particular W.  Ellos saben
los glifos que la integran, pero no conocen todas las formas  posibles
de ordenarlos. Desde que  ellos se enteraron que  ustedes participar n
en la IOI 06, les han pedido su ayuda. Ellos les dar n los g glifos de
la palabra  W y  la secuencia  S de  los glifos  (en el  orden en  que
aparecen)  en el  grabado/escrito que  est n estudiando.  Ay£denlos  a
contar el n£mero de todas las posibles apariciones de la palabra W.

TAREA

Escriba un  programa que,  dados los  glifos para  la palabra  W y  la
secuencia S  de los  glifos en  el grabado/escrito,  cuente todas  las
posibles apariciones de W en S,  esto es que cualquier secuencia de  g
glifos consecutivos en S es una permutaci¢n de glifos en W.

RESTRICCIONES

1 <= g <= 3 000		   cantidad  de glifos que componen  W
g <= |S| <= 3000000	 donde |S| es la cantidad de glifos que componen
                     la secuencia S

ENTRADA

Su  programa  debe  leer  los  siguientes  datos  del archivo
writing.in

writing.in
4 11
cada
AbrAcadAbRa

Descripcion de la  Entrada

LINEA1: Contiene  2 enteros separados   por un espacio que representan
g y |S|.
LINEA  2: Contiene   g caracteres  consecutivos que   representan los
glifos que  componen  W. Los   caracteres  v lidos  son ïaï-ïzï y  ïAï
-ïZï; may£sculas y  min£sculas se  consideran diferentes.
LINEA  3:Contiene |S|  caracteres  consecutivos  que  representan  los
glifos del  grabado. Los  caracteres  v lidos  son ïaï-ïzï  y ïAï-ïZï;
may£sculas  y min£sculas se consideran diferentes.

SALIDA

Su programa  debe escribir  los siguientes  datos del  archive
writing.out

writing.out
2

DESCRIPCION
LINEA 1: Debe contener la cantidad de posibles apariciones de W en S.

PUNTUACION

Para un  conjunto de casos  de prueba que  valen 50 puntos, cada  caso
corrido cumplir  el requerimiento que g = 10.

NOTA IMPORTANTE PARA PROGRAMADORES DE PASCAL Por defecto en FreePascal
una  variable  de  tipo  string  tiene  una  longitud  l¡mite  de  255
caracteres. Si usted  desea usar cadenas  m s largas que  eso, deber n
agregarle la directiva  {$H+}  en su  c¢digo justo debajo  de la l¡nea
program ...;
*/
