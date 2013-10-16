{koder: A^2P}{30 - 4 - 2007}
{PSN 2005 #23 "Vacas agresivas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
var
  fin,fout        : text;
  N,C,D,H,M,i     : longint;
  dist            : array[0..MaxN] of longint;

    var p,tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := dist[(d + h) shr 1];
      repeat
        while dist[i] < p do inc(i);
        while dist[j] > p do dec(j);
        if i <= j then
        begin
          tmp := dist[i]; dist[i] := dist[j]; dist[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

    function check(value: longint): boolean;
    var i,j,cant : longint;
    begin
      i := 1; cant := 1;
      while i < N do
      begin
        inc(cant);
        j := i + 1;
        while (j < N) and (dist[j] - dist[i] < value) do inc(j);
        if dist[j] - dist[i] < value then dec(cant);
        i := j;
      end;{while}
      check := (cant >= C);
    end;{check}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,C);
  for i:=1 to N do readln(fin,dist[i]);

  {solve}
  qsort(1,N);
  D := 0; H := 1000000000;
  repeat
    M := (D + H) shr 1;
    if check(M) then D := M + 1
      else H := M;
  until D = H;

  {dprint}
  writeln(fout,H - 1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
23ş Vacas agresivas                                       Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan ha construido un nuevo establo grande, con N (2 <=  N
<= 100,000) pesebreras.  Las pesebreras est n  ubicadas a lo  largo de
una l¡nea recta en posiciones x1,...,xN (0 <= xi <= 1,000,000,000).

Sus C (2 <= C <= N) vacas no les gusta est  distribuci¢n del establo y
se vuelven  agresivas entre  ellas una  vez puestas  en una pesebrera.
Para prevenir que las vacas se ataquen entre ellas, GJ quiere  asignar
las vacas  a las  pesebreras, de  tal manera  que la  distancia m¡nima
entre cualesquiera dos de ellas sea tan grande como sea posible. ¨Cu l
es la distancia m¡nima m s grande?

NOMBRE DEL PROBLEMA: aggr

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio: N y C
- L¡neas 2..N+1: La  L¡nea   i+1   contiene  la  ubicaci¢n  entera  de
  pesebrera, xi

ENTRADA EJEMPLO (archivo aggr.in):

5 3
1
2
8
4
9

FORMATO DE SALIDA:
- L¡nea 1: Un entero, la distancia m¡nima m s grande

SALIDA EJEMPLO (archivo aggr.out):

3

DETALLES DE LA SALIDA:

GJ puede poner sus 3 vacas en las pesebreras en posiciones 1, 4, y  8,
resultando en una distancia m¡nima de 3.
}
