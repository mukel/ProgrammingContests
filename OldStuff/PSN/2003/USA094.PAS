{koder: A^2P}{3 - 3 - 2007}
{PSN 2003 #94 "Cercado barato"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,i,j,k,h,sol   : longint;
  x,y             : array[0..MaxN] of real;
  list,p          : array[0..MaxN] of byte;
  mark            : array[0..MaxN] of boolean;

    function cross(o,c,m: byte): real;
    begin
      cross := (x[c] - x[o]) * (y[m] - y[o]) -
               (x[m] - x[o]) * (y[c] - y[o]);
    end;{cross}

    function dist(i,j: byte): real;
    begin
      dist := sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
    end;{dist}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    read(fin,p[i]);
    readln(fin,x[p[i]],y[p[i]]);
  end;{for}

  {solve}{convex-hull.jarvis-march}
  j := 1;
  for i:=2 to N do
    if (x[i] < x[j]) or ((x[i] = x[j]) and (y[i] < y[j]))
      then j := i;

  k := j;
  repeat
    h := byte(j = 1) + 1;
    for i:=1 to N do if not mark[i] then
      if (cross(k,h,i) < 0) or
         ((cross(k,h,i) = 0) and (dist(k,i) < dist(k,h)))
         then h := i;
    mark[h] := true;
    inc(sol); list[sol] := h;
    k := h;
  until k = j;

  for i:=N downto 1 do
  begin
    for j:=1 to sol do
      if p[i] = list[j] then break;
    if p[i] = list[j] then break;
  end;{for}

  {dprint}
  writeln(fout,sol);
  for i:=0 to sol - 1 do
    if j + i = sol
      then write(fout,list[sol],' ')
      else write(fout,list[(j + i) mod sol],' ');

  {fclose}
  close(fin); close(fout);
end.{main}

{
94þ Cercado barato.                                           USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un granjero ha decidido rodear su jard¡n con una cerca para proteger
sus frutas del apetito de sus vecinos. Este hombre no tiene mucho
dinero, pero ‚l es una persona muy innovadora. El ha encontrado la
posibilidad de reducir costos usando  rboles de su propiedad como
postes de la cerca. El encontr¢ que para m ximimar el  rea a
ser encerrada por la cerca, los  rboles usados como postes de cerca
tienen que ser seleccionados cuidadosamente e vitando la creaci¢n
de  ngulos hacia adentro en la cerca. Tambi‚n, la selecci¢n de los
 rboles de poste deben ganantizar que la cerca encierre todos los
 rboles que est n en la propiedad.

Tarea

Dado un juego de  rboles (cada  rbol es identificado por un £nico
identificador del  rbol) y la posici¢n de cada  rbol en la propiedad,
escriba un programa que obtenga las siguientes informaciones:

a) El n£mero m¡nimo de  rboles exigido para encerrar todos los  rboles
   en la propiedad
b) La secuencia  de  rboles que deben usarse como postes del  rbol.

Entrada

La primera l¡nea del archivo de la entrada FENCE.IN contiene un valor
entero N representando el n£mero de  rboles disponible en el
jard¡n, 1 < N < 100. Las N siguientes l¡neas contienen tres valores que
representan la identificaci¢n del  rbol (n£mero entero) y la posici¢n
del  rbol (coordenadas X, Y; 1 <= X, Y <= 100) en el jard¡n (las
coordenadas son n£meros reales con un lugar decimal).

Salida

La primera l¡nea del archivo FENCE.OUT, muestra el n£mero de  rboles
que deben usarse como postes de la cerca. Las pr¢ximas l¡neas muestran
la secuencia  de identificadores del  rbol que se usar  como postes
de la cerca.

Ejemplo

La pr¢xima matriz representa la posici¢n de 11  rboles en una
propiedad. Una celda con un n£mero indica que el  rbol cuyo
identificador es el n£mero en la celda se localiza en la posici¢n  X,
Y del jard¡n. Por ejemplo,  rbol 11 est  en la posici¢n (0, 3). En
este ejemplo, El n£mero de postes del cerco requerido ser  6 y la
sucesi¢n de identificadores del  rbol que ser  parte de los postes del
cerco es 11, 6, 4, 10, 9 y 8.

                    ÚÄÄÄÂÄÄÄÄÂÄÄÄÄÂÄÄÄÄÂÄÄÄÄÂÄÄÄÄ¿
                    ³   ³  0 ³  1 ³  2 ³  3 ³  4 ³
                    ÃÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄ´
                    ³ 0 ³    ³    ³    ³ 11 ³    ³
                    ÃÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄ´
                    ³ 1 ³  8 ³    ³  7 ³    ³    ³
                    ÃÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄ´
                    ³ 2 ³    ³    ³  1 ³    ³    ³
                    ÃÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄ´
                    ³ 3 ³  9 ³  2 ³    ³    ³  6 ³
                    ÃÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄ´
                    ³ 4 ³    ³    ³    ³  5 ³    ³
                    ÃÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄ´
                    ³ 5 ³    ³    ³  3 ³  4 ³    ³
                    ÃÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄÅÄÄÄÄ´
                    ³ 6 ³ 10 ³    ³    ³    ³    ³
                    ÀÄÄÄÁÄÄÄÄÁÄÄÄÄÁÄÄÄÄÁÄÄÄÄÁÄÄÄÄÙ

Nota sugerida:

El primer  rbol de la sucesi¢n de la salida siempre es el £ltimo  rbol
para cual una posici¢n se mantuvo en el archivo de la entrada.  La
sucuencia en el archivo de salida debe imprimirse en en el sentido de
las agujas del reloj en ese orden.

Ejemplos de entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ FENCE.IN ³ ³ FENCE.OUT     ³  ³ FENCE.IN    ³ ³ FENCE.OUT  ³
ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 11       ³ ³ 6             ³  ³ 9           ³ ³ 5          ³
³ 1 2 2    ³ ³ 11 6 4 10 9 8 ³  ³ 1 7.1 1.1   ³ ³ 9 2 8 5 4  ³
³ 2 1 3    ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ  ³ 2 2.1 2.1   ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 3 2 5    ³                    ³ 3 9.1 -1.1  ³
³ 4 3 5    ³                    ³ 4 9.1 2.1   ³
³ 5 3 4    ³                    ³ 5 10.1 -1.1 ³
³ 6 4 3    ³                    ³ 6 7.1 0.0   ³
³ 7 2 1    ³                    ³ 7 5.1 2.1   ³
³ 8 0 1    ³                    ³ 8 4.1 -2.1  ³
³ 9 0 3    ³                    ³ 9 4.1 3.1   ³
³ 10 0 6   ³                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 11 3 0   ³
ÀÄÄÄÄÄÄÄÄÄÄÙ
}
