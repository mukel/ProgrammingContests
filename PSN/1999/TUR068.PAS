{koder: A^2P}{12 - 3 - 2007}
{PSN 1999 #68 "Expresiones"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  dp              : array[0..1,-1..MaxN,-1..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);

  {solve}
  N := N div 2;
  dp[0,0,0] := 1; dp[1,0,0] := 1;
  for i:=0 to 1 do
    for j:=1 to N do
      for k:=j - M + i to j do if k >= 0 then
        dp[i,j,k] := dp[i,j - 1,k] + dp[i,j,k - 1];

  {dprint}
  writeln(fout,dp[0,N,N] - dp[1,N,N]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 68ş Expresiones                                          Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Sea    X   un  conjunto  de  expresiones  con  par‚ntesis  construidos
correctamente. Los elementos de X son cadenas que consisten £nicamente
de los caracteres "("  y ")". El conjunto X se define como sigue:

. Una cadena vac¡a pertenece a X.
. Si A pertenece a X, entonces (A) tambien pertenece a X.
. SI  A  y  B  pertenecen  a  X, entonces  la concatenaci¢n AB tambi‚n
  pertenece a X.

Por    ejemplo    las   siguientes  expresiones  de  par‚ntesis  est n
correctamente construidas (y por lo tanto pertenece a X).

()(())()
(()(()))

Las    expresiones    de  par‚ntesis  que  aparecen  debajo  no  est n
correctamente construidas (y no pertenece a X)

(()))(()
())(()

Sea  E  una  expresi¢n  de  par‚ntesis correcta (por lo tanto E es una
cadena contenida en X).

El largo de E es el n£mero de par‚ntesis sencillos (caracteres) en E.
La profundidad D(E) de E se define como sigue:

         ÚÄ
         ³  0 si E est  vac¡o
         ³
   D(E) Ä´  D(A)+1 si  E = (A), y A est  en X
         ³
         ³  M ximo entre D(A) y D(B) si E = AB y A, B est n en X.
         ÀÄ

Por  ejemplo,  el largo de "()(())()" es 8 su profundidad es dos. Cu l
es  el  n£mero  de  expresiones  de  par‚ntesis  correcto de largo N y
profundidad D, para los enteros positivos N y D dados.

Tarea

Escribir un programa el cu l:

ş Lea dos enteros N y D desde un fichero texto de entrada.
ş  Calcule el n£mero de expresiones de par‚ntesis correctos de largo N
  y profundidad D.
ş Escribir el resultado hacia un fichero texto de salida.

Entrada

La  £nica  l¡nea  del  fichero  de  entrada  contiene  2 enteros N y D
separados por un espacio, 2 ó N ó 38, 1 ó D ó 19.

Salida

La  £nica  l¡nea  del  fichero de salida contiene un entero simple, el
n£mero  de expresiones de par‚ntesis correctamente armado de largo N y
profundidad  D.  En el caso que no tenga soluci¢n el fichero de salida
contendr  un 0.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo de Salida ³  ³ Ejemplo de Entrada ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 6 2               ³  ³ 3                  ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Hay exactamente 3 expresiones construidas con par‚ntesis de longitud 6
y profundidad 2 que son:

(())()
()(())
(()())
}
