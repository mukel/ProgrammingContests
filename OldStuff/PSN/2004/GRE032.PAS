{koder: A^2P}
{PSN 2004 #32 "Exchange"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,B,S,i         : word;
  d,m,t           : real;

    function max(a,b: real): real;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  m := 100.0;
  for i:=1 to N do
  begin
    readln(fin,B,S); t := d;
    d := max(d,m / 100 * B );
    m := max(m,t / S * 100 );
  end;{for}

  {dprint}
  writeln(fout,m:0:2);

  {fclose}
  close(fin); close(fout);
end.{main}

{
32ş Exchange.                                              Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

David, de alg£n modo, adquiri¢ las tasas de cambio del d¢lar americano
a marcos alemanes para varios d¡as en el futuro.

Tarea

Escriba un programa que har  pensar a David en cu ndo comprar o vender
marcos o d¢lares para que, empezando con 100 marcos ‚l termine con la
mayor cantidad posible de marcos al final del £ltimo d¡a.

Fichero de entrada (EXCHANGE.IN)

La primera l¡nea del archivo de la entrada contiene un n£mero natural
N, 1 <= N <= 100, el n£mero de d¡as futuros por los que David conoce
las tasas de cambio. Cada uno de las N l¡neas siguientes contiene dos
n£meros naturales B y S separados con un espacio, 100 <= B <= S <=
1000. La (i+1) - ‚sima l¡nea describe el tipo de cambio del i - ‚simo
d¡a. Esos dos n£meros determinan la tasa de cambio de la manera
siguiente: Pueden comprarse B d¢lares para 100 marcos, y pueden
comprarse 100 marcos para S d¢lares.

Fichero de salida (EXCHANGE.OUT)

La primera y £nica l¡nea del archivo de salida debe contener un n£mero
que representa la mayor cantidad de marcos deseados escrito con dos
lugares decimales.

Comentario: Debido a los errores con la aritmetica de los reales, se
considerar n como correctos los resultados dentro del rango de error
de 0.05 marcos.

Ejemplo #1 de Entrada y Salida      Ejemplo #2 de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ EXCHANGE.IN ³ ³ EXCHANGE.OUT ³    ³ EXCHANGE.IN ³ ³ EXCHANGE.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3           ³ ³ 102.07       ³    ³ 5           ³ ³ 103.12       ³
³ 393 398     ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ    ³ 300 300     ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 394 401     ³                     ³ 310 320     ³
³ 386 386     ³                     ³ 320 330     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ                     ³ 330 330     ³
                                    ³ 300 320     ³
                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


Ejemplo #3 de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ EXCHANGE.IN ³ ³ EXCHANGE.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 8           ³ ³ 126.14       ³
³ 218 219     ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 228 231     ³
³ 227 235     ³  Ejemplo #3
³ 205 213     ³
³ 230 232     ³  D¡a 2... Cambiando 100.0000 DEM a 228.0000 USD
³ 239 239     ³  D¡a 4... Cambiando 228.0000 USD a 107.0422 DEM
³ 251 258     ³  D¡a 7... Cambiando 107.0422 DEM a 268.6760 USD
³ 205 213     ³  D¡a 8... Cambiando 268.6760 USD a 126.1389 DEM
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}