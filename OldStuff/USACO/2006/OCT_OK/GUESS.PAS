(*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Adivina Mi Número"
*)
var
  lo, hi, mid : longint;
  answer : string;

begin

  lo := 1;
  readln( hi );

  repeat

    mid := ( lo + hi ) div 2;

    writeln( mid );
    readln( answer );

    if answer = 'L' then
         lo := mid + 1
    else hi := mid - 1;

  until answer = 'OK';

end. { main }

(*
Problema 2: Adivina Mi Número [Tradicional, 2006]

Las vacas están jugando “Mayor-Menor”, el juego de adivinar mi número.
La líder piensa un número en el rango 1..N (10 <= N <= 1,000,000); las
otras vacas tratan de adivinarlo. Cada vez que se da una conjetura, la
líder dice a la adivinadora si el número es mayor, menor, o correcto.
Escriba un programa que juegue este juego en contra de un líder
robótico.

Lea toda su entrada de la entrada estándar (también conocida como la
consola). Escriba todas sus salidas en la salida estándar (simplemente
como imprimiendo en la pantalla). Vea a continuación para instrucciones
especiales.

Primero, lea N, luego haga su conjetura imprimiéndola.

Lea una respuesta que es . 'H', 'L', o 'OK' (Mayor, Menor o Correcto).
Su programa será terminado automáticamente por el sistema de calificación
después del 'OK'.

Su puntaje depende de cuán rápidamente usted adivine el número. Las
soluciones óptimas recibirán todo el puntaje; otras recibirán menos.

Un diálogo típico podría ser como este (el número secreto es 7):
-> 10                 [adivine en el rango 1..10]
<- 4                  [Su conjetura es 4]
-> L                  [Su conjetura es menor]
<- 6                  [Su conjetura es 6]
-> L                  [Su conjetura es menor]
<- 8                  [Su conjetura es 8]
-> H                  [Su conjetura es mayor]
<- 7                  [Su conjetura es 7]
-> OK                 [¡Su conjetura es correcta!]

¡Asegúrese de vaciar su salida! Si usted usa stdio.h, incluya la línea

setbuf(stdout, 0);

cerca al principio de su programa. Si usted usa el estilo C++ de entrada
salida, vacíe cada línea como esto:

cout << line << "\n" << flush;

Para Pascal, haga lo siguiente después de cada sentencia writeln:

flush(stdout);

Para Java, haga lo siguiente después de cada sentencia de salida:

System.out.flush();


NOMBRE DEL PROBLEMA: guess

FORMATO DE ENTRADA:

* Línea 1: Un solo entero N

* Líneas 2..??: Cada línea contiene una respuesta como se ha explicado.

ENTRADA EJEMPLO (entrada estándar)

10
...[Vea antes los detalles]...

FORMATO DE SALIDA:

* Líneas 1..??: Cada línea de salida es una conjetura como se ha
       detallado.


EJEMPLO DE SALIDA (salida estándar):

...[vea antes]...
*)
