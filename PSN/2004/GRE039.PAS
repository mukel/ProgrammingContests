{koder: A^2P}{13 - 3 - 2007}
{PSN 2004 #39 "Cartas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 400;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,M,i,j,k,sol   : longint;
  tupple          : array[0..4] of longint;
  mark            : array[0..4] of boolean;
  color,value     : array[0..MaxN] of longint;
  lcs             : array[0..1,0..MaxN] of longint;

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

    function cost(): longint;
    var a : byte;
    begin
      a := 0;
      fillchar(lcs,sizeof(lcs),0);
      for i:=1 to N * M do
      begin
        a := a xor 1;
        for j:=1 to N * M do
          if i = (tupple[color[j]] - 1) * M + value[j]
            then lcs[a,j] := lcs[a xor 1,j - 1] + 1
            else lcs[a,j] := max(lcs[a xor 1,j],lcs[a,j - 1]);
      end;{for}
      cost := N * M - lcs[a,N * M];
    end;{cost}

  procedure permute(i,j: longint);
  var k : longint;
  begin
    mark[i] := true; tupple[j] := i;
    if j = 4 then
    begin
      k := cost();
      if k < sol then sol := k;
    end;{then}

    for k:=1 to 4 do
      if not mark[k] then permute(k,j + 1);

    mark[i] := false;
  end;{permute}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N * M do
    readln(fin,color[i],value[i]);

  {solve}
  sol := oo;
  permute(0,0);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
39þ Cartas.                                                Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Al independiente hijo peque¤o de Dave le gusta jugar los juegos de las
cartas, pero s¢lo teniendo cuatro a¤os, ‚l siempre pierde al jugar con
sus m s viejos amigos. Tambi‚n, colocar las cartas en su mano es un
problema real para ‚l. Cuando el consigue sus cartas, ‚l tiene que
colocarla en el grupo tal que  todas las cartas en un grupo sean del
mismo color. Luego, ‚l tiene que ordenar las cartas en cada grupo por
su valor - la carta con el valor m s bajo debe ser la que est‚ m s
arriba en su grupo. Claro, ‚l tiene que sostener todas las
cartas en su mano todo el tiempo. El tiene que colocar sus cartas tan
r pidamente como sea posible, es decir haciendo pocos  movimientos
como sea posible. Un movimiento consiste en cambiar una posici¢n de
una de sus cartas. Escriba que un programa que calcule el n£mero m s
peque¤o de movimientos necesario para  colocar las cartas.

Entrada

La primera l¡nea de archivo de la entrada CARDS.IN contiene dos
enteros, C, n£mero de colores (1 <= C <= 4), y N, n£mero de cartas del
mismo color (1 <= N <= 100), separados por un caracter espacio. Cada
una de las pr¢ximas C*N  l¡neas contiene un par de enteros X y Y, 1 <=
X <= C, 1 <= Y <= N, separados por un caracter espacio. Los n£meros en
cada uno de esas l¡neas determinan un color (X) y un valor (Y) de una
carta repartida al independiente peque¤o. El orden de las l¡neas
corresponde al orden que las cartas se repartieron al independiente
peque¤o. Ninguna dos l¡neas describe la misma carta.

Salida

El primero y £nica l¡nea del archivo del salida CARDS.OUT debe
contener el n£mero m s peque¤o de movimientos necesitados para colocar
las cartas como fue descrito anteriormente.

Ejemplos de Entrada y Salida:

Ejemplo #1             Ejemplo #2                Ejemplo #3
ÚÄÄÄÄÄÄÄÄÄÄ¿           ÚÄÄÄÄÄÄÄÄÄÄ¿             ÚÄÄÄÄÄÄÄÄÄÄ¿
³ CARDS.IN ³           ³ CARDS.IN ³             ³ CARDS.IN ³
ÃÄÄÄÄÄÄÄÄÄÄ´           ÃÄÄÄÄÄÄÄÄÄÄ´             ÃÄÄÄÄÄÄÄÄÄÄ´
³ 2 2      ³           ³ 4 1      ³             ³ 3 2      ³
³ 2 1      ³           ³ 2 1      ³             ³ 3 2      ³
³ 1 2      ³           ³ 3 1      ³             ³ 2 2      ³
³ 1 1      ³           ³ 1 1      ³             ³ 1 1      ³
³ 2 2      ³           ³ 4 1      ³             ³ 3 1      ³
ÀÄÄÄÄÄÄÄÄÄÄÙ           ÀÄÄÄÄÄÄÄÄÄÄÙ             ³ 2 1      ³
ÚÄÄÄÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄÄÄÄÄ¿            ³ 1 2      ³
³ CARDS.OUT ³          ³ CARDS.OUT ³            ÀÄÄÄÄÄÄÄÄÄÄÙ
ÃÄÄÄÄÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄÄÄÄÄ´            ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ 2         ³          ³ 0         ³            ³ CARDS.OUT ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ          ÀÄÄÄÄÄÄÄÄÄÄÄÙ            ÃÄÄÄÄÄÄÄÄÄÄÄ´
                                                ³ 2         ³
                                                ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
