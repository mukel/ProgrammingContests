{koder: A^2P}
{PSN 2005 #51 "Grupos"}
{$B-,I-,Q-,R-,S-} 
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 500000;
var
  fin,fout        : text;
  N,i,j,k,cant    : longint;
  noaction        : boolean;
  sol             : array[0..MaxN,0..1] of longint;
  p,f,last        : array[0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  read(fin,p[1]);
  f[1] := p[1];
  for i:=2 to N do
  begin
    read(fin,j);
    p[i] := j; f[i] := j;
    last[i] := i - 1;
    k := last[i];
    repeat
      noaction := true;
      if f[k] = p[i] - 1 then
      begin
        p[i] := p[k];
        last[i] := last[k];
        noaction := false;
        inc(cant);
        sol[cant,0] := p[i];
        sol[cant,1] := f[i];
      end{then ->}
      else if p[k] = f[i] + 1 then
      begin
        f[i] := f[k];
        last[i] := last[k];
        noaction := false;
        inc(cant);
        sol[cant,0] := p[i];
        sol[cant,1] := f[i];
      end;{else}
      k := last[k];
    until (k = 0) or (noaction);
  end;{for}

  {dprint}
  if (p[N] = 1) and (f[N] = N) then
  begin
    writeln(fout,'DA');
    for i:=1 to N-1 do
      writeln(fout,sol[i,0],' ',sol[i,1]);

  end{then ->}
  else writeln(fout,'NE');

  {fclose}
  close(fin); close(fout);
end.{main}

{
51ş Grupos.                                                Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los  primeros N  enteros positivos  (numerados desde  1  hasta  N) son
escritos en  una pizarra  en alg£n  orden arbitrario  (de izquierda  a
derecha).

Un grupo es un conjunto de enteros los cuales forman un intervalo. Por
ejemplo, los conjuntos [2], [4 5] y [3 5 6 4] son grupos, pero [5 7 2]
y [2 4 5] no lo son. Al comienzo nosotros asumimos que cada n£mero  en
la   pizarra  forma   un  simple   grupo  el   mismo   solamente.  Hay
solamente una operaci¢n permitida -  concatenar dos grupos adyacentes,
pero solamente  si el nuevo  conjunto ser¡a un grupo.

Escriba  un  programa  el  cual  determine  si  la  secuencia  de  N-1
operaciones existe, despu‚s que todos los n£meros escritos est‚n en el
mismo grupo. Si tal secuencia existe, tu programa tiene que  encontrar
al menos una de ellas.

Ejemplo (una posible soluci¢n  para el tercer ejemplo)

[6] [3] [2] [1] [4] [5]
[6] [3] [2 1] [4] [5]
[6] [3 2 1] [4] [5]
[6] [3 2 1] [4 5]
[6] [3 2 1 4 5]
[6 3 2 1 4 5]

Entrada

La entrada  es a  trav‚s del  fichero GRUPE.IN  el cual  en la primera
l¡nea aparece un  entero N (1  <= N <=  500,000). En la  segunda l¡nea
aparecer n N enteros positivos separados por un espacio simple.  Estos
n£meros son escritos en la pizarra (en su estado inicial).

Salida

La salida ser  hacia el fichero GRUPE.OUT la palabra  'DA' (si) o 'NE'
(no) , dependiendo de si la secuencia existe. Si su respuesta es 'NE',
entonces esta primera l¡nea debe ser la £ltima. Si escribe la  palabra
'DA',  entonces  las   pr¢ximas N-1  l¡neas  deben   consistir de  dos
enteros a  y  b en ese orden  tal que estos n£meros en la l¡nea  (i+1)
son el  n£mero  m s   peque¤o y  el m s  grande respectivamente  en el
grupo formado en la i-‚sima concatenaci¢n.

Ejemplos de Entrada y Salida:

Ejemplo # 1

ÚÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ GRUPE.IN ³      ³ GRUPE.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 2        ³      ³ DA        ³
³ 2 1      ³      ³ 1 2       ³
ÀÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÙ

Ejemplo # 2

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ GRUPE.IN    ³   ³ GRUPE.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 6           ³   ³ NE        ³
³ 1 4 2 5 3 6 ³   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Ejemplo # 3

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ GRUPE.IN    ³   ³ GRUPE.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 6           ³   ³ DA        ³
³ 6 3 2 1 4 5 ³   ³ 1 2       ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ   ³ 1 3       ³
                  ³ 4 5       ³
                  ³ 1 5       ³
                  ³ 1 6       ³
                  ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
