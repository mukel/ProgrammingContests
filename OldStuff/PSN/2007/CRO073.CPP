/*
koder -> A2P
25 - 5 - 2007
PSN 2007 #73 "Dvaput"
*/
#include <cstdio>
#include <mem.h>

#define problem "d"
#define MAXN 200000
#define MAXHASH 1000001
#define BASE 666

int N, S;
char seq[MAXN];
int hash[MAXHASH];
struct { int pos, next; } ls[MAXN];

  inline int new_node(int pos) {
    S++;
    ls[S].pos = pos;
    ls[S].next = 0;
    return S;
  }

  int duplicated(int len) {
    if (!len) return true;
    memset(hash, 0, sizeof(hash[0]) * MAXHASH);

    int i ,j ,k, pot = 1, now = 0;
    for (i = 0; i < len; i++) {
      if (i) pot = (pot * BASE) % MAXHASH;
      now = (now * BASE + seq[i]) % MAXHASH;
    }

    S = 0;
    hash[now] = new_node(0);
    for ( ; i < N; i++) {
      now = (now - seq[i - len] * pot) % MAXHASH;
      if (now < 0) now += MAXHASH;
      now = (now * BASE + seq[i]) % MAXHASH;

      if (!hash[now]) hash[now] = new_node(i - len + 1);
      else {
        for (j = hash[now]; j; k = j, j = ls[j].next)
          if (memcmp(&seq[ls[j].pos], &seq[i - len + 1], len) == 0) return true;
        ls[k].next = new_node(i - len + 1);
      }
    }
    return false;
  }

int main() {
  freopen(problem ".in", "r", stdin);
  freopen(problem ".out", "w", stdout);

  scanf("%d\n", &N);
  scanf("%s", &seq);

  int d = 0, h = N - 1, mid;
  do {
    mid = (d + h) / 2;
    if ( duplicated(mid) ) d = mid + 1; else h = mid;
  } while (d != h);

  printf("%d\n", h - 1);

  return 0;
}

/*
73¦ Dvaput.                                             Croacia 2007
----------------------------------------------------------------------

Zvonko    ha  estado  observando  durante   algun tiempo  la  pantalla
electrónica  que   está  en   las afueras   del  cine   y    notó  que
algunos mensajes aparecian   en la  pantalla   más de una  vez.  Desde
luego, él está  escribiendo todos  los mensajes en un pedazo de papel.
El quiere saber  la longitud de  la cadena más  larga que apareció  al
menos  dos   veces   (aparecer  en  dos  posiciones  diferentes en  el
papel).

Entrada

La primera linea del fichero de entrada DVAPUT.IN contendrá un  entero
L (1 <=   L <=  200  000),  la  longitud   de la  cadena   que  Zvonko
escribió.   La segunda   linea  contiene  una  cadena   de L    letras
minúsculas  del alfabeto inglés.

Salida

En el  fichero de  salida DVAPUT.OUT  se escribirá una simple linea la
longitud de la cadena más larga que aparece al menos dos veces. Si  no
existe tal, escriba un cero.

Ejemplo de Entrada y Salida

Ejemplo # 1          Ejemplo # 2                Ejemplo # 3

+-------------+      +--------------------+     +------------+
¦ DVAPUT.IN   ¦      ¦ DVAPUT.IN          ¦     ¦ DVAPUT.IN  ¦
+-------------¦      +--------------------¦     +------------¦
¦ 11          ¦      ¦ 18                 ¦     ¦ 6          ¦
¦ sabcabcfabc ¦      ¦ trutrutiktiktappop ¦     ¦ abcdef     ¦
+-------------+      +--------------------+     +------------+
+-------------+      +------------+             +------------+
¦ DVAPUT.OUT  ¦      ¦ DVAPUT.OUT ¦             ¦ DVAPUT.OUT ¦
+-------------¦      +------------¦             +------------¦
¦ 3           ¦      ¦ 4          ¦             ¦ 0          ¦
+-------------+      +------------+             +------------+
*/
