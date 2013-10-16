{koder: A^2P}{7 - 5 - 2007}
{PSN 1998 #10 "Factoriales"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  EPSILON = 1e-9;
  MaxN = 150000;
var
  fin,fout        : text;
  dig,t           : real;
  N,i,j           : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N);

  {solve}
  for i:=1 to MaxN do
  begin
    t :=  trunc(dig + ln(i) / ln(10) + 1 - EPSILON);
    if t > N then break;
    if (t = N) and (j = 0) then j := i;
    dig := dig + ln(i) / ln(10);
  end;{for}

  {dprint}
  if N = 1 then
  begin
    writeln(fout,4);
    for i:=0 to 3 do writeln(fout,i);
  end{then ->}
  else
  if j = 0 then writeln(fout,'NO')
  else begin
    writeln(fout,i - j);
    for i:=j to i - 1 do writeln(fout,i);
  end;{else}

  {fclose}
  close(fin); close(fout);
end.{main}

{
 10ş Factoriales                                          Set£bal 1998
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ-

 Para 	un	entero positivo N, encuentre todos los n£meros positivos X
 (si alguno  de  tales n£mero  existe)	con la propiedad que el n£mero
 1 * 2 * 3 * ... * X tiene	exactamente N d¡gitos decimales. Asuma que
 N es como m ximo 150 000.

 Archivo de Entrada

 Tiene	una 	l¡nea simple la cual contiene un n£mero  entero positivo
 denotando el n£mero N.

 Archivo de Salida

 La  primera	l¡nea contiene la cadena "NO" si el n£mero no existe. De
 lo contrario la primera l¡nea debe contener un n£mero entero positivo
 denotando	cu ntos 	n£meros X existen. Las pr¢ximas l¡neas (hasta el
 final del archivo)  debe contener todos los n£meros X encontrados, un
 n£mero por l¡nea.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ Ejemplo de Entrada ³ ³ Ejemplo de Salida ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 5									³ ³ 1 								³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ³ 8 								³
												ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}