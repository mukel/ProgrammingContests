/*
Alfonso Alfonso Peterssen
1 - 8 - 2007
PSN 2007 #60 "Vacas De La Mesa Redonda" -> Que sugerente...
*/
#include <cstdio>
#include <cstdlib>

#define problem "d"

#define MAXN 20

int mark[MAXN];
int N, M, i, sol;
int seq[MAXN], tup[MAXN];

  void perm( int i, int j ) {

    if ( j && ( abs( seq[i] - seq[ tup[j - 1] ] ) > M ) )
      return;

    if ( j == N - 1 ) {
      if ( abs( seq[i] - seq[0] ) <= M ) sol++;
      return;
    }

    tup[j] = i;
    mark[i] = true;
    for ( int k = 0; k < N; k++ )
      if ( !mark[k] ) perm( k, j + 1 );
    mark[i] = false;
  }

int main () {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d\n",&N, &M );
  for ( i = 0; i < N; i++ )
    scanf( "%d\n", &seq[i] );

  perm( 0, 0 );

  printf( "%d\n", sol );

  return 0;
}

/*
60þ Vacas De La Mesa Redonda.                             Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero  Juan est   llamando a  sus N  (1 <=  N <=  10) vacas a un
reuni¢n muy importante en una mesa redonda.

Las  vacas est n  algo ansiosas  acerca de  esta reuni¢n,  pues  ellas
quieren dar  su mejor  imagen. Para  hacer la  distribuci¢n de la mesa
atractiva,  ellas  quieren  asegurarse  que  cualesquiera  dos   vacas
sentandas  juntas difieran  en altitud  en no  mas de  K (1  <= K   <=
1,000,000) mil¡metros (la vaca i tiene una altura entera de H_i (1  <=
H_i <= 1,000,000) mil¡metros).

Ayude a calcular el n£mero de maneras en que las vacas pueden sentarse
en la mesa redonda  de tal manera que  ning£n par de vacas  adyacentes
difieran en altura por m s de K mil¡metros. Dos maneras son diferentes
si hay al menos una vaca con una vaca diferente a su izquierda en cada
arreglo.

Se garantiza  que la  respuesta entrar   en un  entero de  32 bits con
signo.

NOMBRE DEL PROBLEMA: round

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio: N y K

- L¡neas 2..N+1: La l¡nea i+1 contiene la altura H_i.

Entrada Ejemplo (archivo round.in):

4 10
2
16
6
10

DETALLES DE LA ENTRADA:

Hay 4 vacas, con alturas 2, 16, 6, y 10. No se quiere que haya  ning£n
par de vacas adyacentes cuya altura difiera en m s de 10.

FORMATO DE SALIDA:

- L¡nea 1: El n£mero maneras en que las vacas puedan sentarse en la mesa
      redonda de tal  manera que dos  vacas adyacentes no  difieran en
      altura por m s de K mil¡metros.

SALIDA EJEMPLO (archivo round.out):

2

DETALLES DE LA SALIDA:

Claramente las  vacas con  alturas 2  y 16  deben estar  en posiciones
opuestas,  de tal  manera que  hay 2  maneras de  poner las  vacas  de
alturas 6 y 10.
*/
