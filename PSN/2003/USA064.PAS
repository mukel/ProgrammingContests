{koder: A^2P}{1 - 5 - 2007}
{PSN 2003 #64 "Preguntas"}
{$B-,Q-,I-,R-,S-}
uses LIB;
var
  len             : byte;
  sol             : string;

begin
  {solve}
  Init();
  repeat
    len := length(sol);
    if Ask(sol + '0') = 1 then sol := sol + '0'
      else if Ask(sol + '1') = 1 then sol := sol + '1';
  until len = length(sol);
  repeat
    len := length(sol);
    if Ask('0' + sol) = 1 then sol := '0' + sol
      else if Ask('1' + sol) = 1 then sol := '1' + sol;
  until len = length(sol);

  {sol}
  Solution(sol);
end.{main}

{
64ş Preguntas.                                                USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Escriba un programa que adivine una supuesta cadena que consiste s¢lo
de car cteres 0 y 1 y su longitud es desconocida. La longitud m xima
de la supuesta cadena ser  100 caracteres, y su programa debe adivinar
la cadena en a lo sumo 300 llamadas a la funci¢n Ask.

Biblioteca

Para resolver esta tarea a usted se le proporciona la biblioteca LIB
que contiene tres subrutinas:

Init - usted necesita llamarlo precisamente una vez al principio de su
       programa sin argumentos. Este procedimiento no retorna ning£n
       valor.

       procedure Init;

Ask -  funci¢n que se llama con una cadena de car cteres 0 y 1 como
       argumento. Esta funci¢n devuelve el valor 1 si la cadena  es
       una sub cadena de la cadena  desconocida (no necesariamente
       consecutivo) y 0 de lo contrario. A usted se le permite llamar
       esta funci¢n a lo sumo 300 veces.

       funtion Ask (a: string): integer;

Solution - usted debe llamar a este procedimiento al final de su
           programa; como un argumento usted debe pasar una cadena que
           es id‚ntica a la cadena adivinada. Este procedimiento no
           devuelve ningun valor y regularmente termina la ejecuci¢n de
           de su programa.

           Procedure  Solution (a: string);

La biblioteca LIB genera el fichero ASK.LOG. Este consiste de todas las
preguntas que su programa hizo con las respuestas. En caso de que haya
m s de 300 preguntas, en la fila  301 de este fichero se escribir 
el mensaje  'Number of questions is more then 300!'.  Si usted
llama al procedimiento Soluci¢n despues de a lo sumo 300 preguntas en
la  £ltima l¡nea se escribir  el mensaje: ' Correct answer after
??? questions.' o 'Wrong answer. '

Instrucciones para los programadores

Al principio de su programa escriba 'Uses LIB'. Tambi‚n, usted
necesita copiar los ficheros LIB.O y LIB.PPU en su directorio de
trabajo

Probando tu programa

Usted puede probar su programa creando el fichero ASK.IN en el que
usted escribir  alguna cadena de 0 y 1. Esta ser  la cadena a
adivinar usada por la biblioteca.


Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄ¿
³ ASK.IN  ³
ÃÄÄÄÄÄÄÄÄÄ´
³ 1000101 ³
ÀÄÄÄÄÄÄÄÄÄÙ

Para 5 llamadas correctas a las funciones de la biblioteca la cadena
ser¡a, por ejemplo:

Init;
Ask ('101');
Ask ('11');
Ask ('10001001');
Solution ('1000101');

En archivo ASK.LOG estar  entonces:
Question 1: 101  .....  YES
Question 2: 11  .....  NO
Question 3: 10001001  .....  NO
Solution is 1000101  .....  YES

Respuesta correcta despu‚s de 3 preguntas.
}