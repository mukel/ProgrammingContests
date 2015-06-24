{koder: A^2P}{10 - 5 - 2007}
{PSN 2005 #93 "Foto Satelital"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 76;
  mov : array[0..1,1..4] of shortint =
  ((-1,0,0,1),(0,-1,1,0));
var
  fin,fout        : text;
  N,M,C,B,i,j,
  sol,cant,
  maxX,maxY,
  minX,minY       : longint;
  mat             : array[0..MaxN,0..MaxN] of char;

    procedure dfs(i,j: longint);
    var k : longint;
    begin
      inc(cant);
      mat[i,j] := '.';
      if i > maxX then maxX := i;
      if j > maxY then maxY := j;
      if i < minX then minX := i;
      if j < minY then minY := j;      
      for k:=1 to 4 do
        if mat[i + mov[0,k],j + mov[1,k]] = '#'
          then dfs(i + mov[0,k],j + mov[1,k]);
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    for j:=1 to M do read(fin,mat[i,j]);
    readln(fin);
  end;{for}

  {solve}
  for i:=1 to N do
    for j:=1 to M do
      if mat[i,j] = '#' then
      begin
        cant := 0;
        maxX := i; maxY := j;
        minX := i; minY := j;
        dfs(i,j);
        if (maxY - minY + 1) * (maxX - minX + 1) = cant
          then inc(B)
          else inc(C);
      end;{then}

  {dprint}
  writeln(fout,B);
  writeln(fout,C);

  {fclose}
  close(fin); close(fout);
end.{main}

{
93þ Foto Satelital.                                       Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan siempre quiso un buen mapa de su granja, por lo tanto
el compr¢ una foto satelital de su terreno el cual est  representado
por R (1 <= R <= 75) filas y C (1 <= C <= 75) columnas en la foto. Una
parte de una foto se ve algo asi:

..................
..#####.......##..
..#####......##...
..................
#.......###.....#.
#.....#####.......

Tratando de interpretar la foto, el se imagina que cada forma
conectada es o un establo o una vaca. Una "forma conectada" es un
conjunto de uno o m s #'s que son adyacentes entre s¡ vertical u
horizontalmente. Las dos formas siguientes serian dos 'formas
conectadas' diferentes.

....
.#..
..#.
....

GJ sostiene que una forma conectada es un establo si esta llenando un
rect ngulo cuyos cuatro lados sean paralelos a los ejes x y y. En la
foto antes mostrada, hay tres establos (de tama¤os 2x1, 2x5, y 1x1) y
dos vacas (usted se sorprender¡a por el tama¤o de las vacas de GJ).
Cuente el n£mero de establos y de vacas en su foto satelital.

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacios: R y C.
- L¡neas 2. R+1: La l¡nea i+1 representa la fila i de la foto y
  contiene C caracteres (y no espacios).

ENTRADA EJEMPLO (archivo satel.in):

5 8
#####..#
#####.##
......#.
.###...#
.###..##


DETALLES DE LA ENTRADA:

La foto consiste de 5 l¡neas, cada una de las cuales tiene 8
caracteres de longitud.

FORMATO DE SALIDA:

- L¡nea 1: El n£mero de establos en la foto.
- L¡nea 2: El n£mero de vacas en la foto.

SALIDA EJEMPLO (archivo satel.out):

2
2

DETALLES DE LA SALIDA:

La foto tiene 2 establos (las formas en la izquierda) y 2 vacas (en la
derecha).
}