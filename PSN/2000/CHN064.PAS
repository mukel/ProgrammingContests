{koder: A^2P}{4 - 3 - 2007}
{PSN 2000 #64 "Copiando Libros"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 500;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  t               : array[0..MaxN] of longint;
  c,last          : array[0..MaxN,0..MaxN] of longint;

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

    procedure print(i,j: longint);
    begin
      if j > 1 then
      begin
        print(last[i,j],j - 1);
        write(fout,'/ ');
      end;{then}
      for j:=last[i,j] + 1 to i do
        write(fout,t[j] - t[j - 1],' ');
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    read(fin,t[i]);
    inc(t[i],t[i - 1]);
  end;{for}

  {solve}
  for i:=1 to N do c[i,1] := t[i];
  for j:=2 to M do
    for i:=j to N do
    begin
      c[i,j] := oo;
      for k:=j - 1 to i - 1 do
        if (c[k,j - 1] < c[i,j]) and (t[i] - t[k] < c[i,j]) then
        begin
          c[i,j] := max(c[k,j - 1],t[i] - t[k]);
          last[i,j] := k;
        end;{then}
    end;{for}

  {dprint}
  print(N,M);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 64þ Copiando Libros.                                       China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Antes  de  la invensi¢n de la Imprenta, era muy dif¡cil hacer la copia
de  un  libro.  Todo  el  contenido deb¡a ser reescrito a mano por los
llamados  escribanos.  Al  escribano  se le daba un libro y despu‚s de
varios meses el finalizaba la copia. Uno de los m s famosos escribanos
vivi¢  en  el siglo XV y su nombre fue Xavierus Endricus Renius Ontius
Xendrianus  (XEROX).  De  cualquier  modo el trabajo fue muy molesto y
aburrido  y  el  £nico modo de agilizar esta tarea era contratando m s
escribanos.

En  otros  tiempos existi¢ un grupo de teatro que quiso montar famosas
tragedias antiguas.

Los  guiones  de  esas  obras  fueron  escritos en varios libros y los
actores  necesitaron  m s copias de estos. As¡ que ellos contrataron a
varios  escribanos para que hicieran copias. Imagine que usted tiene M
libros  (numerados  1,  2,  ...,  M)  que tienen diferentes n£meros de
p ginas  (p1,  p2,  ...,  pM)  y quiere hacer una copia de cada uno de
estos.

Tu tarea es dividir estos libros entre K escribanos, K ó M. Cada libro
puede  ser  asignado  a  un solo escribano, y cada escribano tiene que
coger  una secuencia continua de  libros entre bi y bj (bi, bi+1, ...,
bj,  para  i  < j). El tiempo necesitado para hacer una copia de todos
los  libros es determinado por el escribano que tiene m s trabajo. Por
lo  que nuestro prop¢sito es minimizar el n£mero de p ginas asignado a
ese escribano. Tu tarea es encontrar la asignaci¢n ¢ptima.

Entrada

Conformada  por  dos l¡neas. La primera l¡nea aparecen dos enteros M y
K,  1  ó  K  ó  M  ó  500.  En  la segunda l¡nea est n p1, p2, ..., pM
separados  por  espacio.  Estos  valores  son  positivo  y menores que
10000000.

Salida

El  fichero de salida contiene en ua sola l¡nea la sucesi¢n de entrada
p1,  p2,...,  pM  dividida   exactamente  en  K   partes  (cada  parte
corresponde   a  la  sucesi¢n  continua  de  libros  asignada  a  cada
escribano)  tal  que la suma m xima del escribano de mayor trabajo sea
m¡nima.  Use  el  caracter  '/'  para separar las partes. Debe existir
exactamente  un  espacio  entre  dos  n£meros sucesivos cualesquiera y
entre un n£mero y el '/'. Si existe m s de una soluci¢n escriba la que
minimice  el  trabajo  asignado al primer escribano, luego al segundo,
etc. Cada escribano debe tener asignado al menos un libro.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #1 de Entrada                ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 9 3                                 ³
³ 200 100 500 400 300 600 700 900 800 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #1 de Salida                     ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 200 100 500 400 300 / 600 700 / 900 800 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #2 de Entrada³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 4                 ³
³ 100 100 100 100 100 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #2 de Salida       ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 100 / 100 / 100 / 100 100 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}