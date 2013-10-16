{koder: A^2P}{12 - 3 - 2007}
{PSN 2004 #17 "Disminuir el consumo de energ¡a" (POWER) }
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  p,d             : array[0..MaxN] of longint;
  L,R             : array[0..MaxN,0..MaxN] of longint;

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
  readln(fin,N);
  readln(fin,M);
  for i:=1 to N do
  begin
    readln(fin,d[i],p[i]); inc(p[i],p[i-1]);
  end;{for}

  {solve}{dp}
  for i:=1 to N do
  begin
    L[i,i] := abs(d[M] - d[i]) * (p[N] - p[M] + p[M-1]);
    R[i,i] := L[i,i];
  end;{for}

  for k:=1 to N - 1 do
    for i:=1 to N - k do
    begin
      j := i + k;

      L[i,j] := min(
        L[i + 1,j] + (d[i+1] - d[i]) * (p[N] - p[j] + p[i]),
        R[i + 1,j] + (d[j] - d[i]) * (p[N] - p[j] + p[i]) );

      R[i,j] := min(
        L[i,j - 1] + (d[j] - d[i]) * (p[N] - p[j - 1] + p[i - 1]),
        R[i,j - 1] + (d[j] - d[j - 1]) * (p[N] - p[j - 1] + p[i - 1]) );

    end;{for}

  {dprint}
  writeln(fout,min(L[1,N],R[1,N]));

  {fclose}
  close(fin); close(fout);
end.{main}

{
17þ Disminuir el consumo de energ¡a.                       Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Ra£l consigui¢ un interesante y bien pagado trabajo. Todas las ma¤anas
‚l necesita apagar todas las l mparas callejeras en su pueblo. Todas
las l mparas se localizan en el mismo lado de un camino recto. Ra£l
est  en la fiesta todas las noches hasta las 5 AM y entonces ‚l
empieza a apagar las l mparas. Al principio, ‚l est  al lado de una de
ellas. Cada l mpara tiene una bombilla de un poder definido, y porque
Ra£l est  ecol¢gicamente consciente, ‚l quiere apagar todas las
l mparas para que se minimice la energ¡a total gastada. Ra£l se est 
moviendo a la velocidad de 1 m/s porque ‚l est  muy cansado. Apagando
una l mpara no toma tiempo extra porque ‚l puede hacerlo mientras va
pasando.

Tarea.

Escriba un programa para calcular la energ¡a m¡nima que necesita ser
gastada para apagar todas las l mparas para las situaciones dadas de
l mparas, los poderes de bombillas y la posici¢n inicial de Ra£l.

Fichero de entrada.

La primera l¡nea del fichero de entrada POWER.IN contiene el entero N,
2 <= N <= 1000, el n£mero de l mparas en el pueblo. La segunda l¡nea
contiene el entero V, 1 <= V <= N, n£mero de la l mpara en la que Ra£l
empez¢. Cada una de las N l¡neas siguientes contiene datos que
describen una l mpara, dos enteros D y W separados por un solo
espacio, 0 <= D <= 1000, 0 <= W <= 1000. D es la distancia de una
l mpara al principio del pueblo (expresada en metros), y W es el poder
de una bombilla en esa l mpara, es decir la cantidad de energ¡a
gastada por esa bombilla durante un segundo. Se dan las l mparas en
orden.

Fichero de salida.

La primera y £nica l¡nea del fichero de salida POWER.OUT debe contener
un entero - la cantidad m¡nima de energ¡a gastada.

Nota: la soluci¢n siempre ser  m s peque¤a que 1,000,000,000.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿         ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ POWER.IN#1 ³       ³ POWER.IN#2 ³         ³ POWER.IN#3 ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄ´         ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3          ³       ³ 4          ³         ³ 6          ³
³ 2          ³       ³ 3          ³         ³ 5          ³
³ 1 4        ³       ³ 2 2        ³         ³ 3 2        ³
³ 6 5        ³       ³ 5 8        ³         ³ 11 10      ³
³ 9 7        ³       ³ 6 1        ³         ³ 12 18      ³
³            ³       ³ 8 7        ³         ³ 13 19      ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ         ³ 15 15      ³
                                            ³ 17 19      ³
                                            ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ POWER.OUT#1 ³      ³ POWER.OUT#2 ³        ³ POWER.OUT#3 ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 65          ³      ³ 56          ³        ³ 370         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ        ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
