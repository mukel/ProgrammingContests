//koder: A^2P
//PSN 2005 #10 "Laboratorio de computación"
#include <stdio.h>
#define filein "d.in"
#define fileout "d.out"

long N,i,sol;

int main()
{
  //fload
  freopen(filein,"r",stdin);
  freopen(fileout,"w",stdout);
  
  //dread
  scanf("%ld",&N);
  
  //solve
  for (i = 2; i <= N; i++)
  {
    sol = ((sol * (i % 2005)) + (i & 1 ? -1 : 1)) % 2005;
    if (sol = -1) sol = 2004;
  }
  
  //dprint
  printf("%ld",sol);
  
  //fclose
  fflush(stdout);
}

/*
10¦ Laboratorio de computación                            Polonia 2005
----------------------------------------------------------------------

En  un  gran  laboratorio   de  computación  las  computadoras   están
dispuestas todas en una fila una al lado de la otra. En dicha fila hay
N computadoras las que están numeradas  con los números del 1 al  N de
izquierda a derecha. Cada uno de los N estudiantes que trabajan en  el
laboratorio tiene una máquina preferida. En el laboratorio trabaja  un
técnico (de pensamientos muy malos por cierto) que planifica el tiempo
de máquina asignándole a cada estudiante una computadora.

De  cuántas  maneras  el  técnico  de  laboratorio  puede  hacer   una
planificación  del  tiempo  de máquina  en  la  que ningún  estudiante
trabaje en su máquina preferida.

Tarea

Hacer un programa que permita:

- leer desde el fichero de  entrada LAB.IN el número N de  máquinas en
  el laboratorio y la máquina preferida por cada estudiante.

- Determinar el número C de formas que el técnico de laboratorio puede
  hacer   una  planificación   del  tiempo  de  máquina   en  la   que
  ningún estudiante pueda trabajar en su máquina preferida. - escribir
  hacia el fichero de salida LAB.OUT  el número  C mod 2005 (resto  de
  la  división de C entre 2005).

Entrada

El fichero de entrada LAB.IN contiene:

- Línea 1: N (1 <= N <= 10000000), representa laa cantidad de máquinas
  en el laboratorio.
- Línea 2..N+1: en cada una de estas líneas se escribirá el número  de
  la máquina preferida por el estudiante   i, o sea, en la línea   i+1
  del fichero aparecerá la máquina preferida por el estudiante i.

Salida

El fichero de salida LAB.OUT contiene en una sola línea con el  número
C mod 2005.

Ejemplos de Entrada Salida

  LAB.IN             LAB.OUT

  3                  2
  2
  3
  1
*/
