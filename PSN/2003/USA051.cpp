//koder: A^2P GCC
//PSN 2003 #51 "Aislador"
#include <stdio.h>
#include <stdlib.h>//qsort

#define filein "d.in"
#define fileout "d.out"

FILE *fin = fopen(filein,"r");
FILE *fout = fopen(fileout,"w");
long N,i,sol;
int m[100000];

int intcmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    //dread
    fscanf(fin,"%d",&N);
    for (i = 0; i < N; i++) fscanf(fin,"%d",&m[i]);
    
    //solve
    qsort(m,N,sizeof(int),intcmp);
    for (i = 0; i < N / 2; i++) sol += m[i] << 1;    
    if (N & 1) sol += m[N / 2];
    
    //dprint
    fprintf(fout,"%d",sol);
    
    //fclose
    fclose(fin);
    fclose(fout);  
}

/*
51þ Aislador.                                                 USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La  compa¤¡a  Insumax produce aisladores t‚rmicos multicapas. Cada una
de las i capas, i = 1, 2, ..., n de un aislador est  caracterizada por
un    coeficiente  de  aislamiento  a(i)  positivo.  Las  capas  est n
numeradas acorde a la direcci¢n de la fuga del calor.

      calor -> ³³a(1)³a(2)³...³a(i)³a(i+1)³a(n)³³->

El  coeficiente  de  aislamiento del aislador completo, A, es descrito
por  la  suma de los coeficientes de aislamiento de sus capas. Adem s,
el  coeficiente  A  se  eleva  si  una  capa,  con  un  coeficiente de
aislamiento  m s peque¤o es seguida por una capa con un coeficiente de
aislamiento m s grande, acorde a la f¢rmula:

    n         n-1
A = ä      a(i)    +    ä max (0,   a(i+1)  -  a(i))
    i=1       i=1

Por  ejemplo,  el  coeficiente de aislamiento del aislador de la forma

      -> ³³ 5 ³ 4 ³ 1 ³ 7 ³³ ->

es A = (5  +  4  +  1  +  7)  +  (7  -  1)  =  23

Tarea

Escriba  un  programa el cual, para el coeficiente de aislamiento dado
de  las  capas a(1), a(2), ..., a(n), determine un ordenamiento de las
capas  tal que el coeficiente de aislamiento del aislador completo sea
maximizado.

Entrada
En  la  primera l¡nea del fichero texto IZO.IN est  el n£mero de capas
N,  1  <=  N  <=  100,000. En las sucesivas  N l¡neas hay coeficientes
a(1), a(2), ..., a(n), uno por l¡nea. Estos  coeficientes  son enteros
que satisfacen la desigualdad 1 <= a(i) <= 10,000.

Salida

En la primera y £nica l¡nea del fichero texto IZO.OUT tu programa debe
escribir  un  entero igual al valor m s grande posible del coeficiente
de aislamiento A del aislador construido con las capas de coeficientes
dadas, puestas en un orden particular.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
³ IZO.IN ³  ³ IZO.OUT ³
ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
³ 4      ³  ³ 24      ³
³ 5      ³  ÀÄÄÄÄÄÄÄÄÄÙ
³ 4      ³
³ 1      ³
³ 7      ³
ÀÄÄÄÄÄÄÄÄÙ
*/
