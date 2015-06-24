{koder: A^2P}
{PSN 2005 #26 "LSEG"}
program lseg;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   S,i,k,j      : byte;
   sol          : longint;
   m            : array[1..30] of byte;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     read(fin,S);
     for i:=1 to S do read(fin,m[i]);

     {solve}
     for i:=1 to S-2 do
         for k:=i+1 to S-1 do
             for j:=k+1 to S do
                 if (m[j]-m[k]) = (m[k]-m[i])
                    then inc(sol);

     {dprint}
     write(fout,sol);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
26ş Contabilidad de Comida                                Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una  secuencia lineal  es un  triple ordenado  (s1, s2,  s3) donde  la
diferencia s2-s1  es la  misma que  la diferencia  s3-s2. Por ejemplo:
(1,2,3), (2,4,6), y (14,21,28).

Dado un conjunto ordenado de S (3 <= S <= 30) enteros diferentes en el
rango 1..100,  cuente el  n£mero de  secuencias lineales  formados por
todos los triples posibles.

NOMBRE DEL PROBLEMA: lseq

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero, S
- L¡nea 2: S enteros separados por espacios

ENTRADA EJEMPLO (archivo lseq.in):

7
1 2 3 4 6 8 9

FORMATO DE SALIDA:

- L¡nea 1: Un solo entero que es el n£mero de subsecuencias lineales.
Se garantiza que el entero entrar  en un entero con signo de 32 bits.

SALIDA EJEMPLO (archivo lseq.out):

5

DETALLES DE LA SALIDA:

Estas son las secuencias:
1 2 3
2 3 4
2 4 6
3 6 9
4 6 8
}
