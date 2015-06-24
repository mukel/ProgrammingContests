{koder: A^2P}{3 - 5 - 2007}
{PSN 2004 #123 "Bomberos"}
{Raul -> Expresion-Termino-Factor}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxC = 10;
  oo = 1 shl 29;
  sign : string = '+-*/'; { BP }
var
  fin,fout        : text;
  expr            : string;
  found           : boolean;
  N,C,R,i,j,pos   : longint;
  list            : array[0..MaxC] of longint;

    function expresion: longint; forward;

    function factor: longint;
    var A : longint;
    begin
      if expr[pos] = '(' then
      begin
        inc(pos);
        factor := expresion;
        exit;
      end;{then}
      A := 0;
      while expr[pos] in ['0'..'9'] do
      begin
        A := A * 10 + ord(expr[pos]) - ord('0');
        inc(pos);
      end;{while}
      factor := A;
    end;{factor}

    function termino: longint;
    var A,B,op : longint;
    begin
      A := factor;
      while expr[pos] in ['*','/'] do
      begin
        op := pos; inc(pos);
        B := factor;
        case expr[op] of
          '*' : A := A * B;
          '/' : if B <> 0
                  then A := A div B
                  else A := oo;
        end;{case}
      end;{while}
      termino := A;
    end;{termino}

    function expresion: longint;
    var A,B,op : longint;
    begin
      A := termino;
      while expr[pos] in ['+','-'] do
      begin
        op := pos; inc(pos);
        B := termino;
        case expr[op] of
          '+' : A := A + B;
          '-' : A := A - B;
        end;{case}
      end;{while}
      if expr[pos] = ')' then inc(pos);
      expresion := A;
    end;{expresion}

    procedure comb(i : longint);
    var j : longint;
    begin
      if found then exit;
      if i = C + 1 then
      begin
        pos := 1;
        found := (expresion = R);
        exit;
      end;{then}
      for j:=1 to 4 do
      begin
        expr[list[i]] := sign[j];
        comb(i + 1);
      end;{for}
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N do
  begin
    readln(fin,expr); readln(fin,R);
    C := 0; expr := expr + ')';
    for j:=1 to length(expr) do
      if expr[j] = '?' then
      begin
        inc(C); list[C] := j;
      end;{then}
    found := false;
    comb(1);
    if found
      then writeln(fout,'yes')
      else writeln(fout,'no');
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
123ş Bomberos.                                             Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un matem tico conservaba todos sus documentos en un archivo de un
armario cercano a su escritorio. Un d¡a se desat¢ un fuego en su
oficina y la mayor¡a de sus trabajos se da¤aron de mala manera.
Afortunadamente, algunas de las ecuaciones que hab¡a resuelto en
tantos a¤os de su larga carrera se preservaron parcialmente. Cada
ecuaci¢n conten¡a una expresi¢n en el miembro izquierdo y el resultado
en el derecho. Las expresiones preservadas conten¡an todos los n£meros
y parent‚sis, pero desafortunadamente, algunos de los operadores entre
ellos se perdieron en el fuego. Otro problema fue que los resultados
de las ecuaciones se dispersaron y el matem tico no est  seguro si
cierta respuesta es el resultado de cierta expresi¢n. Tu tarea es
ayudar al matem tico a determinar si las expresiones y los resultados
que fue capaz de salvar del fuego se corresponden uno con otro.

Para hacer esto, a usted se le da un grupo de expresiones, consistente
de n£meros enteros entre 1 y 999, operadores matem ticos simples (+,
-, *, /), par‚ntesis y signos de interrogaci¢n (?), representando un
operador matem tico perdido. Para cada expresi¢n dada, su £nica tarea
es afirmar si una expresi¢n puede o no dar el resultado requerido. A
fin de ayudarte, el matem tico seleccion¢ solamente expresiones que
tienen las siguientes restricciones:

1. Las expresiones no contienen m s de 100 s¡mbolos;
2. Los par‚ntesis encierran no m s de 1 operador con sus dos
   operandos. Sin embargo, cada uno de estos operandos puede ser una
   expresi¢n entre par‚ntesis;
3. Las constantes en las expresiones no tienen signo, es decir, no hay
   n£meros negativos en las expresiones;
4. El n£mero m ximo de signos de interrogaci¢n en las expresiones (los
   operadores perdidos) es menor o igual que 10.

El c lculo de debe desarrollar usando las siguientes reglas:

1. Los operadores * y / son de m s prioridad que los operadores + y -.
   Los par‚ntesis pueden cambiar las prioridades como de costumbre;
2. Los operadores +, -, * y / son asociativos de izquierda, significa
   que ellas se agrupan de izquierda a derecha. Si a, b y c son n£meros:
   a*b*c = (a*b)*c, a/b/c = (a/b)/c, a/b*c = (a/b)*c, a+b+c = (a+b)+c,
   a-b+c = (a-b)+c, etc.
3. Cuando se est  dividiendo dos enteros, usted debe ignorar la parte
   decimal, por ejemplo, considere las siguientes ecuaciones: 2/5=0,
   9/5=1, 100/6=16.

Entrada: (bomberos.in)

El fichero de entrada contiene en la primera l¡nea el n£mero K de
expresiones (1<=K<=10). Seguidamente aparecen dos l¡neas para cada
expresi¢n. La primera de estas l¡neas es la expresi¢n, definida en el
miembro izquierdo de la ecuaci¢n; la segunda de estas l¡neas es un
resultado entero definido en el miembro derecho de la ecuaci¢n. Las
l¡neas de entrada no contienen espacios. Se garantiza que las cadenas
que repersentan las expresiones no tienen errores de sintaxis.

Salida: (bomberos.out)

Si una expresi¢n puede dar el resultado, escriba 'yes', en otro caso
escriba 'no' en l¡neas separadas del fichero de salida. Escriba estas
respuestas en el orden en que aparecen en la entrada.

Ejemplos de entrada y salida

 Ejemplo #1                 Ejemplo #2
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³bomberos.in        ³      ³bomberos.in ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³1                  ³      ³2           ³
³1?((2*(3*4))+(5+6))³      ³1?2*3+4-14  ³
³35                 ³      ³0           ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      ³1?3*4/5*6+12³
ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿             ³11          ³
³bomberos.out³             ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´             ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³yes         ³             ³bomberos.out³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ             ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
                           ³no          ³
                           ³no          ³
                           ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
