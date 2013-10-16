{koder: A^2P}
{PSN 2001 #54 "El Cuadrado Máximo"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 60;
var
  fin,fout        : text;
  N,i,j,k,h,sol   : integer;
  s               : array[0..MaxN,0..MaxN] of integer;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    for j:=1 to N do
    begin
      read(fin,k);
      s[i,j] := s[i-1,j] + s[i,j-1] - s[i-1,j-1] + k;
    end;{for}

  {solve}
  sol := -MaxInt;
  for i:=1 to N do
    for j:=i to N do
      for k:=i to N do
      begin
        h := s[j,k] - s[j-i,k] - s[j,k-i] + s[j-i,k-i];
        if h > sol then sol := h;
      end;{then}

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
54ş El Cuadrado M ximo.                                 Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una tabla de cuadrados con dimensiones  NxN (3 <= N <= 60)  es ocupada
con  n£meros  enteros, cada  uno  de  los  cuales se  encuentra en  el
intervalo  [-9, 9]. Cada  parte  de  la  tabla  formada  con  K  filas
consecutivas  y  K  columnas consecutivas, 1 <= K <= N, la denominamos
cuadrado. La  suma  de  todos  los  n£meros  dentro  del  cuadrado  la
denominamos suma del cuadrado.

Tarea

Crear un programa, el cual calcule  la  mayor  suma  de  un   cuadrado
dentro de la tabla de cuadrados dada como entrada.

Entrada

La entrada de  debe  leer del archivo de texto  SQR.INP. En la primera
fila de este archivo se sit£a el tama¤o N de la tabla. Cada una de las
siguientes  N filas contienen los N n£meros enteros de las filas de la
tabla separados por un espacio.

Salida

La salida del programa se escribir  en un archivo de texto SQR.OUT, en
la £nica fila de este, el resultado final, o sea la suma m xima de  un
cuadrado.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo de Entrada³ ³Ejemplo de Salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 4                ³ ³ 20              ³
³ 2 -8 4 -6        ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 7 1 -5 3         ³
³ -9 7 6 5         ³
³ 8 3 2 -4         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}