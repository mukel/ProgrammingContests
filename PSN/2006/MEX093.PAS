{koder: A^2P}
{PSN 2006 #93 "Enviar una tabla"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 50000;
var
  fin,fout        : text;
  N,i,j           : longint;
  prime           : array[0..MaxN] of boolean;
  euler,dp        : array[0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}{Erathostenes Sieve}
  fillchar(prime,sizeof(prime),true);
  for i:=1 to MaxN do euler[i] := i;
  for i:=2 to MaxN do
    if prime[i] then
    begin
      j := i;
      repeat
        euler[j] := euler[j] div i * (i-1);
        prime[j] := false;
        inc(j,i);
      until j > MaxN;
    end;{then}

  {dp}
  dp[1] := 1;
  for i:=2 to MaxN do
    dp[i] := dp[i-1] + 2 * euler[i];

  {dprint}
  readln(fin,N);
  repeat
    writeln(fout,dp[N]);
    readln(fin,N);
  until N = 0;

  {fclose}
  close(fin); close(fout);
end.{main}

{
93ş Enviar una tabla.                                      M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Al participar  en una  competencia de  programaci¢n, usted  a veces se
enfrenta al siguiente problema: usted sabe como calcular el  resultado
para los  valores dados  de entrada,  pero su  algoritmo es  demasiado
lento para  correr en  el tiempo  l¡mite. Sin  importar cuanto trates,
sencillamente no puedes descubrir las correctas condiciones de  parada
que bajar¡an el n£mero de iteraciones a l¡mites aceptables.

Pero, si el rango de los valores de entrada no es muy grande, hay  una
forma de hacerlo. Dejar a tu  PC calculando por media hora y  producir
una tabla de  respuestas para todos  los posibles valores  de entrada,
codificar esta tabla, entregar al  jurado, et voila: Aceptado en  0.00
segundos! (Algunos dir n que eso es trampa, pero recuerda: En el  amor
y las competencias de programaci¢n todo est  permitido).

Enfrentando este problema durante una competencia de programci¢n Jimmy
decide aplicar dicha `t‚cnica`. Pero sin importar cuan duro lo intent¢
el no  fue capaz  de esconder  todos sus  valores pre-calculados  a un
programa lo suficientemente peque¤o para pasar al jurado. La situaci¢n
luc¡a desesperada,  hasta que  descubri¢ la  siguiente propiedad,  sin
importar la respuesta:  las respuestas se  calculaban a partir  de dos
enteros, pero en el caso de que los dos valores de entrada tuvieran un
factor com£n, la respuesta se pod¡a calcular f cilmente a partir de la
respuesta  en la  cual los  valores de  entrada se  divid¡an por  ese
factor. En otras palabras:

Digamos que Jimmy tiene que calcular una funci¢n Answer(X,Y) donde X y
Y  son  ambos  enteros  en  el  rango  [1,  N].  Cuando  el  conoce ya
Answer(X,Y), ‚l  puede f cilmente  hallar Answer(k*X,k*Y),  donde k es
cualquier entero,  aplicando algunos  calculos simples  que implican a
Answer(X,Y) y  k. Por  ejemplo, si  N=4, el  solo necesita conocer las
respuesta de  11 del  total de  16 posibles  combinaciones de entrada:
Answer(1, 1), Answer(1, 2), Answer(2, 1), Answer(1, 3), Answer(2,  3),
Answer(3, 2), Answer(3, 1), Answer(1, 4), Answer(3, 4), Answer(4, 3) y
Answer(4, 1).

Las  otras  5  se  pueden hallar  a  partir  de  ellas (Answer(2,  2),
Answer(3, 3) y  Answer(4,4) a partir  de Answer(1, 1);  Answer(2, 4) a
partir de Answer(1, 2); y Answer(4, 2) a partir de Answer(2, 1)). Note
que la funci¢n Answer  no es sim‚trica, por  tanto Answer(3, 2) no  se
puede hallar a partir de Answer(2, 3).

Tarea

Para cualquier valor de N (1 <= N <= 50000) halla el n£mero  de
funciones qye Jimmy tiene que pre-calcular.


Entrada

El fichero de entrada contiene a lo sumo 600 l¡neas de entradas.  Cada
l¡nea contiene un entero menor que 50001 que indica el valor de N.  La
entrada termina con  una l¡nea conteniendo  un cero. Esta  l¡nea no se
debe procesar.

Salida

Para cada  l¡nea de  entrada genera  una l¡nea  de salida. Esta  l¡nea
contiene un  entero que  indica cuantos  valores Jimmy  tiene que  pre
-calcular para un cierto valor de N.


Ejemplo de Entrada: (fichero table.in)
2
5
0

Ejemplo de Salida (fichero table.out)
3
19
}