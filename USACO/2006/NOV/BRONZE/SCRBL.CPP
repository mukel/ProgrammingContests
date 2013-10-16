/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 NOV Bronze "Juegos de Palabras"
*/
#include <cstdio>
#include <cstring>

#define problem "d"
#define MAXLEN 30

int len, D, i, com, diff;
char word[MAXLEN];
int frq[256], target[256];
char *ch;

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &len, &D );

  scanf( "%s", &word );
  for ( ch = word; *ch; target[ *( ch++ ) ]++ )
    com += ( *ch == '#' );

  freopen( "scrbl.txt", "r", stdin );

  for ( ; D; D-- ) {

    scanf( "%s", &word );
    for ( ch = word; *ch; frq[ *( ch++ ) ]++ );

    diff = 0;
    for ( i = 'A'; i <= 'Z'; frq[i++] = 0 )
      if ( frq[i] > target[i] )
        diff += frq[i] - target[i];

    if ( com >= diff )
      printf( "%s\n", word );
  }

  return 0;
}

/*
Problema 12: Juegos de Palabras [Kolstad, 2006]

Las vacas están jugando Scrabble, pero tristemente, ellas no tienen el
vocabulario para jugar en el nivel de torneo. Bessie quiere que usted
ayude simplemente para la primera movida. Dado su atril (un “atril” es en
donde cada uno de los jugadores tiene sus fichas) de N (3 <= N <= 10)
letras (las cuales podrían o no podrían ser únicas y podrían incluir una
o más fichas “comodines”) junto con un diccionario scrabble de D (10 <= D
<= 50000) palabras, imprima las palabras que ella podría usar
(buscándolas en el diccionario).

Las 27 letras posibles son las mayúsculas 'A'..'Z' y el símbolo '#', que
representa un “comodín” y puede reemplazar cualquier letra. Si dos '#'
aparecen en un atril, entonces cada uno representara una letra diferente
en el juego.

Las palabras en el diccionario pueden ser leídas, una por línea, del
archivo cuyo nombre es 'scrbl.txt' (el nombre del archivo está en
minúsculas, pero no así su contenido). Las letras en el pilar de Bessie
pueden ser siempre usadas para hacer al menos una palabra. Cada palabra
en el diccionario es única. Recuerde que usted está corriendo en Linux:
cada línea de entrada termina con un carácter '\n'; no están presentes
caracteres 'return'.

NOMBRE DEL PROBLEMA: scrbl

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio, N y D.

* Línea 2: N letras (sin espacios intermedios) que son las letras en el
     atril de scrabble de Bessie.

ENTRADA EJEMPLO (archivo scrbl.in):

4 49891
IAFR

DETALLES DE LA ENTRADA

Cuatro letras: I, A, F, y R.

FORMATO DE SALIDA:

* Líneas 1..??: Cada línea contiene una sola palabra que aparece en el
     diccionario scrbl.txt. Imprima la salida en el orden en que las
     palabras aparecen en el diccionario.

SALIDA EJEMPLO (archivo scrbl.out):

AIR
FAIR
FAR
FIR
IF

DETALLES DE LA SALIDA:

Estas palabras aparecen realmente en el diccionario real usado para este
problema.
*/
