//koder: A^2P GCC
//PSN 2001 #22 "Expresi¢n de Divisi¢n"
#include <stdio.h>

#define filein "d.in"
#define fileout "d.out"

FILE *fin = fopen(filein,"r");
FILE *fout = fopen(fileout,"w");
long D,N,i,j,k,m[10000];

long gcd(long a, long b)
{    
  do {
    a %= b; if (a == 0) return(b);
    b %= a; if (b == 0) return(a);     
  } while (true);
}

int main()
{
  fscanf(fin,"%d\n",&D);
  for (i = 1; i <= D; i++)
  {        
    fscanf(fin,"%d\n",&N);
    for (j = 1; j <= N; j++) fscanf(fin,"%d\n",&m[j]);
    k = m[2] / gcd(m[1],m[2]);        
    for (j = 3; (j <= N) && (k != 1); j++) k /= gcd(k,m[j]);
    fprintf(fout,(k == 1) ? "YES\n" : "NO\n");
  }
  fclose(fin);
  fclose(fout);
}

/*
22þ Expresi¢n de Divisi¢n.                              Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una expresi¢n de divisi¢n es una  expresi¢n  aritm‚tica  de  la  forma

x1/x2/x3/ ... /xk

donde xi es un entero positivo, para i, (1<=i<=k).  Una  expresi¢n  de
divisi¢n es evaluada de izquierda a derecha. Por ejemplo el  valor  de
la expresi¢n:

1/2/1/2

es 1/4.  Uno  puede  poner  par‚ntesis en la expresi¢n para cambiar su
valor. Por ejemplo el valor de la expresi¢n:

(1/2)/(1/2)

es 1. Nosotros daremos una expresi¢n de divisi¢n E. Es  posible  poner
varios  par‚ntesis en E para obtener una expresi¢n E' cuyo valor es un
n£mero entero.

Tarea

Escribir    un    programa  que  para  cada  conjunto  de datos de una
secuencia de varios conjuntos de datos:
   þ lea  una  expresi¢n  E  desde  el  fichero  de  texto  DIV.IN,
   þ verifique  si  es posible poner par‚ntesis en E para obtener una
     nueva    expresi¢n    E'    cuyo  valor  sea  un  n£mero  entero,
   þ escriba   el  resultado  para  el  fichero  de  texto  DIV.OUT

Entrada

La  primera  l¡neam del fichero DIV.IN contiene  un entero positivo d,
(d<=5). Este es el n£mero de conjuntos de datos. Los conjuntos de datos
aparecen  a  continuaci¢n.  La  primera  l¡nea  de  cada  unu de ellos
contiene  un  entero n, (2<=n<=10000). Este es el n£mero de enteros en
la  expresi¢n.  Cada    una  de  las  siguientes  n  l¡neas  contienen
exactamente un entero positivo no mayor  que 1,000,000,000. El i-‚simo
n£mero es el i-‚simo entero en la expresi¢n.

Salida

Para  cada  i, (1<=i<=d) su programa escribir  en la i-‚sima l¡nea del
fichero  de  salida DIV.OUT una palabra YES, si  la  i-‚sima expresi¢n
de  la  entrada  puede  ser  transformada  en una expresi¢n cuyo valor
es un n£mero entero, o la palabra NO en otro caso.

Ejemplo:
ÚÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄ¿
³DIV.IN³  ³DIV.OUT³
ÃÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄ´
³2     ³  ³YES    ³
³4     ³  ³NO     ³
³1     ³  ÀÄÄÄÄÄÄÄÙ
³2     ³
³1     ³
³2     ³
³3     ³
³1     ³
³2     ³
³3     ³
ÀÄÄÄÄÄÄÙ
*/
