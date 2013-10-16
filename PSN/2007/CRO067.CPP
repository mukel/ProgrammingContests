/*
Alfonso Alfonso Peterssen
2 - 8 - 2007
PSN 2007 #67 "Coleccionista de monedas"
*/
#include <cstdio>

#define problem "d"
#define MAXN 500001

int N, M, i, j, chng, sol;
int coin[MAXN];
bool mark[MAXN];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &N, &M );
  for ( i = 0; i < N; i++ ) {
    scanf( "%d %d", &coin[i], &j );
    mark[i] = ( j == 1 );
  }

  coin[N] = M;
  for ( i = 0; i < N; i++ )
    if ( !mark[i] && chng + coin[i] < coin[i + 1] ) {
      sol++;
      chng += coin[i];
    }

  printf( "%d\n", sol );
  printf( "%d\n", M - chng - ( chng == 0 ) );

  return 0;
}

/*
67þ Coleccionista de monedas.                             Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En   un   cierto   pa¡s,  hay  N  denominaciones   de   monedas     en
circulaci¢n,     incluyendo     la    momeada    de     un    centavo.
Adicionalmente,  hay billetes   cuyos  valores   de  K   centavos  es
conocido   que    exceden  cualquiera  de  las  monedas.   Existe   un
coleccionista de  monedas quien desea coleccionar una muestra de  cada
denominaci¢n de  monedas. El   ya tiene   un poco   de  monedas  en su
casa, pero  actualmente el  lleva solamente un billete   de K-centavos
en  su billetera. El  est  en una tienda donde todos los art¡culos que
venden sus precios son menores de K centavos (1 centavo, 2 centavos, 3
centavos, ... , K  - 1  centavos). En  esta tienda, el cambio  es dado
usando el siguiente algoritmo:

1. Dada la cantidad de cambio para dar A centavos.
2. Busca la m s alta denominaci¢n que no exceda a A. (De las monedas
   de B-centavos.)
3. Dar al cliente una moneda de B-centavos y reducirle a A la
   cantidad B.
4. Si A = 0, entonces finaliza; en otro caso retorna al paso 2.

El coleccionista de monedas compr¢ un art¡culo, y pag¢ con un billete
de K-centavos.

Tu tarea es escribir un programa que determine:
- ¨Cuantas monedas diferentes que el coleccionista no tiene todav¡a
  en su colecci¢n puede adquirir con esta transacci¢n?
- ¨Cu l es el m s costoso articulo de la tienda  que puede ser
  vendido a ‚l en el proceso?

ENTRADA

La entrada es  a trav‚s del  fichero texto COINS.IN.  La primera l¡nea
del fichero de entrada  contiene los enteros N (1 <= N<= 500 000) y  K
(2 <=  K <=  1 000  000 000).  Las siguientes  N l¡neas  describen las
monedas en circulaci¢n. La (i + 1)-‚sima l¡nea contiene los enteros ci
(1 <= ci < K) y di, donde  ci es el valor (en centavos) de la  moneda,
y di es 1, si el coleccionista tiene de esta moneda, o 0, si no tiene.
Las monedas son dadas en orden  creciente de sus valores, que es, c1 <
c2 < .. < cN. La primera moneda se conoce que es de 1-centavo, que es,
c1 = 1.

SALIDA

La salida ser  hacia el  fichero texto COINS.OUT La primera  l¡nea del
fichero de salida debe contener un simple entero - el n£mero m ximo de
denominaciones  que  el  coleccionista no  tiene  todav¡a,  pero puede
adquirir con una simple compra. La segunda l¡nea debe contener tambi‚n
un simple entero - el precio  m ximo de el art¡culo a comprar  tal que
el  cambio  dado   lo  conllev¢  al   n£mero  m ximo  de   las  nuevas
denominaciones, como se declar¢ en la primera l¡nea.

Ejemplo de Entrada y Salida:

COINS.IN              COINS.OUT

7 25                  3
1 0                   6
2 0
3 1
5 0
10 0
13 0
20 0
*/
