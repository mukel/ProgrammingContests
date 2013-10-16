{koder: A^2P}
{PSN 2005 #48 "Elevador Espacial"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 400;
  MaxH = 40000;
var
  fin,fout        : text;
  N,i,j,p,tmp     : word;
  a,hm,lim        : array[0..MaxN] of word;
  last,c          : array[0..MaxH] of word;

    procedure qsort(d,h: word);
    var i,j : word;
    begin
      i := d; j := h; p := hm[(d + h) shr 1];
      repeat
        while hm[i] < p do inc(i);
        while hm[j] > p do dec(j);
        if i <= j then
        begin
          tmp := a[i]; a[i] := a[j]; a[j] := tmp;
          tmp := hm[i]; hm[i] := hm[j]; hm[j] := tmp;
          tmp := lim[i]; lim[i] := lim[j]; lim[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    readln(fin,a[i],hm[i],lim[i]);

  {solve}{knapsack}
  qsort(1,N); last[0] := 1 shl 9; // > 400
  for i:=1 to N do
    for j:=a[i] to hm[i] do
      if (last[j - a[i]] <> 0) and (c[j] = 0) then
        if last[j - a[i]] = i then
        begin
          if c[j - a[i]] < lim[i] then
          begin
            last[j] := i;
            c[j] := c[j - a[i]] + 1;
          end;{then}
        end{then ->}
        else begin
          last[j] := i; c[j] := 1;
        end;{else}

  {dprint}
  for i:=hm[N] downto 0 do
    if last[i] <> 0 then break;
  write(fout,i);

  {fclose}
  close(fin); close(fout);
end.{main}

{
48ş Elevador Espacial.                                    Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

­Las vacas  est n yendo  al espacio!  Ellas planean  entrar en  ¢rbita
construyendo una especie  de elevador espacial:  una torre gigante  de
bloques. Ellas tienen K  (1 <= K <=  400) tipos diferentes de  bloques
con los cuales  construir la torre. Cada  tipo de bloque i  tienen una
altura h_i (1 <= h_i <= 100) y est  disponible en cantidad c_i  (1  <=
c_i <= 10).  Debido a posibles  da¤os producidos por  rayos  c¢smicos,
ninguna parte de un bloque de  tipo i puede exceder una altura  m xima
a_i (1 <= a_i <= 40000).

Ayude a las  vacas a construir  el elevador espacial  m s alto posible
apilando bloques uno encima del otro de acuerdo a las reglas.

NOMBRE DEL PROBLEMA: elevator

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero, K

- L¡neas 2..K+1:  Cada  l¡nea  contiene  tres  enteros  separados  por
  espacio: h_i, a_i, y c_i. La l¡nea i+1 describe el bloque de tipo i.

ENTRADA EJEMPLO (archivo elevator.in):

3
7 40 3
5 23 8
2 52 6

FORMATO DE SALIDA:

- L¡nea  1: Un  solo entero  H, la  m xima altura  con la que se puede
  construir una torre.

SALIDA EJEMPLO (archivo elevator.out):

48

DETALLES DE LA SALIDA:

Desde abajo: 3 bloques de tipo 2,  debajo de 3 de tipo 1, debajo  de 6
de tipo 3. Apilar 4 bloques de tipo 2 y 3 de tipo 1 no es legal, desde
que la parte superior del £ltimo bloque de tipo 1 exceder¡a la  altura
40.
}
