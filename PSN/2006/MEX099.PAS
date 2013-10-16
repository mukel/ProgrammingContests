{koder: A^2P}{24 - 3 - 2007}
{PSN 2006 #99 "Zapatos Vacunos M gicos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxF = 51;
  mov : array[0..1,0..1,1..8] of shortint =
  (((-2,-2,-1,-1,1,1,2,2),(-1,1,-2,2,-2,2,-1,1)),
   ((-2,0,0,2,0,0,0,0),(0,-2,2,0,0,0,0,0)));
var
  fin,fout        : text;
  F,C,X1,Y1,X2,Y2,
  i,j,a,b,sol     : longint;
  size            : array[0..1] of longint;
  mark            : array[0..1,0..MaxF,0..MaxF] of boolean;
  qx,qy           : array[0..1,0..MaxF * MaxF * 1000] of longint;

    function ok(x,y: longint): boolean;
    var res : boolean;
    begin
      ok := ((x > 0) and (x <= F)) and
            ((y > 0) and (y <= C)) and (not mark[a,x,y]);
    end;{ok}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,F,C);
  readln(fin,X1,Y1);
  readln(fin,X2,Y2);

  {solve}
  a := 1;
  size[a] := 1;
  qx[a,1] := X1; qy[a,1] := Y1;
  repeat
    inc(sol);
    a := a xor 1; b := b xor 1;
    size[a] := 0;
    for i:=1 to size[b] do
      for j:=1 to 8 do
        if ok(qx[b,i] + mov[a,0,j],qy[b,i] + mov[a,1,j]) then
        begin
          inc(size[a]);
          qx[a,size[a]] := qx[b,i] + mov[a,0,j];
          qy[a,size[a]] := qy[b,i] + mov[a,1,j];
          mark[a,qx[a,size[a]],qy[a,size[a]]] := true;
        end;{for}
  until mark[0,X2,Y2] or mark[1,X2,Y2];

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
99ş Zapatos Vacunos M gicos.                               M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

¡Mientras estaba  pasteando en  un pastizal  particularmente profundo,
Betsy descubri¢  cuatro zapatos  vacunos m gicos!  Ella se  los puso y
descubri¢  que  le  permit¡an  saltar  en  el  pastizal  el  cual, por
supuesto, est  subdivido en una cuadricula conveniente con R filas  (1
<= R <= 50) y C columnas (1 <= C <= 50). Los zapatos le permitieron  a
ella saltar como  el caballo de  ajedrez y saltar  en otro patr¢n  que
ella  nunca antes  hab¡a visto.  Ella not¢  que ella  saltaba como  un
caballo  en  sus  movimientos  primero,  tercero,  quinto  y  en   los
movimientos numerados impares,  y que ella  saltaba en la  forma nueva
solo en los movimientos segundo,  cuarto, sexto, y en los  movimientos
numerados pares. Aqu¡ hay un mapa de los patrones de sus movimientos:


Movimientos de        Otros
Caballo               Movimientos
. . K . K . .         . . . O . . .
. K . . . K .         . . . . . . .
. . . B . . .         . O . B . O .
. K . . . K .         . . . . . . .
. . K . K . .         . . . O . . .

Betsy comienza en la 'B'  y dependiendo si su siguiente  movimiento es
par o impar, salta a uno de las  'K's o  'O's. D ndose cuenta que ella
puede desplazarse en  el pastizal m s  r pidamente, Betsy se  pregunta
cu n lejos la llevara a ella saltar usando los zapatos m gicos en todo
el camino hasta la barra  de chocolate que se le  cay¢ accidentalmente
al Granjero  Juan en  su visita  m s reciente  a las  vacas. Dados  el
tama¤o del  campo junto  con las  ubicaciones de  Betsy y  la barra de
chocolate, determine el  m¡nimo n£mero de  saltos con zapatos  m gicos
requeridos  para  que  Betsy  llegue  al  cuadrado  con  la  barra  de
chocolate. A ella no se le permite saltar fuera del pastizal, pero  es
seguro que siempre es posible llegar a la barra de chocolate.

NOMBRE DEL PROBLEMA: MCS.

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio respectivamente R y C

- L¡nea 2: Dos enteros separados por espacio: respectivamente la  fila
y la columna de la posici¢n inicial de Betsy.

- L¡nea 3: Dos enteros separados por espacio: respectivamente la  fila
y la columna de la posici¢n de la barra de chocolate.

ENTRADA EJEMPLO (archivo MCS.IN):

4 5
4 1
4 3

DETALLES DE LA ENTRADA:

. . . . .
. . . . .
. . . . .
B . C . .

FORMATO DE SALIDA:

- L¡nea 1: Un solo entero que es el m¡nimo n£mero de saltos usando los
zapatos m gicos hasta que Betsy llegue a la barra de chocolate.

SALIDA EJEMPLO (archivo MCS.OUT):

3

DETALLES DE LA SALIDA:

. . . . .
. 1 . 2 .
. . . . .
B . 3 . .
}
