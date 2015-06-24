{koder: A^2P}{3 - 3 - 2007}
{PSN 2006 #15 "En busca de la chica perdida"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  PRIME = 30011;
var
  fin,fout        : text;
  N,A,B,i,sol     : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  A := N - 1; B := 1;
  for i:=2 to N do
  begin
    A := A * (i + N) mod PRIME;
    B := B * i mod PRIME;
  end;{for}
  while (sol * B) mod PRIME <> A
    do inc(sol);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
15þ En busca de la chica perdida.                          M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

D. quiere visitar a E. y tiene  que ir desde su casa hasta la  casa de
ella. La  ciudad es  una grilla  de NxN,  la casa  de D.  se encuentra
situada en la posici¢n (0,0) y la casa de E. en la posici¢n (N,N).  Si
D. se encuentra en  la posici¢n (x,y) de  la grilla, ‚l puede  moverse
para la (x+1,y) y para la (x,y+1).

Tarea

Determinar la cantidad de caminos (S) que existen desde la casa de D.
a casa de E. y que en alg£n momento la posici¢n de D. (x,y) cumple x >
y, y en otro momento cumple x < y.


Entrada

El fichero de entrada se llamar  LOST.IN, y consistir  de una £nica l¡nea
conteniendo el entero n (3 <= n <= 30000).

Salida

El fichero de salida se llamar  LOST.OUT, y consistir  de una £nica
l¡nea con un £nico entero m (representando el m¢dulo de la divisi¢n
S / 30011).

 ÚÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄ¿
 ³ LOST.IN ³   ³ LOST.OUT ³
 ÃÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄ´
 ³ 2       ³   ³ 2        ³
 ÀÄÄÄÄÄÄÄÄÄÙ   ÀÄÄÄÄÄÄÄÄÄÄÙ

Explicaci¢n del ejemplo

Todos los caminos posibles son :


   xÄÄÄxÄÄÄE          x   xÄÄÄE          x   x   E
   ³                      ³                      ³
   x   x   x          xÄÄÄx   x          xÄÄÄxÄÄÄx
   ³                  ³                  ³
   D   x   x          D   x   x          D   x   x
      (1)                (2)                (3)


   x   xÄÄÄE          x   x   E          x   x   E
       ³                      ³                  ³
   x   x   x          x   xÄÄÄx          x   x   x
       ³                  ³                      ³
   DÄÄÄx   x          DÄÄÄx   x          DÄÄÄxÄÄÄx
      (4)                (5)                (6)


La respuesta es 2. Ya que existen 2 caminos que satisfacen la
condici¢n, el camino (3) y el (4).

En los caminos (1) y (2) siempre se mantiene x <= y.
En los caminos (5) y (6) siempre se mantiene x >= y.
}