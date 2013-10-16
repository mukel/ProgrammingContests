{koder: A^2P}{24 - 3 - 2007}
{PSN 2006 #128 "Big Mean"}
{ RMQ }
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
var
  fin,fout        : text;
  N,M,A,B,log,
  i,j,k,sol       : longint;
  len             : array[0..MaxN] of byte;
  num             : array[0..MaxN] of string[200];
  max             : array[0..MaxN,0..17] of longint;

    function bigger(i,j: longint): boolean;
    var k : byte;
    begin
      if len[i] = len[j] then
      begin
        for k:=1 to len[i] do
          if num[i,k] <> num[j,k] then
          begin
            bigger := (num[i,k] > num[j,k]);
            exit;
          end;{then}
      end{then ->}
      else bigger := (len[i] > len[j]);
    end;{bigger}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    readln(fin,num[i]);
    max[i,0] := i;
    len[i] := byte(num[i][0]);
  end;{for}

  {build}
  while 1 shl (log + 1) <= N do inc(log);
  for i:=1 to log do
    for j:=1 to N - (1 shl i) + 1 do
      if bigger(max[j,i - 1],max[j + (1 shl (i - 1)),i - 1])
        then max[j,i] := max[j,i - 1]
        else max[j,i] := max[j + (1 shl (i - 1)),i - 1];

  {solve}
  for i:=1 to M do
  begin
    readln(fin,A,B);

    {query}
    sol := 0;
    while B - A >= 0 do
    begin
      log := 0;
      while 1 shl (log + 1) < B - A do inc(log);
      if bigger(max[A,log],sol)
        then sol := max[A,log];
      A := A + (1 shl log);
    end;{while}

    {dprint}
    writeln(fout,num[sol]);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
128þ Big Mean.                                             M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En la  preselecci¢n todos  los estudiantes  quieren participar  en las
olimpiadas,  pero  no  todos  pueden,  a  partir  de  este  a¤o pueden
participar casi todos los estudiantes porque hay muchos eventos,  para
estos  eventos  los profesores  seleccionan  a los  estudiantes  de la
siguiente forma: entre  el estudiante K,K+1,K+2,...,Y  va a ir  el que
mayor promedio tenga entre todos ellos, el promedio de cada estudiante
es un n£mero que estar  entre 10^0 y 10^200.

Tarea.
Ayude a los profesores a determinar que estudiante ir  al evento X.

Entrada

En la primera l¡nea del  fichero de entrada BIG.IN habr n  dos n£meros
3<=N<=100000, 1<=M<=100000  que ser n  el n£mero  de estudiantes  y la
cantidad de eventos que hay  en esa asignatura respectivamente. En  la
l¡nea 2 y  hasta la N+1  habr  un n£mero  por l¡nea que  representa el
promedio del  i-‚simo estudiante.  En la  l¡nea N+2  y hasta  la l¡nea
N+M+1 habr n dos n£meros enteros 1<=K<=N y K<Y<=N.

Salida.

En el fichero de  salida BIG.OUT habr n M n£meros,  el i-‚simo  n£mero
representa el promedio del estudiante que va al i-‚simo evento.

Ejemplo de entrada. (BIG.IN)
4 3
1
9
5
10
1 2
1 3
2 4

Ejemplo de salida. (BIG.OUT)
9
9
10

NOTA:  No se  le permite  usar B£fer,  en caso  contrario su  programa
obtendr  0 puntos.
}
