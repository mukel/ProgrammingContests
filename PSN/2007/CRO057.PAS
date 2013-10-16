{koder: A^2P}{2 - 4 - 2007}
{PSN 2007 # 57 "Mire la Direcci¢n Correcta"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 5000;
  oo = 1 shl 29;
var
  fin,fout        : text;
  ch              : char;
  N,i,j,k,h,
  sol,turns       : longint;
  cow,t           : array[0..MaxN] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,ch);
    cow[i] := byte(ch = 'B');
  end;{for}

  {solve}
  turns := oo;
  for i:=1 to N do
  begin
    k := 0; h := 0;
    fillchar(t,N + 1,0);
    for j:=1 to N - i + 1 do
    begin
      k := k xor t[j];
      if cow[j] xor k = 1 then
      begin
        inc(h);
        k := k xor 1;
        t[j + i] := t[j + i] xor 1;
      end;{then}
    end;{for}

    {check}
    for j:=j + 1 to N do
    begin
      k := k xor t[j];
      if cow[j] xor k = 1 then break;
    end;{for}

    if ((j > N) or (cow[j] xor k = 0)) and (h < turns) then
    begin
      turns := h;
      sol := i;
    end;{then}
  end;{for}

  {dprint}
  writeln(fout,sol,' ',turns);

  {fclose}
  close(fin); close(fout);
end.{main}

{
57þ Mire la Direcci¢n Correcta.                           Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan  ha arreglado sus  N (1 <=  N <= 5,000)  vacas en una
fila y muchas de ellas est n mirando hacia delante, como buenas vacas.
Algunas de ellas, sin embargo, est n mirando hacia atr s y ‚l necesita
que todas miren hacia delante para tenerlo feliz.

Afortunadamente, GJ hace poco compr¢ una m quina volteadora de  vacas.
Como  el  compr¢  un  modelo con  descuento,  esa  m quina  debe estar
irrevocablemente prefijada para  voltear K (1  <= K <=  N) vacas a  la
vez, y puede solo voltear vacas que est n juntas en la fila. Cada  vez
que se usa  la m quina, cambia  la direcci¢n en  que est‚n mirando  un
grupo contiguo de K vacas en la  fila (uno no la puede hacer en  menos
de K vacas, por  ejemplo, en cualquier extremo  de la fila de  vacas).
Cada vaca permanece en la  misma *ubicaci¢n* como antes, pero  termina
mirando en la *direcci¢n opuesta*. Una vaca que comience mirando hacia
delante  terminar  mirando  hacia atr s  despu‚s de  la acci¢n  de la
m quina y viceversa.

Debido a que  GJ, debe elegir  un solo  valor,  nunca cambiante de  K,
ay£delo a determinar el valor de [minimum] K que minimiza el n£mero de
operaciones requeridas por la m quina  para hacer que todas las  vacas
miren  hacia  delante.  Tambi‚n  determine  M,  el  n£mero  m¡nimo  de
operaciones de m quina requerida para que todas las vacas miren  hacia
delante usando ese valor de K.

NOMBRE DEL PROBLEMA: cowturn

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero: N.

-  L¡neas 2..N+1:  La l¡nea  i+1 contiene  un solo  car cter, F  o B,
indicando si la vaca i est  mirando hacia delante o hacia atr s.

ENTRADA EJEMPLO (archivo cowturn.in):

7
B
B
F
B
F
B
B

DETALLES DE LA ENTRADA:

Hay siete  vacas y  ellas est n  mirando hacia  atr s, atr s, delante,
atr s, atr s, delante, atr s, y atr s, respectivamente

FORMATO DE SALIDA:

- L¡nea 1: Dos enteros separados por espacio: K y M


SALIDA EJEMPLO (archivo cowturn.out):

3 3

DETALLES DE LA SALIDA:

Para K = 3, la m quina debe ser operada tres veces: voltear las  vacas
(1,2,3), (3,4,5), y finalmente (5,6,7):

      B > F   F   F
      B > F   F   F
      F > B > F   F
      B   B > F   F
      F   F > B > F
      B   B   B > F
      B   B   B > F
}