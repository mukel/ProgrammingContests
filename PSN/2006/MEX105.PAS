{koder: A^2P}{11 - 3 - 2007}
{PSN 2006 #105 "P-‚sima potencia perfecta"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  EPSILON = 0.000000001;
var
  fin,fout        : text;
  N,sol           : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  readln(fin,N);
  repeat
    sol := 32;
    while frac(exp(ln(N) / sol)) > EPSILON do dec(sol);
    writeln(fout,sol);
    readln(fin,N);
  until N = 0;

  {fclose}
  close(fin); close(fout);
end.{main}

{
105ş P-‚sima potencia perfecta.                            M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se dice que  X es un  cuadrado perfecto si,  para alg£n entero  b, x =
b^2. Similarmente, X es un cubo perfecto si, para alg£n entero b, x  =
b^3. Generalizando, X es una p-‚sima potencia perfecta si, para  alg£n
entero b, x = b^p.

Dado un entero X, determine el valor m s grande de p tal que X sea una
p-‚sima potencia perfecta.

Entrada:
 Cada caso de prueba consistir  de varias l¡neas. Cada l¡nea contendr 
 un valor de X. El valor de X ser  al menos 2 y estar  en el rango de
 un entero de 32-bit. La £ltima l¡nea contendr  un 0.

Salida:
 Para cada l¡nea de entrada, genere una l¡nea de salida conteniendo el
 mayor entero p tal que X es una p-‚sima potencia perfecta.


Ejemplo de Entrada: (fichero power.in)
17
1073741824
25
0


Ejemplo de Salida: (fichero power.out)
1
30
2
}