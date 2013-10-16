/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
PSN 2003 #13 "Huna zerka dekoratiba"
*/
#include <iostream>
using namespace std;

#define MAXN 21

typedef long long int64;

int T ,N, i, j, k, dir, last;
int64 C;
int64 dp[2][MAXN][MAXN];
int sol[MAXN];
bool used[MAXN];

int main() {

  /* Init */
  dp[0][1][1] = dp[1][1][1] = 1;
  for ( i = 2; i < MAXN; i++ )
    for ( j = 1; j <= i; j++ ) {

      /* down */
      for ( k = 1; k < j; k++ )
        dp[0][i][j] += dp[1][i - 1][k];

      /* up */
      for ( k = j; k < i; k++ )
        dp[1][i][j] += dp[0][i - 1][k];
    }

  for ( cin >> T; T; T-- ) {

    cin >> N >> C;

    /* Find First */
    for ( i = 1; i < MAXN; i++ ) {

      dir = 0;
      if ( C > dp[0][N][i] ) C -= dp[0][N][i];
      else break;

      dir = 1;
      if ( C > dp[1][N][i] ) C -= dp[1][N][i];
      else break;
    }

    /* Find the rest */
    sol[N] = last = i;
    for ( i = N - 1; i; i-- ) {

      dir ^= 1;

      if ( dir ) {
        for ( j = 1; j < last; j++ )
          if ( C > dp[1][i][j] ) C -= dp[1][i][j];
          else break;
      } else
        for ( j = last; j <= i; j++ )
          if ( C > dp[0][i][j] ) C -= dp[0][i][j];
          else break;

      sol[i] = last = j;
    }

    /* Print */
    for ( i = 1; i <= N; i++ )
      used[i] = false;

    for ( i = N; i; i-- )
      for ( j = 1; j <= N; j++ )
        if ( !used[j] )
          if ( --sol[i] == 0 ) {
            used[j] = true;
            if ( i > 1 )
                 cout << j << ' ';
            else cout << j << endl;
            break;
          }
  }

  return 0;
}

/*
13¦ Una cerca decorativa.                                     USA 2003
----------------------------------------------------------------------

Richard justamente  terminaba  de  construir  su nueva casa. Ahora  la
única cosa que le faltaba a la  casa es una linda cerca de madera.  El
no tenía ninguna idea de cómo  hacer una cerca de madera,  por  lo que
él decidió  pedir  una.   De algún modo  él  consiguió de manos de  la
ACME (Una Compañía que Hace Todo) del Catálogo de Cercas del 2002,  la
última fuente de lindas cercas  de madera. Después de leer  su prólogo
él supo ya, como hacer una linda cerca de madera.

Una  cerca  de  madera  consiste  de  N  tablones  de  madera, puestos
verticalmente seguidos uno al lado de otro. Una cerca parece bonita si
y sólo si reúne las siguientes condiciones:

* Los tablones tienen longitudes diferentes, particularmente 1, 2,...,
  N unidades de longitud.

* Cada  tablón  con  dos  vecinos o  es más grande que cada uno de sus
  vecinos o más pequeño que cada uno de ellos. (Note que esto hace que
  la cima suba alternadamente de la cerca y se baje).

Nosotros podemos describir cada cerca  bonita con N tablones como  una
permutación a[1], ...,  a[N] de los  números desde 1,  ..., N tal  que
(para  todo i;  1 <  i <  N) (a[i]  - a[i-1])*(a[i]  - a[i+1])  > 0  y
viceversa, cada permutación describe una cerca bonita.

Es obvio, que hay muchas cercas de madera bonitas diferentes hechas de
N  tablones.  Para traer algún orden en su catálogo, el gerente de las
ventas  de  ACME  decidió  pedirlos  de  la  manera siguiente: Cerca A
(representado por la permutación a[1], ..., a[N]) está en el  catálogo
antes de la cerca  B (representado por b[1],  ..., b[N]) si y  sólo si
allí existe tal i que (para todo j  < i) a[j] = b[j] y (a[i] <  b[i]).
(También  para decidir,  cuál de  las dos  cercas está  primero en  el
catálogo, tome sus permutaciones correspondientes, encuentre el primer
lugar en el que ellas difieren y comparar los valores de este  lugar.)
Todos las cercas bonitas con N tablones se enumeran (empezando por  1)
en el orden aparecen en el catálogo. Este número se llama su número de
catálogo.

    ++   ++      ++      ++   ++      ++     ++    ++    ++     ++
  ++¦¦   ¦¦++    ¦++   ++¦¦   ¦¦    ++¦¦   ++¦¦   +¦¦    ¦¦++   ¦¦++
  ¦+¦¦   ¦+¦¦  ++¦¦¦  +¦¦¦¦  +¦¦++  ¦¦¦++  ¦+¦¦   ¦¦¦++  ¦¦¦++  ¦+¦¦
 +¦¦¦¦   ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦   ¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦
 ¦¦¦¦¦  +¦¦¦¦  ¦+¦¦¦  ¦¦+¦¦  ¦¦+¦¦  ¦+¦¦¦  ¦¦¦++  ¦¦+¦¦  ¦+¦¦¦  ¦¦¦++
----------------------------------------------------------------------
   Todas  las cercas fabricada de N=4 tablones, ordenadas por su número
   de catálogo

Después de examinar cuidadosamente todas las cercas bonitas de madera,
Richard decidió  pedir algunas  de ellos.  Para cada  una de  ellas él
anotó el  número de  sus tablones  y su  número de  catálogo. Después,
cuando él se encontró a sus amigos, él quiso mostrarles las cercas que
él pidió, pero perdió el catálogo  en alguna parte. La única cosa  que
él tiene son sus notas. Por favor ayúdele a averiguar, cómo quiere que
aparezcan sus cercas.

Entrada

La  primera línea del archivo de entrada FENCE.IN contiene el número K
(1 <=  K <=  100), el  conjunto de  datos de  la entrada. Las K líneas
siguientes, cada una de ellas describe un juego de datos de entrada.

Cada una de las K líneas siguientes contiene dos enteros N y C (1 <= N
<=  20),  separados  por  un espacio. N es el número de tablones en la
cerca, C es el número de catálogo de la cerca.

Usted  puede  asumir,  que el número total de cercas de madera  con 20
tablones  cabe  en  una variable entera de 64-bit (long long en C/C++,
int64 en  FreePascal). Usted  también puede  asumir que  la entrada es
correcta, en  particular que  C tiene  por lo  menos 1  y no excede el
número de cercas bonitas con N tablones.

Salida

Para  cada  conjunto de  datos  de la  entrada  el archivo  de  salida
FENCE.OUT  tendrá  una  línea, describiendo  la  C-ésima  cerca con  N
tablones en el catálogo. Más precisamente, si la cerca es descrita por
la permutación a[1], ..., a[N], entonces la línea correspondiente  del
archivo del salida debe contener el número a[i] (en el orden
correcto), separados por simples espacios.

Ejemplo de Entrada y Salida:

+----------+    +-----------+
¦ FENCE.IN ¦    ¦ FENCE.OUT ¦
+----------¦    +-----------¦
¦ 2        ¦    ¦ 1 2       ¦
¦ 2 1      ¦    ¦ 2 3 1     ¦
¦ 3 3      ¦    +-----------+
+----------+
*/
