{koder: A^2P}{5 - 3 - 2007}
{PSN 2006 #92 "Medianas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  a,b,c           : real;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  repeat
    readln(fin,a,b,c);
    if (a + b > c) and (a + c > b) and (b + c > a)
      then writeln(fout,sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a))/3 :0:3)
      else writeln(fout,-1);
  until seekeof(fin);

  {fclose}
  close(fin); close(fout);
end.{main}

{
92ş Medianas.                                              M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dadas  las longitudes  de las  tres medianas  de un  triangulo, usted
deber   hallar  el area  del  tri ngulo. A  menos  que este  flojo  en
geometr¡a debe saber que la mediana  de un triangulo se forma al  unir
el punto  medio de  un lado  y el  vertice opuesto.  De esta  forma el
triangulo tiene 3 medianas.

Entrada

El fichero  de entrada  MEDIAN.IN contiene  1000 entradas.  Cada l¡nea
contien  tres numeros  que denotan  la longitud  de las  medianas del
tri ngulo. Todos  los valores  en la  entrada seran  menor que 100. La
entrada estara terminada por un fin de fichero.

Salida

Para cada l¡nea de entrada MEDIAN.OUT usted deber  producir una  l¡nea
de  salida.  Esta  l¡nea  contendra  el  area  del  tri ndulo  para la
correspondiente entrada. Si no  es posible construir un  triangulo con
estas medianas, el area del tri ngulo en la salida deber  ser -1.  Las
areas ser n redondeadas a 3 digitos despues del punto decimal.


Ejemplo de Entrda y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ MEDIAN.IN ³   ³ MEDIAN.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3 3 3     ³   ³ 5.196      ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ   ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
}