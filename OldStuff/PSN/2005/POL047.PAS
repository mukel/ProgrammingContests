{koder: A^2P}{13 - 5 - 2007}
{PSN 2005 #47 "Bovinas Ombrof¢bicas"}
{
  God needs 7 days,
  I do this in 1 hour...
}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 402;
  oo = sqr(MaxLongint);
var
  fin,fout        : text;
  limit           : qword;
  N,M,S,i,j,k,
  d,h,mid,tt,
  a,b,cows,total,
  source,sink     : longint;
  size            : array[0..1] of longint;
  f,last,v        : array[0..MaxN] of longint;
  list            : array[0..sqr(MaxN)] of qword;
  queue           : array[0..1,0..MaxN] of longint;
  cap,flow,flt    : array[0..MaxN,0..MaxN] of word;
  C               : array[0..MaxN,0..MaxN] of qword;

    var p,tmp : qword;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := list[(d + h) shr 1];
      repeat
        while list[i] < p do inc(i);
        while list[j] > p do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

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
  source := 2 * N + 2;
  sink := 2 * N + 1;
  for i:=1 to N do
  begin
    readln(fin,cap[source,i],cap[N + i,sink]);
    inc(cows,cap[source,i]);
  end;{for}

  for i:=1 to N do
    for j:=1 to N do C[i,j] := oo;
  for i:=1 to N do C[i,i] := 0;
  for i:=1 to N do
    for j:=N + 1 to 2 * N do cap[i,j] := cows;

  for i:=1 to M do
  begin
    readln(fin,j,k,h);
    if h < C[j,k] then
    begin
      C[j,k] := h; C[k,j] := h;
    end;{then}
  end;{for}

  {init}
  for i:=1 to 2 * N do
    v[i] := i mod (N + 1) + byte(i > N);

  {floyd}
  for k:=1 to N do
    for i:=1 to N do if C[i,k] <> oo then
      for j:=1 to N do
        if C[i,k] + C[k,j] < C[i,j]
        then C[i,j] := C[i,k] + C[k,j];

  {build list}
  for i:=1 to N do
    for j:=i + 1 to N do
    begin
      inc(S); list[S] := C[i,j];
    end;{for}

  {remove duplicated paths}
  qsort(1,S);
  i := 1; j := 0;
  while list[S] = oo do dec(S);
  repeat
    inc(j); list[j] := list[i];
    while (i < S) and (list[i] = list[i + 1])
      do inc(i);
    inc(i);
  until i > S;

  {solve}
  S := j; list[S + 1] := oo - 1;
  d := 0; h := S + 1;
  repeat
    mid := (d + h) shr 1;
    limit := list[mid];

    tt := total;
    flt := flow;

    {Max-Flow}
    repeat
      a := 1; b := 0;
      size[a] := 1; queue[a,size[a]] := source;
      fillchar(f,sizeof(f),0);
      fillchar(last,sizeof(last),0);
      f[source] := cows;

      {BFS}
      repeat
        a := a xor 1; b := b xor 1;
        size[a] := 0;
        for i:=1 to size[b] do
        begin
          k := queue[b,i];
          if k > N then j := 1 else j := N + 1;
          for j:=j to 2 * N + 1 do
            if last[j] = 0 then
            begin

              if C[v[k],v[j]] > limit then continue;

              if cap[k,j] > flow[k,j] then
              begin
                f[j] := min(f[k],cap[k,j] - flow[k,j]);
                last[j] := k;
              end;{then}

              if flow[j,k] > 0 then
              begin
                f[j] := min(f[k],flow[j,k]);
                last[j] := -k;
              end;{then}

              if last[j] <> 0 then
              begin
                inc(size[a]);
                queue[a,size[a]] := j;
                if j = sink then break;
              end;{then}

            end;{then}

            if last[sink] <> 0 then break;

        end;{for}

      until (last[sink] <> 0) or (size[a] = 0);

      {fix}
      i := sink;
      inc(total,f[sink]);
      if f[sink] <> 0 then
        repeat
          if last[i] > 0
            then inc(flow[last[i],i],f[sink])
            else dec(flow[i,-last[i]],f[sink]);
          i := abs(last[i]);
        until i = source;

    until f[sink] = 0;

    if total = cows then
    begin
      h := mid;
      flow := flt; total := tt;
    end{then}
    else d := mid + 1;

  until d = h;

  {dprint}
  if list[h] <> oo - 1 then writeln(fout,list[h])
    else writeln(fout,-1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
47ş Bovinas Ombrof¢bicas.                                 Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las  vacas  de  GJ  detestan  realmente  mojarse  tanto  que  el  solo
pensamiento de  quedarse bajo  la lluvia  les hace  temblar sus ubres.
Ellas han decidido  poner una sirena  de lluvia en  la granja que  les
permita saber si se est  acercando una lluvia. Ellas intentan crear un
plan  de  evacuaci¢n de  lluvia  de tal  manera  que todas  las  vacas
consigan  refugio  antes  que la  lluvia  comience.  Sin embargo,  las
predicciones de clima  no son siempre  correctas. Con el  prop¢sito de
minimizar falsas alarmas, ellas quieren que la alarma suene tan  tarde
como sea posible  pero d ndoles suficiente  tiempo para que  las vacas
lleguen a alg£n refugio.

La granja  tiene F  (1 <=  F <=  200) campos  en los  cuales las vacas
pastan. Un conjunto  de P (1  <= P <=  1500) caminos las  conecta. Los
caminos son anchos, de tal manera que cualquier n£mero de vacas  puede
recorrer un camino en cualquier direcci¢n.

Algunos de los  campos de la  granja tienen refugios  para lluvia bajo
los cuales las vacas pueden  protegerse. Estos refugios son de  tama¤o
limitado, por lo tanto un solo refugio puede no ser capaz de  albergar
todas las vacas. Los campos son peque¤os comparados con los caminos  y
las vacas no requieren ning£n tiempo para atravesarlos.

Calcule la cantidad m¡nima de  tiempo antes de que la  lluvia comience
en  el que  la sirena  debe sonar  de tal  forma que  cada vaca  pueda
conseguir albergue en alg£n refugio.

NOMBRE DE PROBLEMA: ombro

- L¡nea 1: Dos enteros separados por espacio: F y P

- L¡neas 2..F+1:  Dos enteros separados  por espacio que  describen un
  campo. El primer  entero (rango: 0..1000)  es el n£mero  de vacas en
  ese campo. El segundo entero (rango: 0..1000) es el n£mero de  vacas
  que el refugio en ese campo puede albergar. La l¡nea i+1 describe al
  campo i.

- L¡neas F+2..F+P+1: Tres enteros separados por espacio que  describen
  un camino.   El primer   y el   segundo entero   (ambos en  el rango
  1..F) dicen que  campos est n  conectados por  el camino.  El tercer
  entero (rango:  1..1.000.000.000) es  cuanto se  demora una  vaca en
  recorrerlo.

ENTRADA EJEMPLO (archivo ombro.in):

3 4
7 2
0 4
2 6
1 2 40
3 2 70
2 3 90
1 3 120

FORMATO DE SALIDA:

- L¡nea 1: La cantidad m¡nima de tiempo requerida  para  que todas las
  vacas lleguen a un refugio,  asumiendo que ellas  planeen sus  rutas
  ¢ptimamente. Si  no es  posible  que  todas las  vacas lleguen  a un
  refugio, d‚ como salida "-1".

SALIDA EJEMPLO (archivo ombro.out)

110

DETALLES DE LA SALIDA:

En 110 unidades de tiempo, dos vacas del campo 1 pueden albergarse  en
el refugio en ese campo, cuatro vacas del campo 1 pueden albergarse en
el refugio del campo 2, y la vaca restante del campo 1 puede llegar al
campo  3 y  unirse a  las vacas  en ese  campo para  albergarse en  el
refugio del  campo 3.  A pesar  de haber  otros planes  que pondr¡an a
todas las vacas bajo un refugio, ninguno de ellos lo har  en menos  de
110 unidades de tiempo.
}