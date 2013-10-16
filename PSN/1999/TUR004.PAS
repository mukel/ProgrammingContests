{koder: A^2P}{19 - 3 - 2007 3:07AM }
{PSN 1999 #4 "Camelot"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  oo = 255;
  mov : array[0..1,1..8] of shortint =
  ((-2,-2,-1,-1,1,1,2,2),(-1,1,-2,2,-2,2,-1,1));
type
  coord = record
    X,Y : byte;
  end;{coor}
var
  fin,fout        : text;
  ch              : char;
  N,i,j,k,h,sol   : longint;
  f1,f2,c1,c2     : byte;
  list            : array[0..65] of coord;
  state           : array[1..8,1..8] of byte;
  horse,king      : array[1..8,1..8,1..8,1..8] of byte;

    function ok(i,j: shortint): boolean;
    var res : boolean;
    begin
      res := ((i > 0) and (i < 9)) and
            ((j > 0) and (j < 9));
      res := res and (state[i,j] = 0);
      ok := res;
    end;{ok}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  repeat
    inc(N);
    read(fin,ch);
    list[N].X := byte(ord(ch) - ord('A') + 1);
    read(fin,ch);
    list[N].Y := byte(ord(ch) - ord('0'));
  until seekeoln(fin);

  {solve}

  {horses}
  for f1:=1 to 8 do for c1:=1 to 8 do
  begin
    fillchar(state,sizeof(state),0);
    state[f1,c1] := 1;
    for i:=1 to 20 do
    begin
      for f2:=1 to 8 do for c2:=1 to 8 do
        if state[f2,c2] = 1 then
        begin
          for j:=1 to 8 do
            if ok(f2 + mov[0,j],c2 + mov[1,j]) then
            begin
              state[f2 + mov[0,j],c2 + mov[1,j]] := 2;
              horse[f1,c1,f2 + mov[0,j],c2 + mov[1,j]] := i;
            end;{for}
          state[f2,c2] := 3;
        end;{then}
      for f2:=1 to 8 do for c2:=1 to 8 do
        if state[f2,c2] = 2 then state[f2,c2] := 1;
    end;{for}
  end;{for}

  {king}
  for f1:=1 to 8 do for c1:=1 to 8 do
    for f2:=1 to 8 do for c2:=1 to 8 do
      king[f1,c1,f2,c2] := abs(f2 - f1) + abs(c2 - c1);

  sol := oo;
  for f1:=1 to 8 do for c1:=1 to 8 do
    for f2:=1 to 8 do for c2:=1 to 8 do
      for h:=2 to N do
      begin
        j := horse[list[h].X,list[h].Y,f1,c1] +
             king[list[1].X,list[1].Y,f1,c1] +
             horse[f1,c1,f2,c2];
        for i:=2 to N do if i <> h then
          j := j + horse[list[i].X,list[i].Y,f2,c2];
        if j < sol then sol := j;
      end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
4ş Camelot                                                Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Hace siglos, el rey  Arturo  y  los  caballeros  de  la  Mesa  Redonda
acostumbraban a encontrarse en a¤o nuevo para celebrar su camarader¡a.
En recuerdo de estos hechos consideramos un  juego  en  un  tablero de
ajedrez (8x8) en el cual hay un rey  y  arios  caballos  colocados  al
azar en distintas casillas.

  0 <= cantidad de caballos <= 63

                    ÚÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄ¿
                  8 ³H ³  ³  ³  ³  ³  ³  ³H ³
                    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                  7 ³  ³  ³  ³  ³  ³  ³  ³  ³
                    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                  6 ³  ³  ³  ³  ³  ³  ³  ³  ³
                    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´       Ejemplo de tablero
                  5 ³  ³  ³  ³  ³  ³  ³  ³  ³       de ajedrez
                    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                  4 ³  ³  ³  ³K ³  ³  ³  ³  ³
                    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                  3 ³H ³  ³  ³  ³  ³  ³  ³  ³
                    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                  2 ³  ³  ³  ³  ³  ³  ³  ³  ³
                    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                  1 ³  ³  ³  ³  ³  ³  ³  ³H ³
                    ÀÄÄÁÄÄÁÄÄÁÄÄÁÄÄÁÄÄÁÄÄÁÄÄÙ
                     A  B  C  D  E  F  G  H


Los movimientos del rey y de los caballos son los  mismos  que  en  el
ajedrez. Durante  el juego,  el  jugador  puede   colocar  m s de  una
pieza en una casilla porque las casillas son suficientemente grande de
modo tal que caben todas las piezas que sean necesarias.

El objetivo del jugador es mover las piezas de modo tal  que se junten
todas en la misma  casilla  en  el   menor   n£mero   de  movimientos.
Adicionalmente cuando el rey y uno o m s caballos se  encuentran en la
misma casilla el jugador puede elegir mover al  rey  y  a  un  caballo
simult neamente como un simple caballo, una vez  que  se  halla  hecho
este movimiento el rey y el caballo deberan permanecer juntos hasta el
final del juego. Mover el caballo junto con el rey cuenta como un solo
movimiento.

Escriba un programa que calcule el n£mero m¡nimo  de  jugadas  que  el
jugador debe realizar para producir el encuentro.

DATOS DE ENTRADA:

El archivo CAMELOT.IN contiene la configuraci¢n inicial  del  tablero,
codificado como una secuencia de  caracteres. La  cadena  contiene una
secuencia de hasta 64  distintas posiciones  del  tablero. La  primera
posici¢n es del rey y las restantes  de los caballos. Cada posici¢n es
un par letra-d¡gito. La  letra  indica la  coordenada  horizontal  del
tablero y el d¡gito indica  la  coordenada vertical del tablero. En el
ejemplo de entrada el rey esta en D4  y  los  caballos en A3, A8, H1 y
H8.

DATOS DE SALIDA:

El archivo CAMELOT.OUT debe  contener  una  sola  l¡nea  con un entero
positivo indicando el menor n£mero de  jugadas  que  el  jugador  deba
realizar para producir el encuentro.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Archivo de Entrada ³Archivo de Salida  ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³D4A3A8H1H8         ³10                 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
