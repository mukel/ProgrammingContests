{koder: A^2P}{FPC}
{PSN 2004 #43 "Krug"}
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i,k,sol    : longint;
   pos          : array[1..100000] of longint;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     readln(fin,N);
     for i:=1 to N do
     begin
          readln(fin,k);
          pos[k] := i;
     end;{for}

     {solve}
     for k:=1 to N-1 do
         if pos[k] > pos[k+1] then inc(sol);

     {dprint}
     write(fout,sol);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
43ş Krug.                                                  Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
 
Mirko est  jugando un juego extremadamente interesante. El tiene un
juego de N cartas (numeradas de 1 a N). Tal que ning£n par de cartas
tengan el mismo n£mero. Las cartas ser n barajadas.

Mirko inicia con la primera carta y recorre el mont¢n hasta llegar a 
la carta con el n£mero 1, la cual ‚l quita del mont¢n. Despu‚s que ‚l 
busca y quita cada una de las cartas numeradas con 2, 3, 4, etc. 
siempre inicia desde el lugar donde ‚l encontr¢ la carta previamente
quitada. Cada vez que llega al final del mont¢n ‚l golpea con sus
manos y comienza otra vez desde el inicio del mont¢n.

Este procedimiento finalmente dejar  el mont¢n vac¡o y una vez que la 
£ltima carta (la numerada con N) sea quitada el juego termina.

Escriba un programa que, dada una barajada inicial del mont¢n, 
encuentre el n£mero de veces que Mirko durante el juego golpear  con 
sus manos.

Entrada (KRUG.IN)

La primera l¡nea del fichero de entrada contiene un entero N, el n£mero
de cartas del mont¢n, 1 <= N <= 100000.
Las pr¢ximas N l¡neas contienen los n£meros de las cartas dadas en el
orden de su aparici¢n en el baraje inicial.

Salida (KRUG.OUT)

La £nica l¡nea del fichero de salida debe contener el n£mero de golpes
pedidos como se defini¢ arriba.

Ejemplos Entrada y Salida

Ejemplo #1          Ejemplo #2       Ejemplo #3

ÚÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄ¿
³KRUG.IN³          ³KRUG.IN³        ³KRUG.IN³
ÃÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄ´
³ 3     ³          ³ 5     ³        ³ 7     ³
³ 2     ³          ³ 3     ³        ³ 3     ³
³ 1     ³          ³ 5     ³        ³ 6     ³
³ 3     ³          ³ 1     ³        ³ 7     ³
ÀÄÄÄÄÄÄÄÙ          ³ 4     ³        ³ 1     ³
ÚÄÄÄÄÄÄÄÄ¿         ³ 2     ³        ³ 5     ³
³KRUG.OUT³         ÀÄÄÄÄÄÄÄÙ        ³ 4     ³
ÃÄÄÄÄÄÄÄÄ´         ÚÄÄÄÄÄÄÄÄ¿       ³ 2     ³
³ 1      ³         ³KRUG.OUT³       ÀÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÙ         ÃÄÄÄÄÄÄÄÄ´       ÚÄÄÄÄÄÄÄÄ¿
                   ³ 2      ³       ³KRUG.OUT³
                   ÀÄÄÄÄÄÄÄÄÙ       ÃÄÄÄÄÄÄÄÄ´
                                    ³ 3      ³
                                    ÀÄÄÄÄÄÄÄÄÙ
}