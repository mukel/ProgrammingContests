{koder: A^2P}{3 - 3 - 2007}
{PSN 2006 #27 "Juego del Divisor"}
{$B-,I-,Q-,R-,S-}
uses alice;
const
  MaxN = 1000001;
var
  N,j,sol         : qword;
  i               : longint;
  mark            : array[0..MaxN] of boolean;

begin
  {dread}
  N := get_n;

  {solve}{prime sieve}
  for i:=2 to trunc(sqrt(N)) do
    if not mark[i] then
    begin
      j := sqr(i);
      repeat
        mark[j] := true;
        inc(j,i);
      until j > N;
    end;{then}

  sol := 1; i := 1;
  repeat
    repeat inc(i) until not mark[i];
    while (sol * i <= N) and (is_divisible_by(sol * i))
      do sol := sol * i;
  until sol * i > N;

  {check}
  guess(sol);
end.{main}

{
27ş Juego del Divisor.                                     M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Memoria disponible: 32 MB
Tiempo m ximo de corrida: 1 s

Alice y  Bob inventaron  un juego  para dos  jugadores. Al  principio,
Alice selecciona un  entero positivo k  en el rango  desde 1 hasta  un
cierto entero fijo n. Entonces  Bob realiza preguntas de la  forma ï¨k
es divisible por  m?ï, donde m  es un entero  positivo, Alice responde
cada pregunta de estas  con ïyesï o ïnoï.  Bob desea saber qu‚  n£mero
Alice tiene en mente haciendo tan pocas preguntas como sea posible.
Tu tarea es hacer un programa que juegue al juego como Bob.  Denotemos
por  d(n) el  n£mero m¡nimo  de preguntas,  las cuales  se hacen  para
encontrar a k,  sin preocuparse  que k  seleccion¢ Alice  (para el   n
dado). Las preguntas   de su  programa  para  un caso   de pruebas  se
considerar n correctas,  si k  se determina  correctamente usando   no
m s  de d(n) preguntas.

Biblioteca

Su programa  tiene que  usar una  biblioteca especial  para jugar.  La
biblioteca consiste de los ficheros: alice.pas (para pascal),  alice.h
y  alice.c   (para  C/C++).   La  biblioteca   provee  las  siguientes
facilidades:

ş function get_n: longint / int  get_n() - Su programa llamar  a  esta
  funci¢n al iniciar  el  juego,  antes  de  llamar  a  cualquier otro
  get_n retorna n, el l¡mite superior del n£mero que  Alice  tiene  en
  mente. El n£mero  n satisface las  limitaciones 1 <= n <= 1 000 000.
  Adem s en el 50% de los casos de prueba se cumple que 1<= n <=10000.

ş function is_divisible_by(m: longint): boolean /
           int is_divisible_by(int m) - Su programa puede hacer
  preguntas  llamando  a  esta  funci¢n.  La  funci¢n  is_divisible_by
  retorna  True  / 1  si  el n£mero  k  que Alice  tiene  en mente  es
  divisible por m. En otro caso retorna False / 0. El par metro m debe
  cumplir que 1 <= m <=  n. Su programa debe hacer tan pocas preguntas
  como sea posible.

ş procedure guess(k: longint) /  void guess(int k) - Para  terminar el
  juego su programa deber  reportar el n£mero que Alice tiene en mente
  llamando al procedimiento guess(k). El par metro k deber  satisfacer
  1<=  k  <=  n.  Despu‚s de  llamar a  este procedimiento su programa
  terminar  autom ticamente.

Si su programa  hace una llamada  ilegal, este terminar .  Su programa
solamente deber  comunicar por medio de los procedimientos y funciones
de arriba. Su programa no tiene que leer o escribir cualquier fichero,
este no tiene que usar entrada  ni salida est ndar y no debe  intentar
acceder a cualquier memoria fuera de su programa.

Compilaci¢n

Si  su  programa  se  escribe  en  Pascal,  entonces  debe  incluir la
sentencia ïuses alice;ï en su  c¢digo. Para compilar su programa,  use
el siguiente comando:

ppc386 -O2 -XS div.pas

Si  su  programa se  escribe  en C  o  C++, entonces  debe  incluir la
sentencia  ï#include  "alice.h"ï  en  su  c¢digo.  Para  compilar   su
programa, use uno de los siguientes comandos:

gcc -O2 -static div.c alice.c -lm
g++ -O2 -static div.cpp alice.c -lm

Experimentaci¢n

Para experimentar con su soluci¢n, a usted se le da una biblioteca  de
ejemplo  que juega  como Alice:  este  c¢digo  est   en  los  ficheros
alice.pas. alice.h y alice.c. Cuando ejecute su programa, este  jugar 
en  contra  de  esta simple  biblioteca.  Usted  puede modificar  esta
biblioteca, pero por favor, no  haga cambios en la parte  de interface
de esta.  Por favor,  recuerde que  durante la  evaluaci¢n su programa
jugar  contra un oponente diferente.

Ejemplo de interacci¢n

Abajo hay un ejemplo de interacci¢n entre un programa y la biblioteca.

Su programa llama     Que pasa

get_n()               returns 1000
is_divisible_by(10)   returns True / 1
is_divisible_by(100)  returns True / 1
is_divisible_by(1000) returns False / 0
is_divisible_by(200)  returns False / 0
is_divisible_by(500)  returns False / 0
is_divisible_by(300)  returns False / 0
is_divisible_by(700)  returns False / 0
guess(100)            El n£mero secreto de Alice es 100.
                      Su programa gana y termina autom ticamente.
}