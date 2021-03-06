/*
Alfonso Alfonso Peterssen
20 - 6 - 2007
PSN 2007 #71 "Kokos"
*/
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 10000

#define all( v ) v.begin(), v.end()

int N, M, i, j, sol;
string st;
vector< string > v1, v2;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> M;
  for ( i = 0; i < N; i++ ) {
    fin >> st;
    v1.push_back( st.substr( 0, M ) );
    v2.push_back( st.substr( M, M ) );
    reverse( all( v2[i] ) );
  }

  sort( all( v1 ) );
  for ( i = 0; i < N - 1; i++ ) {
    j = 0;
    while ( ( j < M ) && ( v1[i][j] == v1[i + 1][j] ) ) j++;
    sol += M - j;
  }

  sort( all( v2 ) );
  for ( i = 0; i < N - 1; i++ ) {
    j = 0;
    while ( ( j < M ) && ( v2[i][j] == v2[i + 1][j] ) ) j++;
    sol += M - j;
  }
  
  sol += 2 * M; // First string

  fout << sol << endl;

  return 0;
}

/*
71� Kokos.                                                Croacia 2007
����������������������������������������������������������������������

Un conjunto  de N  palabras es  dado con  la longitud  de cada palabra
compuesta exactamente por 2K caracteres.

Un grafo  dirigido con  cada v�rtice  conteniendo una  letra simple es
llamado un  "kokos" si, para   cada palabra en el conjunto,  existe un
camino dirigido en el  grafo tal que las  letras en los v�rtices  a lo
largo del  camino formen  la palabra.  Adicionalmente, para  todos los
v�rtices  en   ese  camino   tienen  que   satisfacer  las  siguientes
condiciones:

- el grado de entrada del primer  v�rtice es 0
- el grado de entrada de los pr�ximos K-1 v�rtices es 1
- el grado de salida de los pr�ximos K-1 v�rtices es 1
- el grado de salida del �ltimo v�rtice es 0

En otras  palabras, los  caminos pueden  ramificaese solamente  en las
primeras K letras, y ellos pueden encontrarse solamente en las �ltimas
K letras. Para un conjunto de palabras dadas, nosotros decimos que  el
"kokos" es m�nimo si el n�mero total  de  v�rtices es tan peque�o como
sea posible.

Escriba un programa que encuentre el n�mero de v�rtices en un kokos
m�nimo.

Un ejemplo de un kokos m�nimo (el conjunto de palabras es la
del tercer ejemplo):

      ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ
      � E ��� F ��� E ��� F ��� F ��� E �Ŀ
      �����  �����  �����  �����  �����  ����� �
                    ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ �  ���Ŀ  ���Ŀ
               ����� D ��� C ��� F ��� E ����� H ��� G �
               �    �����  �����  �����  ����� �  �����  �����
               �                               ��Ŀ
               �                                  
      ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ
      � A ��� B ��� C ��� D ��� E ��� F ��� G ��� H �
      �����  �����  �����  �����  �����  �����  �����  �����
        �    ���Ŀ  ���Ŀ  ���Ŀ    
        ����� C ��� B ��� D ������
             �����  �����  �����

Le puede parecer que nosotros podemos compactar el grafo as�:

      ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ
      � E ��� F ��� E ��� F ����Ŀ
      �����  �����  �����  �����    �
                                    
                    ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ    ���Ŀ  ���Ŀ
               ����� D ��� C ��� F ��� E ����� H ��� G �
               �    �����  �����  �����  ����� �  �����  �����
               �                               ��Ŀ
               �                                  
      ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ  ���Ŀ
      � A ��� B ��� C ��� D ��� E ��� F ��� G ��� H �
      �����  �����  �����  �����  �����  �����  �����  �����
        �    ���Ŀ  ���Ŀ    
        ����� C ��� B ������
             �����  �����


Sin  embargo,  este grafo   no  es un  kokos   porque los  caminos  se
encuentran en la 4ta letra (D),  y ellos se ramifican en la  6ta letra
(E).

Entrada

La primera l�nea  del fichero de entrada KOKOS.IN contiene dos enteros
N y K, 1 <= N <= 10 000,  1 <= K <= 100. Cada una de las  siguientes N
l�neas contiene  una palabra  del conjunto.  Todas las  letras son  en
may�sculas del alfabeto Ingles ('A'-'Z').

Salida

La primera y �nica l�nea del fichero de salida KOKOS.OUT debe contener
el n�mero de v�rtices en un kokos m�nimo.

Ejemplos de Entrada y Salida

Ejemplo #1            Ejemplo #2          Ejemplo #3

����������Ŀ          ����������Ŀ       ����������Ŀ
� KOKOS.IN �          � KOKOS.IN �       � KOKOS.IN �
����������Ĵ          ����������Ĵ       ����������Ĵ
� 2 4      �          � 4 3      �       � 4 4      �
� ABCDEFGH �          � XXZZXX   �       � ABCDEFGH �
� EFGHIJKL �          � XXYYZZ   �       � ACBDEFGH �
������������          � AABBCZ   �       � ABDCFEHG �
                      � ABCZZZ   �       � EFEFFEGH �
                      ������������       ������������
�����������Ŀ         �����������Ŀ      �����������Ŀ
� KOKOS.OUT �         � KOKOS.OUT �      � KOKOS.OUT �
�����������Ĵ         �����������Ĵ      �����������Ĵ
� 16        �         � 18        �      � 23        �
�������������         �������������      �������������
*/
