{koder: A^2P}
{PSN 2000 #45 "Suma de Subconjuntos" }
program ss;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i          : byte;
   S,k          : longint;
   m            : array[0..780] of longint;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     read(fin,N);

     {solve}
     S := N * (N + 1) shr 1;
     if not odd(S) then
     begin
          m[0] := 1;
          S := S shr 1;
          for i:=1 to N do
              for k:=S downto i do
                  inc(m[k],m[k-i]);
          write(fout,m[S] shr 1);
     end{then}
     else write(fout,0);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
 45ş Suma de Subconjuntos                                   China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Para  muchos  conjuntos  de  enteros  consecutivos  desde  1  hasta  N
(1  ó  N  ó  39) uno puede particionar el conjunto en dos subconjuntos
cuyas sumas sean id‚nticas.

Por  ejemplo,  si  N=3, uno puede particionar el conjunto {1, 2, 3} de
una forma tal que la suma de ambos subconjuntos sean id‚nticas.

        {3} y {1, 2}

Esto  se  cuenta  como  una partici¢n simple (por ejemplo, invirtiendo
el  orden  de  los elementos en la misma partici¢n no se incrementa la
cantidad de particiones).

Si  N=7, hay 4 formas de particionar el conjunto {1, 2, 3, ..., 7} tal
que cada partici¢n tenga la misma suma:

        {1, 6, 7}     y  {2, 3, 4, 5}
        {2, 5, 7}     y  {1, 3, 4, 6}
        {3, 4, 7}     y  {1, 2, 5, 6}
        {1, 2, 4, 7}  y  {3, 5, 6}

Dado  N,  su programa tiene que imprimir el n£mero de formas en que un
conjunto   que  contenga  los  enteros  desde  1  hasta  N  pueda  ser
particionado en dos subconjuntos cuyas sumas sean id‚nticas. Imprima 0
si no hay tal forma.

Su  programa  tiene  que  calcular la respuesta, no buscar ‚sta en una
tabla.

Fichero de entrada:

El  fichero  de  entrada  contiene  una l¡nea simple con un entero que
representa el valor de N.

Fichero de salida:

El  fichero  de  salida  contiene  una  l¡nea simple con un entero que
representa  cu ntas  particiones  que suman lo mismo pueden ser hechas
del  conjunto  {1, 2, 3, ..., N}. El fichero de salida debe contener 0
si no hay formas de hacer una partici¢n que sume lo mismo.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo de entrada³ ³Ejemplo de salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 7                ³ ³ 4               ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}

