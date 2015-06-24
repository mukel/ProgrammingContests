/*
Alfonso Alfonso Peterssen
28 - 10 - 2007
PSN 2007 #87 "Secuencias sin stammers"
O( n )
*/
#include <cstdio>

const int MAXN = 10000001;

int N, i, j, sz;
unsigned char seq[MAXN];

int main() {

  scanf( "%d", &N );

  /* ... */
  if ( N < 4 ) {

    if ( N < 3 ) {
      printf( "%d\n", N );
      for ( i = 0; i < N; i++ )
        printf( "%c", i + 'a' );
      printf( "\n" );
    }

    if ( N == 3 ) {
      printf( "2\n" );
      printf( "aba\n" );
    }

    return 0; /* Suicide */
  }

  seq[ sz++ ] = 0;
  seq[ sz++ ] = 1;
  for ( ; sz <= N; ) {

    int last_sz = sz;

    for ( j = last_sz / 2; j < last_sz && sz <= N; j++ )
      if ( seq[j] == 0 ) {
        seq[ sz++ ] = 0;
        seq[ sz++ ] = 1;
      } else {
        seq[ sz++ ] = 1;
        seq[ sz++ ] = 0;
      }
  }

  printf( "3\n" );
  for ( i = 0; i < N; i++ ) {

    if ( seq[i] == seq[i + 1] )
         j = 2;
    else j = seq[i];

    printf( "%c", j + 'a' );
  }

  printf( "\n" );

  return 0;
}

/*
87þ Secuencias sin stammers.                              Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Nosotros consideramos secuencias de  letras. Nosotros decimos que  una
secuencia  x1x2...xn  contiene  un   stammer (en alguna ciencia  puede
ser  tartamudear),   si  nosotros   podemos  encontrar   en  esta  dos
ocurrencias de la misma subsecuencia,  una siguiendo directamente a la
otra,   es  decir,  si   para  alg£n   i   y   j  (1  <=  i  <  j   <=
(n+i+1)/2)  nosotros tenemos    x(i)=x(j), x(i+1)=x(j+1), ...,  x(j-1)
= x(2j-i-1).

Nosotros estamos  interesados en  secuencias  de  n-elementos  que  no
tengan  stammers,  construidas  con  el  n£mero  m¡nimo  de  letras
diferentes.

Ejemplos

Para  n =  3 es  suficiente usar dos  letras, digamos a y b.  Nosotros
tenemos    exactamente  dos   secuencias de 3-elementos  sin  stammers
construidas por estas letras: aba y bab. Para n = 5 necesitamos   tres
letras   diferentes.   Por    ejemplo  abcab   es   una  secuencia  de
tres letras sin stammers. En  la secuencia babab nosotros tenemos  dos
stammers: ba y ab.

Tarea

Escriba un programa que:

- lea la longitud de la  secuencia n desde el fichero CIA.IN,
- calcule  una secuencia de n-elementos  sin stammers construidas con
  el n£mero m¡nimo de letras diferentes,
- escriba el resultado hacia el fichero CIA.OUT.

Entrada

En la  primera l¡nea  del fichero  de entrada  CIA.IN existe un entero
positivo n, 1 <= n <= 10000000.

Salida

Su programa  debe imprimir  el resultado   hacia el  fichero de salida
CIA.OUT. En la  primera l¡nea debe aparecer un entero positivo k igual
al n£mero m¡nimo de letras  diferentes que tiene que  aparecer en  una
secuencia de n-elementos sin stammers.

En   la   segunda  l¡nea  debe  escribir la  secuencia   calculada sin
stammers como una   palabra que comprende    n letras min£sculas   del
alfabeto  Ingl‚s   y  es  construida  solamente  por  letras  desde la
primera hasta la  k-‚sima letra del  alfabeto. Si hay  muchas de estas
secuencias, su programa debe escribir una de ellas.

Usted puede asumir que 26 letras son suficientes.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
³ CIA.IN ³ ³ CIA.OUT ³
ÃÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
³ 5      ³ ³ 3       ³
ÀÄÄÄÄÄÄÄÄÙ ³ abcab   ³
           ÀÄÄÄÄÄÄÄÄÄÙ
*/
