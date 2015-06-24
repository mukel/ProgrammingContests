{koder: A^2P}{9 - 5 - 2007}
{PSN 2005 #75 "El televisor de Dave"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 20;
  target = 1 shl 3;
var
  fin,fout        : text;
  N,i,j,k,h,sol,
  a,b,start       : longint;
  size            : array[0..1] of longint;
  key             : array[0..MaxN] of longint;
  mark            : array[0..1 shl 21] of boolean;
  queue           : array[0..1,0..1 shl 20] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    read(fin,j);
    if j = 1 then start := start or (j shl i);
  end;{for}
  readln(fin);
  for i:=1 to N do
  begin
    read(fin,j);
    key[i] := 1 shl (N + 1) - 1;
    for j:=1 to j do
    begin
      read(fin,k);
      key[i] := key[i] xor (1 shl k);
    end;{for}
  end;{for}

  {solve}
  a := 1; mark[start] := true;
  size[a] := 1; queue[a,size[a]] := start;
  while not mark[target] do
  begin
    inc(sol);
    a := a xor 1; b := b xor 1;
    size[a] := 0;
    for i:=1 to size[b] do
      for j:=1 to N do
      begin
        k := queue[b,i];
        h := (k and key[j]) or (1 shl j);
        if not odd(k shr j) and (not mark[h]) then
        begin
          mark[h] := true;
          inc(size[a]);
          queue[a,size[a]] := h;
        end;{then}
      end;{for}
  end;{while}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
75ş El televisor de Dave.                                  Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dave tiene un  televisor que est   totalmente viejo, y  algunos de sus
botones  no  est   funcionando  apropiadamente.  Presionando  un bot¢n
(mientras el TV era nuevo) liberaba a todos los otros botones  dejando
solamente un bot¢n presionado.

Presionado un bot¢n ahora liberar  algunos de los botones dejando  las
posiciones de los otros botones  sin cambiar. Dave conoce los  efectos
de presionar cada bot¢n.

Tarea

Escriba un programa que  ayuda a Dave a  determinar la longitud de  la
secuencia m s corta de botones que necesitan ser presionados desde una
posici¢n  dada  tal que  al  final solamente  el  bot¢n 3  est‚  en la
posici¢n presionado y todos los otros est‚n liberados.

Entrada

La entrada ser  a trav‚s del fichero de entrada GUMBI.IN contiene enla
primera l¡nea un entero  n, 3 <= n  <= 20, elo n£emro   de botones del
TV.  La  segunda  l¡nea  de la  entrada  contiene  n  d¡gitos binarios
separados por un caracter espacio determinando la posici¢n inicial  de
los botones - 0 significa que el bot¢n correspondiente est   liberado,
1 -  que el  est  presionado.  Las pr¢ximas  n l¡neas  de la  entdrada
determina los botones que son liberados presionando un bot¢n. (M +  2)
-‚sima l¡nea comienza con un n£mero k seguido por k n£meros (ordenados
en orden ascendente) - los botones que son liberados cuando el bot¢n M
es presionado. (Los  botones est n denotados  por un n£emro  entre 1 y
M). Un bot¢n no puede liberarse el mismo y es posible que un bot¢n  no
pueda liberar alg£n bot¢n.

Nota: los datos de entrada ser n elegitos tal que una soluci¢n siempre
      exista

Salida

La primera y £nica l¡nea del fichero de salida GUMBI.OUT debe contener
la longitud  de la  secuencia m s  corta de  botones que necesitan ser
presionados tal que  al final solamente  el bot¢n 3  este presionado y
todos los otros est‚n liberados.

Ejemplos de Entrada y Salida


Ejemplo # 1        Ejemplo # 2        Ejemplo # 3
ÚÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ GUMBI.IN ³       ³ GUMBI.IN ³       ³ GUMBI.IN  ³
ÃÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 3        ³       ³ 4        ³       ³ 5         ³
³ 1 1 0    ³       ³ 0 1 0 1  ³       ³ 1 1 0 0 1 ³
³ 2 2 3    ³       ³ 3 2 3 4  ³       ³ 4 2 3 4 5 ³
³ 2 1 3    ³       ³ 1 1      ³       ³ 4 1 3 4 5 ³
³ 2 1 2    ³       ³ 1 1      ³       ³ 2 2 4     ³
ÀÄÄÄÄÄÄÄÄÄÄÙ       ³ 0        ³       ³ 0         ³
                   ÀÄÄÄÄÄÄÄÄÄÄÙ       ³ 4 1 2 3 4 ³
                                      ÀÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ GUMBI.OUT ³      ³ GUMBI.OUT ³      ³ GUMBI.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 1         ³      ³ 2         ³      ³ 3         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}