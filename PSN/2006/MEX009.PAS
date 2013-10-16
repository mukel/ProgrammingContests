{koder: A^2P}
{PSN 2006 #9 "Descifrar el mensaje"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxM = 20000;
  MaxN = 200;
var
  fin,fout        : text;
  N,M,i,j         : word;
  msg             : array[1..MaxM] of char;
  len             : array[1..MaxN] of byte;
  last,sol        : array[0..MaxM] of byte;
  mark            : array[0..MaxM] of boolean;
  s               : array[1..MaxN] of string[100];

    function can(i,j: word): boolean;
    var k : byte;
    begin
      for k:=1 to len[i] do
        if s[i][k] <> msg[j+k] then break;
     if s[i][k] <> msg[j+k] then
     begin
      for k:=1 to len[i] do
        if s[i][len[i] - k + 1] <> msg[j+k] then break;
      can := (s[i][len[i] - k + 1] = msg[j+k]);
     end{then ->}
     else can := (s[i][k] = msg[j+k]);
    end;{can}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,s[i]);
    len[i] := byte(s[i][0]);
  end;{for}
  readln(fin,M);
  for i:=1 to M do read(fin,msg[i]);

  {solve}{}
  mark[0] := true;
  for i:=1 to M do
    for j:=1 to N do if len[j] <= i then
      if (mark[i-len[j]]) and (can(j,i - len[j])) then
      begin
        mark[i] := true; last[i] := j; break;
      end;{then}

  {dprint}
  i := M;
  repeat
    inc(sol[0]);
    sol[sol[0]] := last[i];
    i := i - len[last[i]];
  until i = 0;
  writeln(fout,sol[0]);
  for i:=sol[0] downto 1 do writeln(fout,s[sol[i]]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
9þ Descifrar el mensaje.                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se  tiene un diccionario con  N  palabras (formadas por los caracteres
de la A a la Z ). Se sabe que se escribi¢ un mensaje secreto usando
alguna de estas palabras (concaten ndolas sin espacio) y que algunas
palabras fueron puestas al derecho y otras al rev‚s.

Ejemplo:

Palabras de Diccionario: aba  iba  ojo  lelo  alto lento
Mensaje Secreto: ojoolelotlaabaabi

Palabras utilizados: ojo  lelo   alto   iba

Se quiere descifrar el mensaje secreto, es decir, encontrar las
palabras originales del diccionario con las que fue construido el
mensaje. Se garantiza que el mensaje secreto fue formado completamente
con las palabras del diccionario  y de la forma descrita. Las palabras
pueden usarse tantas veces como se desee.

Tarea

Hacer un programa que permita:
- Leer desde fichero de entrada MENSAJE.IN las palabras que tiene el
  diccionario, y el mensaje codificado.
- Determinar las palabras con las que se construy¢ el mensaje.
- Escribir hacia el fichero de salida MENSAJE.OUT las palabras que
  componen el mensaje codificado.


Entrada

El fichero de entrada MENSAJE.IN contiene:
L¡nea 1: N (1 <= N <= 200), cantidad de palabras del diccionario.
L¡nea 2..N+1: en cada una de estas l¡neas se escribir  una palabra P
  (la longitud de P ser   <= 100).
L¡nea N+2: C (1 <= C <= 20 000) cantidad de caracteres en el mensaje
L¡nea N+3: el mensaje codificado.

Salida

El fichero de salida MENSAJE.OUT contiene:
L¡nea 1: P, representa la  cantidad de palabras del mensaje.
L¡nea 2..P+1: en cada una de estas l¡neas se escribir n una palabra,
la cual representa a una palabra del mensaje. Las palabras deben
aparecer en el mismo orden en que aparecen de izquierda a derecha en
el mensaje codificado. Pueden existir varias formas de escoger las
palabras en el mensaje aunque lo que importa es una de ellas.

Ejemplo de Entrada y Salida

MENSAJE.IN                   MENSAJE.OUT

6                            5
aba                          ojo
iba                          lelo
ojo                          alto
lelo                         aba
alto                         iba
lento
17
ojoolelotlaabaabi
}