{koder: A^2P}
{PSN 2002 #1 "Rocket"}
uses rocket;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   Max,tmp      : byte;
   N,S,i,sol    : longint;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     readln(fin,N);
     for i:=1 to N do
     begin
          read(fin,tmp); inc(S,tmp);
          if tmp > Max then Max := tmp;
     end;{for}

     {dprint}
     if Max <= S div 2
        then sol := S
             else sol := 2 * Max - S + 1;
     write(fout,sol);
     sirocket(S,Max,sol);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
1þ Problema del Cohete                                      Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Hay N ciudades, identificadas por n£meros desde 1 hasta N. Se tiene un
cohete  para  transportar  a las personas entre las ciudades. Cada vez
que  se  realiza  un  viaje  en el cohete con personas de una ciudad a
alguna otra ciudad, ganas una suma fija de dinero. Para poder volar el
cohete  necesita  combustible.  En cada ciudad K hay CK recipientes de
combustible, donde 1 <= K <= N  y  0 <= CK <= 100.

El combustible de un recipiente es suficiente para alzar el cohete una
vez  fuera  de  la  atm¢sfera,  y  entonces  el  combustible  se agota
completamente,  despu‚s  el  cohete  puede guiarse a cualquiera de las
ciudades.  Se  har n  vuelos en el cohete hasta que se aterrice en una
ciudad en que no hay ning£n recipiente de combustible. Al comenzar, el
cohete  tiene un recipiente de combustible que le permite llegar desde
su  base  espacial  en las afueras de cualquier pueblo hasta la ciudad
que  se  desee.  El  cohete  solo  conseguir   combustible tomando los
recipientes que est n en las ciudades.

Tarea

Dado  el  n£mero de ciudades y el n£mero de recipientes de combustible
en  cada  ciudad,  encuentre    el  n£mero m ximo de viajes que pueden
hacerse de una ciudad a alguna otra ciudad.

Se le dar  una Unit ROCKET.TPU que contiene un procedimiento Sirocket.

Procedure Sirocket(sum, largest, answer: longint);

Sum: suma de los n£meros de recipientes en todas las ciudades.
Largest:  el  m s  grande  -  no  necesariamente  £nico  -   n£mero de
         recipientes en cualquier ciudad.
Answer: su respuesta el n£mero m ximo de vuelos.

El  procedimiento  Sirocket  imprime  en pantalla 1 si su respuesta es
correcta y 0 si sucede lo contrario.

Entrada

El nombre del archivo de Entrada es ROCKET.IN.
La  primera  l¡nea  del  archivo  de la Entrada contiene un entero: el
n£mero de ciudades N, 1 <= N <= 100000.
La segunda l¡nea contiene N enteros: los valores C1, C2, ..., CN. Para
cada CK tenemos 1 <= K <= N y 0 <= CK <= 100.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ ROCKET.IN ³ ³ ROCKET.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³ ³ 23         ³
³ 5 6 20    ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}