//koder: A^2P GCC
//PSN 2005 #77 "Suma de conjuntos"
#include <stdio.h>

#define filein "d.in"
#define fileout "d.out"

FILE *fin = fopen(filein,"r");
FILE *fout = fopen(fileout,"w");
long N,i,j,m[500001];

int main()
{
  //dread
  fscanf(fin,"%ld",&N);
     
  //solve
  N /= 2;
  m[0] = 1;    
  for (i = 1; i <= N; i++)
  {
    m[i] = (m[i - 1] + m[j]) % 1000000000;
    if (i & 1) j++;       
  }
    
  //dprint
  fprintf(fout,"%ld",m[N]);
    
  //fclose
  fclose(fin); fclose(fout);  
}

/*
77þ Suma de conjuntos.                                    Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan (GJ) ha pedido a sus vacas que busquen diferentes 
conjuntos de n£meros que sumen un n£mero dado. Las vacas usan
solamente n£meros que sean potencias enteras de 2. Aqu¡ est n los
conjuntos posibles de n£meros que suman 7:

1) 1+1+1+1+1+1+1
2) 1+1+1+1+1+2
3) 1+1+1+2+2
4) 1+1+1+4
5) 1+2+2+2
6) 1+2+4

Ayude a GJ a contar todas las representaciones posibles para un entero
N dado (1 <= N <= 1,000,000).

NOMBRE DEL PROBLEMA: sumset

FORMATO DE ENTRADA:

Una sola l¡nea con un solo entero, N.

ENTRADA EJEMPLO (archivo sumset.in):

7

FORMATO DE SALIDA:

El n£mero de maneras de representar a N como la suma indicada. Debido
a lo potencialmente grande que puede ser este n£mero, imprima
solamente los £ltimos 9 d¡gitos (en representaci¢n base 10).

SALIDA EJEMPLO (arhivo sumset.out):

6
*/
