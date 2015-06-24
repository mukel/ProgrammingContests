{koder: A^2P}{5 - 3 - 2007}
{PSN 2006 #107 "Chocolates  para las vacas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 2000;
var
  fin,fout        : text;
  N,i,j,sol       : longint;
  v               : array[-1..MaxN] of word;
  c               : array[-1..MaxN,-1..MaxN] of longint;

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,v[i]);

  {solve}{dp}
  for i:=0 to N do
    for j:=0 to N-i do
    begin
      c[i,j] := max( c[i - 1,j] + v[i] * (i + j),
                     c[i,j - 1] + v[N - j + 1] * (i + j) );
      if c[i,j] > sol then sol := c[i,j];
    end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
107ş Chocolates  para las vacas.                           M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

GJ ha comprando N (1 <=  N <= 2000) chocolates para vend‚rselos  a las
vacas que  obtienen dinero  por dar  grandes cantidades  de leche.  GJ
vende un chocolate por d¡a y quiere maximizar el dinero que ‚l  recibe
sobre un periodo dado de tiempo.

Los chocolates son interesantes por varias razones:

- Los chocolates est n numerados 1..N y est n almacenados
  secuencialmente en un un solo archivo en una caja larga que est 
  abierta en ambos lados. En cualquier d¡a, GJ puede obtener un
  chocolate por cualquier lado de su alijo de regalos.
- Como los vinos finos y los quesos deliciosos, los chocolates se
  mejoran con los a¤os y aumentan de precio.
- Los chocolates no son uniformes: algunos son mejores y tienen un
  valor intr¡nseco m s alto. El chocolate i tiene valor (1 <= v(i) <=
  1000).
- Las vacas pagan m s por chocolates que est‚n m s a¤ejados: una vaca
  pagar v(i)*a por un regalo de edad a.

Dados los  valores v(i)  de cada  uno de  los chocolates  al¡neados en
orden del ¡ndice i en su caja,  Cu l  es el mayor valor que GJ  puede
recibir por ellos si ‚l ordena ¢ptimamente su venta?

El primer chocolate es vendido en el d¡a 1 y tiene edad a=1. Cada d¡a
subsecuente aumenta la edad en 1.

NOMBRE DEL PROBLEMA: trt

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero, N
- L¡neas 2..N+1: La l¡nea i+1 contiene el valor del chocolate v(i)

ENTRADA EJEMPLO (archivo TRT.IN):

5
1
3
1
5
2

DETALLES DE LA ENTRADA:

Cinco chocolates. En el primer d¡a GJ puede vender o el chocolate #1
(valor 1) o el chocolate #5 (valor 2).

FORMATO DE SALIDA:

- L¡nea 1: La ganancia m xima que GJ puede conseguir vendiendo los
  chocolates

SALIDA EJEMPLO (archivo TRT.OUT):

43

DETALLES DE LA SALIDA:

GJ vende los chocolates (valores 1, 3, 1, 5, 2) en el siguiente orden
de ¡ndices 1, 5, 2, 3, 4, obteniendo 1x1 + 2x2 + 3x3 + 4x1 + 5x5 = 43.
}