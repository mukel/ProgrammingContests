{koder: A^2P}
{PSN 2003 #38 "Liga de Baseball"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 200;
var
  fin,fout        : text;
  N,i,j           : byte;
  c               : array[1..MaxN,1..MaxN] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}{tennis tournament}
  for i:=1 to N do
    for j:=1 to N do
    begin
      c[i,j] := (j + N - i) mod N;
      if c[i,j] = 0 then c[i,j] := N;
      if c[i,j] = i then c[i,j] := 0;
    end;{then}

  {dprint}
  for i:=1 to N do
  begin
    for j:=1 to N do write(fout,c[i,j],' ');
    writeln(fout);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
38ş Liga de Baseball.                                         USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una  de  las  tareas del Ministerio de Deportes de nuestro pa¡s piensa
organizar  un campeonato de baseball con N equipos (numerados del 1 al
N).  El campeonato tiene que consistir de no m s de N d¡as de juegos y
cada  equipo  tiene que jugar contra cada uno de los otros exactamente
una  vez.  Escriba  un  programa  que  produzca  un calendario para el
campeonato.

Entrada

El  fichero  de  entrada  BEISBOL.IN  contendr  el n£mero N (1 <= N <=
200) de equipos que participar n en el torneo.

Salida

El  fichero de salida BEISBOL.OUT consiste de una tabla de enteros con
N  filas. El j-‚simo entero en la i-‚sima fila es el n£mero del equipo
contra  el cual juega el equipo i en el j-‚simo d¡a de competencia. Si
el  equipo  i  no juega en el j-‚simo d¡a entonces se colocara un cero
en ese lugar.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ BEISBOL.IN ³ ³ BEISBOL.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5          ³ ³ 2 5 4 3 0   ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ ³ 1 3 5 0 4   ³
               ³ 4 2 0 1 5   ³
               ³ 3 0 1 5 2   ³
               ³ 0 1 2 4 3   ³
               ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}