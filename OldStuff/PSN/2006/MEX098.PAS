{koder: A^2P}{24 - 3 - 2007}
{PSN 2006 #98 "Marcas RADAR"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  S               : string;
  N,i,j,sol       : longint;
  len             : byte absolute S;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  repeat
    inc(sol);
    i := N; j := 0;

    {reverse}
    repeat
      j := j * 10 + i mod 10;
      i := i div 10;
    until i = 0;

    inc(N,j); str(N,S);
    for i:=1 to len div 2 do
      if s[i] <> s[len - i + 1] then break;
  until s[i] = s[len - i + 1];

  {dprint}
  writeln(fout,sol,' ',s);

  {fclose}
  close(fin); close(fout);
end.{main}

{
98ş Marcas RADAR.                                          M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

GJ ha estado marcando  las vacas con un  n£mero serial. Est n de  moda
las marcas  'RADAR', llamadas  as¡ porque  ellas se  leen igual  hacia
delante y hacia atr s: ellas son pal¡ndromos. Todas las vacas  quieren
que sus hijas sean marcadas con el nuevo estilo.

Cada madre quiere que  la marca de su  hija sea derivada de  su propia
marca no-RADAR  sumando la  marca de  la madre  y su  reversa. Algunas
veces (por ejemplo, 12 + 21 = 33) esto da directamente un  pal¡ndromo.
Algunas veces  el proceso  debe ser  repetido varias  veces hasta  que
aparezca la marca RADAR. Considere  la marca '87' que requiere  cuatro
pasos para convertirse en una marca RADAR:

          Marca    Reverso Suma
   Paso 1:   87 +    78 =  165
   Paso 2:  165 +   561 =  726
   Paso 3:  726 +   627 = 1353
   Paso 4: 1353 +  3531 = 4884

Dada la marca de la madre (un entero positivo), determine el n£mero de
pasos  y  la  marca  RADAR que  resulte  de  aplicar  el procedimiento
descrito. Ninguna respuesta ser  mayor que dos billones.

NOMBRE DEL PROBLEMA: radar

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero, la marca de la madre no pal¡ndromo.


ENTRADA EJEMPLO (archivo RADAR.OUT):

87

FORMATO DE SALIDA:

- L¡nea 1: Dos enteros separados por espacio, que son respectivamente:
el n£mero  de pasos  para encontrar  la marca  RADAR y  la marca RADAR
encontrada.

SALIDA EJEMPLO (archivo RADAR.OUT):

4 4884
}