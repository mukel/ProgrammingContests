//koder: A^2P
//PSN 2005 #32 "kino"
#include <stdio.h>
#define filein "d.in"
#define fileout "d.out"
#define MAXN 10000

int N,i,j,k,c[MAXN],freq[MAXN];

int main()
{
  //fload
  freopen(filein,"r",stdin);
  freopen(fileout,"w",stdout);
  
  //dread
  scanf("%d\n",&N);
  for (i = 1; i <= N; i++)
  {
    scanf("%d\n",&j); freq[j]++;
  }
    
  //solve
  for (i = 0; i <= N; i++) if (freq[i])
    for (j = 1; j <= freq[i]; j++) c[k++] = i;    
  for (i = 0; (i <= N) & (c[i] > i); i++);  
  
  //dprint
  printf("%d",i+1);  
}

/*
32¦ kino.                                                 Polonia 2005
----------------------------------------------------------------------

Mirko esta celebrando su cumpleaños  y quiere invitar a sus  amigos al
cine. A todos ellos le gustaria ir al cine en grandes grupos. Cada uno
le solicita  que ademas  de Mirko   y el mismo cierto numero de  otros
amigos de Mirko vengan al cine con ellos.

Mirko no tiene suficiente dinero para invitarlos a todos ellos asi que
el  quiere  invitar  a  un  numero  minimo  de  gente.  El  tiene  que
determinar tal grupo minimo tal que cada solicitud de las personas sea
satisfecha y el grupo consista de al menos una persona.

Ayude a Mirko a escribir un programa que calcule este numero.

Entrada

En la primera linea del  fichero de entrada KINO.IN aparece  un entero
N, 2 <= N <= 10000, el numero de amigos. En las proximas N lineas  hay
un  entero por  linea Zi,  1 <=  Zi <  N. Este  numero representa  las
peticiones de todos los amigos de Mirko, esto es, el numero minimo  de
gente que ellos estan deseando que vayan al cine con ellos.

Salida

En la primera y unica linea del fichero de salida KINO.OUT usted  debe
escribir el numero minimo de gente que Mirko puede invitar al cine.

Ejemplos de Entrada y Salida

Ejemplo # 1

 +---------+ +----------+
 ¦ KINO.IN ¦ ¦ KINO.OUT ¦
 +---------¦ +----------¦
 ¦ 2       ¦ ¦ 2        ¦
 ¦ 1       ¦ +----------+
 ¦ 1       ¦
 +---------+

Ejemplo #2

 +---------+ +----------+
 ¦ KINO.IN ¦ ¦ KINO.OUT ¦
 +---------¦ +----------¦
 ¦ 3       ¦ ¦ 2        ¦
 ¦ 1       ¦ +----------+
 ¦ 2       ¦
 ¦ 1       ¦
 +---------+

Ejemplo # 3

 +---------+ +----------+
 ¦ KINO.IN ¦ ¦ KINO.OUT ¦
 +---------¦ +----------¦
 ¦ 5       ¦ ¦ 4        ¦
 ¦ 3       ¦ +----------+
 ¦ 4       ¦
 ¦ 3       ¦
 ¦ 3       ¦
 ¦ 3       ¦
 +---------+
*/