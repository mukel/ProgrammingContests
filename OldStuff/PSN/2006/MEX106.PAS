{koder: A^2P}{20 - 3 - 2006}
{PSN 2006 #106 "Reservaciones de Puestos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 50000;
type
  thing = record
    A,B,C : longint;
  end;{cow}
var
  fin,fout        : text;
  N,M,i,j,k,sol   : longint;
  list            : array[0..2 * MaxN] of thing;
  stall,free      : array[0..MaxN] of longint;

    var p,tmp : thing;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := list[(d + h) shr 1];
      repeat
        while (list[i].A < p.A) or
              ((list[i].A = p.A) and (list[i].B > p.B)) do inc(i);
        while (list[j].A > p.A) or
              ((list[j].A = p.A) and (list[j].B < p.B)) do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
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
  begin
    readln(fin,list[i].A,list[N + i].A);
    list[i].B := 1;
    list[i].C := i;

    list[N + i].B := -1;
    list[N + i].C := i;
  end;{for}

  {solve}
  qsort(1,2 * N);
  for i:=1 to 2 * N do
  begin
    if list[i].B = 1 then
    begin
      if M = 0 then
      begin
        inc(sol);
        stall[list[i].C] := sol;
      end{then ->}
      else begin
        stall[list[i].C] := free[M];
        dec(M);
      end;{else}
    end{then ->}
    else begin
      inc(M);
      free[M] := stall[list[i].C];
    end;{else}
  end;{for}

  {dprint}
  writeln(fout,sol);
  for i:=1 to N do writeln(fout,stall[i]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
106ş Reservaciones de Puestos.                             M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Oh esas  N (1  <= N  <= 50,000)  vacas quisquillosas!  Ellas son   tan
quisquillosas que cada una £nicamente ser  orde¤ada en alg£n intervalo
A..B (1 <=  A <= B  <= 1,000,000) preciso  de tiempo, el  cual incluye
ambos  extremos  A  y  B. Obviamente,  GJ  debe  crear  un sistema  de
reservaciones para  determinar a  cual puesto  debe ser  asignada cada
vaca para su  orde¤amiento. Por supuesto,  ninguna vaca compartir   un
momento tan privado con ninguna otra vaca.

Ayude a GJ determinando:
- El m¡nimo n£mero de puestos requeridos en el establo de tal manera
  que cada vaca tenga su periodo privado de orde¤amiento
- Una asignaci¢n de vacas a los puestos en el tiempo

Son correctas muchas respuestas para cada conjunto de datos de
entrada; un programa calificar  su respuesta.

NOMBRE DEL PROBLEMA: reserve

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero, N

- L¡neas 2..N+1: La l¡nea i+1 describe el intervalo de orde¤o de la
  vaca i con dos enteros separados por espacio.

ENTRADA EJEMPLO (archivo RESERVE.IN):

5
1 10
2 4
3 6
5 8
4 7

FORMATO DE SALIDA:

- L¡nea 1: El m¡nimo n£mero de puestos que el establo debe tener.

- L¡neas 2..N+1: La l¡nea i+1 describe el puesto al cual la vaca i
  debe ser asignada para su periodo de orde¤amiento.

SALIDA EJEMPLO (archivo RESERVE.OUT):

4
1
2
3
2
4

DETALLES DE LA SALIDA:

Aqu¡ hay un horario gr fico para esta salida:

Tiempo   1  2  3  4  5  6  7  8  9 10
Puesto 1 c1>>>>>>>>>>>>>>>>>>>>>>>>>>>
Puesto 2 .. c2>>>>>> c4>>>>>>>>> .. ..
Puesto 3 .. .. c3>>>>>>>>> .. .. .. ..
Puesto 4 .. .. .. c5>>>>>>>>> .. .. ..

Son posibles otras salidas usando el mismo n£mero de puestos.
}
