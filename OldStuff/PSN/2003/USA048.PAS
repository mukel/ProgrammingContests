{koder: A^2P}{5 - 5 - 2007}
{PSN 2003 #48 "Explosi¢n"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 2000;
var
  fin,fout        : text;
  N,M,D,i,j       : longint;
  A,B             : array[0..MaxN] of char;
  C               : array[0..MaxN,0..MaxN] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  repeat
    inc(N); read(fin,A[N]);
  until seekeoln(fin);
  readln(fin);
  repeat
    inc(M); read(fin,B[M]);
  until seekeoln(fin);
  readln(fin);
  readln(fin,D);

  {init}
  j := N;
  if M > j then j := M;
  for i:=1 to j do
  begin
    C[i,0] := C[i - 1,0] + D;
    C[0,i] := C[0,i - 1] + D;
  end;{for}

  {solve}
  for i:=1 to N do
    for j:=1 to M do
      C[i,j] := min( min(C[i - 1,j],C[i,j - 1]) + D,
                     C[i - 1,j - 1] + abs(ord(A[i]) - ord(B[j])));

  {dprint}
  writeln(fout,C[N,M]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
48ş Explosi¢n.                                                USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Sean  dos cadenas, A y B.

Una  expansi¢n  de  alguna  cadena  X  es un cadena creada agregando o
insertando  cualquier  n£mero (ceros, uno o m s) de espacios en blanco
en  cualquier  parte  en  la cadena, o en el comienzo o al final de la
cadena.  Ejemplo,  si  la  cadena  X es 'abcbcd', entonces las cadenas
'abcb-cd',  '-a-bcbcd-'  y  'abcb-cd-' son  expansiones de la cadena X
(los espacios en blanco son denotados por el car cter '-').

Si  A1  es  una expansi¢n de la cadena A, y B1 es una  expansi¢n de la
cadena  B,  y  si  A1 y B1 son de la misma longitud, entonces nosotros
definimos  la  distancia  de  las  cadenas A1 y B1 como la suma de las
distancias  de  los  car cteres  en  las  mismas  posiciones  en estas
cadenas.  Nosotros  definimos  la  distancia de dos car cteres como la
diferencia  absoluta  de  su  c¢digo  ASCII,  excepto la distancia del
espacio en blanco y otro car cter, la cual es dada (e igual para todos
los caracteres).

Tarea

Usted  tiene que escribir un programa que encuentre las expansiones A1
y B1, de las cadenas A y B, que tengan la diferencia m s peque¤a.

Entrada

La  primera  l¡nea  del  archivo  de  entrada  BLAST.IN consiste de la
cadena  A,  y la segunda l¡nea de la cadena B. Ellas s¢lo consisten en
car cteres    del  alfabeto ingl‚s (a-z) en min£sculas, y el n£mero de
car cteres  en  cualquiera  de las cadenas es menor o igual a 2000. La
tercera l¡nea consiste en un entero K, 1 <= K <= 100, la distancia del
espacio en blanco y los otros car cteres.

Salida

La  primera  y £nica l¡nea del archivo BLAST.OUT  debe consistir en la
distancia m s peque¤a como se defini¢ en el texto de la tarea.

Ejemplos de Entrada y Salida:

 Ejemplo #1       Ejemplo #2         Ejemplo  #3
ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ BLAST.IN  ³     ³ BLAST.IN  ³     ³ BLAST.IN  ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ cmc       ³     ³ koiv      ³     ³ mj        ³
³ snmn      ³     ³ ua        ³     ³ jao       ³
³ 2         ³     ³ 1         ³     ³ 4         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ BLAST.OUT ³     ³ BLAST.OUT ³     ³ BLAST.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 10        ³     ³ 5         ³     ³ 12        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}