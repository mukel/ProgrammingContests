{koder: A^2P}{24 - 3 - 2007}
{PSN 2006 #97 "Paseo Vespertino"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxFC = 30;
var
  fin,fout        : text;
  space           : char;
  F,C,i,j,k       : longint;
  X,Y             : array[0..1] of longint;
  mat             : array[0..MaxFC,0..MaxFC] of char;
  cant            : array[0..MaxFC,0..MaxFC] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,F,C);
  for i:=1 to F do
    for j:=1 to C do
    begin
      read(fin,mat[i,j]);
      if j < C then read(fin,space)
        else readln(fin);
      if mat[i,j] = 'B' then
      begin
        X[k] := i; Y[k] := j;
        inc(k);
      end;{then}
    end;{for}

  {solve}{easy dp}
  cant[X[0],Y[0]] := 1;
  for i:=X[0] to X[1] do
    for j:=Y[0] to Y[1] do if mat[i,j] <> 'R'
      then inc(cant[i,j],cant[i - 1,j] + cant[i,j - 1]);

  {dprint}
  writeln(fout,cant[X[1],Y[1]]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
97ş Paseo Vespertino.                                      M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Como todos sabemos, a las vacas les gustan las novedades. Por lo tanto
muchas veces  somos llamados  para ayudarles  a evitar  duplicaci¢n de
esfuerzos o escenarios. Otra pregunta importante ha aparecido.

Betsy est  feliz pasteando en un campo de R (1 <= R <= 20) filas por C
(1 <= C <= 30) columnas de lotes de pasteo (denotados por '.') y lotes
rocosos  (denotados por   'R'). El  lote (1,  1) est   en la   esquina
superior izquierda de esta cuadr¡cula.  El sol se est  ocultando,  por
lo tanto es tiempo de devolverse al establo, el cual est  al sur y  al
este de Betsy.

Betsy quiere usar una ruta nueva al establo cada noche. Ella no  puede
caminar sobre los lotes  rocosos y solo se  desplazar  hacia el sur  y
hacia el este hacia el establo, nunca al norte ni al oeste. Por  favor
calcule cuàntas tardes  puede ella deambular  en una nueva  ruta antes
que ella tenga que repetir una ruta usada anteriormente.

Como ejemplo, considere esta distribuci¢n para la zona de pasteo de
Besty:

              B . . .       B = Betsy    . = lote para caminar
              R . . .       R = Rocas
              . . . B       B = Establo

Aqu¡ est n las seis maneras en que ella puede caminar al establo:

B## . .    B## . .    B#### .    B## . .   B######   B#### .
R # . .    R ### .    R . # .    R #####   R . . #   R . ###
. ####B    . . ##B    . . ##B    . . . B   . . . B   . . . B


NOMBRE DEL PROBLEMA: stroll

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio, respectivamente: R y C

-  L¡neas 2..R+1:  La l¡nea  i+1 representa  la fila  i y  contiene  C
elementos separados por espacios que representan lotes en el campo. El
primer elemento es el elemento en la columna 1 o fila 1. Cada elemento
es una 'B', 'R', o  '.'. Las 'B's no son ambiguas.

ENTRADA EJEMPLO (archivo STROLL.IN):

3 4
B . . .
R . . .
. . . B


FORMATO DE SALIDA:

- L¡nea 1: Un solo entero que es el n£mero de caminos £nicos de  Betsy
al establo. La respuesta no exceder  2,000,000,000.


SALIDA EJEMPLO (archivo STROLL.OUT):

6
}