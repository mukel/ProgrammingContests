/*
Alfonso Alfonso Peterssen
11 - 11 - 2007
PSN 2007 #81 "Ivana"
*/
#include <cstdio>

const int MAXN = 200;

int N, i, j, k, sol;
int dp[MAXN][MAXN];

int main() {

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    scanf( "%d", &j );
    dp[i][i] = dp[N + i][N + i] = ( j & 1 );
  }

  /* DP */
  for ( k = 1; k < N; k++ )
    for ( j = k; j < 2 * N; j++ ) {
      i = j - k;
      dp[i][j] = ( dp[i][i] - dp[i + 1][j] ) >?
                 ( dp[j][j] - dp[i][j - 1] );
    }

  for ( i = 0; i < N; i++ )
    if ( dp[i][i] - dp[i + 1][i + N - 1] > 0 )
      sol++;

  printf( "%d\n", sol );

  return 0;
}

/*
81ş Ivana.                                                Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Zvonko invit¢  a su  enamorada Ivana  a jugar  su juego favorito. Este
consiste en colocar N enteros positivos en un c¡rculo sobre el piso  y
se rige por las siguientes  reglas:

- El primer jugador toma cualquier n£mero.

- El segundo jugador toma uno de los dos n£meros adyacentes al  n£mero
  tomado por el primer jugador.

- El   pr¢ximo  jugador   toma  uno  de   los  n£meros  adyacentes   a
  cualquiera   de  los  n£meros   tomados    hasta  ahora,     y   asi
  sucesivamente hasta que ellos agoten los n£meros.

El jugador  que tome  m s n£meros  impares (no  divibles por  2) gana.
Zvonko  juega  optimamente;  el   siempre  busca  una  estrategia  que
conduzca a la victoria o a un empate. Zvonko  no sabe  cuan bien Ivana
juega. Siendo un verdadero caballero, ‚l le permite a Ivana  hacer  la
primera jugada.

Escriba un  programa que  encuentre cu ntas  primera jugada diferentes
Ivana  puede  hacer,   tal  que  ella   tenga  oportunidad  de   ganar
posteriormente.

Entrada

La primera linea del fichero de entrada IVANA.IN contiene un entero  N
(1 <=  N <=  100), que representa la cantidad de numeros que hay en el
c¡rculo. La segunda l¡nea contiene N  enteros separados por un espacio
simple. Todos los numeros estar n entre 1 y 1000 (inclusive).  Numeros
iguales no aparecer n.

Salida

En la primera y £nica  l¡nea del fichero de salida  IVANA.OUT contiene
el numero deseado, o sea, la cantidad de primera jugada diferentes que
Ivana  puede  hacer,   tal  que  ella   tenga  oportunidad  de   ganar
posteriormente.

 Ejemplos de Entrada y Salida

Ejemplo # 1        Ejemplo # 2        Ejemplo # 3

ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ IVANA.IN  ³      ³ IVANA.IN  ³      ³ IVANA.IN         ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³      ³ 4         ³      ³ 8                ³
³ 3 1 5     ³      ³ 1 2 3 4   ³      ³ 4 10 5 2 9 8 1 7 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ IVANA.OUT ³      ³ IVANA.OUT ³      ³ IVANA.OUT        ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³      ³ 2         ³      ³ 5                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
