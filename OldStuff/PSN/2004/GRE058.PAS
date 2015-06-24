{koder: A^2P}{19 - 3 - 2007}
{PSN 2004 #58 "Rect ngulos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10001;
type
  point = record
    X,Y,target,value : longint;
  end;{rect}
var
  fin,fout        : text;
  pend            : real;
  X,Y,N,S,P,i,sol : longint;
  list            : array[0..MaxN * 2] of point;

    var p : longint; tmp : point;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h;
      p := list[(d + h) shr 1].target;
      repeat
        while list[i].target < p do inc(i);
        while list[j].target > p do dec(j);
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
  readln(fin,X,Y,N);
  for i:=1 to N do
  begin
    readln(fin,list[i].X,list[N + i].Y,
               list[N + i].X,list[i].Y);

    list[i].value := 1;
    list[N + i].value := -1;

    pend := list[i].Y / list[i].X;
    if pend > Y / X
      then list[i].target := trunc(Y / pend + 0.999999)
      else list[i].target := Y + X - trunc(X * pend);

    pend := list[N + i].Y / list[N + i].X;
    if pend > Y / X
      then list[N + i].target := trunc(Y / pend) + 1
      else list[N + i].target := Y + X - trunc(X * pend) + 1;

  end;{for}

  {solve}
  qsort(1,2 * N);
  i := 1;
  repeat
    repeat
      inc(S,list[i].value);
      inc(i);
    until list[i].target <> list[i + 1].target;
    inc(S,list[i].value);

    if S > sol then
    begin
      sol := S; P := list[i].target;
    end;{then}
    inc(i);
  until i > 2 * N;

  {dprint}
  write(fout,sol,' ');
  if P <= X
    then writeln(fout,P,' ',Y)
    else writeln(fout,X,' ',Y + X - P);

  {fclose}
  close(fin); close(fout);
end.{main}

{
58þ Rect ngulos.                                           Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se tienen N rect ngulos en un plano. Los lados de los rect ngulos son
paralelos a los ejes de coordenadas. Los rect ngulos pueden
superponerse, coincidiendo o estar dibujado dentro uno de los otros.
Los v‚rtices tienen coordenadas enteras no negativas y la coordenada X
no sobrepasa a Xmax y la coordenada Y no sobrepasa a Ymax.

Un segmento comienza en punto A(0, 0) y termina en un punto B. Las
  coordenadas del punto B (el otro extremo del segmento)
  satisface las siguientes condiciones:

- La coordenadas del punto B son n£meros enteros;
- El punto B pertenece al segmento [(0, Ymax), (Xmax, Ymax)] o al
  segmento [(Xmax, 0), (Xmax, Ymax)].

El segmento AB quiz s pueda cruzar  rect ngulos (nosotros asumimos el
cruzamiento tiene lugar si solamente un v‚rtice del rect ngulo esta
cruzado).

Tarea

Escriba un programa que encuentre un punto B para el cual el segmento
AB cruza la mayor cantidad de rect ngulos como sea posible.

Entrada (RECT.IN)

La primera l¡nea del fichero contiene 3 enteros Xmax, Ymax (0 < Xmax,
Ymax <= 10^9 ) y N (1 <= N <= 10000). Cada una de las siguientes N
l¡neas contiene 4 enteros: coordenadas de la esquina inferior
izquierda Xbl, Ybl y la coordenada de la esquina superior derecha Xtr,
Ytr. Estos n£meros estar n separados por un simple espacio.

Salida (RECT.OUT)

La primera £nica y l¡nea del fichero de salida debe contener 3 n£meros
enteros. El primer n£mero es el n£mero m ximo de rect ngulos cruzados
seguidos por X y Y, coordenadas del punto B. Estos n£meros estar n
separados por un simple espacio. Si hay varias soluciones, imprima
solo una de ellas.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄ¿
³ RECT.IN      ³  ³ RECT.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄ´
³ 22 14 8      ³  ³ 5 22 12  ³
³ 1 6 7 11     ³  ÀÄÄÄÄÄÄÄÄÄÄÙ
³ 18 10 20 12  ³
³ 17 1 19 7    ³  Otra posible soluci¢n: 5 22 11
³ 12 2 16 3    ³
³ 16 7 19 9    ³
³ 8 4 12 11    ³
³ 7 4 9 6      ³
³ 10 5 11 6    ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
