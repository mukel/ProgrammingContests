{koder: A^2P}{2 - 4 - 2007}
{PSN 2007 #54 "Gasto Mensual"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,C,D,M,H,i,sol : longint;
  t               : array[0..MaxN] of longint;

    function ok(value: longint): boolean;
    var i,j,cant : longint;
    begin
      i := 1; cant := 0;
      repeat
        j := i; inc(cant);
        if t[i] - t[i - 1] > value then exit(false);
        while (j < N) and (t[j + 1] - t[i - 1] <= value)
          do inc(j);
        i := j + 1;
      until i > N;
      ok := (cant <= C);
    end;{ok}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,C);
  for i:=1 to N do
  begin
    readln(fin,t[i]);
    inc(t[i],t[i - 1]);
  end;{for}

  {solve}
  sol := oo;
  D := 0; H := 1000000000;
  repeat
    M := (D + H) shr 1;
    if ok(M) then
    begin
      if M < sol then sol := M;
      H := M;
    end{then ->}
    else D := M + 1;
  until D = H;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
54ş Gasto Mensual.                                        Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan  es un mago  asombroso para la  contabilidad y se  ha
dado cuenta que podr¡a quedarse sin dinero para manejar la granja.  El
ya  ha calculado  y registrado  la cantidad  exacta de  dinero (1   <=
dinero_i <= 10,000) que ‚l  siempre necesitar¡a gastar en cada  uno de
los siguientes N (1 <= N <= 100,000) d¡as.

GJ  quiere  crear  un  presupuesto  para  un  conjunto  secuencial  de
exactamente M (1  <= M <=  N) per¡odos fiscales  llamados ïfajomesesï.
Cada uno  de estos  fajomeses contiene  un conjunto  de 1  ¢ m s  d¡as
consecutivos. Cada d¡a est  contenido en exactamente un fajomes.

El  objetivo  de  GJ  es organizar  los  fajomeses  de  tal manera  de
minimizar los gastos  del fajomes con  el mayor gasto  y por lo  tanto
determinar su l¡mite de gasto mensual.

NOMBRE DEL PROBLEMA: expense

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por un espacio: N y M

- L¡neas 2..N+1:  La l¡nea i+1  contiene el n£mero  de dolares que  el
Granjero Juan gasta en el i-‚simo d¡a.

ENTRADA EJEMPLO (archivo expense.in):

7 5
100
400
300
100
500
101
400

DETALLES DE LA ENTRADA:

Hay 7 d¡as para distribuir a trav‚s de 5 fajomeses. El gata $100, $400,
$300, $100, $500, $101, y $400 en d¡as consecutivos.

FORMATO DE LA SALIDA:

- L¡nea 1: El menor limite mensual posible que el Granjero Juan debe
       tener para sobrevivir.

SALIDA EJEMPLO (archivo expense.out):

500

DETALLES DE LA SALIDA:

Si el  Granjero Juan  programa los  meses de  tal manera  que los  dos
primeros d¡as son  un mes, el  tercero y el  cuarto son un  mes, y los
£ltimos tres sean sus propios meses, ‚l gasta a lo m ximo $500 en cada
mes. Cualquier  otro modo  de programaci¢n  dar  un  l¡mite de  m¡nimo
mensual m s grande.

100 400   300 100   500   101   400   Gasto Diario
---1---   ---2---   -3-   -4-   -5-   N£mero de Mes
  500       400     500   101   400   Gasto Mensual
}
