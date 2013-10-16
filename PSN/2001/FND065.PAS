{koder: A^2P}{8 - 7 - 2007}
{PSN 2001 #65 "Entregando Regalos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1102; { N + M + source + sink }
  source = MaxN - 1;
  sink = MaxN;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,M,i,j,k,h,
  a,b,sol         : longint;
  size            : array[0..1] of longint;
  last,len,f      : array[0..MaxN] of longint;
  queue           : array[0..1,0..MaxN] of longint;
  list,cap,flow   : array[0..MaxN,0..MaxN] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
  begin
    read(fin,j); inc(j,N);
    inc(cap[source,j]);
    inc(len[source]); list[source,len[source]] := j;
  end;{for}
  for i:=1 to N do
  begin
    readln(fin); read(fin,j);
    for j:=1 to j do
    begin
      read(fin,k); inc(k,N);
      inc(len[k]); list[k,len[k]] := i;
      inc(len[i]); list[i,len[i]] := k;
      cap[k,i] := oo;
    end;{for}
    inc(len[i]); list[i,len[i]] := sink;
    cap[i,sink] := 1;
  end;{for}

  {solve}
  repeat
    a := 1; b := 0;
    size[a] := 1; queue[a,size[a]] := source;
    fillchar(f,sizeof(f),0);
    fillchar(last,sizeof(last),0);
    f[source] := oo;

    repeat
      a := a xor 1; b := b xor 1;
      size[a] := 0;

      for i:=1 to size[b] do
        for j:=1 to len[queue[b,i]] do
          if last[list[queue[b,i],j]] = 0 then
          begin
            k := queue[b,i];
            h := list[k,j];

            if cap[k,h] > flow[k,h] then
            begin
              f[h] := min(f[k],cap[k,h] - flow[k,h]);
              last[h] := k;
            end;{then}

            if flow[h,k] > 0 then
            begin
              f[h] := min(f[k],flow[h,k]);
             last[h] := -k;
            end;{then}

            if last[h] <> 0 then
            begin
              inc(size[a]);
              queue[a,size[a]] := h;
            end;{then}

          end;{then}
    until (last[sink] <> 0) or (size[a] = 0);

    {fix}
    i := sink;
    inc(sol,f[sink]);
    if f[sink] <> 0 then
      repeat
        if last[i] > 0
          then inc(flow[last[i],i],f[sink])
          else dec(flow[i,-last[i]],f[sink]);
        i := abs(last[i]);
      until i = source;

  until f[sink] = 0;

  {dprint}
  writeln(fout,sol);
  for i:=1 to N do
    for j:=1 to 1000 do
      if flow[j + N,i] > 0 then
      begin
        writeln(fout,i,' ',j);
        break;
      end;{then}

  {fclose}
  close(fin); close(fout);
end.{main}

{
65ş Entregando Regalos.                                 Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  profesor  gu¡a  para  un d¡a de fiesta a comprado regalos para los
estudiantes  de  su  grupo  y  ahora est  tratando de elegir el regalo
perfecto  para  cada  alumno.  Cada alumno le ha dado a ‚l su lista de
regalos  deseados.  Cada  alumno  recibir   exactamente  un regalo. Un
alumno  es  complacido  por  su  regalo si este aparece en su lista de
deseo.

Su  tarea  es  determinar  el  mayor  n£mero de alumnos que pueden ser
complacidos dado un ciento conjunto de regalos para entregar. La lista
de  regalos  puede  tener un regalo m s de una vez si m s de un regalo
del mimso tipo fue compraado.

En  este  problema,  cada  regalo estar  designado por un entero en el
rango de 1..1000.

Formato de Entrada

El fichero de entrada REGALO.IN tiene el siguiente formato:

L¡nea 1: dos enteros: C (1 <= C <= 100, el n£mero de alumnos que optan
                      por  regalos) y  G (C <= G <=  1000,  el  n£mero
                      de regalos que ser n entregados).

L¡nea 2: G enteros   separdos   por un  espacio simple denotando a los
				 regalos que ser n entregados.

L¡nea 3..C+2: C  l¡neas  especificando  los  regalos  que  quieren los
							alumnos, cada l¡nea se parecer  a esto:
              N W0 W1 W2 ... WN, (donde  1 <= n <= G)
              donde  N  es  el  n£mero   de  regalos  que  cada alumno
              quiere y  W0,    W1   ...  ect.  son   los   n£meros  de
              los   regalos.  La   primera  l¡nea   de   este   bloque
              corresponde a lo que quiere el alumno 1, la segunda l¡nea
              al alumno  2,  as¡ sucesivamente.

Formato de Salida

El  fichero  de  salida  REGALO.OUT  contiene  en  la primera l¡nea el
n£mero  V  de  alumnos  que  pueden ser complacidos. En las pr¢ximas V
l¡neas  aparecr n  cada  una  con dos  enteros especificando el n£mero
del alumno y el regalo con el cual fue complacido.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ REGALO.IN 				 ³ ³	REGALO.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 5 							 ³ ³	4 				 ³
³ 35 35 483 622 801  ³ ³	1 35			 ³
³ 1 35							 ³ ³	2 35			 ³
³ 1 35							 ³ ³	4 622 		 ³
³ 1 35							 ³ ³	5 801 		 ³
³ 3 483 622 801 		 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 3 35 801 483			 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Nota: una posible soluci¢n ser¡a esta, aunque pueden existir otras
			m s:
}
