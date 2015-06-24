{koder: A^2P}
{PSN 2006 #102 "Freckles"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  oo = 1 shl 32;
var
  fin,fout        : text;
  sol             : real;
  N,i,j,k         : byte;
  d,x,y           : array[0..MaxN] of real;
  mark            : array[0..MaxN] of boolean;
  dist            : array[0..MaxN,0..MaxN] of real;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,x[i],y[i]);
    for j:=1 to i-1 do
    begin
      dist[i,j] := sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
      dist[j,i] := dist[i,j];
    end;{for}
  end;{for}

  {solve}{mst(euclidean).prim}
   d[0] := oo; mark[1] := true;
  for i:=2 to N do d[i] := dist[1,i];
  for i:=1 to N-1 do
  begin
    k := 0;
    for j:=2 to N do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    mark[k] := true;
    sol := sol + sqrt(d[k]);
    for j:=2 to N do
      if (not mark[j]) and (dist[j,k] < d[j])
        then d[j] := dist[j,k];
  end;{for}

  {dprint}
  writeln(fout,sol:0:2);

  {fclose}
  close(fin); close(fout);
end.{main}

{
102þ Freckles.                                             M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En el episodio : El show de Dick Van Dyke, el peque¤o Richie uni¢  las
pecas en la espalda de su padre formando la Estatua de la Libertad.  A
las, una de las pecas desapareci¢ dejando una cicatriz, as¡ el  dibujo
de Richie quedo sin forma alguna.

Considerando la espalda  de Dick (padre  de Richie) como  un plano con
pecas en varias localizaciones (x, y).  Su tarea es ayudar a Richie  a
conectar todos  los puntos  de forma  que se  minimize la  suma de las
longitudes de las conexiones usadas.

Entrada

La primera l¡nea del fichero PECAS.IN  contiene un entero N, 0 <  N <=
100, el n£mero  de pecas en  la espalda de  Dick. Para cada  peca, una
l¡nea, cada una contiene dos reales (x, y) indicando la coordenada  de
la peca.

Salida

Su programa deber  imprimir hacia el fichero PECAS.OUT un n£mero  real
con dos lugares decimales indicando: la menor longitud que se requiere
para conectar todas las pecas.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ PECAS.IN ³       ³ PECAS.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 3        ³       ³ 3.41      ³
³ 1.0 1.0  ³       ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 2.0 2.0  ³
³ 2.0 4.0  ³
ÀÄÄÄÄÄÄÄÄÄÄÙ
}