{koder: A^2P}
{PSN 2002 #83 "Superpalabras"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxS = 750;
var
  fin,fout        : text;
  N,i,j,k         : longint;
  b               : boolean;
  len             : array[boolean] of integer;
  s               : array[boolean,1..MaxS] of char;

    function isprefix(offset: word): boolean;
    var j : word;
    begin
      for j:=offset to len[not b] do
        if s[b][j - offset + 1] <> s[not b][j] then exit(false);
      isprefix := true;
    end;{iprefix}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  repeat
    inc(len[b]); read(fin,s[b,len[b]]);
  until seekeoln(fin);
  readln(fin);
  for i:=1 to len[b] do write(fout,s[b][i]);

  for i:=2 to N do
  begin
    b := not b; len[b] := 0;
    repeat
      inc(len[b]); read(fin,s[b,len[b]]);
    until seekeoln(fin);
    readln(fin);
    if len[b] >= len[not b] then
    begin
      for j:=2 to len[not b]+1 do if isprefix(j) then break;
    end{then ->}
    else {do}
      for j:=len[not b] - len[b] to len[not b]+1 do
        if isprefix(j) then break;
    for k:=len[not b] - j + 2 to len[b] do write(fout,s[b][k]);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
83ş Superpalabras                                           Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los  miembros  de la preselecci¢n nacional est n jugando nuevamente un
juego  de  diccionario;  no  hay mucho m s que hacer mientras uno esta
aburrido. El nuevo juego es simple, pero ellos necesitan verificar sus
respuestas.

Dada  una  lista  de  N  (1  <= N <= 10000) palabras, Cu l es la menor
"superpalabra"    que  las  cotiene  a  todas  ellas,  en  orden, como
subpalabras?   Considere  un  ejemplo  usando  tres  palabras:  'big',
'green',  and  'engine'.  Para  hacer  una  "superpalabra"   (la cual,
desafortunadamente,  rara  vez  aparece  en  el  diccionario), uno las
combina cuidadosamente para obtener: 'bigreengine'.

Las  palabras  aparecen  secuencialmente en una superpalabra cuando la
primera  letra  de  una  palabra  consituyente  aparece  estrictamente
despu‚s que la primera letra de la palabra previa y la £ltima letra de
la  palabra  aparece  estrictamente  despu‚s en la superpalabra que la
£ltima  letra  de  la palabra previa. Aqu¡ hay algunos ejemplos de dos
palabras:

        sin in    -> sinin
        sin sine  -> sinsine
        sin int   -> sint

Su tarea es encontrar superpalabras.

Entrada

El fichero de entrada SUWORD.IN contiene:
- L¡nea 1: Un solo entero: N
- L¡neas 2..N+1: Cada l¡nea contiene una sola palabra que s¢lo
  contiene  letras  en  m¡nusculas  ('a'..'z').  Ninguna palabra tiene
  longitud superior a 750 caracteres.

Salida

El  fichero  de  salida SUWORD.IN contiene una sola l¡nea que contiene
la  "superpalabra".

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ SUWORD.IN ³  ³ SUWORD.OUT  ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³  ³ bigreengine ³
³ big       ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ green     ³
³ engine    ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
