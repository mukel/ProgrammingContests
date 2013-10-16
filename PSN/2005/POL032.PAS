{koder: A^2P}
{PSN 2005 #32 "kino"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  N,i,j,k         : word;
  s,freq          : array[0..MaxN] of word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,j); inc(freq[j]);
  end;{for}

  {solve}
  for i:=1 to N do if freq[i] > 0 then
    for j:=1 to freq[i] do
    begin
      inc(k); s[k] := i;
    end;{for}
  for i:=1 to N do
    if s[i] < i then break;

  {dprint}
  write(fout,i);

  {fclose}
  close(fin); close(fout);
end.{main}

{
32þ kino.                                                 Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mirko esta celebrando su cumplea¤os  y quiere invitar a sus  amigos al
cine. A todos ellos le gustaria ir al cine en grandes grupos. Cada uno
le solicita  que ademas  de Mirko   y el mismo cierto numero de  otros
amigos de Mirko vengan al cine con ellos.

Mirko no tiene suficiente dinero para invitarlos a todos ellos asi que
el  quiere  invitar  a  un  numero  minimo  de  gente.  El  tiene  que
determinar tal grupo minimo tal que cada solicitud de las personas sea
satisfecha y el grupo consista de al menos una persona.

Ayude a Mirko a escribir un programa que calcule este numero.

Entrada

En la primera linea del  fichero de entrada KINO.IN aparece  un entero
N, 2 <= N <= 10000, el numero de amigos. En las proximas N lineas  hay
un  entero por  linea Zi,  1 <=  Zi <  N. Este  numero representa  las
peticiones de todos los amigos de Mirko, esto es, el numero minimo  de
gente que ellos estan deseando que vayan al cine con ellos.

Salida

En la primera y unica linea del fichero de salida KINO.OUT usted  debe
escribir el numero minimo de gente que Mirko puede invitar al cine.

Ejemplos de Entrada y Salida

Ejemplo # 1

 ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄ¿
 ³ KINO.IN ³ ³ KINO.OUT ³
 ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄ´
 ³ 2       ³ ³ 2        ³
 ³ 1       ³ ÀÄÄÄÄÄÄÄÄÄÄÙ
 ³ 1       ³
 ÀÄÄÄÄÄÄÄÄÄÙ

Ejemplo #2

 ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄ¿
 ³ KINO.IN ³ ³ KINO.OUT ³
 ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄ´
 ³ 3       ³ ³ 2        ³
 ³ 1       ³ ÀÄÄÄÄÄÄÄÄÄÄÙ
 ³ 2       ³
 ³ 1       ³
 ÀÄÄÄÄÄÄÄÄÄÙ

Ejemplo # 3

 ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄ¿
 ³ KINO.IN ³ ³ KINO.OUT ³
 ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄ´
 ³ 5       ³ ³ 4        ³
 ³ 3       ³ ÀÄÄÄÄÄÄÄÄÄÄÙ
 ³ 4       ³
 ³ 3       ³
 ³ 3       ³
 ³ 3       ³
 ÀÄÄÄÄÄÄÄÄÄÙ
}