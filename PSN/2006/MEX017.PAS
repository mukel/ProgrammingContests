{koder: A^2P}
{PSN 2006 #17 "Tablero"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  mov : array[0..1,1..4] of shortint =
  ((-1,0,0,1),(0,-1,1,0));
var
  fin,fout        : text;
  i,j,k,sol       : longint;
  mat             : array[0..6,0..6] of byte;
  mark            : array[0..999999] of boolean;

    function ok(i,j: shortint): boolean;
    begin
      ok := ((i > 0) and (i < 6))
        and ((j > 0) and (j < 6));
    end;{ok}

    procedure dfs(x,y,lvl: byte);
    var i : byte;
    begin
      k := k * 10 + mat[x,y];
      if (lvl = 6) and (not mark[k]) then
      begin
        mark[k] := true; inc(sol);
      end;{then}
      if lvl < 6 then
        for i:=1 to 4 do
          if ok(x + mov[0,i],y + mov[1,i])
            then dfs(x + mov[0,i],y + mov[1,i],lvl + 1);
      k := k div 10;
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  for i:=1 to 5 do
    for j:=1 to 5 do
      read(fin,mat[i,j]);

  {solve}
  for i:=1 to 5 do
    for j:=1 to 5 do dfs(i,j,1);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
17ş Tablero.                                               M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las vacas se inventaron un juego que consiste en un tablero de 5x5
casillas pintado en el piso paralelo a los ejes x y y en el cual ellas
brincan. En cada una de las casillas est  escrito un d¡gito.

Ellas saltan h bilmente en cualquier d¡gito del tablero y de ah¡ a
otro en alg£n d¡gito adyacente, hacia delante, hacia atr s, hacia la
derecha, o hacia la izquierda (nunca en diagonal). Vuelven a saltar
nuevamente (mismas reglas) a otro d¡gito (potencialmente un d¡gito ya
visitado).

Con un total de cinco saltos entre casillas, sus saltos crean un
entero de seis d¡gitos (el cual podr¡a tener ceros a la izquierda como
000201).

Determine el n£mero de distintos enteros que pueden ser creados de
esta manera.

NOMBRE DEL PROBLEMA: numgrid

FORMATO DE ENTRADA:

- L¡neas 1..5: El tablero, cinco d¡gitos separados por espacios por
  l¡nea.

ENTRADA EJEMPLO (archivo numgrid.in):

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1

FORMATO DE SALIDA:

L¡nea 1: El n£mero de enteros distintos que pueden ser construidos

SALIDA EJEMPLO (archivo numgrid.out):

15

DETALLES DE LA SALIDA:

111111, 111112, 111121, 111211, 111212, 112111, 112121, 121111, 121112,
121211, 121212, 211111, 211121, 212111, y 212121 pueden ser construidos.
No son posibles otros valores.
}