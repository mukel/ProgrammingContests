{koder: A^2P}
{PSN 2002 #76 "Mapa de Densidad"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 250;
var
  fin,fout        : text;
  N,M,i,j,
  x1,x2,y1,y2     : word;
  t               : array[0..MaxN,0..MaxN] of word;

    function max(a,b: integer): integer;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

    function min(a,b: integer): integer;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
    for j:=1 to N do
    begin
      read(fin,t[i,j]);
      inc(t[i,j],t[i-1,j] + t[i,j-1] - t[i-1,j-1]);
    end;{for}

  {solve}
  for i:=1 to N do
  begin
    for j:=1 to N do
    begin
      x1 := max(i-M-1,0); x2 := min(i+M,N);
      y1 := max(j-M-1,0); y2 := min(j+M,N);
      write(fout,t[x2,y2] - t[x1,y2] - t[x2,y1] + t[x1,y1],' ');
    end;{for}
    writeln(fout);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

(*
76þ Mapa de Densidad                                        Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se dan:
. los enteros n y r, n > r >= 0,
. la  tabla  F  de n x n con n£meros del conjunto {0,1}; las columnas
  y las filas de la tabla son numeradas desde 1 hasta n, el n£mero en
  la i-‚sima columna y en la j-‚sima fila es denotado como F[i,j].

Si  [i,j]  y  [i',j']  son  dos posiciones de la tabla F, la distancia
entre  ellas  es el Max(|i-i'|,|j-j'|). La tabla W, de n x n, debe ser
calculada,  donde  W[i,j]  (el  n£mero  en  la i-‚sima columna y en la
j-‚sima fila de la tabla W) es igual a la suma de todos los n£meros de
F[x, y], tal que la distancia entre [x, y] y [i, j] no es mayor que r.

Tarea

Escriba un programa, el cual:
- lea los enteros n, r y la tabla F desde el fichero texto MAP.IN,
- calcule la tabla W,
- escriba la tabla W hacia el fichero texto MAP.OUT.

Entrada

En    la   primera  l¡nea  texto  MAP.IN  hay  dos  enteros  positivos
separados  por  un  espacio:  n  y  r,  donde  0  <=  r < n <= 250. En
las  siguientes  n  l¡neas  es  descrita la tabla F. Cada una de estas
l¡neas    contiene   n  enteros  del  conjunto  {0,1},  separados  por
espacios.  El  i-‚simo  n£mero  escrito  en  la  (j+1)-‚sima  l¡nea es
igual a F[i,j].

Salida

El  fichero  MAP.OUT debe contener exactamente n l¡neas. En la j-‚sima
l¡nea    deben    ser    escritos    los  valores  W[1,  j]...  W[n,j]
respectivamente; ellos deben estar separados por un espacio.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ MAP.IN      ³     ³ MAP.OUT     ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 1         ³     ³ 3 4 2 2 1   ³
³ 1 0 0 0 1   ³     ³ 4 5 2 2 1   ³
³ 1 1 1 0 0   ³     ³ 3 4 3 3 2   ³
³ 1 0 0 0 0   ³     ³ 2 2 2 2 2   ³
³ 0 0 0 1 1   ³     ³ 1 1 2 2 2   ³
³ 0 1 0 0 0   ³     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*)
