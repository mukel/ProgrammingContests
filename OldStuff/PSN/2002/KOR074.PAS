{koder: A^2P}{11 - 3 - 2007}
{PSN 2002 #74 "Ordenamiento Tonto"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,i,j,k,lowest,
  swaps,cost      : longint;
  seq,pos         : array[0..MaxN] of longint;
  mark,
  take_lowest     : array[0..MaxN] of boolean;

    var p,tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := seq[(d + h) shr 1];
      repeat
        while seq[i] < p do inc(i);
        while seq[j] > p do dec(j);
        if i <= j then
        begin
          tmp := seq[i]; seq[i] := seq[j]; seq[j] := tmp;
          tmp := pos[i]; pos[i] := pos[j]; pos[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
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
    pos[i] := i;
    readln(fin,seq[i]);
  end;{for}

  {solve}
  qsort(1,N);

  {find d_sets}
  for i:=1 to N do
    if (not mark[i]) and (pos[i] <> i) then
    begin
      j := pos[i]; k := 1;
      repeat
        inc(k);
        mark[j] := true;
        inc(cost,seq[j]);
        j := pos[j];
      until j = i;

      if (k - 1) * seq[1] + 2 * (seq[i] + seq[1]) <
         (k - 1) * seq[i] then
      begin
        inc(swaps,k + 1);
        take_lowest[i] := true;
        cost := cost + (k - 1) * seq[1] + 2 * (seq[i] + seq[1]);
      end{then ->}
      else begin
        inc(swaps,k - 1);
        cost := cost + (k - 1) * seq[i];;
      end;{else}

    end;{then}

  {sort d_sets}
  writeln(fout,cost,' ',swaps);
  fillchar(mark,sizeof(mark),false);
  for i:=1 to N do
    if (not mark[i]) and (pos[i] <> i) then
    begin
      lowest := seq[i];
      if take_lowest[i] then
      begin
        lowest := seq[1];
        writeln(fout,lowest,' ',seq[i])
      end;{then}

      j := pos[i];
      repeat
        writeln(fout,lowest,' ',seq[j]);
        mark[j] := true;
        j := pos[j];
      until j = i;

      if take_lowest[i] then
        writeln(fout,seq[i],' ',lowest);
    end;{then}

  {fclose}
  close(fin); close(fout);
end.{main}

{
74ş Ordenamiento Tonto                                      Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Tu  hermano  m s  joven  tiene un encargo y  necesita alguna ayuda. Su
profesor  le  di¢    a ‚l una secuencia de n£meros diferentes para ser
ordenados en orden ascendente. Durante el proceso de ordenamiento, las
posiciones de dos n£meros  pueden ser intercambiadas. Cada intercambio
tiene un costo, el cual es la suma de los dos n£meros implicados.

Tarea

Tu tienes que escribir un programa que determine el costo m¡nimo C para
ordenar  la secuencia  de n£meros  y los n£meros a intercambiar en cada
paso.

Entrada

El fichero de entrada SILLY.IN contiene:
- l¡nea 1: Un entero simple N (1 < N <= 1000), representando el n£mero
           de elementos que ser n ordenados.
- l¡nea 2..N+1: contienen los n£meros a ser ordenados. Cada l¡nea
           contiene un solo n£mero (positivo y menor que 1000).

Salida

El fichero de salida SILLY.OUT contiene:
- l¡nea 1: dos enteros C y W separados por un espacio en blanco, los
           que  representan respectivamente el costo m¡nimo encontrado
           para realizar el ordenamiento y la cantidad de intercambios
           que fue necesario realizar.
- l¡nea 2.. W+1 : cada l¡nea contendr  dos n£meros enteros los que
           fueron  intercambiados  en  el  paso. Debe escribirse en el
           mismo orden en que aparecen en la lista en el momento de su
           intercambio.

Ejemplo de Entrada y Salida:

 ÚÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ SILLY.IN ³   ³ SYLLY.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 5        ³   ³ 41 5      ³
 ³ 1        ³   ³ 1 6       ³
 ³ 8        ³   ³ 9 1       ³
 ³ 9        ³   ³ 1 7       ³
 ³ 7        ³   ³ 8 1       ³
 ³ 6        ³   ³ 6 1       ³
 ÀÄÄÄÄÄÄÄÄÄÄÙ   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
