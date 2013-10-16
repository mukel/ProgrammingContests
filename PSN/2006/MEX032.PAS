{koder: A^2P}
{PSN 2006 #32 "Nule"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  factor : array[0..1] of word = (2,5);
  MaxN = 1000;
var
  fin,fout        : text;
  N,i,j,k,t,p,lvl : longint;
  buf             : array[0..4095] of byte;
  c               : array[0..1,0..1,0..MaxN] of word;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);
  settextbuf(fin,buf);

  {dread}
  readln(fin,N);

  {solve}{dp}
  fillchar(c,sizeof(c),$7f);
  c[lvl,0,1] := 0; c[lvl,1,1] := 0;
  for i:=1 to N do
  begin
    lvl := lvl xor 1; {i and 1;}
    fillchar(c[lvl],sizeof(c[lvl]),$7f);
    for j:=1 to N do
    begin
      read(fin,t);
      if t <> 0 then
        for k:=0 to 1 do
        begin
          p := 0;
          while t mod factor[k] = 0 do
          begin
            inc(p); t := t div factor[k];
          end;{while}
          c[lvl,k,j] :=
            min(c[lvl,k,j-1],c[lvl xor 1,k,j]) + p;
        end;{for}
    end;{for}
  end;{for}

  {dprint}
  writeln(fout,min(c[lvl,0,N],c[lvl,1,N]));

  {fclose}
  close(fin); close(fout);
end.{main}

{
32ş Nule                                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

A usted se le  da un tablero consistente  de cuadrados ordenados en  N
filas y N columnas, con cada cuadrado conteniendo un entero simple  no
negativo.

Al comienzo del juego, una  pieza esta situada en el  cuadradosuperior
izquierdo  (1,1)  y  esta tienen  que  alcanzar  el cuadrado  inferior
derecho (N,N) solamente moviendo un cuadrado hacia abajo o un cuadrado
a la derecha en cada paso. Ademas una pieza no puede ser ubicada en un
cuadrado que contenga al n£mero 0.

Nosotros definimos el costo del  camino como el producto de  todos los
n£meros en ese camino. Nosotros decimos que algun camino es optimo  si
el n£mero de zeros a;l final de esa representacion decimal es minima.

Escribir un programa  que calcule el  n£mero de ceros  al final de  la
representacion decimal de su costo del camino optimo.

Entrada

La primera l¡nea del fichero de  entrada NULE.IN contiene al entero N,
1  <= N <= 1000.  Cada una  de las  siguientes N  l¡neas contienen  N
n£meros. Estos n£meros representan el  tablero del problema. Todos los
n£meros seran enteros no negativos menores que o iguales a 1,000,000.
Note que habra siempre soluciones para cada datos de prueba.

Salida

La primera y unica l¡nea del fichero de salida NULE.OUT debe contener
el n£mero de ceros segun se explico en el enunciado del problema.

Ejemplos de entrada y salida

Ejemplo # 1          Ejemplo # 2        Ejemplo # 3
ÚÄÄÄÄÄÄÄÄÄÄ¿         ÚÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ NULE.IN  ³         ³ NUE.IN   ³       ³ NUE.IN     ³
ÃÄÄÄÄÄÄÄÄÄÄ´         ÃÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄ³
³ 3        ³         ³  3       ³       ³  4         ³
³ 1 2 3    ³         ³  5 7 6   ³       ³  1 3 0 0   ³
³ 4 5 6    ³         ³  4 0 1   ³       ³  0 8 2 25  ³
³ 7 8 9    ³         ³  3 2 5   ³       ³  6 5 0 3   ³
ÀÄÄÄÄÄÄÄÄÄÄÙ         ÀÄÄÄÄÄÄÄÄÄÄÙ       ³  0 15 7 4  ³
                                        ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄ¿         ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ NULE.OUT ³         ³  NULE.OUT ³      ³  NULE.OUT   ³
ÃÄÄÄÄÄÄÄÄÄÄ´         ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 0        ³         ³   1       ³      ³    2        ³
ÀÄÄÄÄÄÄÄÄÄÄÙ         ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}