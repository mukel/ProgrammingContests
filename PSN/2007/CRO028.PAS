{koder: A^2P}{5 - 3 - 2007}
{PSN 2007 #28 "Minuses"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  ch,last         : char;
  N,i             : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N - 1 do
  begin
    last := ch;
    readln(fin,ch);
    case ch of
      '+' : if last = '-' then write(fout,'(');
      '-' : if last = '+' then write(fout,')');
    end;{case}
    write(fout,'-');
  end;{for}
  if ch = '+' then write(fout,')');

  {fclose}
  close(fin); close(fout);
end.{main}

{
28ş Minuses.                                              Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La  operaci¢n  de  sustracci¢n no es asociativa, es decir (5-2)-1 = 2,
pero  5-(2-1)=4,  por lo tanto (5-2)-1 <> 5-(2-1). Esto implica que la
operacion  de  la forma 5-2-1 depende del orden de que se efectuan las
subtracciones.  Cuando  no  hay  par‚ntesis  nosotros asumimos que las
operaciones  fueron  efectuadas  de  izquierda a derecha, es decir, la
expresi¢n   5-2-1  denota  (5-2)-1.  Nosotros  le  estamos  dando  una
expresi¢n de la forma
       X1 +/- X2 +/-... +/- Xn,
donde  cada +/- denotan los signos + (mas) o - (menos) y X1, X2,... Xn
denotan    distintas    variables.   En  una  expresi¢n  de  la  forma
       X1 - X2 - ... - Xn
nosotros    queremos  insertar  par‚ntesis  de  tal  manera  que  para
obtener una expresi¢n equivalente a la expresi¢n dada. Por ejemplo, si
nosotros  queremos  obtener  una  expresi¢n equivalente a la expresi¢n
       X1 - X2 - X3 + X4 + X5 - X6 + X7
nosotros podemos insertar par‚ntesis en
       X1 - X2 - X3 - X4 - X5 - X6 - X7
como sigue
       ((X1 - X2) - (X3 - X4 - X5)) - (X6 - X7)

Nota:  los  par‚ntesis  que  no  encierran  a  ninguna  variable o que
encierran solamente una variable no est n permitido.

Tarea

Escriba un programa que:
- lea del fichero texto MIN.IN la descripci¢n de la expresi¢n dada de
  la forma X1 +/- X2 +/-... +/- Xn,
- determine la forma en que se insertar n los par‚ntesis en la expresi¢n
  X1  -  X2 - ... Xn tal que se obtenga una expresi¢n equivalente a la
  expresi¢n  dada;  como  m ximo N-1 par‚ntesis pueden ser insertados,
- describa en el fichero texto MIN.OUT esta distribuci¢n de los
  par‚ntesis.

Entrada

En el fichero de entrada MIN.IN hay un entero N, 2 <= N <= 1000000.
Este  es  el  n£mero de variables de la expresi¢n dada. En cada una de
las  siguientes  N-1 l¡neas hay un caracter + ¢ -. En la i-‚sima l¡nea
est  el signo que aparece entre Xi-1 y Xi en la expresi¢n dada.

Salida

En  la primera l¡nea del fichero de salida MIN.OUT tu programa debe de
escribir  la forma en que se insertar n los parentesis en la expresi¢n
X1  -  X2  - ... Xn. Solamente par‚ntesis y signos menos (sin espacios
entre  ellos)  deben ser escritos, y las variables X1, X2, ...Xn deben
ser  omitidas. Usted puede asumir que para los datos de prueba siempre
hay  una  soluci¢n,  si  existen  muchas  soluciones  tu programa debe
escribir una de ellas.

 Ejemplo de Entrada y Salida:

 ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ MIN.IN ³  ³ MIN.OUT        ³
 ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 7      ³  ³ ((-)-(--))-(-) ³
 ³ -      ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ -      ³
 ³ +      ³
 ³ +      ³
 ³ -      ³
 ³ +      ³
 ÀÄÄÄÄÄÄÄÄÙ
}