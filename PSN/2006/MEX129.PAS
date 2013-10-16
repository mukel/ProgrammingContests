{koder: A^2P}{5 - 3 - 2007}
{PSN 2006 #129 "Zvrk"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,p,sol       : qword;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M);

  {solve}
  sol := 0; p := 1;
  repeat
    inc(sol,(M+p) div (p shl 1) * p);
    p := p shl 1;
  until p > M;
  p := 1; dec(N);
  repeat
    dec(sol,(N+p) div (p shl 1) * p);
    p := p shl 1;
  until p > N;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
129ş Zvrk                                                  M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Eliminando todos  los digitos  a la  izquierda del  digito 1  mas a la
derecha  en  la  representacion  binaria  de  algun  entero,  nosotros
obtenemos lo que es llamado el  "zvrk" de ese numero. Por ejemplo,  el
zvrk de 6 es decir (110)2 is 2  o sea (10)2, y el zvrk of 40  es decir
(101000)2 is 8 o sea (1000)2.

Tarea

Escriba un  programa que  calcule la  suma de  los zvrks  de todos los
numeros entre dos numeros dados A y B (inclusive).

Entrada

La primera y £nica linea del fichero de entrada ZVRK.IN contienen  dos
entreos A y B, 1 <= A <= B <= 1015.

Salida

La primera y £nica linea del fichero de salida ZVRK.OUT debe  contener
la la suma  de los zvrks  de todos los  numeros entre los  dos numeros
dados A y B (inclusive)


Nota: el resultado se  ajustara a un typo  entero con signo de  64-bit
(int64 in Pascal, long long in C/C++).

Ejemplos de Entrada y Salida

Ejemplo # 1

ZVRK.IN

176 177

ZVRK.OUT

17


Ejemplo # 2

input ZVRK.IN

5 9

ZVRK.OUT

13


Ejemplo # 3

ZVRK.IN

25 28

ZVRK.OUT

8
}