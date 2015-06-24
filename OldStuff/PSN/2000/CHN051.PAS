{koder: A^2P}
{PSN 2000 #51 "Factores y Factoriales" }
program fyf;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i,j,k      : word;

     function prime(d: word): boolean;
     var i    : byte;
     begin
          if d < 4 {2 o 3} then
          begin prime := true; exit; end;{then}
          prime := false;
          for i:=2 to trunc(sqrt(d)) do
              if d mod i = 0 then exit;
          prime := true;
     end;{prime}

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     read(fin,N);

     {solve}
     i := 2;
     repeat
           if prime(i) then
           begin
                k := N; j := 0;
                repeat
                      k := k div i;
                      inc(j,k);
                until k < i;
                write(fout,j,#32);
           end;{then}
           inc(i);
     until i > N div 2;
     for i:=i to N do if prime(i)
         then write(fout,1,#32);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
 51ş Factores y Factoriales.                                China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  factorial  de  un  n£mero  N  (se  escribe N!) es definido como el
producto  de  todos  los enteros desde 1 hasta N. Esto muchas veces es
definido recursivamente como sigue:

1! = 1
N! = N * (N - 1)!

El    factorial    crece  r pidamente   5! = 120, 10! = 2 628 800. Una
manera  de especificar tales n£meros grandes es describiendo el n£mero
de veces  que  los  n£meros primos aparecen en este, tal que 825 puede
ser  representado    como 0 1 2 0 1, lo que significa que no hay 2, un
n£mero 3, 2 n£meros 5, no hay potencia de n£meros 7 y un n£mero 11.

Escribir  un programa que dado un n£mero N (2 ó N ó 32000) escribir el
factorial  en  t‚rminos  de los n£meros de veces de los n£meros primos
que contenga.

Entrada

La entrada consiste de una l¡nea, la que contiene el entero N.

Salida

La  salida contiene un lista de n£meros que son el n£mero de veces que
cada  n£mero  primo est  en N!. Cada n£mero es separado por un espacio
en blanco.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #1 de Entrada³³Ejemplo #1 de Salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5                   ³³ 3 1 1              ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #2 de Entrada³³Ejemplo #2 de Salida                ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 53                  ³³ 49 23 12 8 4 4 3 2 2 1 1 1 1 1 1 1 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}