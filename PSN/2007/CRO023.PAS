{koder: A^2P}{26 - 2 - 2007}
{PSN 2007 #23 "Sumando N£meros"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,i,j,sol     : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N do
  begin
    readln(fin,M);
    sol := -1; j := 0;
    repeat
      inc(j); dec(M,j);
      if M mod j = 0 then inc(sol);
    until M <= 0;
    writeln(fout,sol);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
23þ Sumando N£meros                                      Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La FEEM de  la LENIN ha  decidido realizar una  Competencia de C lculo
para celebrar la Copa. Para ello se ha consultado a un matem tico.  El
matem tico nos cuenta que la  mayor¡a de los enteros positivos  puedes
ser escritos como  la suma de  una secuencia de  al menos dos  enteros
consecutivos. Por ejemplo:

6 = 1 + 2 + 3
9 = 5 + 4 = 2 + 3 + 4

Pero 8 no puede ser escrito de ese modo.

Problema

El problema consiste en determinar de cuantas maneras diferentes puede
ser escrito un n£mero dado, como la suma de una secuencia de al  menos
2 enteros consecutivos.

Entrada

Ejemplo (SUM.IN)
6
6
9
8
1800
31999
32000

Descripci¢n

L¡nea1:  Un entero  n que  representa la  cantidad de  n£meros a  ser
escritos como la suma  enteros consecutivos. Siguientes n  L¡neas: Los
n£meros a ser escritos como la suma de enteros consecutivos.


Salida

Ejemplo (SUM.OUT)
1
2
0
8
3
3

Descripci¢n

Debe contener  n l¡neas  cada una  con la  cantidad de  maneras en que
puede ser escrito el n£mero de entrada al que corresponde como la suma
de enteros consecutivos.

Consideraciones

- 1< N <= 1000
- Cada n£mero a analizar ser  menor que 2^31 (32-bit integer).
- Para el 50 % de los casos de prueba el n£mero a analizar sera menor
  que 32000.
}