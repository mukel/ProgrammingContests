{koder: A^2P}{18 - 3 - 2007}
{PSN 2001 #88 "Computadoras extra¤as"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 200;
  oo = 1 shl 30;
var
  fin,fout        : text;
  N,i,j,k,h,a,b   : longint;
  t               : array[0..MaxN] of longint;
  d               : array[0..MaxN,0..1] of longint;
  c,last          : array[0..MaxN,0..MaxN] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

    procedure print(i,j: longint);
    var k : longint;
    begin
      if last[i,j] = 0 then exit;
      k := abs(last[i,j]);
      print(i,k);
      print(k + 1,j);
      if last[i,j] < 0
      then writeln(fout,k,' ',k + 1)
      else writeln(fout,k + 1,' ',k);
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,t[i],d[i,1],d[i,0]);
    inc(t[i],t[i - 1]);
  end;{for}

  {solve}
  for h:=1 to N - 1 do
    for i:=1 to N - h do
    begin
      j := i + h; c[i,j] := oo;
      for k:=i to j - 1 do
      begin
        a := (t[k] - t[i - 1]) * d[k,0] + (t[j] - t[k]) * d[k + 1,1];
        b := (t[k] - t[i - 1]) * d[k,1] + (t[j] - t[k]) * d[k + 1,0];
        if c[i,k] + c[k + 1,j] + min(a,b) < c[i,j] then
        begin
          c[i,j] := c[i,k] + c[k + 1,j] + min(a,b);
          if a <= b then last[i,j] := k
          else last[i,j] := -k;
        end;{then}
      end;{for}
    end;{for}

  {dprint}
  writeln(fout,c[1,N]);
  print(1,N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
88þ Computadoras extra¤as.                              Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Para que los estudiantes de la  PSN de  Inform tica pudieran resolver
el problema  de  las  Calcoman¡as, los profesores  ha  tra¡do  para el
laboratorio N computadoras  muy  extra¤as,  las cuales ha colocado  en
una fila, una al lado de la otra. Con el objetivo de tener m s memoria,
ellos han decido conectarlas, pero lo  £nico que tienen son N-1 cables
muy cortos, por lo  que  solamente  pueden  conectar  una  computadora
con  la que  se  encuentra  a su derecha, y a su izquierda en la fila,
excepto la primera y la £ltima que solo pueden ser conectadas con la de
la derecha y con la de la izquierda respectivamente. Esto  es posible,
ya  que  estas extra¤as m quinas cuentan cada una con dos puertos para
conexiones.

 Los profesores lo ten¡an todo listo para comenzar la conexi¢n de  las
m quinas cuando se dieron cuenta   que: la  £nica forma de conectarlas
para usar las memorias de todas era mediante un software   muy extra¤o
que estas  tra¡an residente,  el funcionamiento del software en  todas
las computadoras no era el mismo,  y  que  por  cierto  este  consum¡a
una   gran  cantidad de  electricidad.  Despu‚s  de   leer  la  ayuda,
entonces  ya  conocen que el software funciona de la siguiente manera:

- para que dos m quinas puedan ser conectadas una de ellas debe actuar
  como MASTER, y la otra como SLAVE.
- al conectarse las computadoras, la memoria con que trabaja  cada una
  de las conectadas, ser  entonces  la  suma de las  memorias de todas
  las  computadoras conectadas.
- en cada conexi¢n se consume  una  cantidad  de  electricidad  W  que
  puede ser  calculada como sigue:

    W =  Kmaster*MEMmaster + Ksalve*MEMslave

  donde:
  . MEMmaster es  la  memoria de  la computadora que fue  seleccionada
    como MASTER.
  . Kmaster, propiedad  de cada   computadora, llamado  coeficiente de
    consumo de electricidad cuando la m quina act£a como MASTER.
  . MEMslave es la memoria de la computadora que fue seleccionada como
    SLAVE.
  . Kslave, propiedad   de cada  computadora, llamado   coeficiente de
    consumo  de electricidad cuando la m quina act£a como SLAVE.

 Por ejemplo, suponga que tengamos  5  computadoras extra¤as   con las
 siguientes propiedades:

  ÚÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ¿
  ³Computadora ³  1  ³  2  ³  3  ³  4  ³  5  ³
  ÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄ´
  ³Memoria     ³  7  ³  3  ³  6  ³  1  ³  5  ³
  ³Kmaster     ³  2  ³  1  ³  1  ³  9  ³ 10  ³
  ³Kslave      ³  5  ³  4  ³  2  ³  2  ³  8  ³
  ÀÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ

 Una  posible  forma  de  conectar  las computadoras haciendo 4
 conexiones.
ÚÄÂÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ ³ MASTER  ³ SLAVE   ³ CONSUMO DE ELECTRICIDAD  ³ ESTADO DE LAS COMP.³
ÃÄÅÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³1³ (1)     ³ (2)     ³ 2*7 + 4*3 = 26           ³ 1-2  3  4  5       ³
³2³ (1,2)   ³ (3)     ³ 1*(7+3) + 2*6 = 22       ³ 1-2-3   4  5       ³
³3³ (4)     ³ (5)     ³ 9*1 + 8*5 = 49           ³ 1-2-3  4-5         ³
³4³ (1,2,3) ³ (4,5)   ³ 1*(7+3+6) + 2*(1+5) = 28 ³ 1-2-3-4-5          ³
ÀÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

 Al ver lo complicado que era conectar  estas extra¤as   computadoras,
y  que si no era  conectadas de forma ¢ptima se   derrochar¡a una gran
cantidad  de electricidad, los profesores decidieron dejar esta  tarea
en manos de los  estudiantes, para as¡ ellos no tener nada que ver con
esto.  Como  los  profesores  sab¡an  que  los  estudiantes eran   muy
perezosos, le  dijeron que si no conectaban las  computadoras gastando
la menor  cantidad  de  energ¡a  posible, los obligar¡a a "Ubicar  los
 tomos en la caja negra".

Tarea:

 Prepara un programa el cual determine como deben  ser conectadas  las
computadoras de tal forma que la cantidad de electricidad consumida sea
m¡nima.

Entrada:

 El fichero de entrada con nombre COMP.IN tiene en su primera l¡nea un
entero N (2 <= N <= 200), el  n£mero de computadoras. En  las pr¢ximas
l¡neas,  la  l¡nea  i + 1 del fichero (representa a  la computadora i)
contiene tres  enteros  positivos  separados  por un  simple  espacio:
la memoria, el coeficiente  de   consumo  de  electricidad  cuando  la
m quina act£a como MASTER, y el coeficiente de consumo de electricidad
cuando  la   m quina act£a  como SLAVE respectivamente de  la  i-‚sima
computadora en la fila. Ninguno de  los enteros del fichero de entrada
excede a 1000.

Salida:

 El fichero de salida debe tener el nombre COMP.OUT y contener  en su
primera l¡nea un entero que indique la cantidad m¡nima de electricidad
usada para hacer las conexiones. En las pr¢ximas l¡neas se describir 
como fueron hechas las conexiones, en su respectivo orden (una conexi¢n
por l¡nea). Una conexi¢n es descrita mediante un  par de enteros i,j
que indican que la i-‚sima comutadora en la fila fue usada como MASTER
y la j-‚sima como SLAVE. Note que i = j ñ 1.

Ejemplo #1 de entrada y salida:      Ejemplo #2 de entrada y salida
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ COMP.IN     ³ ³ COMP.OUT       ³  ³ COMP.IN     ³ ³ COMP.OUT       ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5           ³ ³ 125            ³  ³ 6           ³ ³ 191            ³
³ 7 2 5       ³ ³ 1 2            ³  ³ 8 8 19      ³ ³ 3 2            ³
³ 3 1 4       ³ ³ 2 3            ³  ³ 3 4 1       ³ ³ 4 3            ³
³ 6 1 2       ³ ³ 4 5            ³  ³ 2 4 1       ³ ³ 6 5            ³
³ 1 9 2       ³ ³ 3 4            ³  ³ 7 2 6       ³ ³ 4 5            ³
³ 5 10 8      ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ  ³ 8 7 2       ³ ³ 1 2            ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ                     ³ 3 4 12      ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}