{koder: A^2P}
{PSN 2000 #7 "El Juego del Dado"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 62506;
  NONE = 1 shl 16 - 1;
var
  fin,fout        : text;
  N,M,i,j,k,lvl   : word;
  b               : boolean;
  next,last,t,sol : array[0..MaxN] of word;
  d               : array[boolean,0..MaxN] of word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N * M do
  begin
    next[i] := i; last[i] := NONE;
  end;{for}
  repeat
    readln(fin,j,k); next[j] := k;
  until seekeof(fin);

  {solve}{bfs}
  d[b,0] := 1; d[b,1] := 0;
  repeat
    inc(lvl);
    b := not b; d[b,0] := 0;
    for i:=1 to d[not b,0] do
      for j:=1 to 6 do
        if last[next[d[not b,i] + j]] = NONE then
        begin
          inc(d[b,0]); d[b,d[b,0]] := next[d[not b,i] + j];
          last[next[d[not b,i] + j]] := next[d[not b,i]];
          t[next[d[not b,i] + j]] := j;
        end;{for}
  until last[M * N] <> NONE;

  {dprint}
  writeln(fout,lvl);
  i := N * M;
  while t[i] <> 0 do
  begin
    inc(sol[0]); sol[sol[0]] := t[i];  i := last[i];
  end;{while}
  for i:=sol[0] downto 1 do write(fout,sol[i],' ');

  {fclose}
  close(fin); close(fout);
end.{main}

{
 7ş El Juego del Dado                                       China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  tablero de NxM casillas se ha enumerado  consecutivamente con  los
n£meros  del  1  al  NxM  comenzando  por  la £ltima fila llenando las
casillas  de izquierda a derecha, luego la pen£ltima fila de derecha a
izquierda y asi alternadamente hasta la primera fila (figura 1).
Algunas  casillas tienen pase directo a otras casillas, bien en avance
o  en  retroceso  (se  indica  con una flecha). Estos pases  solo  son
validos cuando se termina de contar en una casilla que contenga enlace
directo con otra casilla.

Un  jugador con su ficha se va moviendo por las casillas (en el  orden
en  que fueron enumeradas) a medida que lanza un dado y avanza  tantas
casillas  como puntos salen. Las caras del dado est n enumeradas del 1
al  6. El objetivo del juego es  llegar  a la casilla  de mayor n£mero
(meta)  con la menor cantidad posible de tiros del dado. Se comienza a
contar la primera vez a partir de la casilla n£mero 1.

Determine  la puntuaci¢n que debe sacar un jugador en cada uno  de sus
turnos para ganar el juego lo m s pronto posible.

Figura 1 (Hoja).

Entrada

El  archivo de Entrada contiene en la primera l¡nea el n£mero de filas
del   tablero  N y el  n£mero  de  columnas  separados por un  espacio
(4  ó  N,  M ó 1000). Las  pr¢ximas l¡neas  tienen los  enlaces de las
casillas  que tienen pase directo a otra, uno por l¡nea, primero  esta
el n£mero de la casilla y luego, separado por espacio, el n£mero de la
casilla a donde se dirigir  la flecha.

Salida

El  archivo de  Salida  deber   contener en  una l¡nea la cantidad  de
veces  que  habra  que  lanzar  el  dado,  la  segunda l¡nea tendra la
puntuaci¢n que alcanzar  en cada tirada.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³  Ejemplo de Entrada  ³ ³ Ejemplo de Salida ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 5                  ³ ³ 4                 ³
³ 3 12                 ³ ³ 3 6 1 1           ³
³ 13 1                 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 17 7                 ³
³ 19 24                ³  Nota: S¢lo se dar  una soluci¢n.
³ 22 11                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Descripci¢n  del ejemplo de salida: En el primer  lanzamiento sali¢ la
cara 3, entonces movemos la ficha por las casillas 1, 2 y 3. Al llegar
a  la casilla 3 esta tiene un enlace directo  hasta la  casilla 12 por
lo  que autom ticamente la ficha se  mueve hasta dicha  casilla. En el
segundo tiro sali¢ un 6, por tanto nos movemos por las casillas  desde
la  13 hasta la 18. En el tercer lance sali¢ un 1 y nos movemos  hasta
la  casilla 19, esta tiene un pase directo hasta la casilla 24. En  el
£ltimo lance sali¢ un 1 y con esto llegamos a la casilla final, la 25.
}
