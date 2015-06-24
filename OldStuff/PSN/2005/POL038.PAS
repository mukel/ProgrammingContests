{koder: A^2P}{10 - 5 - 2007}
{PSN 2005 #38 "Decodificando Secuencias Morse"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
  code : array['A'..'Z'] of string =
  ('.-','-...','-.-.','-..','.','..-.',
   '--.','....','..','.---','-.-','.-..',
   '--','-.','---','.--.','--.-','.-.','...',
   '-','..-','...-','.--','-..-','-.--','--..');
var
  fin,fout        : text;
  N,M,i,j,k,sol   : longint;
  seq             : array[0..MaxN] of char;
  st              : array[0..MaxN] of string;
  C,len           : array[0..MaxN] of longint;

    function match(i,j: longint): boolean;
    var h,k : longint;
    begin
      for h:=1 to byte(st[i][0]) do
        for k:=1 to byte(code[st[i][h]][0]) do
        begin
          inc(j);
          if seq[j] <> code[st[i][h]][k]
            then exit(false);
        end;{for}
      match := true;
    end;{match}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  repeat
    inc(N); read(fin,seq[N]);
  until seekeoln(fin);
  readln(fin);
  readln(fin,M);
  for i:=1 to M do readln(fin,st[i]);

  {init}
  for i:=1 to M do
    for j:=1 to length(st[i]) do
      inc(len[i],length(code[st[i][j]]));

  {solve}
  C[0] := 1;
  for i:=1 to N do
    for j:=1 to M do
      if (len[j] <= i) and (C[i - len[j]] > 0) and
         (match(j,i - len[j]))
         then inc(C[i],C[i - len[j]]);  

  {dprint}
  writeln(fout,C[N]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
38ş Decodificando Secuencias Morse.                       Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Antes de  la era  digital, la  mayor¡a del  codigo binario  comun para
comunicacion  por radio  fue el  codigo Morse.  En codigo  Morse,  los
simbolos  estan codificados  como secuencias  de pulso  largo y  corto
(llamados  puntos  y  guiones  respectivamente.  La  siguiente   tabla
reproduce el  codigo morse  para el  alfabeto, donde  puntos y guiones
estan representados por los caracteres ASCII "." and "-":

A .-    B -...   C -.-.   D -..
E .     F ..-.   G --.    H ....
I ..    J .---   K -.-    L .-..
M --    N -.     O ---    P .--.
Q --.-  R .-.    S ...    T -
U ..-   V ...-   W .--    X -..-
Y -.--  Z --..

Observe que en   ausencia de  pausas  entre  letras serian   multiples
las  interpretaciones  de  una  secuencia   Morse.   Por  ejemplo,  la
secuencia -.-..-- podr¡a  ser decofificada  como CAT  or  NXT   (entre
otras).  Un operador  Morse  utilizaria  otra  informaci¢n  contextual
(tal   como   un   diccionario  del    lenguaje)  para    decidir  la
decodificaci¢n  apropiada.  Aun  teniendo  tal  diccionario  uno puede
obtener multiples frases de una secuencia Morse simple.

Tarea

Escriba un programa  el cual:

- lea una secuencia  Morse y una  lista de palabras (un diccionario),
- calcule el numero de  distintas frases que pueden  ser obtenidas  de
  la secuencia Morse usando palabras del diccionario,
- escriba el resultado.

Observe que  nosotros  estamos  interesados en   relaciones completas,
es decir, la  secuencia Morse  completa tiene  que estar   relacionada
con palabras en  el diccionario.

Entrada

La  primera  l¡nea  del  fichero  de  entrada  MORSE.IN  contiene  una
secuencia  no vacia de a lo sumo  10000  caracteres  "."  y   "-"  sin
espacios entre ellos. La segunda l¡nea contiene exactamente un  entero
N,   1  <=   N  <=   10000,  igual   al  n£mero   de  palabras  en  un
diccionario. Cada una  de las siguientes  lineas contiene una  palabra
del diccionario de a lo sumo 20 letras may£sculas de la "A" a la  "Z".
Ninguna palabra  aparece en  el diccionario  m s de  una vez.

Salida

La unica  linea del  fichero de  salida MORSE.OUT  contiene un  entero
igual al numero de distintas frases dentro del cual la secuencia Morse
puede  ser  analizada  gramaticalmente. Usted  puede  asumir  que este
numero a los sumo es 2*10^9.

Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ MORSE.IN                   ³ ³ MORSE.OUT   ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ .---.--.-.-.-.---...-.---. ³ ³ 2           ³
 ³ 6                          ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ AT                         ³
 ³ TACK                       ³
 ³ TICK                       ³
 ³ ATTACK                     ³
 ³ DAWN                       ³
 ³ DUSK                       ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
