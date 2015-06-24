{koder: A^2P}{5 - 3 - 2007}
{PSN 2006 #18 "Fotograf¡as Satelitales"}
{$B-,I-,Q-,R-,S-}
{$M 0,0,0}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1001;
var
  fin,fout        : text;
  c               : char;
  N,M,i,j,k,sol   : longint;
  mark            : array[0..MaxN,0..MaxN] of boolean;

    procedure dfs(x,y: word);
    begin
      mark[x,y] := false; inc(k);
      if mark[x - 1,y] then dfs(x - 1,y);
      if mark[x + 1,y] then dfs(x + 1,y);
      if mark[x,y - 1] then dfs(x,y - 1);
      if mark[x,y + 1] then dfs(x,y + 1);
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,M,N);
  for i:=1 to N do
  begin
    for j:=1 to M do
    begin
      read(fin,c);
      if c = '*' then mark[i,j] := true;
    end;{for}
    readln(fin);
  end;{for}

  {solve}
  for i:=1 to N do
    for j:=1 to M do
      if mark[i,j] then
      begin
        k := 0; dfs(i,j);
        if k > sol then sol := k;
      end;{then}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
18ş Fotograf¡as Satelitales.                               M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan compr¢ fotos satelitales de W x H pixels de su granja
(1 <= W <= 80, 1 <= H <= 1000) y desea determinar el pastizal conexo
m s grande. Un pastizal es conexo cuando cualquier par de pixels en ‚l
pueden ser conectados atravesando pixels adyacentes vertical u
horizontalmente que tambi‚n son parte del pastizal. (Es f cil crear
pastizales de formas muy extra¤as, a£n c¡rculos que rodeen otros
c¡rculos).

Cada foto ha sido digitalizada permitiendo mostrar  reas de pastizales
como un asterisco ('*') y las  reas de no-pastizales como un punto
('.'). Aqu¡ hay un ejemplo de una foto satelital 10 x 5:

..*.....**
.**..*****
.*...*....
..****.***
..****.***

Esta foto muestra tres pastizales conexos de 4, 16, y 6 pixels. Ayude
al Granjero Juan ha encontrar el pastizal conexo m s grande en cada
una de sus fotos satelitales.

NOMBRE DEL PROBLEMA: satpix

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio: W y H

- L¡neas 2..H+1: Cada l¡nea contiene W caracteres '*' o '.'
        representando una l¡nea de una foto satelital.

ENTRADA EJEMPLO (archivo satpix.in):

10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***

FORMATO DE SALIDA:

L¡nea 1: El tama¤o de la regi¢n conexa m s grande en la foto
satelital.

SALIDA EJEMPLO (archivo satpix.out):

16
}