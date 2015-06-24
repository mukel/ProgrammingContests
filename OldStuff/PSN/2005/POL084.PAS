{koder: A^2P}
{PSN 2005 #84 "Las compa¤ias de juegos y la guerra"}
uses umissile;
var
   A,B,C,j,k    : longint;

begin
     {solve}
     C := high(0);
     j := high(1) - C; {j = A + B}
     k := high(-1) - C; {k = A - B}
     A := (j + k) div 2;
     B := j - A;

     {check}
     solution(high(-B div (A * 2)));
end.{main}

{
84ş ş Las compa¤ias de juegos y la guerra.                Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La compa¤¡a Nintendo ha inventado una nueva consola de juegos, para
que la disfruten los ni¤os de los presidentes de pa¡ses poderosos.

La consola de juegos tiene un funcionamiento muy sencillo, cada vez
que pap  (el presidente) lanza un misil sobre un pa¡s  rabe, ‚sta
filma todo el lanzamiento, despu‚s el ni¤o (con un dulce de chocolate
en la mano) introduce un n£mero entero "x" en la consola, para el cual
es devuelto otro entero "y" calculado a partir de y=axı+bx+c. El ni¤o
introduce varios n£meros hasta que ya sabe cual es el x que retorna
mayor y, entonces da este x como soluci¢n si es correcto gana sino
pierde.

Los enteros a, b, y c determinan la trayectoria del misil; para un
valor de x se tiene que axı+bx+c es la altura alcanzada por el misil
para la coordenada x. (a siempre es negativo x,y,b,c pueden ser
negativos o positivos)

Note que "y" puede ser negativo aunque represente la altura.

Tarea

Usted ser  ni¤o de presidente poderoso por unas horas y debe
determinar el valor de x para el cual axı+bx+c tiene un valor m ximo.

Unit

Existir  una unit llamada UMISSILE, que funciona id‚ntico a la consola
de juegos; posee una funci¢n y un procedimiento:

  function high(x:longint) : longint;
  procedure solution(x:longint);

La funci¢n high puede ser llamada cada vez que se quiera, a esta se le
pasa un entero "x" y devuelve la altura "y" del misile para esa "x".

El procedimiento solution debe ser llamada con el valor de x para el
cual high(x) retorna el mayor valor. Este procedimiento terminar  la
corrida de su programa.

La unit UMISSILE leer  los valores de a,b,c desde el archivo
MISSILE.IN, adem s escribir  en el archivo MISSILE.OUT si su programa
lleg¢ a la soluci¢n correcta, adem s crear  el archivo MISSILE.LOG con
toda la interacci¢n de su programa con la unit.

Su programa no tiene permitido leer del archivo MISSILE.IN


Restricciones

-4000 <= valor x de la soluci¢n <= 4000
-100 <= a,b,c <= 100 a es negativa Los valores de a,b,c en los juegos
 de datos son tales que la "x" que alcanza altura m xima ser  siempre
 un entero.
 
Calificaci¢n

Si el valor de x en Solution(x) es incorrecto usted obtendr  0 ptos;
de lo contrario se le dar n 3*V/S ptos donde S es la cantidad de
preguntas a high y V es el valor del ese juego de datos.

Informaci¢n adicional

. la funcion y=axı+bx+c describe en el plano una par bola.
. si a < 0 la par bola tiene una "y" m xima pero no tiene m¡nima
. si a > 0 la par bola tiene una "y" m¡nima pero no m xima
. la "y" m xima o m¡nima se obtiene cuando x=-b/(2a)

Ejemplo

Para a=-1, b=2, c=3, la m xima y se alcanza cuando x=1
}