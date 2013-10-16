{koder: A^2P}
{PSN 2002 #45 "El poder de la Criptograf¡a"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxLen = 120;
  SMALLER = -1;
  EQUAL = 0;
  GREATER = 1;
var
  fin,fout        : text;
  ch              : char;
  N,M,i,j         : byte;
  d,h,sol,r,t     : qword;
  target,num      : array[0..MaxLen] of byte;

    function compare(k: qword): shortint;
    begin
      num[0] := 1; num[num[0]] := 1;
      for i:=1 to N do
      begin
        r := 0;
        if num[0] > M then exit(GREATER);
        for j:=1 to num[0] do
        begin
          t := num[j] * k + r;
          num[j] := t mod 10;
          r := t div 10;
        end;{for}
        if r > 0 then
          repeat
            inc(num[0]); num[num[0]] := r mod 10;
            r := r div 10;
          until r = 0;
      end;{for}
      if num[0] > M then exit(GREATER);
      if num[0] < M then exit(SMALLER);
      for i:=1 to M do
        if num[M - i + 1] > target[i] then exit(GREATER)
          else if num[M - i + 1] < target[i] then exit(SMALLER);
      exit(EQUAL);
    end;{check}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  repeat
    read(fin,ch); inc(M);
    target[M] := ord(ch) - ord('0');
  until seekeof(fin);

  {solve}
  d := 1; h := 1000000000;
  repeat
    sol := (d + h) shr 1;
    case compare(sol) of
      SMALLER : d := sol + 1;
      GREATER : h := sol;
      EQUAL   : break;
    end;{case}
  until false;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
45þ El poder de la Criptograf¡a                             Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  trabajo  actual  en  criptograf¡a  involucra (entre otras cosas) a
n£meros   primos  grandes,  en  inform tica  se  pueden  calcular  con
funciones  de  n£meros  primos.  El  trabajo  en  esta  rea ha sido el
resultado del uso pr ctico de la teor¡a de n£meros y de otras ramas de
la  matem tica  consideradas  de  inter‚s  s¢lo te¢rico. Este problema
involucra el c lculo eficiente de las ra¡ces de n£meros enteros.

Tarea

Dado  un  entero n >= 1  y  un  entero p >= 1  usted  debe escribir un
programa  que  determine, la  n-‚sima  ra¡z  positiva  de  p. En  este
problema, dados tales   enteros  n y p, p siempre ser  de la forma k^n
para un entero k (este entero es lo que su programa debe encontrar).

Entrada

La  entrada ser  a trav‚s del fichero texto CRIPTO.IN el cual consiste
en  una  sucesi¢n  de  pares de enteros n y p, cada entero en una sola
l¡nea.  Para  todos  los pares 1 <= n <= 200, 1 <= p <= 10^101, existe
un entero k, 1 <= k <= 10^9 tal que k^n = p.

Salida

La  salida  ser   hacia  el fichero texto CRIPTO.OUT. Para cada par de
enteros n  y p, debe imprimirse el valor  de la raiz  n-‚sima de p, es
decir, el n£mero k tal que k^n = p.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ CRIPTO.IN              ³   ³ CRIPTO.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 2                      ³   ³ 4          ³
³ 16                     ³   ³ 3          ³
³ 3                      ³   ³ 1234       ³
³ 27                     ³   ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 7                      ³
³ 4357186184021382204544 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}