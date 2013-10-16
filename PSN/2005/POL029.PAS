{koder: A^2P}
{PSN 2005 #29 "Numeros Binarios Stirling"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 109;
var
  fin,fout        : text;
  N,M,i,j         : byte;
  c               : array[0..MaxN,0..MaxN] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M);

  {solve}
  c[0,0] := 1;
  for i:=1 to N do
    for j:=1 to i{M} do
      c[i,j] := j and c[i-1,j] xor c[i-1,j-1] and 1;

  {dprint}
  write(fout,c[N,M]);

  {fclose}
  close(fin);
  close(fout);
end.{main}

(*
 29þ Numeros Binarios Stirling.                           Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los numeros Stirling  del segundo tipo S(n,m) simbolizan al numero  de
formas para particionar  un conjunto  de  n objetos en m  subconjuntos
no vacios.  Por ejemplo,  hay 7  formas para  dividir un  conjunto  de
4 elementos en dos partes:

  {1,2,3} U {4}
  {1,2,4} U {3}
  {1,3,4} U {2}
  {2,3,4} U {1}
  {1,2} U {3,4}
  {1,3} U {2,4}
  {1,4} U {2,3}

Existe una recurrencia la cual permite calcular S(n;m) para todo m y n.

S(0,0) = 1; S(n,0) = 0 for n > 0; S(0,m) = 0 para m >0;
S(n,m) = mS(n-1,m) + S(n-1,m-1) para n,m > 0

Tu  tarea  es  muy  facil. Dado  los  enteros  n  y  m  que satisfacen
1 <=  m <= n, calcule la paridad de S(n,m), es decir, S(n,m) mod 2.

Ejemplo

S(4,2) mod 2 = 1.

Tarea

Escriba un programa el cual:

- lea  dos  enteros positivos  n  y  m  desde  el  fichero  de entrada
  STIRLING.IN
- calcule S(n,m) mod 2,
- escriba el resultado hacia el fichero de salida STIRLING.OUT.

Entrada

El fichero de entrada  STIRLING.IN contiene en una sola linea con  dos
enteros n y m (1 <= M <=  N <= 109) separados entre si por un  espacio
en blanco.

Salida

El fichero de  salida STIRLING.OUT  consiste  exactamente en una  sola
linea con el valor de S(n,m) mod 2.

Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ STIRLING.IN  ³ ³ STIRLING.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 4 2          ³ ³ 1            ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*)
