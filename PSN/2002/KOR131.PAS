{koder: A^2P}{4 - 5 - 2007}
{PSN 2002 #131 "Cadenas de Subcadenas"}
{$B-,I-,Q-,R-,S-}
uses oracle;
const
  filein = 'd.in';
  fileout = 'd.out';
  ADN = 'ATCG';
var
  fin,fout        : text;
  i,len           : longint;
  sol             : string;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {init}
  start_string;

  {solve}
  repeat
    i := 1;
    while (i < 5) and (oracle_call(sol + ADN[i]) = 0) do inc(i);
    if i < 5 then sol := sol + ADN[i];
  until (i = 5) or (length(sol) = 255);
  repeat
    i := 1;
    while (i < 5) and (oracle_call(ADN[i] + sol) = 0) do inc(i);
    if i < 5 then sol := ADN[i] + sol;
  until (i = 5) or (length(sol) = 255);

  {dprint}
  answer_string(sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
131þ Cadenas de Subcadenas                                  Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Cada cadena de ADN consiste en s¢lo 4 letras, A, T, G y C. Usted tiene
una  cadena  de  ADN desconocida y debe determinar la cadena. La £nica
manera  que  usted puede acceder informaci¢n sobre la cadena oculta es
atraves  de un or culo. El or culo, cuando dada determinada pregunta a
un  cadena  S,  respondera s  si  el cadena oculta contiene S como una
subcadena. Por ejemplo, permita la cadena oculta So = "ATTGCGCGATCG".
Entonces  "ATTG" y "CGCG", "T", "A" son subcadenas de So. Pero ninguno
de  "TGG" o "GCGATG" no es un subcadena de So. Cuando una cadena So se
representa como So = (s[1], s[2], s[3],..., s[N]), donde el s[i] es el
i-‚simo   car cter  de  So,  entonces  una  subcadena  de  So  es  una
subsequencia  consecutiva representado como (s[i], s[i+1], s[i+2],...,
s[j]), donde 1 <= i <= j <= N <= 255.

Usted  debe escribir un programa que determine la cadena oculta usando
pocas preguntas del or culo como sea posible.

BIBLIOTECA

A usted se le da la siguiente biblioteca.

FreePascal Library: (oracle.ppu, oracle.o)

Las funciones de biblioteca de pascal correspondientes son:
- el procedimiento start_string;
- la funci¢n oracle_call(S: String): integer;
- procedimiento answer_string(S: string);

Instrucci¢n:

Para compilar su  programa  STRING.PAS,  incluya  la  declaraci¢n  de
importaci¢n or culo  de  los  usos; en  el  c¢digo  de la fuente y lo
compila como:

fpc -as¡ -O2 -XS STRING.pas
lib_test.pas muestra c¢mo usar la biblioteca de FreePascal.

El  biblioteca   genera un archivo nombrado STRING.out autom ticamente
en  una  llamada  al  answer_STRING.  El  archivo STRING.out tiene dos
l¡neas.  Un entero en la primera l¡nea muestra el n£mero de llamadas a
oracle_call  hecho  por  su  programa  y  la segunda l¡nea contiene la
cadena oculta que su programa ha dado como una soluci¢n.

Entrada y Salida:

La longitud L de la cadena oculta satisface 1 <= L <= 255. Usted puede
experimentar  con la biblioteca creando un archivo del texto STRING.IN
con  una sola l¡nea que contiene la cadena de ADN oculta.  Note que la
STRING.out en el ejemplo siguiente no es necesariamente ¢ptimo.
Muestra el formato del archivo de entrada y salida simplemente.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ STRING.IN    ³  ³ STRING.OUT   ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ ATTGCGCGATCG ³  ³ 41           ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ  ³ ATTGCGCGATCG ³
                  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Puntuaci¢n

Si su programa viola una de las restricciones (ej. demasiadas llamadas
a funci¢n), entonces usted obtendr  0 punto.

Si  su soluci¢n no es correcta, entonces la puntuaci¢n es 0. Cuando la
soluci¢n  de la salida es correcta, entonces su puntuaci¢n depende del
n£mero  de  la  funci¢n de la biblioteca que requiere cada datos de la
comprobaci¢n.  Para  cada datos si el n£mero de llamadas de la funci¢n
est   menos de un B limitado (eso es independientemente fijo para cada
dato),  entonces usted obtendr  todos los puntos. Por otra parte usted
obtendr  0 puntos.
}