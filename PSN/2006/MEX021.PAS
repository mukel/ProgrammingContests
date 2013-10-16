{koder: A^2P}
{PSN 2006 #21 "Par‚ntesis M gicos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  BufferSize = 100000;
var
  fin,fout        : text;
  ch              : char;
  N,M,i,j,k       : longint;
  buf1,buf2       : array[0..BufferSize] of byte;

    procedure finish;
    begin
      rewrite(fout); writeln(fout,0);
      close(fin); close(fout); halt;
    end;{finish}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);
  settextbuf(fin,buf1); settextbuf(fout,buf2);

  {dread}
  readln(fin,N,M);

  {solve}
  writeln(fout,1);
  repeat
    repeat
      read(fin,ch);
      case ch of
        ')' : begin
          if i = 0 then finish; dec(i);
        end;{...}
        '(' : inc(i);
        ']' : begin
          inc(k);
          if k <> M then
          begin
            if i = 0 then finish; dec(i);
            writeln(fout,1);
          end{then ->}
          else dec(i);
        end;{...}
      end;{case}
    until seekeoln(fin); readln(fin);
  until seekeof(fin);
  writeln(fout,i + 1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
21ş Par‚ntesis M gicos.                                    M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En el lenguaje de programaci¢n LISP todas las cosas estan escritas
dentro de par‚ntesis balanceados ( similar a este ). Esto significa
que el codigo de LISP algunas veces contiene largas cadenas de
par‚ntesis cerrados "))) ... )". Esto es muy tedioso para el
programador de LISP obtener el n£mero de par‚ntesis cerrados ')' para
comprender exactamente al n£mero de par‚ntesis abiertos '('.

Para prevenir tales errores sint cticos, algunos dialectos LISP
introducen un par‚ntesis cerrado m gico ']' el cual sustituye a uno o
mas par‚ntesis cerrados ')' necesitado para balancear apropiadamente
los par‚ntesis abiertos '('. Pero entonces el compilador de LISP tiene
que calcular cu ntos par‚ntesis cerrados ')' cada par‚ntesis m gico
']' realmente sustituyen. C¢mo ?.

Escriba un programa al cu l se le de una cadena de par‚ntesis
abiertos, cerrados y m gicos, y calcule para cada ocurrencia del
par‚ntesis m gico el n£mero de par‚ntesis abiertos a que este
corresponde. En caso de m£ltiples soluciones, el programa debe
encontrar una de ellas.

Entrada

El nombre del fichero de entrada es LISP.IN. La primera l¡nea consiste
de dos enteros 0 <= N <= 10 000 000 y 0 <= M <= 5 000 000 separados
por un espacio. El primer n£mero N es la longitud de la cadena de
entrada. El segundo n£mero M es el n£mero de par‚ntesis cerrados
m gicos en la cadena. El resto del fichero de entrada comienza en la
segunda l¡nea y es una cadena de longitud N consistente de los
caracteres '(', ')' y ']' aparece exactamente M <= N veces en esta
cadena. Esta cadena est  dividida en l¡neas de a lo sumo 72 caracteres
cada una para fiabilidad en la lectura.

Salida

El nombre del fichero de salida es LISP.OUT. La primera l¡nea consiste
de un entero '0' ¢ '1'.

El n£mero '0' significa que la entrada no puede ser balanceada. Por
ejemplo, la cadena la cual consiste de justamente un par‚ntesis m gico
simple "]" obviamente no puede ser balanceada. En este caso no hay m s
salida.

El n£mero '1' significa que la entrada puede ser balanceada. En este
caso la salida contin£a con las siguientes M l¡neas extras.

La primera de estas l¡neas extras consiste del n£mero C1 >= 1 de
par‚ntesis cerrados ')' que el primer par‚ntesis m gico ']' sustituye en
la entrada. La segunda l¡nea extra consiste del n£mero correspondiente
C2 >= 1 para el segundo ']' en la entrada y asi sucesivamente.

Si hay muchas maneras en la cual la cadena dada puede ser balanceada,
entonces tu programa debe escribir una de ellas.

Ejemplo

La entrada describe una cadena con 8 caracteres, de los cuales 2 son
m gicos. La salida muestra una manera de balancear esta entrada: el
primer par‚ntesis m gico corresponde a tres par‚ntesis abiertos, y el
segundo par‚ntesis m gico corresponde a 1 par‚ntesis abierto. Y
realmente la cadena libre-magica esta balanceada apropiadamente, donde
los par‚ntesis cerrados corresponden a los par‚ntesis m gicos que
estan subrayados ( ( ( ( ( ) ) ) ) )
                           ÄÄÄÄÄ   Ä

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄ¿
³ LISP.IN  ³     ³ LISP.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄ´
³ 8 2      ³     ³ 1        ³
³ (((((])] ³     ³ 3        ³
ÀÄÄÄÄÄÄÄÄÄÄÙ     ³ 1        ³
                 ÀÄÄÄÄÄÄÄÄÄÄÙ
}