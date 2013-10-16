{koder: A^2P}
{PSN 2005 #13 "Trabajando con primos"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,i,j,k       : longint;

    procedure print(a,b,c: longint);
    begin
      writeln(fout,a); writeln(fout,b); writeln(fout,c);
      writeln(fout);
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N);

  {solve}
  M := N; j := 2;
  repeat
    if M mod j = 0 then
    begin
      print(j,N,1); k := N div j * j;
      repeat
        repeat dec(k,j) until (k = 0) or (N mod k = 0);
        if k <> 0 then print(j,k,N div k);
      until k = 0;
      repeat M := M div j; until M mod j <> 0;
    end;{then}
    inc(j);
  until M = 1;

  {fclose}
  close(fin); close(fout);
end.{main}

{
13þ Trabajando con primos.                                Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los n£meros primos  tienen muchas propiedades,  ejemplo de este  es el
siguiente ejercicio que les propongo. Si p es un n£mero primo (p >  1)
y divide el producto de dos n£meros a y b entonces a lo sumo p  divide
a cualquiera de los dos n£meros a o b.

Tarea

A usted se le  dar   a trav‚s de  un fichero texto un  producto de dos
n£meros  enteros cualesquiera  y usted  debe de  determinar todos  los
n£meros primos p que cumple estas condiciones adem s de los valores de
a y b.

Ejemplo: sea a * b = 28, se pueden determinar los siguientes datos:
         los divisores de 28 son: 1, 2, 4, 7, 14 y 28,
         donde solamente 2 y 7 son los n£meros primos, entonces
         se obtiene:

          p  =   2   2   2    2    7   7    7
          a  =  28  14   4    2   28   7   14
          b  =   1   2   7   14    1   4    2

         observe que todas estas combinaciones da como producto a * b
         = 28, y a siempre es divisible por p.

Entrada

La Entrada ser  a  trav‚s del fichero texto  PRIMO.ENT, el cual en  su
£nica l¡nea aparecer  el valor de N, (1 < N <= 10000000).

Salida

La salida ser   hacia el fichero  texto PRIMO.SAL, el  cual debe tener
por cada primo encontrado cuatro  l¡neas, donde la primera l¡nea  debe
imprimirse el n£mero primo p, en la segunda l¡nea cual de los  n£meros
a o b  es divisible por  p, en la  tercera l¡nea el  n£mero a o  b que
puede o no ser divisible por p y la cuarta l¡nea debe ser un  registro
en blanco para delimitar las soluciones encontradas. La soluci¢n  como
muestra el ejemplo de  salida ser  £nica por  lo que su soluci¢n  debe
coincidir con  los juegos  de datos,  de lo  contrario tendr    0 ptos
este.

Nota: Se exige un programa que no puede emplear estructura de arreglos
ni  recursividad,  debe   de  ser  con   ciclos,  en  este   caso  ser
descalificado.

Ejemplos de Entrada y Salida:

     Ejemplo # 1

     PRIMO.ENT

     10


     PRIMO.SAL

     2
     10
     1

     2
     2
     5

     5
     10
     1

     5
     5
     2


     Ejemplo # 2

     PRIMO.ENT

     4

     PRIMO.SAL

     2
     4
     1

     2
     2
     2
}