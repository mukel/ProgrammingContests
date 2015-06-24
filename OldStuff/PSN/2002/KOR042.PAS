{koder: A^2P}{10 - 3 - 2007}
{PSN 2002 #42 "Bitmap"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 183;
  oo = $ffff;
  mov : array[0..1,1..4] of shortint =
  ((-1,0,0,1),(0,-1,1,0));
var
  fin,fout        : text;
  ch              : char;
  N,M,i,j,k,
  a,b,lvl         : longint;
  size            : array[0..1] of longint;
  sol             : array[0..MaxN,0..MaxN] of word;
  qx,qy           : array[0..1,0..MaxN * MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    for j:=1 to M do
    begin
      read(fin,ch);
      if ch = '1' then
      begin
        sol[i,j] := 0;
        inc(size[a]);
        qx[a,size[a]] := i;
        qy[a,size[a]] := j;
      end{then ->}
      else sol[i,j] := oo;
    end;{for}
    readln(fin);
  end;{for}

  {solve}{bfs}
  b := 1;
  repeat
    a := a xor 1; b := b xor 1;
    size[a] := 0; inc(lvl);
    for i:=1 to size[b] do
      for j:=1 to 4 do
        if sol[qx[b,i] + mov[0,j],qy[b,i] + mov[1,j]] > lvl then
        begin
          inc(size[a]);
          qx[a,size[a]] := qx[b,i] + mov[0,j];
          qy[a,size[a]] := qy[b,i] + mov[1,j];
          sol[qx[b,i] + mov[0,j],qy[b,i] + mov[1,j]] := lvl;
        end;{then}
  until size[a] = 0;

  {dprint}
  for i:=1 to N do
  begin
    for j:=1 to M do write(fout,sol[i,j],' ');
    writeln(fout);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
42ş Bitmap                                                  Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se tiene un bitmap rectangular de tama¤o NxM. Cada pixel del bitmap es
blanco  o  negro,  pero al menos uno es blanco. El pixel en la i-‚sima
l¡nea  y j-‚sima columna es llamado el pixel (i,j). La distancia entre
dos pixel p1 = (i1, j1) y p2 = (i2, j2) es definido como:

     d(p1, p2) = |i1 - i2| + |j1 - j2|

Tarea

Escriba un programa el cual:

- lea la descripci¢n del bitmap del fichero texto BIT.IN,
- para cada pixel, calcule la distancia al pixel blanco m s cercano,
- escriba los resultados hacia el fichero texto BIT.OUT.

Entrada

En  la  primera  l¡nea  del fichero texto BIT.IN hay un par de n£meros
enteros N, M separados por un espacio simple, 1 <= N <= 182, 1 <= M <=
182.  En  cada  una  de  las  siguientes  N  l¡neas del fichero BIT.IN
contendr   exactamente una palabra (de ceros y unos) de longitud M, la
descripci¢n  de  una  l¡nea  del  bitmap,  es  escrita. En la posici¢n
j-‚sima  en la l¡nea (i+1), 1 <= i <= N, 1 <= j <= M, es '1' s¡ y solo
s¡ el pixel (i,j) es blanco.

Salida

En  la  i-‚sima l¡nea del fichero de salida BIT.OUT, 1 <= i <= N, debe
haber  escrito  M  enteros  f(i,1),... f(i,M) separados por un espacio
simple,  donde  f(i,j) es la distancia del pixel (i,j) al pixel blanco
m s cercano.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄ¿
³ BIT.IN ³    ³ BIT.OUT ³
ÃÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄ´
³ 3 4    ³    ³ 3 2 1 0 ³
³ 0001   ³    ³ 2 1 0 0 ³
³ 0011   ³    ³ 1 0 0 1 ³
³ 0110   ³    ÀÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÙ
}
