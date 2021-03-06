/*
Alfonso Alfonso Peterssen
24 - 6 - 2007
PSN 2007 #78 "Luci�rnaga"
*/
#include <cstdio>

#define problem "d"
#define MAXM 500000

int N, M, i, j, k, sol, cnt;
int T[MAXM];

int main() {
  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d\n", &N, &M );
  N /= 2;
  for ( i = 0; i < N; i++ ) {
    scanf( "%d %d\n", &j, &k );
    T[j]--; T[M - k]++;
  }

  j = N; sol = 1 << 20;
  for ( i = 0; i < M; i++ ) {
    j += T[i];
    if ( j == sol ) cnt++;
    if ( j < sol ) sol = j, cnt = 1;
  }

  printf( "%d %d\n", sol, cnt );

  return 0;
}

/*
78� Luci�rnaga.                                           Croacia 2007
����������������������������������������������������������������������

Una  luci�rnaga  japonesa  ha  volado dentro  de  una  cueva  llena de
obst�culos: estalagmitas (subiendo del suelo) y estalactitas (colgando
del techo). La cueva es  de N unidades de largo  (donde N es par) y  H
unidades  de alto.  El  primer  obst�culo es  una  estalagmita despu�s
las estalactitas y estalagmitas de manera alterna.

Aqu�  tienes un  ejemplo de  una cueva  de 14  unidades de  largo y  5
unidades de alto (la imagen corresponde al segundo ejemplo):

�����������������������������������������������������������
        �       �       �       �       �       �      �
� � � � � � � � �� � � ��� � � ��� � � ��� � � ��� � � ���
        �       �       �       �       �       �      �
� � � � �� ��� ��� � � ��� � � ��� � � ��� � � ��� � � ���
        �   �           �       �       �              �
� � � � �� ��� � � � � ��� �� ���� ��� ��� ��� � � �� ����
            �           �   �   �   �       �      �
�  ��� �� ���� �� ����� ��� ��� �� ��� � � ��� � � �� � �
    �       �       �       �       �       �      �
�����������������������������������������������������������

La  luci�rnaga  japonesa no  es  del tipo  que  volar�a alrededor  del
obst�culo,  en  cambio  escoger�  una altura  �nica  y  atacar�  de un
extremo de  la cueva  al otro  destruyendo todos  los obst�culos en su
camino  con sus  poderosos  movimientos  de  kung-fu.  En  el  ejemplo
anterior,  escogiendo  el 4to  nivel  desde  la  tierra  la luci�rnaga
destruye  ocho obst�culos:

�����������������������������������������������������������
        �       �       �       �       �       �      �
� � � � � � � � �� � � ��� � � ��� � � ��� � � ��� � � ���
...............................................................
� � � � �� �� ���� � � ��� � � ��� � � ��� � � ��� � � ���
        �   �           �       �       �              �
� � � � �� ��� � � � � ��� �� ���� ��� ��� ��� � � �� ����
            �           �   �   �   �       �      �
�  ��� �� ���� �� ����� ��� ��� �� ��� � � ��� � � �� � �
    �       �       �       �       �       �      �
�����������������������������������������������������������

Esta  no  es la  mejor  opci�n porque  la  luci�rnaga terminar�  menos
cansada si escoge cualquiera de  los niveles uno o cinco,  destruyendo
s�lo siete obst�culos. A usted se da la altura y longitud de la  cueva
y los tama�os de todos los obst�culos.

Escriba un  programa que determine el n�mero  m�nimo de obst�culos que
la luci�rnaga necesita destruir para alcanzar el final de la cueva,  y
en cu�ntos niveles distintos puede lograr ese n�mero.

Entrada

La  primera  l�nea  del fichero  de  entrada  FIREFLY.IN contiene  dos
enteros N y H, 2 <= N <= 200  000, 2 <= H <= 500 000, el largo  y alto
de la cueva. N siempre ser�  par. Las pr�ximas N l�neas  contienen  el
tama�o de los  obst�culos, uno por  cada l�nea, el  primer   obst�culo
es   una   estalagmita  despu�s las  estalactitas  y  estalagmitas  de
manera  alterna alternas.  Todos  los  tama�os son  enteros positivos
menores o  iguales que H.

Salida

El fichero de  salida FIREFLY.OUT debe contener en una sola l�nea  dos
enteros separados  por un   simple espacio.   El primer   n�mero es el
m�nimo de  obst�culos que  la luci�rnaga  debe destruir  y el  segundo
n�mero es la cantidad de niveles en la que puede alcanzarlo.

Ejemplo de Entrada y Salida:

Ejemplo #1                      Ejemplo #2
������������Ŀ                  ������������Ŀ
� FIREFLY.IN �                  � FIREFLY.IN �
������������Ĵ                  ������������Ĵ
� 6 7        �                  � 14 5       �
� 1          �                  � 1          �
� 5          �                  � 3          �
� 3          �                  � 4          �
� 3          �                  � 2          �
� 5          �                  � 2          �
� 1          �                  � 4          �
��������������                  � 3          �
�������������Ŀ                 � 4          �
� FIREFLY.OUT �                 � 3          �
�������������Ĵ                 � 3          �
� 2 3         �                 � 3          �
���������������                 � 2          �
                                � 3          �
                                � 3          �
                                ��������������
                                �������������Ŀ
                                � FIREFLY.OUT �
                                �������������Ĵ
                                � 7 2         �
                                ���������������
*/
